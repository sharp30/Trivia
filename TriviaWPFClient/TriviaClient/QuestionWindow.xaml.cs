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
    /// Interaction logic for QuestionWindow.xaml
    /// </summary>
    public partial class QuestionWindow : Window
    {
        private string username;
        private string roomname;
        public QuestionWindow(string uName, string rName)
        {
            this.username = uName;
            this.roomname = rName;

            InitializeComponent();

            TBUsername.Text += uName;
            TBRoomName.Text += rName;
        }

        private void Btn_Exit_Clicked(object sender, RoutedEventArgs e)
        {

        }

        private void Btn_Answer_Clicked(object sender, RoutedEventArgs e)
        {

        }
    }
}
