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
                case SignupResponse.MESSAGE_CODE:
                    response = serializer.Deserialize<SignupResponse>(reader);
                    break;
                case LoginResponse.MESSAGE_CODE:
                    response = serializer.Deserialize<LoginResponse>(reader);
                    break;
                case GetStatisticsResponse.MESSAGE_CODE:
                    response = serializer.Deserialize<GetStatisticsResponse>(reader);
                    break;
                case BestScoresResponse.MESSAGE_CODE:
                    response = serializer.Deserialize<BestScoresResponse>(reader);
                    break;
                case LogoutResponse.MESSAGE_CODE:
                    response = serializer.Deserialize<LogoutResponse>(reader);
                    break;
                case CreateRoomResponse.MESSAGE_CODE:
                    response = serializer.Deserialize<CreateRoomResponse>(reader);
                    break;
                case GetRoomsResponse.MESSAGE_CODE:
                    response = serializer.Deserialize<GetRoomsResponse>(reader);
                    break;
                default:
                    break;
            }

            return response;
        }
    }
}