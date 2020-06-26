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
        public string rooms { set; get; }

        GetRoomsResponse() : base(MESSAGE_CODE)
        {

        }
            
    }
}
