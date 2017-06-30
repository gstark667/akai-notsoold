import socket
import threading

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(('127.0.0.1', 6666))
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
server.listen(5)

sock1 = server.accept()
print('client 1 accpeted')
sock2 = server.accept()
print('client 2 accpeted')

def router(sender, recver):
    print('spawning router')
    while True:
        recver[0].send(sender[0].recv(256))

print(sock1)
t1 = threading.Thread(target=router, args=(sock1, sock2))
t2 = threading.Thread(target=router, args=(sock2, sock1))

t1.start()
t2.start()

t1.join()
t2.join()
