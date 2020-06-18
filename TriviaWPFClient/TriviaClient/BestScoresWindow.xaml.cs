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

            BestScoresResponse = (BestScoresResponse)Communicator.Communicate(new BestScoresRequest());

            //add textBoxes
            this.Hide();
            TextBlock txt = new TextBlock { Text = "Galant", FontSize = 15 };
            for (int i = 0; i < 5; i++)
            {
                txt = new TextBlock { Text = "Galant"+i.ToString()+"                    " + (i*50).ToString(), FontSize = 40, Margin = new Thickness(90,35*i,120,35*(i+1)) };
                Grid.SetRow(txt, i);
                mainPart.Children.Add(txt);
            }
            
                
        }

        private void TextBox_TextChanged(object sender, TextChangedEventArgs e)
        {

        }
    }
}
