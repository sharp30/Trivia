namespace TriviaClient
{
    class GetStatisticsResponse : Response
    {
        //#TODO (Omri): check how the ResponseDecoder builds this object, the stats attributes might be replaced with a string contains the data as an attribute.
        public const int MESSAGE_CODE = 71;
        public int status { get; set; }
        public int gamesAmount { get; set; }
        public int correctAnswers { get; set; }
        public int incorrectAnswers { get; set; }
        public double averageAnswerTime { get; set; }
        public GetStatisticsResponse() : base(MESSAGE_CODE) { }
    }
}
