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
        public string roomName { set; get; }
        public int numberOfPlayers { set; get; }
        public int numberOfQuestions { set; get; }
        public int TimeForQuestion { set; get; }
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
            this.roomName = TBRoomName.Text;
            this.numberOfPlayers = int.Parse(TBPlayers.Text);
            this.numberOfQuestions = int.Parse(TBQuestions.Text);
            this.TimeForQuestion = int.Parse(TBTimePerQuestion.Text);

            CreateRoomResponse response = (CreateRoomResponse)Communicator.Communicate(
                new CreateRoomRequest(this.roomName, this.numberOfPlayers, this.numberOfQuestions, this.TimeForQuestion));

            if (response.status == 1)
            {
                //#TODO: move room creator to waiting room (to allow other players join)
                /*
                WaitingRoomWindow wind = new WaitingRoomWindow(params);
                wind.Show();
                this.Hide();
                this.Close();
                */
            }
        }
    }
}
