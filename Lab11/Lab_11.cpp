#include <iostream>

 int foo(int var1){
        int var3 = var1;
        asm("movl $20, -0x4(%rbp)");
        return var3;
    }

int main(){

    int x = 9;
    int y =x*30;
    int var = foo(x);
    std::cout<<var<<std::endl;
    return 0;
}