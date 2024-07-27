#include <iostream>


int main() {
    std::string myString = "Hello World!\n";
    std::string name;
    delete &myString;
    std::cout << myString;

    std::cout << "What is your name? \n";
    std::cin >> name;
    std::cout << "Nice to meet you, " << name ;
    return 0;
}
// so we could also just cout << "Hello World!"
/* but i wanted to use a variable
*/
/* Alternatively awe could ignore "using namespace std" and then for cout do 
#include <iostream>

int main() {
  std::cout << "Hello World!";
  return 0;
} 
 OR
int main() {
    std::string myString = "Hello World!";
    std::cout << myString;
    return 0;
}
I'll be sticking with using namespace.


*/