﻿using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Newtonsoft.Json;
using Newtonsoft.Json.Bson;

namespace TriviaClient
{
    class GetQuestionRequest : Request
    {
        public const int MESSAGE_CODE = 80;
        public GetQuestionRequest() : base(MESSAGE_CODE){}
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