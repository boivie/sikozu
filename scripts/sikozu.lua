local port = 9080

print("Sikozu v" .. MAJOR_VERSION .. "." .. MINOR_VERSION)
print("Listening on UDP port " .. port .. "...")
listen_socket(port)

