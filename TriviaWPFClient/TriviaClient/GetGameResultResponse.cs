using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TriviaClient
{
    class GetGameResultResponse : Response
    {
        public const int MESSAGE_CODE = 85;
        GetGameResultResponse() : base(MESSAGE_CODE) { }
        public int status { get; set; }
        public string results { get; set; }

        public PlayerResults[] GetResults()
        {
            string[] players = results.Split(','); // ["[dani:5:6:7]", "[avi:1:2:3]", "[moshe:1:3:2]"]
            PlayerResults[] res = new PlayerResults[players.Length];

            for (int i = 0; i < players.Length; i++)
            {
                res[i] = new PlayerResults(players[i]);
            }

            return res;
        }
    }
}
