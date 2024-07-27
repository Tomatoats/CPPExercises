#include <iostream>

int main (){
    std::string quote;
    std::string author;
    /* setting up strings needed and then the cout calls*/
    std::cout << "What is the quote? \n";
    getline(std::cin,quote);
    std::cout << "And who said it? \n";
    getline(std::cin,author);
    //making a string to concat an output, setting it out
    std::string output;
    output = author + " said: \"" + quote + "\""; 
    std::cout << output;
    
    return 0;
}