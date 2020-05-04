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

        BITS_IN_BYTE = 8
        content = self.to_json()

        if len(content) < 2 ** BITS_IN_BYTE:  # means the : len < 256
            length = bytes([0,0,0,len(content)])

        length = bytes(4)  # create an object of 4 bytes to hold the content size
        return (len(self.to_bin()) / 8)

    def export_message(self):
        """
        The function will cast this object to a binary sequence of type 'bytes'
        """
        content = bytes(self.to_json(), 'utf-8')
        #build the binary message: [code~1byte~][content size~4bytes~][content~xbytes~]
        msg = bytes([super().get_code()]) + self.message_content_size_bytes() + content

        return msg


