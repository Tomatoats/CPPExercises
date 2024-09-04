#include <iostream> 
#include <map> // to store info via maps
#include <algorithm> // to sort 
#include <set> // to sort
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

int* toSort(std::map<int,std::string> lastName){
    std::map<int,std::string> lName = lastName;

    std::string counter = "zzzzzzzzzzzzzzzzzzzzzzz";
    int j;
    int *sort;
    for (int k = 0; k = 6; k++){
        for (int i = 0; i < 6; i++){
            if (counter > lName[i]){
                counter = lName[i];
                j = i;
            }
        }
    lName[j] = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    sort[k] = j;
    }
    return sort;
}



int main (){
    std::map<int, std::string> firstName = initializefirst();
    std::map<int, std::string> lastName  = initializelast();
    std::map<int, std::string> position  = initializePos();
    std::map<int, std::string> date      = initializeDate();
    std::cout << "meow\n";
   int* sorted = toSort(lastName);
    std::cout << "meow\n";
    std::cout << "Name\t\t| Position\t\t| SeperationDate\n";
    std::cout << "------------|-------------------------|-----------------------------------------\n";
    for (int i = 0; i < 6; i++){
        std::cout << firstName[sorted[i]] << " " << lastName[sorted[i]] << "\t| "<< position[sorted[i]] << "\t| " << date[sorted[i]];
    }
    return 0;

}