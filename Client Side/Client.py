import Config
import socket
import re
import sys

BYTES_TO_READ = 5

def main():
    # Connect to server
    try:
        sock = connect_to_server()
    except Exception as e:
        print("Error: ", e)
        sys.exit()

    # from now on, the client and server are connected
    try:
        msg = sock.recv(BYTES_TO_READ).decode()  # get data from socket
    except ConnectionResetError as e:
        print("ERROR- " + str(e))

    if (msg == "Hello"):
        print(msg)
        sock.sendall(msg.encode())


def connect_to_server():
    """
    the function will connect the client with the server
    :return: a conversation socket
    :rtype: socket.socket
    """
    # Create a TCP/IP socket
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Connecting to remote computer 2020
    server_address = (Config.SERVER_IP, Config.SERVER_PORT)
    sock.connect(server_address)
    return sock



if __name__ == '__main__':
    main()
    