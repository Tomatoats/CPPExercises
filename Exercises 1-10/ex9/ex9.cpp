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
        }
        catch(const std::invalid_argument& e){
            //if it doesn't int, it says to cli
            std::cout << "Not a int!\n";
            //flag = false;
        }
        
    }
    return input;
    
}





int main () {
    //grab our length and width from user via a method
 int length = validateInt("What's the length of the room (in feet)? ");
 int width = validateInt("What's the width of the room (in feet)? ");


 int gallonAmount = 350;
 int area = length * width;
 int gallonNeeded = area / gallonAmount;
 if (area % gallonAmount != 0){
    gallonNeeded++;

 }
 std::cout << "You will need to purchase " << gallonNeeded << " gallons of paint to cover " << area << " square feet.";
 return 0;

}

