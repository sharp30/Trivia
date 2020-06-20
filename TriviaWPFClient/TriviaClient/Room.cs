using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TriviaClient
{
    public class Room
    {
        public string roomName { set; get; }
        public uint numberOfPlayers { set; get; }
        public uint numberOfQuestions { set; get; }
        public uint TimeForQuestion { set; get; }

        public Room(string name, uint playersNum, uint questionsNum, uint timePerQuestion)
        {
            this.roomName = name;
            this.numberOfPlayers = playersNum;
            this.numberOfQuestions = questionsNum;
            this.TimeForQuestion = timePerQuestion;
        }
    }
}
