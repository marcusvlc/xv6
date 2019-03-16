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
        if(id < 0){
            //printf(1, "%d falhou no fork!\n", getpid());
        } else if(id > 0){ // pai
            //printf(1, "Pai %d criou o filho %d \n", getpid(), id);
            printf(1, "----------------------- \n");
            cps();
            wait();
        } else { // filho
            //printf(1, "Filho %d criado \n", getpid());
            printf(1, "----------------------- \n");
            cps();
            for(z = 0; z < 8000000.0; z+=d){      // Cálculo pra consumir tempo (sleep)
                x = x * 3.14 * 89.64; 
            }
            break;
        }
    }

    exit(); 




  /*double result = 0;
  int id = fork();
  if(id == 5) {
    printf(1, "FILHAO COMECOU !\n");  
    for(int i = 0; i < 8000000; i++){ // Cálculo pra consumir tempo (sleep)
      result = i * 3.14654561541618 * 89.64495158116156568; 
    }
    printf(1, "FILHAO TERMINOU !\n");  
  } else {
    printf(1, "PAIZAO COMECOU !\n");  
    //for(int i = 0; i < 800000000000000; i++){ // Cálculo pra consumir tempo (sleep)
    //  result = i * 3.14 * 89.64; 
    }
    wait();
    printf(1, "PAIZAO TERMINOU !\n");  
  }
  return result; 
  
  exit(); */




}
