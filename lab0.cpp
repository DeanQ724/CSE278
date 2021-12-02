#include <iostream>
#include <string>
// Declaration of functions/methods
int main(int, char**);
void createSecret(std::string&);

// Definition of createSecret: It puts some random characters in a string
void createSecret(std::string &myString) {
    myString[0] = 36;
    myString[1] = 61;
    myString[2] = 88;
    myString[3] = 105;
    myString[4] = 50;
    myString[5] = 57;
    myString[6] = 94;
    myString[7] = 37;
}

// Main function: Declare a string, fill it with random characters and
// write it out
int main(int argc, char** argv) {
    std::string secretCode = "00000000";

    createSecret(secretCode);
    std::cout << "The secret code is\n" << secretCode << "\n";
    return 0;
}

