#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]) {

    int k, n, id;
    double x = 0, z, d;

    if(argc < 2)
        n = 1;  // default value
    else 
        n = atoi(argv[1]); // from command line
    if(n < 0 || n > 20)
        n = 2;
    if(argc < 3)
        d = 1.0;
    else 
        d = atoi(argv[2]);
    
    x = 0;
    id = 0;
    for(k = 0; k < n; k++){
        id = fork();
        if(id > 0){ // pai
            cps();
            wait();
        } else { // filho
            cps();
            for(z = 0; z < 8000000.0; z+=d){   // Cálculo pra consumir tempo (sleep)
                x = x * 3.14 * 89.64; 
            }
            break;
        }
    }

    exit(); 

}
