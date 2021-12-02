#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<unordered_map>

using namespace std;

/** A simple string to print the HTML header. */
const std::string HTML_HEADER =
        "<!DOCTYPE html>\n"
        "<html>\n"
        "<title> Using C++ to Generate Table in HTML</title>\n"
        "  <body>\n"
        "    <table border=1>\n"
        "      <tr><td>Movie Name</td><td>Update Time</td></tr>\n";

/** A simple string to finish the HTML. */
const std::string HTML_TRAILER =
        "    </table>\n"
        "  </body>\n"
        "</html>\n";


int main()
{
    // get the input files
    std::ifstream input("Movies.txt");
    std::ifstream inputB("Info.txt");

    std::vector <std::string> Movie;
    std::vector <std::string> Info;

    if(!input.good()||!inputB.good())
    {
        std::cout<<"No input file";
        return -1;
    }
    
    // read each item and store them into two vector and count the total number.
    // Assume the info and movie should match with the same number

    int Count=0;
    std::string temp;
    while(std::getline(input,temp)){
        Movie.push_back(temp);
    }
    while(std::getline(inputB,temp)){
        Info.push_back(temp);
    }
    Count = Movie.size();




    //=====TO DO======
    // append all the new table to the final output HTML content

    std::string HTML_Final;

    HTML_Final=HTML_Final+HTML_HEADER;


    for (int i=0;i<Count;i++)
    {
        HTML_Final = HTML_Final + "<tr><td>" + Movie[i] + "</td><td>" + Info[i] + "</td></tr>\n";
    }



    //===========ADD the HTML_TRAILER to the end===============

        HTML_Final=HTML_Final+HTML_TRAILER;

    //======output the file as "MovieInfo.html"========================

    std::ofstream out("MovieInfo.html");
    out << HTML_Final;

    return 0;
}