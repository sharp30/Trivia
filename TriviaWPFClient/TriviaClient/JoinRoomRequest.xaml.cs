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
    /// Interaction logic for JoinRoomRequest.xaml
    /// </summary>
    public partial class JoinRoomRequest : Window
    {
        public JoinRoomRequest()
        {
            InitializeComponent();

            //add textBoxes
            this.Hide();
            Button btn = new Button { Content = "Room ", FontSize = 15, Name = "Room0" };
            for (int i = 0; i < 5; i++)
            {
                btn = new Button { Content = "Room " + i.ToString() + "                    " + (i * 50).ToString(), FontSize = 40, Margin = new Thickness(90, 35 * i, 120, 35 * (i + 1)), Name = "room" + (i+1).ToString() };
                Grid.SetRow(btn, i);
                mainPart.Children.Add(btn);
            }
        }
    }
}
