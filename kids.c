#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]) {
    int k, n, id;

    if(argc < 2)
        n = 1;  // quant filhos default 
    else 
        n = atoi(argv[1]); // quant filhos linha comando
    
    if(n < 0 || n > 20) // validar quant filhos
        n = 1;
    
    id = 0;
    for(k = 0; k < n; k++){
        id = fork();
        if(id == 0){ // filho
            cps();
            sleep(500);
            cps();
            exit();
        }        
    }

    while (wait() != -1);

    cps();    

    exit(); 

}
