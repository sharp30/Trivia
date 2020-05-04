import Config
import socket
import sys
import LoginRequest
import SignupRequest

BYTES_TO_READ = 1024  # standard number of bytes to read
MESSAGES = {1: SignupRequest, 2: LoginRequest}

def main():
    # Connect to server
    try:
        sock = connect_to_server()
    except Exception as e:
        print("Error: ", e)
        sys.exit()

    # from now on, the client and server are connected
    try:
        msg = sock.recv(BYTES_TO_READ).decode()  # get data from socket (success message)
    except ConnectionResetError as e:
        print("ERROR- " + str(e))
    
    
    try:
        choice = print_menu()
    except Exception as e:
        print(e)
    
    while choice != 0:
        try:
            msg = MESSAGES[choice]()
            sock.sendall(msg.export_message().encode())
            msg = sock.recv(BYTES_TO_READ).decode()  # get data from socket (success message)
            print(msg)
            choice = print_menu()
        except Exception as e:
            print(e)


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



def print_menu():
    """
    The function will print the menu for the user
    """
    choice = -1
    while int(choice) not in MESSAGES.keys() and choice != 0:
        print("Enter your choice:")
        print("0. Exit")
        print("1. Signup")
        print("2. Login")
        choice = input("Enter: ")

    return int(choice)


if __name__ == '__main__':
    main()
    