using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TriviaClient
{
    class JoinRoomResponse : Response
    {
      
        
        public const int MESSAGE_CODE = 45;
        
        public int status { set; get; }
        public string Rooms { set; get; }

        
        
        public JoinRoomResponse() : base(MESSAGE_CODE)
        {

        }
        
    }
}
