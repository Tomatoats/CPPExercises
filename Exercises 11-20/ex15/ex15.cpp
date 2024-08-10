#include <iostream> 
std::string getUserInput(std::string question){
    //grab user's input
    std::string input;
    std::cout << question;
    getline(std::cin,input);
    return input;
}

int compare(std::string name, std::string pass){
    std::string knownName = "Oats";
    std::string knownPass = "Cinder !";
    //compare name and pass to each ither
    if (name == knownName && pass == knownPass){
        return 1; // 1 should be a success
    }
    return 0; // 0 is a failiure
}

int main () {
    //grab the user name and password
    std::string name = getUserInput("What is your username? ");
    std::string pass = getUserInput("What is your password? "); 
    //compare name and pass to the one on file
    if(compare(name,pass) == 1){ //1 is a success
        std::cout << "Welcome";
    }
    else {
        std::cout << "I don't know you.";
    }
}