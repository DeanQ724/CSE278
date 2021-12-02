#include <fstream>
#include <unordered_map>
#include<iostream>
#include <string>

class Lab4Q1{

    public: void averageFile(){
        int sum = 0;
        int num = 0;
        int count = 0;
        int average = 0;
        std::ifstream inFile("input.txt");
        if(!inFile.good()){
            std::cout << "cant read file";
        }
        while(inFile >> num){
            sum+=num;
            count++;
        }
        average = sum/count;
        std::cout << average;


        
    }

    // public: void map(){


    //     std::ifstream inFileName("NameFile.txt");
    //     std::ifstream inFileGade("input.txt");

    //     std::string uInput = "";
    //     using StrIntMap = std::unordered_map<std::string,int>;
    //     StrIntMap dean = {{"Dean",12}};

    //      dean.insert(std::pair<std::string,int>{inFileName,2});


    //     //finding if it has it
    //     std::cout << "Enter a name to search for: \n";
    //     std::cin >> uInput;


    // }

};


int main(int argc, char *argv[]) {

    Lab4Q1 run;

    run.averageFile();



}