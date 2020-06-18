using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TriviaClient
{
    class GetStatisticsResponse : Response
    {
        //#TODO (Omri): check how the ResponseDecoder builds this object, the stats attributes might be replaced with a string contains the data as an attribute.
        public const int MESSAGE_CODE = 71;
        public int status { get; set; }
        public int gamesAmount { get; set; }
        public int correctAnswers { get; set; }
        public int incorrectAnswers { get; set; }
        public double avgTimePerAns { get; set; }
        public GetStatisticsResponse() : base(MESSAGE_CODE){}
    }
}
