#include <iostream> 
#include <map> // to store info via maps
#include <iomanip> // for setting the width
#include <vector> // to make sets
#include <set> // to make sets


std::map<int,std::string> initializefirst(){

    std::map<int,std::string> firstName;
    firstName[0] = "John";
    firstName[1] = "Tou";
    firstName[2] = "Michaela";
    firstName[3] = "Jake";
    firstName[4] = "Jacquelyn";
    firstName[5] = "Sally";

    return firstName;
}

std::map<int,std::string> initializelast(){

    std::map<int,std::string> lastName;
    lastName[0] = "Johnson";
    lastName[1] = "Xiong";
    lastName[2] = "Michaelson";
    lastName[3] = "Jacobson";
    lastName[4] = "Jackson";
    lastName[5] = "Webber";

    return lastName;
}
std::map<int,std::string> initializeName(){

    std::map<int,std::string> Name;
    Name[0] = "John Johnson";
    Name[1] = "Tou Xiong";
    Name[2] = "Michaela Michaelson";
    Name[3] = "Jake Jacobson";
    Name[4] = "Jacquelyn Jackson";
    Name[5] = "Sally Webber";

    return Name;
}


std::map<int,std::string> initializePos(){

    std::map<int,std::string> position;
    position[0] = "Manager";
    position[1] = "Software Engineer";
    position[2] = "District Manager";
    position[3] = "Programmer";
    position[4] = "DBA";
    position[5] = "Web Devoloper";

    return position;
}
std::map<int,std::string> initializeDate(){

    std::map<int,std::string> date;
    date[0] = "2016-12-31";
    date[1] = "2016-10-05";
    date[2] = "2015-12-19";
    date[3] = "";
    date[4] = "";
    date[5] = "2015-12-18";

    return date;
}

std::string grabString(std::string question){
    std::string userInput;
    std::cout << question;
    getline(std::cin,userInput);
    return userInput;
}

std::set<int>  goFind(std::map<int, std::string> stringMap, std::string userInput, std::set<int> found){
    for (int i = 0; i < stringMap.size(); i++){
        if (stringMap[i].find(userInput) != std::string::npos){
            //std::cout << "found!\n";
            //std::cout << stringMap[i] << " has " << userInput << " so add " << i <<  "\n"; 
            found.insert(i);
        }
    }
    return found;
}


int main (){
    std::map<int, std::string> firstName = initializefirst();
    std::map<int, std::string> lastName  = initializelast();
    std::map<int, std::string> position  = initializePos();
    std::map<int, std::string> date      = initializeDate();
    std::map<int, std::string> fullName  = initializeName();
    
    std::string userInput = grabString("Enter a search String: ");
    std::set<int> found;
    
    int counter;
    
    
    found = goFind(position,userInput,found);
    found = goFind(date,userInput,found);
    found = goFind(fullName,userInput,found);


    //toSort(lastName,sortNumber.sorted);
    std::cout << "Name\t\t\t| Position\t\t| Seperation Date\n";
    std::cout << "------------------------|-----------------------|-------------------------------\n";
    for (int fun : found ){
        std::cout << std::left  << std::setw(24) << std::setfill(' ') << fullName[fun] << "| " << std::left  << std::setw(22) << std::setfill(' ') << position[fun] <<  "| " << date[fun] << "\n";
    }
    return 0;

}