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

            UpdatePlayersListGrid();
        }

        /*
        The function will rapidly ask the server to send the players list so it will be updated // Might be a thread
        input: none
        output: none
        */
        private void RefreshPlayersList()
        {
            //#TODO: get players list from server, if a change was detected, change the attribute array of players and call the UpdatePlayersListGrid function
        }

        /*
        The function will add the new players that has joined to the grid
        input: none
        output: none
        */
        private void UpdatePlayersListGrid()
        {
            TextBlock txt = null;

            for (int i = 0; i < this.players.Length ; i++)
            {
                txt = new TextBlock { Text = this.players[i], FontSize = 30, Margin = new Thickness(90, 35 * i, 120, 35 * (i + 1)) };
                Grid.SetRow(txt, i);
                mainPart.Children.Add(txt);
            }
        }
    }
}
