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
        public static bool first = true;
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

        /*
         This function handles the communication with server
         Input:The request to be sent to the server
         Output:The response from the server
         */
        public static Response Communicate(LoginRequest req)
        {
            
            if(first)
            {
                serverSocket.Receive(new byte[5], 5, SocketFlags.None);
            }
            first = false;
            //send
            byte[] mes = RequestEncoder.Encode(req);
            serverSocket.Send(mes);

            //receive
            const int CODE_LENGTH = 1;
            const int SIZE_LENGTH = 4;

            byte[] arr = new byte[CODE_LENGTH];

            serverSocket.Receive(arr, CODE_LENGTH, SocketFlags.None);
            int code = FromByteToInt(arr);

            arr = new byte[SIZE_LENGTH];
            serverSocket.Receive(arr, SIZE_LENGTH, SocketFlags.None);
            int size = FromByteToInt(arr);

            arr = new byte[size];
            serverSocket.Receive(arr, size, SocketFlags.None);
            //return ResponseDecoder.doStuff();
            return new Response();
        }

        /*
         This function transform for array of bytes to integer value
         Input:Pointer to bytes array
         Output: The integer value
         */
        private static int FromByteToInt(byte[] data)
        {
            int val = 0;
            for (int i = 0; i < data.Length; i++)
            {
                val += (int)Math.Pow(256, i) * data[data.Length-i-1];
            }
            return val;
        }
    }
}
