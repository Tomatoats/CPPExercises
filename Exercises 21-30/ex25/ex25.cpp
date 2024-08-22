#include <iostream>
#include <string.h> // for size
#include <algorithm>
#include <cctype>
#include <string> //those last 3 are to turn shit to lowercase

std::string grabString(std::string question){
    std::string input = "";
    std::cout << question;
    getline(std::cin, input);
    return input;
}

bool isSomething(char compared[],char c){
    return std::string(compared).find(c) != std::string::npos;
} //compares if a certain char is in a char array

std::string passwordValidator(std::string userPass){
    int strength = 0;
    std::string result = "";
    int length = userPass.size();

    std::transform(userPass.begin(),userPass.end(),userPass.begin(),[](unsigned char lowerpass){ return std::tolower(lowerpass); });
    //turns a string lowercase according to Stack overflow

    int number = 0;
    int letter = 0;
    int special = 0;
    char letters[26] = {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'};
    char numbers[10] = {'1','2','3','4','5','6','7','8','9','0'};
    char specials[24] =   {';','/','?','{','[','}',']','|','+','=','-','_',')','(','*','&','^','%','$','#','@','!','`','~'};

    //convert userpass to char array
    char * passArray = new char[length +1];
    strcpy(passArray, userPass.c_str());



    for (int i = 0; i < userPass.size(); i++){
        if (isSomething(letters,passArray[i]) == true){
            letter++;
        }
        else if (isSomething(numbers, passArray[i]) == true){
            number++;
        }
        else if (isSomething(specials,passArray[i]) == true){
            special++;
        }
    }


    if (length < 8){
        if (length == number){
            strength = 1;
        }
        else if (length == letter){
            strength = 2;
        }
        else {
            strength = 0;
        }
    }
    else{
        if (number > 0 && letter > 0 && special == 0){
            strength = 3;
        }
        else if (special > 0 && letter > 0 && number > 0){
            strength = 4;
        }
        else{
            strength = 0;
        }
    } 
    


    switch(strength){
        default: result = "is indeterminate.";
            break;
        case 1: result = "is a very weak password";
            break;
        case 2: result = "is a weak password";
            break;
        case 3: result = "is a strong password";
            break;
        case 4: result = "is a very strong password";
            break;
            //breaks are very needed

    delete[] passArray;
    return result;
    }
}


int main() {
    std::string userPass = grabString("Give me your password and I'll let you know if it's weak or not. ");

    std::string result = passwordValidator(userPass);
    
   
    std::cout << "The password '" << userPass << "' " << result;

    return 0;
}


