#include <iostream>
#include <vector>
#include <fstream> // to read files
#include <algorithm> // to sort


std::vector<std::string> grabInput(){
    std::vector<std::string> input;
    std::string line;
    
    //open up the file
    std::ifstream inputFile("ex41_input.txt");
    //read it line by line
    while(getline(inputFile,line)){
        input.push_back(line);
    }
    inputFile.close();
    return input;
}

void printToFile(std::vector<std::string> input){
    std::ofstream outFile;
    int length = input.size();

    outFile.open("ex41_output.txt");
    outFile << "Total of " << length << " names\n";
    outFile << "-------------------------\n";
    for (int i = 0; i < length; i++){
        outFile << input.at(i) << "\n";
    }
}


int main(){

    std::vector<std::string> input = grabInput();
    std::sort(input.begin(),input.end());
    printToFile(input);

    return 0;
}
