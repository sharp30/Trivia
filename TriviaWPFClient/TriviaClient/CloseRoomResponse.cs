using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TriviaClient
{
    class CloseRoomResponse : Response
    {
        public const int MESSAGE_CODE = 53;

        public int status { set; get; }

        CloseRoomResponse() : base(MESSAGE_CODE) { }



    }
}
