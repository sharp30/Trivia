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
        protected string username;
        protected string password;

        public LoginRequest(string _username, string _password)
        {
            this.username = _username;
            this.password = _password;
        }

        public string GetUsername()
        {
            return this.username;
        }

        public string GetPassword()
        {
            return this.password;
        }

        public override string CastToJson()
        {
            return JsonConvert.SerializeObject(this, Formatting.Indented);
        }
    }
}
