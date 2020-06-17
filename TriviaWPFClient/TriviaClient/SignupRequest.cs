using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Newtonsoft.Json;
using Newtonsoft.Json.Bson;

namespace TriviaClient
{
    class SignupRequest : Request
    {
        public string username { get; set; }
        public string password { get; set; }
        public string email { get; set; }

        public SignupRequest(string _username, string _password, string _email) : base(10)
        {
            this.username = _username;
            this.password = _password;
            this.email = _email;
        }

        public override byte[] CastToJson()
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
