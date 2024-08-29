#include <iostream>
#include <ctime> // to seed the random
#include <cstdlib> // to grab random

int grabDifficulty(std::string difficulty){
    std::string userInput;
    int input;
    //set up flag, and a while that uses a try / catch for errors
    bool flag = false;
    while (flag == false){
        //get user input
        std::cout << difficulty;
        std::cin >> userInput;
        try {
            //try turning it into an int
            input = std::stoi(userInput);
           
        }
        catch(const std::invalid_argument& e){
            //if it doesn't int, it says to cli
            std::cout << "Not an int!\n";
            //flag = false;
        }
        if (input > 3 || input < 0){
            std::cout << "not a proper number!  Choose 1,2 or 3\n";
            
        }
        else {
            flag = true;
            
        }
    }
    return input;
}

int randomize(int difficulty){
    int randomNumber = 0;
    switch(difficulty){
        case 1: std::srand(std::time(nullptr));
            randomNumber = std::rand() % 10;
            break;
        case 2: std::srand(std::time(nullptr));
            randomNumber = std::rand() % 100;
            break;
        case 3: std::srand(std::time(nullptr));
            randomNumber = std::rand() % 1000;
            break;
        default: std::cout << "huh? You weren't supposed to get here.\n";
            break;
        }
    return randomNumber;
}

char playAgain(std::string question){
    char userInput;

    //set up flag, and a while that uses a try / catch for errors
    bool flag = false;
    while (flag == false){
        //get user input
        std::cout << question;
        std::cin >> userInput;
        if (userInput == 'Y' || userInput == 'y'){
            return true;
        }
        else if (userInput == 'N' || userInput == 'n'){
            return false;
        }
        else {
            std::cout << "Hey bud i need a y or an n\n";
        }
    }
}

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

int playGame(int randomNumber){
    int guesses = 0;
    bool flag = false;
    while (flag == false){
        int userGuess = validateInt("Guess! ");

        if (userGuess < randomNumber){
            std::cout << "Too low. ";
            guesses++;
        }
        else if (userGuess  > randomNumber){
            std::cout << "Too high. ";
            guesses++;
        }
        else
        {
            guesses++;
            return guesses;
        }
    }
}


int main (){
   
    bool flag = false;
    while (flag == false){
        std::cout << "Let's play Guess the Number!\n";
        int difficulty = grabDifficulty("Enter the difficulty level (1, 2, or 3): ");

        //seed the random
        int randomNumber = randomize(difficulty);

        int guesses = playGame(randomNumber);

        std::cout << "You got it in " << guesses << " guesses!\n";

        bool gamestart =  playAgain("Do you wish to play again (Y/N) ? ");
        if (gamestart == true){
            flag = false;
        }
        else {
            flag = true;
        }
        
    }
    return 0;
}

    