#include <iostream>

int output(float subtotal,float tax,float total){
    std::cout << "Subtotal: " << subtotal << "\n";
    std::cout << "Tax: " << tax << "\n";
    std::cout << "Total: " << total << "\n";
    return 0;

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
        }
        catch(const std::invalid_argument& e){
            //if it doesn't int, it says to cli
            std::cout << "Not a int!\n";
            //flag = false;
        }
        
    }
    return input;
    
}

int calculate(int* ptr, int count){
    float subtotal, tax, total = 0;
    for  (int i = 0; i < count; i++) {
        //std::cout << i;
        subtotal += (ptr[i] * ptr[i+1]); 
        i++;
    }
    tax = subtotal * 0.055;
    total = subtotal + tax;
    //output now
    return output(subtotal,tax,total);
    
}





int main () {
    //init an array of a certain size
    int arrayOfPrices[6];
    //get the info we need (must be a better way than this
    arrayOfPrices[0] = validateInt("Enter the price of item 1: ");
    arrayOfPrices[1] = validateInt("Enter the quantity of item 1: ");
    arrayOfPrices[2] = validateInt("Enter the price of item 2: ");
    arrayOfPrices[3] = validateInt("Enter the quantity of item 2: ");
    arrayOfPrices[4] = validateInt("Enter the price of item 3: ");
    arrayOfPrices[5] = validateInt("Enter the quantity of item 3: ");
    //calculate in a seperate  function
    return calculate(arrayOfPrices,6);
}
