#include <iostream>
#include <vector> // for a modifiable array
#include <ctime> // to seed the random
#include <cstdlib> // to grab random

std::string grabName(std::string question){
    std::string userInput;
    std::cout << question;
    getline(std::cin, userInput);
    return userInput;
}

int main (){
    //set up the while loop
    bool flag = false;
    std::vector<std::string> names;
    while (flag == false){
        //while names aren't empty, keep up the while loop
        std::string name = grabName("Enter a name: ");
        if (name == ""){
            flag = true;
        }
        else{
            //add it to the vector
            names.push_back(name);
        }
    }
    //seed random
    int randomNumber;
    std::srand(std::time(nullptr));
    randomNumber = std::rand() % names.size();
    //print out
    std::cout << "The winner is... " << names.at(randomNumber) << ".\n";

    return 0;
}



        
