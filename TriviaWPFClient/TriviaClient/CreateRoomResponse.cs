using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TriviaClient
{
    class CreateRoomResponse : Response
    {
        public const int MESSAGE_CODE = 41;
        public int status { get; set; }
        public CreateRoomResponse() : base(MESSAGE_CODE) { }
    }
}
