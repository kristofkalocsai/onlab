__author__ = 'kristofkalocsai'
import socket

TCP_IP = '127.0.0.1'
TCP_PORT = 5007
BUFFER_SIZE = 20  # Normally 1024, but we want fast response

s = socket.socket(socket.AF_INET6, socket.SOCK_STREAM)
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
s.bind(('', TCP_PORT))
s.listen(1)

conn, addr = s.accept()
print 'Connection address:', addr
try:
    while 1:
        data = conn.recv(BUFFER_SIZE)
        print "received data:", data
        conn.send("hello launchpad!\n")     # echo
except KeyboardInterrupt:
    conn.close()