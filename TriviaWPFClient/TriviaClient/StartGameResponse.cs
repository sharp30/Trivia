namespace TriviaClient
{
    class StartGameResponse : Response
    {
        public const int MESSAGE_CODE = 51;
        public int status { get; set; }
        public StartGameResponse() : base(MESSAGE_CODE)
        {

        }
    }
}