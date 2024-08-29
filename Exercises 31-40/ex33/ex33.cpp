 #include <iostream>
 #include <ctime> // to seed the random
#include <cstdlib> // to grab random

std::string grabString(int randomNumber){
    std::string answer;
    switch(randomNumber){
        case 0: answer = "Yes.\n";
                break;
        case 1: answer = "No.\n";
                break;
        case 2: answer = "Maybe.\n";
                break;
        case 3: answer = "Ask again later.\n";
                break;
        default: answer = "idk";
                break;
    }
    return answer;
}


int main(){
    std::string question;
    std::cout << "What's your question?\n";
    std::cin >> question;

    int randomNumber;
    std::srand(std::time(nullptr));
    randomNumber = std::rand() % 4;

    std::string result = grabString(randomNumber);

    std::cout << result;
    return 0;
}
    