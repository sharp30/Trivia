import Message
import json
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
        return json.dumps({"username": self.username, "password": self.password})


    def message_content_size(self):
        """
        The function will calculate the size of the message's content and convert it to bytes object
        """
        length = bytes(Message.length_to_dec_sequence(len(self.to_json())))


    def export_message(self):
        """
        The function will cast this object to a binary sequence of type 'bytes'
        """
        # build the binary message: [code~1byte~][content size~4bytes~][content~xbytes~]
        return bytes([super().get_code()]) + self.message_content_size_bytes() + bytes(self.to_json(), 'utf-8')


