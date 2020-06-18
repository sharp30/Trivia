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
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace TriviaClient
{
    public partial class MyStatsWindow : Window
    {
         private string _username;
            
        public MyStatsWindow(string username)
        {
            this._username = username;
            InitializeComponent();
            usernameTB.Text += this._username;

            SetStatistics();
        }
        

        private void BtnBackClick(object sender, RoutedEventArgs e)
        {
            MenuWindow wind = new MenuWindow(_username);
            wind.Show();
            this.Hide();
            this.Close();
        }

        /*
        The function will get the statistics from the server and set it into the text boxes
        input: none
        output: none
         */
        private void SetStatistics()
        {
            GetStatisticsResponse response = (GetStatisticsResponse)Communicator.Communicate(new GetStatisticsRequest());
            if (response.status != 1) // invalid response will take the user back to menu
            {
                MenuWindow wind = new MenuWindow(_username);
                wind.Show();
                this.Hide();
                this.Close();
            }
            else
            {
                gamesNumTB.Text += response.gamesAmount;
                CorrectAnsTB.Text += response.correctAnswers;
                incorrectAnsTB.Text += response.incorrectAnswers;
                avgTimeTB.Text += response.avgTimePerAns;
            }
        }
    }
}
