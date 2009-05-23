import core_pb2
import sys
import struct
import random
from socket import *

CORE_CHANNEL = 0
PING_REQUEST = 0
FIND_NODE_REQUEST = 2
ANNOUNCE_SERVICE_REQUEST = 6
GET_CHANNEL_REQUEST = 8
what = sys.argv[1]

def create_header(channel, command, sid):
	return struct.pack("<BBHHHL", 1, 3, 0xFFFF, channel, command, sid)

def random_nid():
	return "".join([chr(random.randint(0, 255)) for i in range(20)])

s = socket(AF_INET,SOCK_DGRAM)

if what == "ping":
	header = create_header(CORE_CHANNEL, PING_REQUEST, 0)
	data = ""
elif what == "find_node":
	header = create_header(CORE_CHANNEL, FIND_NODE_REQUEST, 0)
	outmsg = core_pb2.FindNodeRequest()
	outmsg.nid = random_nid()
	data = outmsg.SerializeToString()	
	print("<< " + repr(header) + " + " + repr(data))
	
elif what == "announce":
  header = create_header(CORE_CHANNEL, ANNOUNCE_SERVICE_REQUEST, 0)
  outmsg = core_pb2.AnnounceServiceRequest()
  outmsg.nid = random_nid()
  outmsg.service.append("compile")
  outmsg.service.append("repository")
  data = outmsg.SerializeToString()	
  print("<< " + repr(header) + " + " + repr(data))
  
elif what == "get_channel":
  header = create_header(CORE_CHANNEL, GET_CHANNEL_REQUEST, 0)
  outmsg = core_pb2.GetChannelRequest()
  outmsg.name = "simpledb"
  data = outmsg.SerializeToString()	
  print("<< " + repr(header) + " + " + repr(data))

s.sendto(header + data, ("127.0.0.1", 9081))
data, addr = s.recvfrom(65536)
print(">> addr = " + repr(addr))
print(">> " + str(len(data)) + " bytes = " + repr(data))
	
