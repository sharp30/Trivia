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
    class JoinRoomRequest :Request
    {
        public uint roomId { set; get; }
       
        public JoinRoomRequest(uint _roomId) : base(44)
        {
            this.roomId = _roomId;
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
