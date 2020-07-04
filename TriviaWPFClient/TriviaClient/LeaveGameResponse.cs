using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TriviaClient
{
    class LeaveGameResponse : Response
    {
        public const int MESSAGE_CODE = 87;
        LeaveGameResponse() : base(MESSAGE_CODE){}
        public int status { get; set; }
    }
}
