# A Study on System Calls

## Flow of a System Call

- In **usys.S**:
  - Inside `#define`:
    - It stores the value of the system call (defined in **syscall.h**) in the `eax` register;
    - It then calls the interrupt `T_SYSCALL`, which defaults to 64, defined in **traps.h**.
- In **vector.S**:
    - It contains assembly instructions for handling interrupts (especially in `vector64`) and calls the function to create a `trapframe`.
        - Trapframe: structure that holds the context of the process in user mode while the OS executes the system call, so that when the system call finishes executing the process continues the execution in user mode.
- In **trapasm.S**:
    - It creates a `trapframe` and sets the `trapno` attribute to 64, which is just the interrupt code `T_SYSCALL`;
    - It calls the trap function, in **trap.c**, which takes as a parameter a `trapframe`.
- In **trap.C**:
    - It checks whether the `trapno` attribute of trapframe is the same number as the syscall(64) interrupt;
    - If so, it checks before and after whether the process has died (if yes, do `exit`). If not, it saves the trapframe in the process and then calls the syscall function from **syscall.c**.
- In **syscall.C**:
    - In `static int (* syscalls []) (void)`, it creates an array of pointers to system calls where the reference/index is its number declared in **syscall.h**.
    - In the syscall function, it takes the eax register value that contains the stored system call number and calls the function as it is defined in **sysproc.C**.
- In **sysproc.C**:
    - The functions are being defined (respecting the “syscall.c interface”), where the parameters are required and the function is properly called, being implemented in **proc.c**.


<!-- AQUI AINDA ESTÁ EM PORTUGUÊS 


Como criar uma System Call
No arquivo syscall.h adicione uma linha seguindo o template:
#define SYS_seuComando
No arquivo defs.h, onde tem o comentário // proc.c, coloque a assinatura da função;
Em user.h, sob o comentário // system calls, também adicione a assinatura da função;
Em proc.c, implemente sua função no final do arquivo;
Em sysproc.c, no final do arquivo:
Se o comando não tem parâmetros, adicione da seguinte forma:
int sys_meuComando(void) { return meuComando(); }
Se o comando tiver parâmetros, adicione da seguinte forma:
int sys_meuComando(void) {
 int atributo1, ... , atributoN;

 // Aqui você coloca os argumentos da sua função correlacionando com os parâmetros

 if(argint(0, &atributo1) < 0) 
   return -1;

  .....

 if(argint(N-1, &atributoN) < 0)
   return -1;
  return meuComando(atributo1,..., atributoN);
}
Em usys.S adicione o nome da sua função no molde:
SYSCALL(meuComando)
Achou que tinha acabado ?

Em syscall.c:
Coloque no bloco de declarações extern (a partir da linha 85) da seguinte forma:
extern int sys_meuComando(void)
Mais abaixo, no array syscalls (a partir da linha 111), adicione a seguinte linha no final do array:
[SYS_meuComando] sys_meuComando,
Crie um arquivo meuComando.c que irá chamar sua função:
Se não houverem parâmetros, eis uma sugestão de modelo:
#include “types.h”
#include “stat.h”
#include “user.h”
#include “fcntl.h”

int main (int argc, char *argv[]) {
	meuComando();
	exit();
}
Caso hajam parâmetros, um modelo segue adiante:
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char const *argv[]) {
  int atributo1,..., atributoN;

  if(argc < a ){ // a = Número de Argumentos = 
			 // Nome da Função+Parâmetros Dela
      exit();
  }

  atributo1Inteiro = atoi(argv[1]);
  ....
  atributoNInteiro = atoi(argv[N]);

  meuComado(atributo1, ..., atributoN);
  exit();
}
Por fim, no arquivo Makefile:
Adicione seu comando em UPROGS (a partir da linha 168) seguindo o template:
_meuComando\
Em EXTRA (a partir da linha 252) coloque meuComando.c no final da linha 254, ficando assim:
wc.c zombie.c ... meuComando.c\
Descanse e seja feliz :) -->



*And that's all folks !!!*

