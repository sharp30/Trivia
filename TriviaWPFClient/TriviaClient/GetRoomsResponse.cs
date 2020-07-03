using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TriviaClient
{
    class GetRoomsResponse : Response
    {
        public const int MESSAGE_CODE = 43;
    
        public int status { set; get; }
        public string rooms { set; get; } //"id1:roomName1,id2:roomName2"

        GetRoomsResponse() : base(MESSAGE_CODE)
        {

        }
            
    }
}
