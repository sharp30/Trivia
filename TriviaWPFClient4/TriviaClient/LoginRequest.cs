using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Newtonsoft.Json;

namespace TriviaClient
{
    public class LoginRequest : Request
    {
        protected string _username;
        protected string _password;

        public LoginRequest(string username, string password):base(20)
        {
            this._username = username;
            this._password = password;
        }

        public string GetUsername()
        {
            return this._username;
        }

        public string GetPassword()
        {
            return this._password;
        }

        public override string CastToJson()
        {
            return JsonConvert.SerializeObject(this, Formatting.Indented);
        }
    }
}
