from Message import Message
import bson

class SignupRequest(Message):
    def __init__(self):
        super().__init__(10)
        self.set_username()
        self.set_password()
        self.set_email()


    def set_username(self):
        self.username = input("Enter username: ")


    def set_password(self):
        self.password = input("Enter password: ")


    def set_email(self):
        self.email = input("Enter email: ")


    def to_json(self):
        """
        rtype: bytes
        """
        return bson.dumps({"username": self.username, "password": self.password, "email": self.email})