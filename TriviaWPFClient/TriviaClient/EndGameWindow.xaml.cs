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
    /// Interaction logic for EndGameWindow.xaml
    /// </summary>
    public partial class EndGameWindow : Window
    {
        private string username;
        private string roomname;
        private PlayerResults[] results;
        public EndGameWindow(string uName, string rName)
        {
            this.username = uName;
            this.roomname = rName;

            InitializeComponent();

            GetGameResultResponse response = (GetGameResultResponse)Communicator.Communicate(new GetGameResultRequest());

            this.results = response.GetResults();

            FillScoreboard();
        }

        private void FillScoreboard()
        {

        }

        private void Btn_back_Click(object sender, RoutedEventArgs e)
        {
            MenuWindow wind = new MenuWindow(this.username);
            wind.Show();
            this.Hide();
            this.Close();
        }
    }
}
