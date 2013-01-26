package com.gromholl.proto;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.Reader;
import java.net.Socket;

import com.google.protobuf.ByteString;
import com.gromholl.proto.MessagePacket.Message;;

public class Client {
	
	public static final String TIME_OPT      = "TIME";
	public static final String UPTIME_OPT    = "UPTIME";
	public static final String INV_OPT       = "INV";
	public static final String ERRROR_OPT    = "ERROR";

	public static final String TIME_FLAG   = "-t";
	public static final String UPTIME_FLAG = "-u";
	public static final String INV_FLAG    = "-i";
	public static final String HELP_FLAG   = "-h";

	public static final String DEF_ADDR = "localhost";
	public static final int DEF_PORT = 5555;
	
	public static void exec(String flag, String opt) throws Exception {
		
		Message.Builder message = Message.newBuilder();
		
		if(flag.equals(TIME_FLAG)) {			
			message.setCommand(ByteString.copyFromUtf8(TIME_OPT));			
		} else if(flag.equals(UPTIME_FLAG)) {			
			message.setCommand(ByteString.copyFromUtf8(UPTIME_OPT));			
		} else if(flag.equals(INV_FLAG)) {			
			message.setCommand(ByteString.copyFromUtf8(INV_OPT));
		}
		
		if(opt != null) {
			message.setArgument(ByteString.copyFromUtf8(opt));
		}
			
		
		FileOutputStream output = new FileOutputStream("message.txt");
		message.build().writeTo(output);
	    output.close();
	    

		Socket s = new Socket(DEF_ADDR, DEF_PORT);

	    BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
	    
	    br.readLine();
	    
	    Message answer = Message.parseFrom(new FileInputStream("message.txt"));	    
	    System.out.println(answer.getArgument());

	}
	
	public static void main(String[] args) {
		
		if(args.length == 1) {
			
			if(args[0].equals(HELP_FLAG)) {
				
				System.out.println("*** PROTOBUF TEST APPLICATION HELP ***\n" +
						   "Synopsis:\n" +
						   " -t\n" +
						   "     get server time\n" +
						   " -u\n" +
						   "     get server uptime\n" +
						   " -i string\n" +
						   "     get inverse string\n" +
						   "\n" +
						   "Created by GromHoll. 2013");
				return;				
			} else if(args[0].equals(TIME_FLAG) || args[0].equals(UPTIME_FLAG)) {
				
				try {
					exec(args[0], null);
				} catch(Exception e) {
					e.printStackTrace();
				}
				return;				
			}
		} else if(args.length == 2) {
			
			if(args[0].equals(INV_FLAG)) {				

				try {
					exec(args[0], args[1]);
				} catch(Exception e) {
					e.printStackTrace();
				}
				return;				
			}
		}
		
		System.out.println("Unknown arguments. Use Client -h for looking help.");
		
	}

}
