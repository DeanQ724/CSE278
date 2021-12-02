#include<iostream>

class MyTime
{
    public:
        MyTime();
        MyTime(int hr, int mi);
        ~MyTime();
        void displayTime();
    //operation overload for + (e)
   MyTime operator+(const MyTime& time);
    //operation overload for > (f)
   bool operator<(const MyTime& time);
    

    private:
        int hour;
        int min;
};