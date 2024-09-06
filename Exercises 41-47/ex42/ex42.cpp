#include <iostream>
#include <vector>
#include <fstream> // to read files
#include <iomanip> // for setting the width in the table

std::vector<std::string> grabInput(){
    std::vector<std::string> input;
    std::string line;
    
    //open up the file
    std::ifstream inputFile("ex42_input.txt");
    //read it line by line
    while(getline(inputFile,line)){
        input.push_back(line);
    }
    inputFile.close();
    return input;
}

std::vector<std::string> split(std::vector<std::string> input){
    std::vector<std::string> seperatedInput;
    //this will all be to split based on a comma from here on out
    const std::string delimiter = ",";
    std::string token;
    size_t position = 0;
    for (int i = 0; i < input.size();i++){
        while ((position = input.at(i).find(delimiter)) != std::string::npos){
            token = input.at(i).substr(0,position);
            seperatedInput.push_back(token);
            input.at(i).erase(0,position + delimiter.length());
        }
        seperatedInput.push_back(input.at(i));
    }

    return seperatedInput;
}

void printToFile(std::vector<std::string> input){
    std::ofstream outFile;
    int length = input.size();

    outFile.open("ex42_output.txt");
    outFile << "Last         First        Salary\n";
    outFile << "--------------------------------\n";
    for (int i = 0; i < length; i++){
        outFile << std::left  << std::setw(13) << std::setfill(' ') << input.at(i) <<std::left  << std::setw(13) << std::setfill(' ') << input.at(i+1) << std::left  << std::setw(13) << std::setfill(' ') << input.at(i+2) << "\n";
        i = i+2;
    }
}

int main(){
    std::vector<std::string> input = grabInput();
    std::vector<std::string> seperatedInput = split(input);

    printToFile(seperatedInput);



    return 0;
}
    