using EO.WebBrowser.DOM;
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
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class SignupWindow : Window
    {
         private string username;
         private string password;
         private string email;
            
        public SignupWindow()
        {
            InitializeComponent();

            
        }
        

        private void Btn_quit_Click(object sender, RoutedEventArgs e)
        {
            Application.Current.Shutdown();
        }

        private void TBUsername_TextChanged(object sender, TextChangedEventArgs e)
        {
        }

        private void TextBox_TextChanged(object sender, TextChangedEventArgs e)
        {

        }

        private void myButton_Click(object sender, RoutedEventArgs e)
        {

        }

        private void Btn_Signup_Click(object sender, RoutedEventArgs e)
        {
            this.username = TBUsername.Text;
            this.password = TBPassword.Password;
            this.email = TBEmail.Text;

            MenuWindow wind = new MenuWindow(username);
            wind.Show();
            this.Hide();
            this.Close();

            //signupRequest
            //move to menu
        }

        private void TBPassword_TextChanged(object sender, TextChangedEventArgs e)
        {

        }
    }
}
