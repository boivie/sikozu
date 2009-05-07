import core_pb2
import sys
import struct
from socket import *

what = sys.argv[1]

if what == "ping":
	data = struct.pack("<BB18s20s", 0, 0, "testsid", "testnid")
	s = socket(AF_INET,SOCK_DGRAM)
	s.sendto(data, ("127.0.0.1", 9080))
	data, addr = s.recvfrom(65536)
	print(addr)
	print(repr(data))