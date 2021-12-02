#include <iostream>
#include <cstdlib>
#include "MyTime.h"


using namespace std;
int main()
{
    // Write down your code for Q1




    int hrA=3;
    int hrB=2;
    int MinA=20;
    int MinB=10;
    
    MyTime VcA(hrA,MinA);
    cout<<"Time for VcA is: \n";
    VcA.displayTime();
    MyTime VcB(hrB,MinB);
    cout<<"Time for VcB is: \n";
    VcB.displayTime();
    MyTime VcC;
    VcC=VcA+VcB;
    cout<<"Time for VcC is: \n";
    VcC.displayTime();
    if (VcA<VcB)
    {
        cout<<"VcA<VcB is true\n";
    }
    else
    {
        cout<<"VcA<VcB is false\n";
    }


}