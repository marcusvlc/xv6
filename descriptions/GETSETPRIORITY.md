# Implementing _getPriority_ and _setPriority_

## Step by step

- In **proc.h**: 
  - In this file there are process properties, such as name and pid, must be added to the priority property. In this implementation, the priority of a process should range from 0 to 10, so that the lower the value, the higher the priority.
 
- In **proc.c**:
  - We need to change the _allocproc_ function, because its role is to allocate resources for a new process and we need to allocate the priority, which was not there before. The default priority is 10, which is the lowest possible priority;
  - To make our life easier and the visualization of running processes, we have the command com command ps.
  
## _getPriority_

It basically consists of scanning the process table behind the desired process and returning its priority value.

## _setPriority_

It consists of changing the priority value of the desired process, being assigned the value chosen by the user as the new priority value.
