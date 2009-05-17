import core_pb2
import sys
import struct
from socket import *

CORE_CHANNEL = 0
PING_REQUEST = 0
FIND_NODE_REQUEST = 2

what = sys.argv[1]

def create_header(channel, command, sid):
	return struct.pack("<BBHHHL", 1, 3, 0xFFFF, channel, command, sid)

s = socket(AF_INET,SOCK_DGRAM)

if what == "ping":
	header = create_header(CORE_CHANNEL, PING_REQUEST, 0)
	data = ""
elif what == "find_node":
	header = create_header(CORE_CHANNEL, FIND_NODE_REQUEST, 0)
	outmsg = core_pb2.FindNodeRequest()
	outmsg.nid = "testnid"
	data = outmsg.SerializeToString()	
	print("<< " + repr(header) + " + " + repr(data))
	
s.sendto(header + data, ("127.0.0.1", 9081))
data, addr = s.recvfrom(65536)
print(">> addr = " + repr(addr))
print(">> " + repr(data))
	
