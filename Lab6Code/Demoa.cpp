#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
    // Connect to database with: database, server, userID, password
    mysqlpp::Connection myDB("cse278","localhost" , "cse278",
            "student123");

    query << ("CREATE TABLE UserInfo( USER_ID varchar(32) NOT NULL, 
                            CarPlate varchar(32) NOT NULL,
                            UserCountry varchar(32) NOT NULL
                            );");

	// More code to come...
    mysqlpp::Query query = myDA.query();
    DB.query();   
    mysqlpp::Query query2 = myDB.query2(); 
    DB.query2();   

    

    std::ifStream USER_ID("User_ID.txt");
    ifStream CarPlate("CarPlate.txt");
    ifStream UserCountry("UserCountry.txt");
    ifStream ManufactCountry("ManufactCountry.txt");
    ifStream CarPrice("CarPrice.txt");


    while(USER_ID >> num)

    vector<String> USER_ID;
    vector<String> CarPlate;
    vector<String> UserCountry;
    vector<String> ManufactCountry;
    vector<int> CarPrice;

    if(!USER_ID.good()){
        std::ceer << "Cannot read USER_ID.txt\n";
    }

    string ret = "";
    while(User_ID >> ret){
        USER_ID.push_back(ret);
    }

    if(!CarPlate.good()){
        std::ceer << "Cannot read CarPlate.txt\n";
    }

    string ret = "";
    while(CarPlate >> ret){
        CarPlate.push_back(ret);
    }   

    if(!UserCountry.good()){
        std::ceer << "Cannot read UserCountry.txt\n";
    }
     
    string ret = "";
    while(UserCountry >> ret){
        UserCountry.push_back(ret);
    }      

    if(!ManufactCountry.good()){
        std::ceer << "Cannot read ManufactCountry.txt\n";
    }

    string ret = "";
    while(ManufactCountry >> ret){
        ManufactCountry.push_back(ret);
    }  

    if(!CarPrice.good()){
        std::ceer << "Cannot read CarPrice.txt\n";
    }

    int num = 0;  
    while(CarPrice >> ret){
        CarPrice.push_back(num);
    }
    




    query << "SELECT pname, price FROM Product;";
    query.parse();  // check to ensure it is correct
    query2.parse();
    mysqlpp::query1 = myDB.query();
    mysqlpp::StoreQueryResult result = query.store();

    query1 << "INSERT INTO UserInfo(USER_ID,CarPlate,UserCountry) VALUES ('2f2r',USA', '40000')";

    // Result is in 2-D vector of mysqlpp::String objects
    for (size_t row = 0; row < result.size(); row++) {
        std::string pname = result[row][0].c_str();
        float price = result[row][1];
        std::cout << pname << "\t" << price << "\n";
    } // done printing results

    //cout<<query<<endl;





}
