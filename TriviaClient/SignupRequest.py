import Message
import json

class SignupRequest(Message):
    def __init__(self):
        super().__init__(100)
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

<<<<<<< HEAD
=======
    @staticmethod
    def cast_size_to_bin(size):
        return bin(size)[2:].zfill(32) //function zfill: - adds zeroes at beginning

    @staticmethod
    def cast_msg_code_to_bin(code):
        return bin(code)[2:].zfill(8) //function zfill: - adds zeroes at beginning
>>>>>>> d355471a5cdda1cad61db3b03868830e6f94e961

