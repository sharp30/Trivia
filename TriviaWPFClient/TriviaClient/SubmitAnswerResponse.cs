using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TriviaClient
{
    class SubmitAnswerResponse : Response
    {
        public const int MESSAGE_CODE = 83;
        public int status { get; set; }
        public string correctAnswerId { get; set; }
        public SubmitAnswerResponse() : base(MESSAGE_CODE) { }

    }
}
