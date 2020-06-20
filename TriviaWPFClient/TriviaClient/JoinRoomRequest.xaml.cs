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
    /// Interaction logic for JoinRoomRequest.xaml
    /// </summary>
    public partial class JoinRoomRequest : Window
    {
        public Room[] availiableRooms { set; get; }

        public JoinRoomRequest()
        {
            InitializeComponent();

            //add buttons of rooms
            this.Hide();

            UpdateRoomsListGrid();
        }

        /*
        The function will rapidly ask the server to send the rooms list so it will be updated // Might be a thread
        input: none
        output: none
        */
        private void RefreshRoomsList()
        {
            //#TODO: get players list from server, if a change was detected, change the attribute array of players and call the UpdatePlayersListGrid function
        }

        /*
        The function will add the new players that has joined to the grid
        input: none
        output: none
        */
        private void UpdateRoomsListGrid()
        {
            Button btn = null;

            for (int i = 0; i < this.availiableRooms.Length; i++)
            {
                btn = new Button { Content = this.availiableRooms[i].roomName, FontSize = 25, Margin = new Thickness(90, 35 * i, 120, 35 * (i + 1)) };
                Grid.SetRow(btn, i);
                mainPart.Children.Add(btn);
            }
        }
    }
}
