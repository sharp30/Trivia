using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
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
    public partial class MainWindow : Window
    {
        private string username;
        private string password;

        public MainWindow()
        {
            InitializeComponent();
            this.Hide();
            bool isConnected = Communicator.Connect("127.0.0.1", 2019);
            while (!isConnected)
            {
                MessageBoxResult res = MessageBox.Show("Sorry man can't connect to server", "ERROR MESSAGE", MessageBoxButton.OKCancel, MessageBoxImage.Exclamation);
                if (res == MessageBoxResult.Cancel)
                {
                    btn_quit.RaiseEvent(new RoutedEventArgs(ButtonBase.ClickEvent));
                    return;
                }
                isConnected = Communicator.Connect("127.0.0.1", 2019);
            }
            this.Show();
            
        }
        
        private void Btn_signin(object sender, RoutedEventArgs e)
        {
            this.username = TBUsername.Text;
            this.password = TBPassword.Password;


            LoginResponse req = (LoginResponse)Communicator.Communicate(new LoginRequest(username, password));
            if (req.status == 1)
            {
                MenuWindow wind = new MenuWindow(username);
                wind.Show();
                this.Hide();
                this.Close();
            }

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

        private void btn_signup_Click(object sender, RoutedEventArgs e)
        {
            SignupWindow wind = new SignupWindow();
            wind.Show();
            this.Hide();
            this.Close();

        }

        private void TBPassword_TextChanged(object sender, TextChangedEventArgs e)
        {

        }


    }
}
