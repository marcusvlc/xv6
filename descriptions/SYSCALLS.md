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


## How to create a System Call

- In the **syscall.h** file add a line following the template:

        #define SYS_yourCommand

- In the **defs.h** file, below the comment

        // proc.c 

    put the signature of the function.

- In **user.h**, under the comment 

        // system calls 
        
    also add the function signature.

- In **proc.c**, implement your function at the end of the file.

- In **sysproc.c**, at the end of the file:
    - If the command has no parameters, add as follows:

            int sys_myCommand (void) {return myCommand (); }

    - If the command has parameters, add as follows:

            int sys_myCommand (void) {
                               
                int attribute1, ..., attributeN;

                // Here you put the arguments of your function correlating 
                // with the parameters

                if (argint (0, & attribute1) <0)
                  return -1;
                
                .....

                if (argint (N-1, & attributeN) <0)
                   return -1;
                 
                return myCommand (attribute1, ..., attributeN);
    
            }

- In **usys.S** add the name of your function in the template:
            
        SYSCALL (myCommand)


- In **syscall.c**:

    - Put in the extern declaration block (starting at line 85) as follows:

            extern int sys_myCommand (void)

    - Below, in the syscalls array (starting at line 111), add the following line to the end of the array:

            [SYS_myCommand] sys_myCommand

- Create a **myCommand.c** file that will call your function:
    - If there are no parameters, here's a model suggestion:

            #include “types.h”
            #include “stat.h”
            #include “user.h”
            #include “fcntl.h”

            int main (int argc, char * argv []) {
               myCommand ();
               exit ();
            }

    - If there are parameters, a model follows:

            #include "types.h"
            #include "stat.h"
            #include "user.h"
            #include "fcntl.h"

            int main (int argc, char const * argv []) {
              int attribute1, ..., attributeN;

              if (argc <a) {
                
              // a = Number of Arguments = Function Name + Parameters

                  exit ();
              }

              integer1 attribute = acti (argv [1]);
              
                ....

              Integer attribute = acti (argv [N]);

              myCode (attribute1, ..., attributeN);
              exit ();
            }

- Finally, in the **Makefile** file:
    - Add your command on `UPROGS` (from line 168) following the template:
        
            _myCommand\

    - In `EXTRA` (from line 252) put **myCommand.c** at the end of line 254, like this:

            wc.c zombie.c ... myCommand.c\




  *And that's all folks !!!*
  