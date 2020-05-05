from Message import Message
import bson
import binascii

class LoginRequest(Message):
    def __init__(self):
        super().__init__(20)
        self.set_username()
        self.set_password()

    def set_username(self):
        self.username = input("Enter username: ")

    def set_password(self):
        self.password = input("Enter password: ")

    def to_json(self):
        """
        rtype: bytes
        """
        return bson.dumps({"username": self.username, "password": self.password})
