using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TriviaClient
{
    class GetRoomStateResponse : Response
	{
		public const int MESSAGE_CODE = 49;
		public uint _status { set; get; }
		public bool hasGameBegun { set; get; }
		public string players { set; get; }
		public uint questionCount { set; get; }
		public uint answerTimeOut { set; get; }
		public int state { set; get; }

		public GetRoomStateResponse() : base(MESSAGE_CODE) { }
	}
}
