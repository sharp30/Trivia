using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Newtonsoft.Json;

namespace TriviaClient
{
    class SignupRequest : Request
    {
        public string _username { get; set; }
        public string _password { get; set; }
        public string _email { get; set; }

        public SignupRequest(string username, string password, string email) : base(10)
        {
            this._username = username;
            this._password = password;
            this._email = email;
        }

        public override string CastToJson()
        {
            return JsonConvert.SerializeObject(this, Formatting.None);
        }
    }
}
