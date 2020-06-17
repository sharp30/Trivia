using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.Json;
using System.Threading.Tasks;
using JsonSerializer = Newtonsoft.Json.JsonSerializer;

namespace TriviaClient
{
    public static class ResponseDecoder
    {

        public static Response Decode(int code, byte[] arr)
        {
            string str = Encoding.UTF8.GetString(arr);
            Response response = null;

            switch (code)
            {
                case 11:

                    break;
                case 21:
                    response = JsonConvert.DeserializeObject<LoginResponse>(str);
                    break;
            }


            
        }
        
    }
}