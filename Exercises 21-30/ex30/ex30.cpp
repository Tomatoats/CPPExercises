#include <iostream>
#include <iomanip> // for setting the width

int main (){
    int numb = 1;
    
    for (int i = 1; i < 13; i++){
        for (int k = 1; k < 13; k++){
            std::cout << "\t" <<i*k;//std::setw(8);
            //std::cout <<i*k << std::setw(4);
        }
        std::cout << "\n";
    }
    return 0;
}
