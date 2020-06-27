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
        public string username { set; get; }
        public Room[] availiableRoom { set; get; }
        public string[] availiableRooms { set; get; }

        public JoinRoomWindow(string uName)
        {
            InitializeComponent();
            this.username = uName;

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
            
            //clear previous values in Grid
            mainPart.Children.Clear();

            for (int i = 0; i < this.availiableRooms.Length; i++)
            {
                //TODO: change content of button to the room's name
                btn = new Button { Name = this.availiableRooms[i], Content = "room" + i.ToString(), FontSize = 25, Margin = new Thickness(40, 25, 40, 25)};
                btn.Click += new RoutedEventHandler(RoomBtnClicked);
                Grid.SetRow(btn, i);
                mainPart.Children.Add(btn);
            }
        }

        protected void RoomBtnClicked(object sender, RoutedEventArgs e)
        {
            string id = ((Button)sender).Name;

            JoinRoomResponse response = (JoinRoomResponse)Communicator.Communicate(new JoinRoomRequest(uint.Parse(id)));

            /*
            TODO in future
            SomeDataType = GetRoomData();
            Room room = new Room(someDatatype.something)
            */
            if (response.status == 1)
            {
                /*
                WaitingRoomWindow wind = new WaitingRoomWindow(false, this.username, this.room);
                wind.Show();
                this.Hide();
                this.Close();
                */            
            }
        }
    }
}
