#include <iostream>

int main () {
    //prepare the user strings
    std::string length;
    std::string width;

    //grab it through couts and cins!
    std::cout << "What is the length of the rectangle? ";
    std::cin >> length;
    std::cout << "What is the width of the rectangle? ";
    std::cin >> width;

    //convert to int 
    int len = std::stoi(length);
    int wdth = std::stoi(width);

    // do the math with it
    int area = len * wdth;
    const float conversion = 0.09290304;
    float areaMeters = float(area) * conversion;

    //print!
    std::cout << "You entered dimensions of " << len << " by " << wdth << " feet.\n";
    std::cout << "The area is\n" << area << " square feet\n" << areaMeters << " square meters\n";

    return 0;
}