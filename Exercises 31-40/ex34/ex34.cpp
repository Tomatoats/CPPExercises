#include <iostream>
#include <list> // to pop easily

int main(){
    std::list<std::string> names = {"John Smith","Jackie Jackson","Chris Jones","Amanda Cullen","Jeremy Goodwin"};

    
    std::cout << "There are " << names.size() << " employees.\n";

    for (std::string name : names){
        std::cout << name << "\n";
    }
    
    std::string removeName;
    std::cout << "Enter an empolyee name to remove: ";
    std::getline(std::cin,removeName);
    //std::cin >> removeName;

    std::list<std::string> newNames ={};
    for (std::string name : names){
        if (name == removeName){
            //names.pop_front();
        }
        else{
            newNames.push_back(name);
        }
    }

    std::cout << "There are " << newNames.size() << " employees.\n";

    for (std::string name : newNames){
        std::cout << name << "\n";
    }
    return 0;
}

        

