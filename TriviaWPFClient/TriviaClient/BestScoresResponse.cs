using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace TriviaClient
{
    class BestScoresResponse : Response
    {
        public const int MESSAGE_CODE = 81;
        public BestScoresResponse() : base(MESSAGE_CODE)
        {
            status = 1;
        }
        public string[] UserStatistics { get; set; }
        public int status { get; set; }

    }

}
