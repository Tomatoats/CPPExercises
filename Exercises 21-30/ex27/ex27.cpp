#include <iostream>
#include <regex>

std::string grabString(std::string question){
    std::string input = "";
    std::cout << question;
    std::cin >> input;
    return input;
}

bool validateName(std::string name){
    int length = name.size();
    if ( length >= 2){
        return true;
    }
    else{
        return false;
    }
}

bool validateZip(std::string zip){
    int length = zip.size();
    if ( length == 5){
        try {
            //try turning it into an int
            int input = std::stoi(zip);
            
        }
        catch(const std::invalid_argument& e){
            //if it doesn't int, it says to cli
            //std::cout << "The zipcode must be a 5 digit number.\n";
            return false;
            //flag = false;
        }
    }
    else{
        return false;
    }
    return true;
}

bool validateID(std::string empID){
    std::regex regexp ("[a-zA-Z][a-zA-Z]-[0-9][0-9][0-9][0-9]");
    //useing regex to make an expression we want it to match
    //if matches, returns true
    if (std::regex_match(empID,regexp)){
        return true;
    }
    else {
        return false;
    }

}

void validateInput(std::string first, std::string last, std::string zip, std::string empID){
    bool firstBool = validateName(first);
    bool lastBool = validateName(last);
    bool zipBool = validateZip(zip);
    bool idBool = validateID(empID);


    if (firstBool == true && lastBool == true && zipBool  == true && idBool == true){
        std::cout << "There were no errors found. \n";

    }
    else{
        if (firstBool == false){
            std::cout << "The first name must be at least 2 characters long.\n";
        }
        if (lastBool == false){
            std::cout << "The last name must be at least 2 characters long.\n";
        }
        if (zipBool == false){
            std::cout << "The zip code must be a 5 digit number.\n";
        }
        if (idBool == false){
            std::cout << "The employee ID must be in the format of AA-1234\n";
        }
    }
}

int main () {
    std::string first = grabString("Enter the first name: ");
    std::string last = grabString("Enter the last name: ");
    std::string zip = grabString("Enter the zip code ");
    std::string empID = grabString("Enter the employee ID ");

    validateInput(first,last,zip,empID);

    return 0;
}