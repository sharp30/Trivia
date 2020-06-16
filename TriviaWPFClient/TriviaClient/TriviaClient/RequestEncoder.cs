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
            return new byte[5];
        }
    }
}