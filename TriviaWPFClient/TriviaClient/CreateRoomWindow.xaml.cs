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
    /// Interaction logic for CreateRoomWindow.xaml
    /// </summary>
    public partial class CreateRoomWindow : Window
    {
        public string username { set; get; }
        public Room room { set; get; }

        public CreateRoomWindow(string userName)
        {
            this.username = userName;
            InitializeComponent();

            usernameTB.Text += this.username;
        }

        private void BtnBackClick(object sender, RoutedEventArgs e)
        {
            MenuWindow wind = new MenuWindow(this.username);
            wind.Show();
            this.Hide();
            this.Close();
        }


        private void BtnCreateClick(object sender, RoutedEventArgs e)
        {
            this.room = new Room(TBRoomName.Text, uint.Parse(TBPlayers.Text), uint.Parse(TBQuestions.Text), uint.Parse(TBTimePerQuestion.Text));

            CreateRoomResponse response = (CreateRoomResponse)Communicator.Communicate(
                new CreateRoomRequest(this.room.roomName, this.room.numberOfPlayers, this.room.numberOfQuestions, this.room.TimeForQuestion));

            if (response.status == 1)
            {
                WaitingRoomWindow wind = new WaitingRoomWindow(true, this.username, this.room);
                wind.Show();
                this.Hide();
                this.Close();
            }
        }
    }
}
