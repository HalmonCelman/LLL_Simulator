#include <iostream>

extern "C" {
#include <LLL.h>
}

int main(int args, char **argv){
    if(args == 2){
        LLL_init();
        LLL_run(argv[1]);
        LLL_end();
    }else{
        std::cout<<"Give EXACTLY ONE file to simulate"<<std::endl;
        exit(0);
    }
    return 0;
}