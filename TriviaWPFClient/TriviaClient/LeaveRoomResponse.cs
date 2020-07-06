namespace TriviaClient
{
    class LeaveRoomResponse : Response
    {
        public const int MESSAGE_CODE = 55;
        public int status { set; get; }
        public LeaveRoomResponse() : base(MESSAGE_CODE) { }
    }
}