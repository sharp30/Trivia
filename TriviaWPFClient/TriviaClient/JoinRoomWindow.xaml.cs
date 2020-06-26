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
    /// Interaction logic for JoinRoomWindow.xaml
    /// </summary>
    public partial class JoinRoomWindow : Window
    {
        public Room[] availiableRoom { set; get; }
        public string[] availiableRooms { set; get; }

        public JoinRoomWindow()
        {
            InitializeComponent();

            //add buttons of rooms
            //this.Hide();

            RefreshRoomsList();
        }

        /*
        The function will rapidly ask the server to send the rooms list so it will be updated // Might be a thread
        input: none
        output: none
        */
        private void RefreshRoomsList()
        {
            GetRoomsResponse response = (GetRoomsResponse)Communicator.Communicate(new GetRoomsRequest());
            if(response.status == 1)
            {
                this.availiableRooms = response.rooms.Split(',');
                UpdateRoomsListGrid();
            }
        
        }

        /*
        The function will add the new rooms that has joined to the grid
        input: none
        output: none
        */
        private void UpdateRoomsListGrid()
        {
            Button btn = null;

            for (int i = 0; i < this.availiableRooms.Length; i++)
            {
                btn = new Button { Content = this.availiableRooms[i], FontSize = 25, Margin = new Thickness(90, 20 * i, 120, 20 * (i + 1)) };
                Grid.SetRow(btn, i);
                mainPart.Children.Add(btn);
            }
        }
    }
}
