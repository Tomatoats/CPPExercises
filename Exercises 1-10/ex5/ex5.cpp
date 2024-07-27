#include <iostream>

int main () {
    // set up the two int's we need
    std::string firstNumber;
    std::string secondNumber;

    //start the couts 
    std::cout << "What is the first number?\n";
    std::cin >> firstNumber;
    std::cout << "What is the second number?\n";
    std::cin >> secondNumber;

    //convert the user numbers into int to work with
    int number1 = std::stoi(firstNumber);
    int number2 = std::stoi(secondNumber);


    //get the numbers after doing some math expression to them
    int addNumbers = number1 + number2;
    int minusNumbers = number1 - number2;
    int multNumbers = number1 * number2;
    float divNumbers = float(number1) / float(number2);
    //std::cout << divNumbers;
    //to do division it's best to turn the int numbers into floats
    //print.
    std::cout << number1 << " + " << number2 << " = " << addNumbers << "\n" 
    << number1 << " - " << number2 << " = " << minusNumbers << "\n" 
    << number1 << " * " << number2 << " = " << multNumbers << "\n" 
    << number1 << " / " << number2 << " = " << divNumbers << "\n";

    return 0;
}