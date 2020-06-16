using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TriviaClient
{
    public static class RequestEncoder
    {
        /*
        The function will encode a request object into an encoded request
        input: Request object
        output: bytes array represents the encoded message
        */
        public static byte[] Encode(Request req)
        {
            byte[] data = Convert.FromBase64String(req.CastToJson());
        

            byte[] code = FromIntToByte(req.GetMsgCode(), 1);
            byte[] size = FromIntToByte(data.Length, 4);

            byte[] full = new byte[5 + data.Length];
            Array.Copy(code, 0, full, 0, code.Length);
            Array.Copy(size, 0, full, code.Length, size.Length);
            Array.Copy(code, 0, full, code.Length + size.Length, data.Length);

            return full;
        }

        public static byte[] FromIntToByte(int val,int size)
        {
            byte[] arr = new byte[size];
            for (int i = 0; i<size; i++)
            {
                arr[i] = (byte)(val %256);
                val /= 256;
            }

            return arr;           
        }
    }
}