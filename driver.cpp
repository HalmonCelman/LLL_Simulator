#include <iostream>
#include <string>
#include <fstream>

extern "C"{
#include <LLL.h>
}

uint64_t actualPosition=0;
std::ifstream program;


uint8_t lll_init_program(char* path,uint32_t numberOfProgram){
    program.open(path,std::ios::in);
    if(!program.is_open() ){
        std::cout<<"ERROR: No such file or directory: "<<path<<std::endl;
        exit(0);
    }
    return 0;
}

uint8_t lll_end_program(void){
    program.close();
    return 0;
}

unsigned char lll_get(void){
    char c;
    program.read(&c,1);
    if(!program){
        c = LLL_EXIT;
    }
    actualPosition++;
    return c;
}

void lll_send_info(char* message, uint32_t number){
    std::cout<<"INFO: "<<message<<" : "<<(int)number<<std::endl;
}

void lll_throw_error(uint8_t error,char * message,uint8_t errnum){
    if(error){
        std::cout<<"Error: "<<message<<" : "<<(int)errnum<<std::endl;
        exit(0);
    }
}

void lll_goTo(uint64_t position){
    actualPosition = position;
    program.seekg(actualPosition);
}

uint64_t lll_getPosition(void){
    return actualPosition;
}

void lll_pushStack(uint8_t data){
    if(stack_pointer.value >= LLL_STACK_SIZE){
        std::cout<<"ERROR: STACK OVERFLOW - Exiting\n";
        exit(0);
    }
    LLL_STACK[stack_pointer.value++]=data;
}

uint8_t lll_popStack(void){
    if(stack_pointer.value){
        return LLL_STACK[--stack_pointer.value];
    }else{
        std::cout<<"ERROR: NO ELEMENTS ON STACK TO POP - Exiting\n";
        exit(0);
    }
}


lll_err lll_stream_out(uint32_t reg, uint8_t stream){
    lll_err tmpErr;
    tmpErr.status=LLL_OK;

    return tmpErr;
}

lll_err lll_stream_in(uint32_t reg, uint8_t stream){
    lll_err tmpErr;
    tmpErr.status=LLL_OK;

    return tmpErr;
}