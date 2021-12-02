#include "MyTime.h"
MyTime:: MyTime()
{}

//=====TO DO====(b)===============
MyTime:: MyTime(int hr, int mi){
    this -> hour = hr;
    this -> min = mi;
}



//=====TO DO=====(e)=============
MyTime MyTime:: operator+(const MyTime& time)
{
    MyTime temp;
    temp.hour = this -> hour + time.hour;
    temp.min = this -> min + time.min;
    return temp;
}

//=====TO DO=====(f)=============
bool MyTime:: operator<(const MyTime& time)
{
    if(time.min < this -> min) {
        if(time.hour < this -> hour){
            return true;  
        }
    }else {
        if(time.hour > this -> hour){
            return true;
        }
    }
    return false;
}
MyTime::~MyTime()
{
    std::cout<<"end of the object. Space Deleted.\n";
}
void MyTime::displayTime()
{
    std::cout<<"The time is: hour: "<<hour<<"   The min is:  "<<min<<".\n";
}
