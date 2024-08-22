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

int findBiggest(int numbers[]){
    int index = 0;
    int biggest = numbers[0];
    if (numbers[0] == numbers[1] && numbers[1] == numbers[2]){
        return -1;
    }
    for (int i = 0; i < 3; i++){
        if (numbers[i] > biggest){
            index = i;
            biggest = numbers[i];
        }
    }
    return index;
}



int main () {
    int numbers[3];
    numbers[0] = validateInt("Enter the first number: ");
    numbers[1] = validateInt("Enter the second number: ");
    numbers[2] = validateInt("Enter the third number: ");

    int index = findBiggest(numbers);

    if (index == -1){
        return 0;
    }

    std::cout << "The largest number is " << numbers[index] ;
    return 0;
}
