using System;
using System.CodeDom;
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
        public Dictionary<string,string> availiableRoom { set; get; }
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
            availiableRoom = new Dictionary<string, string>();
            if(response.status == 1)
            {
                if (!response.rooms.Equals(""))
                {
                    string[] rooms = response.rooms.Split(',');
                    for (int i = 0; i < rooms.Length; i++)
                    {
                        string[] parts = rooms[i].Split(':');
                        availiableRoom.Add(parts[0], parts[1]);
                    }
                }
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
            int count = 0;
            foreach (KeyValuePair<string, string> entry in availiableRoom)
            {
                //TODO: change content of button to the room's name
                btn = new Button { Name = "r" + entry.Key, Content = entry.Value, FontSize = 25, Margin = new Thickness(40, 25, 40, 25)};
                btn.Click += new RoutedEventHandler(RoomBtnClicked);
                Grid.SetRow(btn, count);
                mainPart.Children.Add(btn);
                count++;
            }
        }

        protected void RoomBtnClicked(object sender, RoutedEventArgs e)
        {
            uint id = uint.Parse(((Button)sender).Name.Substring(1));
            string roomName = (string)((Button)sender).Content;

            JoinRoomResponse response = (JoinRoomResponse)Communicator.Communicate(new JoinRoomRequest(id));

            GetRoomStateResponse res = (GetRoomStateResponse)Communicator.Communicate(new GetRoomStateRequest());

            Room room = new Room(roomName, (uint)res.players.Split(',').Length, res.questionCount, res.answerTimeOut);
            if (response.status == 1)
            {
                WaitingRoomWindow wind = new WaitingRoomWindow(false, this.username, res.players.Split(','), room);
                wind.Show();
                this.Hide();
                this.Close();           
            }
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            RefreshRoomsList();
        }

        private void BackBtn_Click(object sender, RoutedEventArgs e)
        {
            MenuWindow wind = new MenuWindow(this.username);
            wind.Show();
            this.Hide();
            this.Close();
        }
    }
}
