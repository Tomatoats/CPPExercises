#include <iostream> 
#include <cmath> //for std
#include <vector>
int validateInt(std::string question){
    //set up the variables needed
    std::string userInput;
    int input;
    //set up flag, and a while that uses a try / catch for errors
    bool flag = false;
    while (flag == false){
        //get user input
        std::cout << question;
        //std::cin >> userInput;
        getline(std::cin,userInput);
        if (userInput == ""){
            return -1;
        }
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


class stats{
    public:
    std::vector<int> numbers;

    void add(int number){
        numbers.push_back(number);
    }

    float Average(){
        int toAdd = 0;
        int size = numbers.size();
        for (int numb : numbers){
            toAdd+= numb;
        }
        float average = static_cast<float> (toAdd) / static_cast<float> (size);
        return average;
    }

    float Max(){
        int max = 0;
        for (int numb : numbers){
            if (max < numb){
                max = numb;
            }
        }
        return max;
    }
    
    float Min(){
        int min = INT32_MAX;
        for (int numb : numbers){
            if (min > numb){
                min = numb;
            }
        }
        return min;
    }

    float stdrd(){
        float stand = 0;
        float avg = Average();
        for (int numb : numbers){
            stand += std::pow(static_cast<float>(numb) - avg, 2);
        }
        return sqrt(stand / numbers.size());
    }
};


int main (){
    stats myNumbers;
    bool flag = false;
    float average;
    int max;
    int min;
    float stand;
    while (flag == false){
        int number = validateInt("Enter a number: ");
        if (number == -1){
            average = myNumbers.Average();
            max = myNumbers.Max();
            min = myNumbers.Min();
            stand = myNumbers.stdrd();
            flag = true;
        }
        else{
            myNumbers.add(number);
        }
    }
    std::cout << "Numbers: ";
    for (int numb: myNumbers.numbers){
        
        std::cout << numb <<", ";
    }

    std::cout << "\nThe average is " << average << "\n";
    std::cout << "The minimum is " << min << "\n";
    std::cout << "The maximum is " << max << "\n";
    std::cout << "The standard deviation is " << stand << "\n";
    return 0;
}
