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
        public string username { get; set; }
        public string password { get; set; }

        public LoginRequest(string _username, string _password):base(20)
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
            return JsonConvert.SerializeObject(this, Formatting.None);
        }
    }
}
