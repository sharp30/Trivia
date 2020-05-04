class Message:
    def __init__(self, code):
        self._msg_code = code


    def to_json(self):
        """
        definition will be in child's class
        """
        pass

    def get_code(self):
        return self._msg_code

    def message_content_size(self):
        """
        The function will calculate the size of the message's content and convert it to bytes object
        """
        return bytes(Message.length_to_dec_sequence(len(self.to_json())))


    def export_message(self):
        """
        The function will cast this object to a binary sequence of type 'bytes'
        """
        # build the binary message: [code~1byte~][content size~4bytes~][content~xbytes~]
        return bytes([self.get_code()]) + self.message_content_size() + bytes(self.to_json(), 'utf-8')

    @staticmethod
    def length_to_dec_sequence(length): 
        """
        the function will get a decimal integer and cast into 4 bytes integer that will fit the 'bytes' object
        EXAMPLE: 400 --> 0-0-1-90 // 256 --> 0-0-1-0 // 1000 --> 0-0-3-232
        FutureIdea: create recursive function instead
        """
        BITS_IN_BYTE = 8
        REQUIRED_BYTES = 4
        result = [0,0,0,0]

        if (length > 2** (4 * BITS_IN_BYTE)):
            raise Exception("Number is to Big!")
        index = 0
        while length > 0:
            result[REQUIRED_BYTES - 1 -index] = length % (2 ** BITS_IN_BYTE)
            length = length // (2 ** BITS_IN_BYTE)
            index += 1


        return result
