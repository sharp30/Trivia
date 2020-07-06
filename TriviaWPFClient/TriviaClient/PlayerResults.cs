using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TriviaClient
{
    class PlayerResults
    {
        protected string name;
        protected uint correctAnswers;
        protected uint incorrectAnswers;
        protected uint averageTime;

        public PlayerResults(string _name, uint _correct, uint _incorrect, uint avgTime)
        {
            this.name = _name;
            this.correctAnswers = _correct;
            this.incorrectAnswers = _incorrect;
            this.averageTime = avgTime;
        }

        public string GetName()
        {
            return this.name;
        }

        public uint GetCorrectAnswersAmount()
        {
            return this.correctAnswers;
        }

        public uint GetInorrectAnswersAmount()
        {
            return this.incorrectAnswers;
        }

        public uint getAvgTime()
        {
            return this.averageTime;
        }

        public PlayerResults(string data) // "[avi:1:2:3]"
        {
            string[] elements = data.Split(':');

            //Remove '[' and ']'
            elements[0] = elements[0].Substring(1);
            elements[elements.Length - 1] = elements[elements.Length - 1].Substring(0, elements[elements.Length - 1].Length - 1);

            this.name = elements[0];
            this.correctAnswers = uint.Parse(elements[1]);
            this.incorrectAnswers = uint.Parse(elements[2]);
            this.averageTime = uint.Parse(elements[3]);
        }

        public override string ToString()
        {
            return this.name + ": Correct->" + this.correctAnswers + ", incorrect->" + this.incorrectAnswers + ", avg->" + this.averageTime;
        }
    }
}
