using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TriviaClient
{
    public class Response
    {
        protected int messageCode;

        public int GetMsgCode()
        {
            return this.messageCode;
        }


    }
}
