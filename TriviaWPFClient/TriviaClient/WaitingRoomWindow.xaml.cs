using System;
using System.Collections.Generic;
using System.Linq;
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

        public WaitingRoomWindow(bool admin, string _username, Room _room)
        {
            InitializeComponent();
            this.room = _room;
            this.username = _username;

            this.isAdmin = admin;
            this.players = new string[this.room.numberOfPlayers];
            this.players[0] = this.username;
            this.lastPlayerIndex = 1;

            FillTBs();
        }

        private void FillTBs()
        {
            usernameTB.Text += this.username;
            roomnameTB.Text += this.room.roomName;
            maxplayersTB.Text += this.room.numberOfPlayers;
            questAmountTB.Text += this.room.numberOfQuestions;
            questTimeTB.Text += this.room.TimeForQuestion;
        }
    }
}
