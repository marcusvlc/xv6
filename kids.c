#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "date.h"

int main(int argc, char *argv[]) {
    int startTicks = uptime();
    int k, n, id;

    if(argc < 2)
        n = 5;  // quant filhos default 
    else 
        n = atoi(argv[1]); // quant filhos linha comando

    
    
    id = 0;
    for(k = 0; k < n; k++){
        id = fork();
        if(id == 0){ // filho
            cps();
            sleep(500);
            cps();
            exit();
        } else {
            setpriority(id, k);
        }       
    }

    while (wait() != -1);

    cps();    

    int endTicks = uptime();

    int seconds = (endTicks - startTicks)/100;

    printf(1, "\n Tempo em segundos da execucao do kids: %d segundos \n", seconds);

    exit(); 

}
