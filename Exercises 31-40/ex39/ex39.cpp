#include <iostream> 
#include <map> // to store info via maps
#include <algorithm> // to sort 
#include <set> // to sort
#include <iomanip> // for setting the width


class sortedArray{
    public:
    int sorted[6];

    void add(int number,int counter){
        sorted[number] = counter;
    }
    int sendSort(int number){
        return (sorted[number]);
    }
};

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


void toSend(int* sorted){
   
    for (int i = 0; i < 6; i++){
        std::cout << sorted[i] << "\n";
    }
}


void toSort(std::map<int,std::string> lastName, int sorted[6]){
    std::map<int,std::string> lName = lastName;
     
    //std::cout << "in toSort\n";
    std::string counter; 
    int j;
    //int* sorted;
    //std::cout << "established everything\n";
    for (int k = 0; k < 6; k++){
        counter = "zzzzzzzzzzzzzzzzzzzzzzz";
        for (int i = 0; i < 6; i++){
           // std::cout << "in i: " << i << "\n";
            if (counter > lName[i]){
                counter = lName[i];
                j = i;
               // std::cout << "in if\n";
            }
        //std::cout << "counter = " << counter << "\n";
        }
    lName[j] = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    //sorted[k] = j;
    //sortNumber.add(k,j);
    sorted[k] = j;
    //std::cout << lastName[sortNumber.sorted[k]] << "\n";
    }
   
    //std::cout << &lastName[2] << "\n";
    //for (int x = 0; x < 6; x++){
        //std::cout << lastName[x] << "\n";
    //}
    counter = "";
    //delete sorted;
}




int main (){
    std::map<int, std::string> firstName = initializefirst();
    std::map<int, std::string> lastName  = initializelast();
    std::map<int, std::string> position  = initializePos();
    std::map<int, std::string> date      = initializeDate();
    std::map<int, std::string> fullName  = initializeName();

    sortedArray sortNumber;
    toSort(lastName,sortNumber.sorted);
    std::cout << "Name\t\t\t| Position\t\t| Seperation Date\n";
    std::cout << "------------------------|-----------------------|-------------------------------\n";
    for (int i = 0; i < 6; i++){
        std::cout << std::left  << std::setw(24) << std::setfill(' ') << fullName[sortNumber.sorted[i]] << "| " << std::left  << std::setw(22) << std::setfill(' ') << position[sortNumber.sendSort(i)] <<  "| " << date[sortNumber.sendSort(i)] << "\n";
    }
    return 0;

}