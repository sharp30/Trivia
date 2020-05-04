import Message
import json

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
        return json.dumps({"username": self.username, "password": self.password, "email": self.email})

    def to_bin(self):
        st = self.to_json()
        return ''.join(format(ord(x), 'b') for x in st)

    def message_content_size(self):
        return (len(self.to_bin()) / 8)

    def export_message(self):
        #build the binary message: [code~1byte~][content size~4bytes~][content~xbytes~]
        msg = str(Message.cast_msg_code_to_bin(super().get_code())) + Message.cast_size_to_bin(self.message_content_size) + self.to_bin()
