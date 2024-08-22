#include <iostream>

bool question(std::string question){
    bool flag = false;
    char answer = 'k';
    while (flag == false){
        std::cout << question;
        std::cin >> answer;
        if (answer == 'y' || answer == 'Y'){
            flag = true;
            return true;
        }
        else if (answer == 'n' || answer == 'N'){
            flag = true;
            return false;
        }
        else {
            std::cout << "Please type the character 'y' or 'n' to reply yes or no.\n" ;
        }
    }
}



int main () {
    bool flag = true;
    if (question("Is the car silent when you turned the key? ") == true){
        if (question("Are the battery terminals corroded? ") == true){
            std::cout << "Clean terminals and try starting again";
        }
        else{
            std::cout << "Replace cables and try again.";
        }
    }
    else{
        if (question("Does the car make a slicking noise? ") == true){
            std::cout << "Replace the battery." ;
        }
        else{
            if (question("Does the car crank up but fail to start? ") == true){
                std::cout << "Check Spark plug connections. ";
            }
            else {
                if (question("Does the engine start and then die? ") == true){
                    if (question("Does your car have fuel injection ? ") == true){
                        std::cout << "Get it in for service. ";
                    }
                    else {
                        std::cout << "Check to ensure the choke is opening and closing.";
                    }
                }
                else{
                    std::cout << "This should not be possible.";
                }
            }
        }
    }
    return 0;
}