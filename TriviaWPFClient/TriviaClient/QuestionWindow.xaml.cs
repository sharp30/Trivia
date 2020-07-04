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
            Button[] buttons = { Btn_Ans1, Btn_Ans2, Btn_Ans3, Btn_Ans4 };
            this.username = uName;
            this.roomname = rName;

            InitializeComponent();

            TBUsername.Text += uName;
            TBRoomName.Text += rName;

            GetQuestionResponse response = (GetQuestionResponse)Communicator.Communicate(new GetQuestionRequest());

            TBQuestion.Text = response.question;

            //Fill buttons' contents
            for (int i = 0; i < buttons.Length; i++)
            {
                buttons[i].Content = response.answers[i];
            }
        }

        private void Btn_Exit_Clicked(object sender, RoutedEventArgs e)
        {

        }

        private void Btn_Answer_Clicked(object sender, RoutedEventArgs e)
        {

        }
    }
}
