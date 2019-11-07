# Implementing Clock Interruption

## Steps Taken:

1. First, it was necessary to find in the code where the interrupts were being counted, since the task explicitly asked to kill a process every “X” interrupts. To do this, we first analyze the xv6 code and find a _sys_uptime_ function in the **sysproc.c** file whose documentation said: "Returns how many interrupts have happened so far";

2. Looking at the _sys_uptime_ function, we saw that it handled and returned a ticks variable, which made it clear that this variable would be responsible for storing the number of interrupts;

3. After knowing where the interrupts were being stored, it was enough to search in the code where they were being counted (aka _ticks ++_), and we arrived at the trap function of the **trap.c** file, which inside a switch, it counted these ticks;

4. After finding the area of code that would be called every time an interrupt was being generated, we put an 'if' with a call to our _interruptProcess_ function. The reason this call is inside an 'if' is so that this function is called only when there is a need, or explicitly speaking, for every "X" tick;

5. Finally, when the _interruptProcess_ function, whose implementation is in the **proc.c** file, is called, its main action is to acquire the process table (so that no other thread gets in the way of code execution) and with that table in hand, sweeps it. it to look for the latest "killable" process. What would be a “killable” process? Simple: In xv6, there are two basic processes running, init and sh, these processes cannot be killed, otherwise the system will be affected. Since _interruptProcess_ scans the process table and finds someone other than init and sh (a.k.a process killable), it writes its pid (process id) to a temporary variable and returns the process table for use by other threads. It is important to say that if there is more than one “killable” process, the latter will be chosen to die. After having the process pid to be killed in hand, the _kill_ function (whose implementation is also in the **proc.c** file) is called, passing this pid as a parameter, and it will be in charge of killing the process. After all the interruptProcess function returns the process pid that was killed, if none is killed, returns 0.

_Note: In xv6, processes that are in the UNUSED state have _PID_ 0, and the basic system processes, init and sh, have _PID_ 1 and 2, so when scanning the process table for a killable process, only processes with _PID_ > 2 are chosen._

