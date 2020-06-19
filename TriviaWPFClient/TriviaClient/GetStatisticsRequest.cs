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
    class GetStatisticsRequest : Request
    {
        //public const int MESSAGE_CODE = 70;
        public GetStatisticsRequest() : base (70)
        {

        }
        public override byte[] CastToBson()
        {
            return null;
        }
    }
}
