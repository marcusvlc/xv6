# Implementing _getUsage_

## Step by step

- In **proc.h**:
  - The _cputimes_ attribute was created, which will be a kind of counter, keeping the information on how many times the process got the CPU.
  
- In **allocproc**:
  - The value of cputimes was set to 0 as soon as it was created as UNUSED, because although the process was created it has not yet gained the CPU.

- In **scheduler**:
  - As soon as the process is set to RUNNING, _cputimes_ is incremented.
  
 ## _getUsage_
  
 Following the procedure of creating a system call, using _ps_ to list the processes and get their _ids_, and calling _getUsage_ with the _id_ as a parameter, we get the value of _cputimes_. The id must be greater than 0 (handled in **getusage.c**). So we will know how many times the process has gained the CPU.
