#include <iostream> 

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


std::string switchTable(int monthInInt){
    std::string result = "";
    switch (monthInInt){
        case 1: result = "January.";
                break;
        case 2: result = "February.";
                break; 
        case 3: result = "March.";
                break; 
        case 4: result = "April.";
                break; 
        case 5: result = "May.";
                break; 
        case 6: result = "June.";
                break; 
        case 7: result = "July.";
                break; 
        case 8: result = "August.";
                break; 
        case 9: result = "September.";
                break; 
        case 10: result = "October.";
                break; 
        case 11: result = "November.";
                break;
        case 12: result = "December.";
                break; 
        default: result = "N/A";
                break; 
    }
    return result;
}




int main () {
    int monthInInt = validateInt("Please enter the number of the month: ");
    std::string result = switchTable(monthInInt);

    std::cout << "The name of the month is " << result;
    return 0;
}