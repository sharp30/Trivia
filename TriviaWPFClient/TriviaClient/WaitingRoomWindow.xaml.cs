using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using System.Threading;

namespace TriviaClient
{
    /// <summary>
    /// Interaction logic for WaitingRoomWindow.xaml
    /// </summary>
    public partial class WaitingRoomWindow : Window
    {
        public string username { set; get; }
        public Room room { set; get; }
        public string[] players { set; get; }

        public int lastPlayerIndex;
        public bool isAdmin { set; get; }

        protected Thread thread;
        public int state { set; get;}

        public WaitingRoomWindow(bool admin, string _username, Room _room)//when created
        {
            InitializeComponent();
            this.room = _room;
            this.username = _username;

            this.isAdmin = admin;
            this.players = new string[_room.numberOfPlayers];
            this.players[0] = _username;

            this.lastPlayerIndex = 1;
            this.state = 0;//Waiting

            if (admin)
                this.LeaveBTN.IsEnabled = false;           
            thread = new Thread(Threaded);
            thread.Start();
        }
        public WaitingRoomWindow(bool admin, string _username, string[] _players, Room _room)
        {
            InitializeComponent();
            this.room = _room;
            this.username = _username;

            this.isAdmin = admin;
            this.players = _players;
            this.lastPlayerIndex = 1;
            this.state = 0;//ACTIVE
            thread = new Thread(Threaded);
            thread.Start();
            if (!isAdmin)//disable buttons
            {
                this.StartBTN.IsEnabled = false;
                this.CloseBTN.IsEnabled = false;
            }

        }

        private void FillTBs()
        {
            this.Dispatcher.Invoke((Action)(() =>
            {
                usernameTB.Text = this.username;
                roomnameTB.Text = "You are connected to room " +  this.room.roomName;
                maxplayersTB.Text = "Players amount: " + this.room.numberOfPlayers.ToString();
                questAmountTB.Text = "Questions amount: " + this.room.numberOfQuestions.ToString();
                questTimeTB.Text = "time per question: " +  this.room.TimeForQuestion.ToString();
                UpdatePlayersListGrid();
            }));

        }

        /*
        The function will rapidly ask the server to send the players list so it will be updated // Might be a thread
        input: none
        output: none
        */
        private void RefreshPlayersList()
        {

            GetRoomStateResponse response = (GetRoomStateResponse)Communicator.Communicate(new GetRoomStateRequest());
            string[] newList = response.players.Split(',');
            this.state = response.state;
            if (!IsSamePlayers(newList))            {

                this.players = newList;
                this.room.numberOfPlayers = (uint)players.Length;
                FillTBs();
            }
        }

        /*
        The function will add the new players that has joined to the grid
        input: none
        output: none
        */
        private void UpdatePlayersListGrid()
        {
            TextBlock txt = null;
            mainPart.Children.Clear();
            for (int i = 0; i < this.players.Length ; i++)
            {
                txt = new TextBlock { Text = this.players[i], FontSize = 30, Margin = new Thickness(90, 35 * i, 120, 35 * (i + 1)) };
                Grid.SetRow(txt, i);
                mainPart.Children.Add(txt);
            }
        }

        private void CloseBTN_Click(object sender, RoutedEventArgs e)
        {
            CloseRoomResponse response = (CloseRoomResponse)Communicator.Communicate(new CloseRoomRequest());
            if(response.status == 1)
            {
                thread.Abort();
                MenuWindow wind = new MenuWindow(this.username);
                wind.Show();
                this.Hide();
                this.Close();
            }
        }


        private void StartBTN_Click(object sender, RoutedEventArgs e)
        {
            this.thread.Abort();//TODO:find place for it
            StartGameResponse response = (StartGameResponse)Communicator.Communicate(new StartGameRequest());
            QuestionWindow wind = new QuestionWindow(this.username, this.room.roomName, this.room.numberOfQuestions, 0, this.room.TimeForQuestion);
            wind.Show();
            this.Close();

        }
        
        public void Threaded()
        {
            FillTBs();
            while (this.state == 0)
            {
                Thread.Sleep(3000);
                RefreshPlayersList();
            }
            if (this.state == -1 && !isAdmin)
            {
                this.Dispatcher.Invoke((Action)(() =>
                {
                    LeaveBTN.RaiseEvent(new RoutedEventArgs(Button.ClickEvent));
                }));
            }
            else // if game had started
            {
                QuestionWindow wind = new QuestionWindow(this.username, this.room.roomName, this.room.numberOfQuestions, 0, this.room.TimeForQuestion);
                wind.Show();
                this.Close();
            }
        }
        public bool IsSamePlayers(string[] newList)
        {
            if (this.players.Length != newList.Length)
                return false;

            for (int i = 0; i < newList.Length; i++)
            {
                if (!this.players[i].Equals(newList[i]))
                    return false;
            }
            return true;
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {

        }

        private void LeaveBTN_Click(object sender, RoutedEventArgs e)
        {
            LeaveRoomResponse response = (LeaveRoomResponse)Communicator.Communicate(new LeaveRoomRequest());
            if(response.status == 1)
            {
                MenuWindow wind = new MenuWindow(this.username);
                wind.Show();
                this.Hide();
                this.Close();
            }
        }
    }
}
