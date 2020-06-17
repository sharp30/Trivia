using Newtonsoft.Json;
using Newtonsoft.Json.Bson;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TriviaClient
{
    public static class ResponseDecoder
    {

        public static Response Decode(int code, byte[] arr)
        {
            MemoryStream ms = new MemoryStream(arr);
            BsonReader reader = new BsonReader(ms);
            JsonSerializer serializer = new JsonSerializer();

            Response response = null;

            switch (code)
            {
                case 11:
                    response = serializer.Deserialize<SignupResponse>(reader);
                    break;
                case 21:
                    response = serializer.Deserialize<LoginResponse>(reader);
                    break;
                default:
                    break;
            }

            return response;
        }
        
    }
}