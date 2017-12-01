### MiniComunicator TeamProject 
# Requirements 

* Multichat program (something like IRC)
* Multiple client chat
* 2 diffrent programs: server and client
* Coding language: C++
* PDF doc with history of work 

# Features

* Server provides a loobSerwer udostępnia lobby do którego można się zalogować
* User can write in lobby or hold a direct conversation with another user
* Communication in each instance happens in order client-server-client in real time
* Server creates a log of conversation (planned)
* Savin conversation into a file (File->Save conversation)
* Changing the username 


## Client application 

# Description #
Client app based on **TODO(Qt?, wxWidgets?, WinApi?)** gui framework.

# Visual Concept 

![](https://raw.githubusercontent.com/adrozd16/ProgrammingMiniProject/master/Mini%20project%20window-01.jpg)

Top menu:

* File:
  * Save conversation as .txt file
  * Close program
* Server:
  * Connect to server (displays a window prompt)
  * Disconnect
* Options:
  * Change display name
* Help:
  * About MiniComunicator (display author, current program version)

## Server application

# Description
App based on cmd window, shows debug communicates when running, saves communicates to log file.


## Workflow

# Todo list
* Create a client app with interface with functions for displaying content like users list from array.
* C++ file header to provide communication (with funcs like: connect_to_server(ip...), send_msg(text) etc.) It will be used both for server and client app
* Server application

# Work distribution

Team consist of 6 people so the work would be best divided into 3 groups:

* Network programmer (group 1)
* Server app programmer (group 1)
* Client side GUI programmer (group 2)
* Application engineer (group 3)

**Group 1:**

* person 1
* person 2

**Group 2:**

* person 3
* person 4

**Group 3:**

* person 5
* person 6

