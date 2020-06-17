using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TriviaClient
{
    class SignupResponse : Response
    {
        public const int MESSAGE_CODE = 11;
        public int status { get; set; }

        SignupResponse() : base(MESSAGE_CODE)
        {

        }
    }
}
