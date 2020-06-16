using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;

namespace TriviaClient
{
    static class Communicator
    {
        public static Socket serverSocket;
        public static bool Connect(string serverIp,int port)
        {
            serverSocket = null;
            Socket sock = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            IPAddress ipaddress = System.Net.IPAddress.Parse(serverIp);
            IPEndPoint ipEndPoint = new IPEndPoint(ipaddress, port);
            try
            {
                sock.Connect(ipEndPoint);
            }
            catch(Exception e)
            {
                return false;
            }
            serverSocket = sock;
            return true;
        }
        
        public static void SendMessage()
        {

        }
    }
}
