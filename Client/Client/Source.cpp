#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <string>
#include<iostream>

using namespace std;
int main()
{
	//Declaritions
	sf::IpAddress ip = sf::IpAddress::getLocalAddress();//Getting the local IP address that will be used to connect to the server
	sf::TcpSocket socket;
	char buffer[5000];//Will be used to send and recieve the lines of characters between the client and the server
	std::size_t recieved;
	std::string text = "Connected to:";
	unsigned short port;
	std::string IP;
	
	//Asking the user to enter any port number
	std::cout << "What port? ";
	std::cin >> port;
	std::cin.get();

	//Giving the client the ability to decide what IP address it will be connected to (local host in our case)
	std::cout << "Server IP? (1 = local host), (2 = local), (3 = public) : ";	
	std::getline(std::cin, IP);
	sf::Socket::Status status;
	if (IP == "1")
		status = socket.connect(sf::IpAddress::LocalHost, port);//Connecting the socket with the server which is using the local IP address
	else if (IP == "2")
		status = socket.connect(sf::IpAddress::getLocalAddress(), port);
	else if (IP == "3")
		status = socket.connect(sf::IpAddress::getPublicAddress(), port);
	else
	{
		std::cout << "Unknown command\n";
		return -1;
	}
		
			text += "Client";
			
			socket.send(text.c_str(), text.length() + 1);//Send a buffer that contains a confirmation of the client connectivety
			socket.receive(buffer, sizeof(buffer), recieved);//Send a buffer that contains a confirmation of the server connectivety
			std::cout << buffer << std::endl;

	//Entering the wanted characters to be translated into ASCII
			while (true) 
			{
				std::cout << "Enter some characters to show its ASCII code :  ";
				std::getline(cin, text);
				socket.send(text.c_str(), text.length() + 1);//Sending the buffer of characters to the server
				socket.receive(buffer, sizeof(buffer), recieved);//Recieving the buffer that contains the ASCII code
				std::cout << "The ASCII code is : ";
				std::cout << buffer << std::endl;
				std::cout << "\n\n";
				
			}
			system("pause");
}