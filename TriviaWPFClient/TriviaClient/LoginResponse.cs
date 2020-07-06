using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TriviaClient
{
    class LoginResponse : Response
    {
        public const int MESSAGE_CODE = 21;
        LoginResponse() : base(MESSAGE_CODE)
        {

        }
        public int status { get; set; }

    }
}
