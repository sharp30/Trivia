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
        public uint _maxPlayers { get; set; }
        public uint _numOfQuestions { get; set; }
        public uint _timePerQuestion { get; set; }

        public CreateRoomRequest(string name, uint players, uint questions, uint timeForQuestion) : base(40) 
        {
            this._roomName = name;
            this._maxPlayers = players;
            this._numOfQuestions = questions;
            this._timePerQuestion = timeForQuestion;
        }
    }
}
