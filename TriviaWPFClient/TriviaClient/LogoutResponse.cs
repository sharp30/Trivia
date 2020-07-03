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
        LogoutResponse() : base(101)
        {

        }
        public int status { get; set; }

    }
}
