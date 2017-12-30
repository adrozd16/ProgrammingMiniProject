

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <string>
#include<iostream>
using namespace std;

int main()
{	//Declaritions
	sf::IpAddress ip = sf::IpAddress::getLocalAddress();//Getting the local IP address that will be used to connect to the client
	sf::TcpSocket socket;
	char buffer[5000];//Will be used to send and recieve the lines of characters between the client and the client
	std::size_t recieved;	//Will be used as a flag to check if the server and client are connected or not
	std::string text = "Connected to:";
	unsigned short port;
	
	//Setting up the port which will be used to communicatie with the client
	std::cout << "what port?";
	std::cin >> port;
	std::cout << "\n";
	std::cout << "Waiting for request..." << std::endl;

	//The listner will be listning for connection request from the client
		sf::TcpListener listner;
		listner.listen(port);//Waiting for request
		
		listner.accept(socket);//Accepting the request
		text += "Server";
	
	
	socket.send(text.c_str(), text.length() + 1);//Send a buffer that contains a confirmation of the server connectivety
	socket.receive(buffer, sizeof(buffer), recieved);//Send a buffer that contains a confirmation of the client connectivety	


	std::cout << buffer << std::endl;
	std::cout << "Server is running......" << std::endl;
	//Converting the Characters to ASCII
	while (true)
	{	string coded ;
		socket.receive(buffer, size(buffer), recieved);//Recieving the buffer of the characters
		 coded = "";
		if (recieved > 0)
		{
			for (int i = 0; i < strlen(buffer); i++)
				coded+=to_string( int(buffer[i]))+" ";//Converts 1 character to ASCII each FOR loop										
			socket.send(coded.c_str(), coded.length() + 1);//Send the buffer of ASCII code to the client
		}	
	}
	system("pause");
}