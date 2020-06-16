using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Newtonsoft.Json;

namespace TriviaClient
{
    class SignupRequest
    {
        protected string _username;
        protected string _password;
        protected string _email;

        public SignupRequest(string username, string password, string email)
        {
            this._username = username;
            this._password = password;
            this._email = email;
        }

        public string GetUsername()
        {
            return this._username;
        }

        public string GetPassword()
        {
            return this._password;
        }

        public string GetEmail()
        {
            return this._email;
        }

        public string CastToJson()
        {
            return JsonConvert.SerializeObject(this, Formatting.Indented);
        }
    }
}
