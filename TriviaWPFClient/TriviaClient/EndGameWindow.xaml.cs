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

        private PlayerResults[] results;
        public EndGameWindow(string uName)
        {
            this.username = uName;

            InitializeComponent();

            GetGameResultResponse response = (GetGameResultResponse)Communicator.Communicate(new GetGameResultRequest());

            this.results = response.GetResults();

            FillScoreboard();
        }

        private void FillScoreboard()
        {
            //add textBoxes
            TextBlock txt = null;
            int count = 1;
            
            //-----print winner------
            txt = new TextBlock { Text = "The winner is " + FindWinner() + "!", FontSize = 40, Margin = new Thickness(90, 35 * count, 120, 35 * (count + 1)), Foreground = Brushes.White };

            Grid.SetRow(txt, count);
            mainPart.Children.Add(txt);
            count++;
            //-----------------------

            foreach (PlayerResults res in this.results)
            {
                txt = new TextBlock { Text = res.ToString(), FontSize = 40, Margin = new Thickness(90, 35 * count, 120, 35 * (count + 1)), Foreground = Brushes.White };

                Grid.SetRow(txt, count);
                mainPart.Children.Add(txt);
                count++;
            }
        }

        private void Btn_back_Click(object sender, RoutedEventArgs e)
        {
            MenuWindow wind = new MenuWindow(this.username);
            wind.Show();
            this.Hide();
            this.Close();
        }

        /*
        The function will find the name of the player who has won the game
        input: none
        output: the name of the player who has won the game --> string
        */
        private string FindWinner()
        {
            //#TODO: if everything works fine, consider changing this algorithm.
            uint maxPoints = 0;
            foreach (PlayerResults res in this.results)
            {
                maxPoints = res.GetCorrectAnswersAmount() > maxPoints ? res.GetCorrectAnswersAmount() : maxPoints; 
            }

            foreach (PlayerResults res in this.results)
            {
                if (res.GetCorrectAnswersAmount() == maxPoints) return res.GetName();
            }
            return "no one";
        }
    }
}
