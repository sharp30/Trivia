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
            if (IsNumericValue(TBPlayers.Text) && IsNumericValue(TBQuestions.Text) && IsNumericValue(TBTimePerQuestion.Text))
            {
                this.room = new Room(TBRoomName.Text, uint.Parse(TBPlayers.Text), uint.Parse(TBQuestions.Text), uint.Parse(TBTimePerQuestion.Text));

                CreateRoomResponse response = (CreateRoomResponse)Communicator.Communicate(
                    new CreateRoomRequest(this.room.roomName, this.room.numberOfPlayers, this.room.numberOfQuestions, this.room.TimeForQuestion));

                if (response.status == 1)
                {
                    WaitingRoomWindow wind = new WaitingRoomWindow(true, this.username, this.room);
                    wind.Show();
                    base.Hide();
                    base.Close();
                }
            }
            else
            {
                TBInvalid.Text = "One or more arguments are invalid";
            }
        }

        private bool IsNumericValue(string val)
        {
            foreach (char ch in val)
            {
                if (ch < '0' || ch > '9') return false;
            }
            return true;
        }

    }
}
