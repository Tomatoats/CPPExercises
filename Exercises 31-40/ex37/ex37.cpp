#include <iostream>
#include <ctime> // to seed the random
#include <cstdlib> // to grab random
#include <algorithm> // to shuffle

int validateInt(std::string question){
    //set up the variables needed
    std::string userInput;
    int input;
    //set up flag, and a while that uses a try / catch for errors
    bool flag = false;
    while (flag == false){
        //get user input
        std::cout << question;
        std::cin >> userInput;
        try {
            //try turning it into an int
            input = std::stoi(userInput);
            flag = true;
            return input;
        }
        catch(const std::invalid_argument& e){
            //if it doesn't int, it says to cli
            std::cout << "Not an int!\n";
            //flag = false;
        }    
    }
}

char grabSpecial(){
    char specials[24] = {';','/','?','{','[','}',']','|','+','=','-','_',')','(','*','&','^','%','$','#','@','!','`','~'};
    //std::srand(std::time(nullptr));
    int randomNumber = std::rand() % 23;
    return specials[randomNumber];
}

char grabNumbers(){
    char numbers[10] = {'1','2','3','4','5','6','7','8','9','0'};
    //std::srand(std::time(nullptr));
    int randomNumber = std::rand() % 9;
    return numbers[randomNumber];
}

char grabLetters(){
    char letters[26] = {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'};
    //std::srand(std::time(nullptr));
    int randomNumber = std::rand() % 25;
    return letters[randomNumber];
}

std::string makePassword(int length, int special, int number){
    std::string pass;
    //grab length
    int totalNon = special + number;
    if (length < totalNon){
        length = totalNon;
    }
    //std::srand(std::time(nullptr));
    int randomNumber = std::rand() % 6;
    length = length + randomNumber;
    char characters[length];
    int i = 0;
    
    for (i; i < special; i++){
        characters[i] = grabSpecial();
    }
    for (i; i < (special + number); i++){
        characters[i] = grabNumbers();
    }
    for (i; i < length; i++){
        characters[i] = grabLetters();
    }
    std::random_shuffle(characters,characters+length);
    std::string password = characters;
    return password;
}


int main () {
    std::srand(std::time(nullptr));
    int length = validateInt("What's the minimum length? ");
    int special = validateInt("How many special characters? ");
    int numbers = validateInt("How many numbers? ");

    std::string password = makePassword(length,special,numbers);

    std::cout << "Your password is " << password << "\n";
    return 0;
}