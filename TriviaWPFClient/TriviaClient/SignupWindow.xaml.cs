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
         private string _username;
         private string _password;
         private string _email;
            
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
            this._username = TBUsername.Text;
            this._password = TBPassword.Password;
            this._email = TBEmail.Text;

            SignupResponse response = (SignupResponse)Communicator.Communicate(new SignupRequest(this._username, this._password, this._email));
            if (response.status == 1)
            {
                MenuWindow wind = new MenuWindow(this._username);
                wind.Show();
                this.Hide();
                this.Close();
            }
        }

        private void TBPassword_TextChanged(object sender, TextChangedEventArgs e)
        {

        }
    }
}
