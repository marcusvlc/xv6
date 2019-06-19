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
            int count = 0;
            int i = 0;
           for(i = 1; i <= 9999999999;i++){

            count = (count * 238741225925952989 + 9823444724)%3768232368993;

         }


            cps();
            exit();
        } else {
            setpriority(id, k);
        }       
    }

    while (wait() != -1);

    cps();    

    int endTicks = uptime();

    //float seconds = (float)(endTicks - startTicks)/100;

    printf(1, "\n Start ticks: %d Endticks: %d \n", startTicks, endTicks);

    exit(); 

}
