#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <cmath>

#include <sys/types.h> 
#include <sys/socket.h>

#include <netinet/in.h>
#include <unistd.h>

#include "MessagePacket.pb.h"

#define DEF_PORT 5555

using namespace std;

const char MESSAGE_FILENAME[] = "message.txt";

const char ERROR_OPT[] = "ERROR";
const char OK_OPT[] = "OK";

const char TIME_OPT[]   = "TIME";
const char UPTIME_OPT[] = "UPTIME";
const char INV_OPT[]    = "INV";

time_t start_time;

int s;

proto::Message process() {

	proto::Message message;
	proto::Message answer;

	fstream input(MESSAGE_FILENAME, ios::in | ios::binary);
	if (!input) {
		answer.set_command(ERROR_OPT);
		answer.set_argument("Message not found.");
		return answer;
	}
	if (!message.ParseFromIstream(&input)) {
		answer.set_command(ERROR_OPT);
		answer.set_argument("Failed to parse message.");
		return answer;
	}

	if(!message.has_command()) {
		answer.set_command(ERROR_OPT);
		answer.set_argument("Message have not command.");
		return answer;
	}

	cout << message.command() << " : " << message.argument() << endl;

	if(message.command().compare(TIME_OPT) == 0) {

		answer.set_command(OK_OPT);

		time_t rawtime;
		time(&rawtime);
		answer.set_argument(ctime (&rawtime));

	} else if(message.command().compare(UPTIME_OPT) == 0) {

		answer.set_command(OK_OPT);
		time_t rawtime;
		time(&rawtime);

		ostringstream strs;
		strs << fabs(difftime(start_time, rawtime));

		answer.set_argument( strs.str() );

	} else if(message.command().compare(INV_OPT) == 0) {

		if(!message.has_argument()) {
			answer.set_command(ERROR_OPT);
			answer.set_argument("Message have not argument.");
			return answer;
		}
		answer.set_command(OK_OPT);
		answer.set_argument(string(message.argument().rbegin(), message.argument().rend()));

	} else {
		answer.set_command(ERROR_OPT);
		answer.set_argument("Unknown command.");
		return answer;
	}
	
	return answer;
}

void acceptMessage() {

	int cs;
	struct sockaddr_in c_addr;
	unsigned int c_len = sizeof(c_addr);

	if ((cs = accept(s, (struct sockaddr *) &c_addr, &c_len)) < 0) {
		cout << "Failed to accept client connection" << endl;
		exit(4);
	}

	proto::Message answer = process();

	fstream output(MESSAGE_FILENAME, ios::out | ios::trunc | ios::binary);
	if (!answer.SerializeToOstream(&output)) {
		cerr << "Failed to write address book." << endl;
		return;
	}

	// Sorry for this... but... i'm lazy.
	char ok_str[3];
	ok_str[0] = 'o';	
	ok_str[0] = 'k';
	ok_str[0] = '\0';

	send(cs, ok_str, strlen(ok_str), 0);

	close(cs);
}

int main() {

	GOOGLE_PROTOBUF_VERIFY_VERSION;

	time(&start_time);

	struct sockaddr_in server_addr;
	if ((s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
		cout << "Socket creating error" << endl;
		return 1;
	}
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(DEF_PORT);

	if (bind(s, (struct sockaddr *) &server_addr,
		               sizeof(server_addr)) < 0) {
		cout << "Failed to bind the server socket" << endl;
		return 2;
	}
	if (listen(s, 5) < 0) {
		cout << "Failed to listen on server socket" << endl;
		return 3;
	}

	cout << "Server is running." << endl;
	cout << "Kill process by signals, please." << endl;
	cout << "Server PID: " << getpid() << endl;

	string str;
	while(true) {
		acceptMessage();		
	}

	close(s);

	google::protobuf::ShutdownProtobufLibrary();

	return 0;

}
