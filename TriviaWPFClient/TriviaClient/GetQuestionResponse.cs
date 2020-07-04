using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TriviaClient
{
    class GetQuestionResponse : Response
    {
        public const int MESSAGE_CODE = 81;
        public int status { get; set; }
        public string question { get; set; }
        public string[] answers { get; set; }
        GetQuestionResponse() : base(MESSAGE_CODE){}
        
    }
}
