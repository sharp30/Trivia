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
        private uint numOfQuestions;
        private uint currentQuestionNum;

        private Button[] buttons;
        private Dictionary<string, uint> answers;

        public QuestionWindow(string uName, string rName, uint questionsAmount, uint currQuestionNum)
        {
            if(questionsAmount == currentQuestionNum)
            {
                //EndGameWindow wind = new EndGameWindow(this.username, this.roomname);
                //wind.Show();
                this.Hide();
                this.Close();
            }

            this.buttons = new Button[4];
            this.buttons[0] = Btn_Ans1;
            this.buttons[1] = Btn_Ans2;
            this.buttons[2] = Btn_Ans3;
            this.buttons[3] = Btn_Ans4;

            this.username = uName;
            this.roomname = rName;
            this.numOfQuestions = questionsAmount;
            this.currentQuestionNum = currQuestionNum;

            InitializeComponent();

            TBUsername.Text += uName;
            TBRoomName.Text += rName;

            GetQuestionResponse response = (GetQuestionResponse)Communicator.Communicate(new GetQuestionRequest());

            TBQuestion.Text = response.question;

            FillAnswers(response.answers);
            FillButtons();
        }

        private void Btn_Exit_Clicked(object sender, RoutedEventArgs e)
        {
            LeaveGameResponse response = (LeaveGameResponse)Communicator.Communicate(new LeaveGameRequest());

            if (response.status == 1)
            {
                MenuWindow wind = new MenuWindow(this.username);
                wind.Show();
                this.Hide();
                this.Close();
            }
        }

        private void Btn_Answer_Clicked(object sender, RoutedEventArgs e)
        {
            uint chosenAnsId = 5;

            foreach (var ans in this.answers)
            {
                if (((Button)sender).Content.Equals(ans.Key))
                    chosenAnsId = ans.Value;
            }

            SubmitAnswerResponse response = (SubmitAnswerResponse)Communicator.Communicate(new SubmitAnswerRequest(chosenAnsId));
            
            if (response.correctAnswerId == chosenAnsId)
            {
                ((Button)sender).Background = Brushes.Green; 
            }
            else
            {
                ((Button)sender).Background = Brushes.Red;
            }
            
            //TODO: Wait until all players are ready for the next question

            if (response.status == 1)
            {
                QuestionWindow wind = new QuestionWindow(this.username, this.roomname, this.numOfQuestions, this.currentQuestionNum + 1);
                wind.Show();
                this.Hide();
                this.Close();
            }
        }


        private void FillButtons()
        {
            Random rnd = new Random();

            foreach(var ans in this.answers)
            {
                int i = rnd.Next(0, 4);
                
                while (!this.buttons[i].Content.Equals(""))
                    i = (i + 1) % 4;

                this.buttons[i].Content = ans.Key;
            }
        }

        private void FillAnswers(string[] _answers)
        {
            for (uint i = 0; i < _answers.Length; i++)
            {
                this.answers.Add(_answers[i], i);
            }
        }
    }
}
