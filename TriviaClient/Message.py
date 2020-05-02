class Message:
    def __init__(self, code):
        self._msg_code = code

    def get_code(self):
        return self._msg_code