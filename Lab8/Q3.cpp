#include<iostream>
using namespace std;
class Student
{
    public:
        Student(){}
        Student(int newID):ID(newID)
        {

        }
        int getID()
        {
            return ID;
        }
        void ShowMajor()
        {
            cout<<"I am a student in Miami University\n";
        }
    protected:
        int ID;
};

class RA
{
    public:
        RA(){}
        RA(int NewSalary)
        {
            Salary=NewSalary;
        }
        int getSalary()
        {
            return Salary;
        }
        void ShowYourWork()
        {
            cout<<"I am a RA in Miami University\n";
        }
    protected:
        int Salary;
};

class AboutMe
{
    public:
        AboutMe()
        {}
        AboutMe(int ID, int Salary){
            this -> ID = ID;
        }

        void setMyID(int i){
            ID = i;
        }

        void setSalary(int i){
            Salary = i;
        }

        void ShowMajor()
        {
            cout<<"I am a student in Miami University\n";
        }

        void ShowYourWork()
        {
            cout<<"I am a RA in Miami University\n";
        }

        void DisplayInfo(){
            cout<< "My ID in Miami University is: " << ID << " My salary as an RA is: " << Salary << "\n";
        }
    protected:
        int ID;
        int Salary;

};

int main()
{
    AboutMe Alice(22,223);
    Alice.ShowMajor();
    Alice.ShowYourWork();
    Alice.setMyID(1273);
    Alice.setSalary(2000);
    Alice.DisplayInfo();
}