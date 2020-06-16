using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Newtonsoft.Json;

namespace TriviaClient
{
    public class LoginRequest
    {
        protected string username;
        protected string password;

        public LoginRequest(string _username, string _password)
        {

        }

        public string GetUsername()
        {
            return this.username;
        }

        public string GetPassword()
        {
            return this.password;
        }

        public string CastToJson()
        {
            return JsonConvert.SerializeObject(this, Formatting.Indented);
        }
    }
}
