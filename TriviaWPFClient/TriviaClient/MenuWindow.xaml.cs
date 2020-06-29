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
    /// Interaction logic for MenuWindow.xaml
    /// </summary>
    public partial class MenuWindow : Window
    {
        private string username;
        public MenuWindow(string user)
        {
            username = user;
            InitializeComponent();
            TBHello.Text += username;
        }

        private void TextBox_TextChanged(object sender, TextChangedEventArgs e)
        {

        }

        private void TBHello_TextChanged(object sender, TextChangedEventArgs e)
        {

        }

        private void Btn_CreateRoom_Click(object sender, RoutedEventArgs e)
        {
            CreateRoomWindow wind = new CreateRoomWindow(this.username);
            wind.Show();
            this.Hide();
            this.Close();
        }

        private void Btn_joinRoom_Click(object sender, RoutedEventArgs e)
        {
            JoinRoomWindow wind = new JoinRoomWindow(this.username) ; //new JoinRoomWindow
            wind.Show();
            this.Hide();
        }

        private void Btn_MyStatus_Click(object sender, RoutedEventArgs e)
        {
            MyStatsWindow wind = new MyStatsWindow(this.username);
            if (wind.IsFailed())
                return;
            wind.Show();
            this.Hide();
            this.Close();
        }
            
        private void Btn_Quit_Click(object sender, RoutedEventArgs e)
        {
            Application.Current.Shutdown();
        }

        private void Btn_Logout_Click(object sender, RoutedEventArgs e)
        {
            LogoutResponse response = (LogoutResponse)Communicator.Communicate(new LogoutRequest());
            if (response.status == 1)
            {
                MainWindow wind = new MainWindow();
                wind.Show();
                this.Hide();
                this.Close();
            }
        }

        private void Btn_BestScores_Click(object sender, RoutedEventArgs e)
        {

            BestScoresWindow wind = new BestScoresWindow();
            wind.Show();
            //this.Hide();
            //this.Close();
        }

    }
}
