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
    class CreateRoomRequest : Request
    {
        //public const int MESSAGE_CODE = 40;
        public string roomName { get; set; }
        public uint maxUsers { get; set; }
        public uint questionCount { get; set; }
        public uint answerTimeOut { get; set; }

        public CreateRoomRequest(string name, uint players, uint questions, uint timeForQuestion) : base(40) 
        {
            this.roomName = name;
            this.maxUsers = players;
            this.questionCount = questions;
            this.answerTimeOut = timeForQuestion;
        }
        public override byte[] CastToBson()
        {
            MemoryStream ms = new MemoryStream();
            using (BsonWriter writer = new BsonWriter(ms))
            {
                JsonSerializer serializer = new JsonSerializer();
                serializer.Serialize(writer, this);
            }
            return ms.ToArray();
        }
    }
}
