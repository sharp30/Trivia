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
            bool isConnected = Communicator.Connect("127.0.0.1", 2020);
            if (!isConnected)
            {
                MessageBoxResult res = MessageBox.Show("Sorry man can't connect to server", "ERROR MESSAGE", MessageBoxButton.OKCancel, MessageBoxImage.Exclamation);
                btn_quit.RaiseEvent(new RoutedEventArgs(ButtonBase.ClickEvent));
            }
            this.Show();
            
        }
        
        private void Btn_signin(object sender, RoutedEventArgs e)
        {
            this.username = TBUsername.Text;
            this.password = TBPassword.Password;

            TBUsername.Text = "yay";
            TBPassword.Password = "yay";
            MenuWindow wind = new MenuWindow(username);
            wind.Show();
            this.Hide();
            this.Close();


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

        private void Btn_BestScores_Click(object sender, RoutedEventArgs e)
        {

        }

        private void btn_signup_Click(object sender, RoutedEventArgs e)
        {
            SignupWindow wind = new SignupWindow();
            wind.Show();
            this.Hide();
            this.Close();

            //NavigationService nav = NavigationService.GetNavigationService(this);
            //Page1 p = new Page1();
           // nav.Navigate(p);

        }

        private void TBPassword_TextChanged(object sender, TextChangedEventArgs e)
        {

        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {

        }
    }
}
