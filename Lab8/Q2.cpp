#include<iostream>
using namespace std;
class Student
{
    public:
        Student()
        {}
        Student(int ID)
        {
            this->ID=ID;
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

class CSStudent
{
    public:
        CSStudent();

        CSStudent(int ID)
        {
            this->ID=ID;
        }
        int getID()
        {
            return ID;
        }
        void ShowMajor()
        {
            cout<<"I am a student majoring computer science\n";
            cout<<"My id is: " << ID << "\n";
        }
    protected:
        int ID;
};

class SEStudent
{
    public:
        SEStudent();

        SEStudent(int ID)
        {
            this->ID=ID;
        }
        int getID()
        {
            return ID;
        }
        void ShowMajor()
        {
            cout<<"I am a student majoring software engineering\n";
            cout<<"My id is: " << ID << "\n";
        }
    protected:
        int ID;

};

int main()
{
    //Student::ShowMajor();
    CSStudent CSA(25);
    CSA.ShowMajor();
    SEStudent SEB(22);
    SEB.ShowMajor();
}