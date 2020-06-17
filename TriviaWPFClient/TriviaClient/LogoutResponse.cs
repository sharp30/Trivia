using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TriviaClient
{
    class LogoutResponse : Response
    {
        public const int MESSAGE_CODE = 101;
        LogoutResponse() : base(MESSAGE_CODE)
        {

        }
        public int status { get; set; }

    }
}
