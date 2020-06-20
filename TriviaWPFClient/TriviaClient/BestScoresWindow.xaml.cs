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
    /// Interaction logic for BestScoresWindow.xaml
    /// </summary>
    public partial class BestScoresWindow : Window
    {
        public BestScoresWindow()
        {
            InitializeComponent();

            BestScoresResponse response = (BestScoresResponse)Communicator.Communicate(new BestScoresRequest());
            string data = response.UserStatistics;
            string[] dous = data.Split(',');

            //add textBoxes
            this.Hide();
            TextBlock txt = null;
            int count = 0;
            foreach (string s in dous)
            {
                string[] parts = s.Split(':');

                txt = new TextBlock { Text =count.ToString() + ". "  + parts[0] + "                    " + parts[1], FontSize = 40, Margin = new Thickness(90,35*count,120,35*(count+1)) };

                Grid.SetRow(txt, count);
                mainPart.Children.Add(txt);
                count++;
            }
            
                
        }

        private void TextBox_TextChanged(object sender, TextChangedEventArgs e)
        {

        }

        private void Btn_back_Click(object sender, RoutedEventArgs e)
        {
           //MenuWindow wind = new MenuWindow(t);
           //// wind.Show();
            //this.Hide();
            ///this.Close();
        }
    }
}
