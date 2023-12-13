extern "C" {
#include <LLL.h>
}

int main(int args, char **argv){
    LLL_init();
    LLL_run(argv[1]);

    return 0;
}