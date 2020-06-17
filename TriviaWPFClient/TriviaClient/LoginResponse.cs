using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TriviaClient
{
    class LoginResponse : Response
    {
        LoginResponse() : base(21)
        {

        }
        public int status { get; set; }

    }
}
