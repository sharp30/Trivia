using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TriviaClient
{
    class CreateRoomRequest : Request
    {
        //public const int MESSAGE_CODE = 40;
        public string _roomName { get; set; }
        public int _numOfPlayers { get; set; }
        public int _numOfQuestions { get; set; }
        public int _timePerQuestion { get; set; }

        public CreateRoomRequest(string name, int players, int questions, int timeForQuestion) : base(40) 
        {
            this._roomName = name;
            this._numOfPlayers = players;
            this._numOfQuestions = questions;
            this._timePerQuestion = timeForQuestion;
        }
    }
}
