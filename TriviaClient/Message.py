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


    @staticmethod
    def length_to_dec_sequence(length):
        """
        the function will get a decimal integer and cast into 4 bytes integer that will fit the 'bytes' object
        EXAMPLE: 400 --> 0-0-1-90 // 256 --> 0-0-1-0 // 1000 --> 0-0-3-232
        FutureIdea: create recursive function instead
        """
        BITS_IN_BYTE = 8
        count = 0
        result = []

        if length < 2 ** BITS_IN_BYTE:  # means that : len < 256, fits to 1 byte
            result = [0,0,0,length]

        elif length < 2 ** (BITS_IN_BYTE * 2):  # means that : 255 < len < 65536, fits to 2 bytes
            substractor = 2 ** BITS_IN_BYTE
            while not (length < 2 ** BITS_IN_BYTE):
                length -= substractor
                count += 1 

            return [0, 0, count, length]

        elif length < 2 ** (BITS_IN_BYTE * 3):  # means that : 65535 < len < 16777216, fits to 3 bytes
            substractor = 2 ** (BITS_IN_BYTE * 2)
            while not (length < 2 ** (BITS_IN_BYTE * 2)):
                length -= substractor
                count += 1 

            result += [0, count]
            count = 0

            substractor = 2 ** BITS_IN_BYTE
            while not (length < 2 ** BITS_IN_BYTE):
                length -= substractor
                count += 1 

            result += [count, length]

        elif length < 2 ** (BITS_IN_BYTE * 4):  # means that : 16777215 < len < 4294967296, fits to 4 bytes
            substractor = 2 ** (BITS_IN_BYTE * 3)
            while not (length < 2 ** (BITS_IN_BYTE * 3)):
                length -= substractor
                count += 1 

            result += [count]
            count = 0
            
            substractor = 2 ** (BITS_IN_BYTE * 2)
            while not (length < 2 ** (BITS_IN_BYTE * 2)):
                length -= substractor
                count += 1 

            result += [count]
            count = 0

            substractor = 2 ** BITS_IN_BYTE
            while not (length < 2 ** BITS_IN_BYTE):
                length -= substractor
                count += 1 

            result += [count, length]

        else:
            raise Exception("Number is to Big!")

        return result