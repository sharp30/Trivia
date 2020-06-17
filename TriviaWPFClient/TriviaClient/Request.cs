using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TriviaClient
{
    public class Request
    {
        protected int _messageCode;

        public Request(int code)
        {
            this._messageCode = code;
        }
        public int GetMsgCode()
        {
            return this._messageCode;
        }

        virtual public byte[] CastToJson()
        {
            return null;
        }
    }
}
