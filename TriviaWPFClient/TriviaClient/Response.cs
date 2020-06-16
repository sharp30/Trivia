using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TriviaClient
{
    public class  Request
    {
        protected int messageCode;

        public int GetMsgCode()
        {
            return this.messageCode;
        }

        virtual public string CastToJson()
        {
            return "";
        }
}
