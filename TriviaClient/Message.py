class Message:
    def __init__(self, code):
        self._msg_code = code

    def get_code(self):
        return self._msg_code

    @staticmethod
    def cast_size_to_bin(size):
        return bin(size)[2:].zfill(32)

    @staticmethod
    def cast_msg_code_to_bin(code):
        return bin(code)[2:].zfill(8)