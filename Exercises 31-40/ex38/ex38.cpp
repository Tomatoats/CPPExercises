#include <iostream>
#include <vector> // to make vector


std::vector<std::string> grabString(std::string question){
    std::string userInput;
    std::cout << question;
    getline(std::cin, userInput);

    //setting up vector shit
    const std::string delimiter = " ";
    std::vector<std::string> toReturn;
    size_t position = 0;
    std::string number;
    //so this will allow us to iterate and split up the string into a vector
    //man shout out java split becauase this is ASS

   while ((position = userInput.find(delimiter)) != std::string::npos) {
        number = userInput.substr(0, position);
        toReturn.push_back(number);
        userInput.erase(0, position + delimiter.length());
    }
    toReturn.push_back(userInput);
         


    return toReturn;
}





void filterEvenNumbers(std::vector<std::string> inputString){
    
    int size = inputString.size();
    int evenArray[size];
    int j = 0; 
    int input;

    for (int i = 0; i < inputString.size();i++){
        input =  std::stoi(inputString.at(i));
        if (input % 2 == 0){
            evenArray[j] = input;
            j++;
        }
    }

     std::cout << "The even numbers are ";
    for (int i = 0; i < j; i++){
        std::cout << evenArray[i] << " ";
    }
    std::cout << ".\n";




}




int main (){
    std::vector<std::string> inputString = grabString("Enter a list of numbers, separated by spaces: ");
    
    filterEvenNumbers(inputString); // the end string and command line is in filter even numbers asa waell

    return 0;
}
