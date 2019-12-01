# Priority Scheduler

Since processes have priorities ranging from 0 to 31 (0 being the highest priority) we will divide the processes into 3 classes: class 0, which covers processes whose priority goes from 0 to 7, class 1, where the priority goes from 8 15 and class 2, with priority ranging from 16 to 31.

Once divided into classes, we will generate a random number between 0 and 99, which will be used to map to one of the classes. Such mapping will be done as follows: if the random number is between 0 and 49, class 0 will be chosen; if it is between 50 and 84, class 1 will be chosen; and between 85 and 99, class 2 will be chosen. Thus, we chose the first _RUNNABLE_ process of that class and put it to run (**Round-Robin** within the classes).

## Prioritizing Processes That are no Longer Blocked

The _initPriority_ attribute has been added to the process which, as well as the priority, when process is created has the value 31. When the priority value is modified through _setPriority_, _initPriority_ is also modified.

When the process is blocked, the priority is changed to 0, so that it gets top priority and is more likely to be escalated. When the process is scheduled, it is checked that _initPriority_ and _priority_ are the same. If not, _initPriority_ is set to the priority value

## Conclusions:

The mapping was done this way to ensure that class 0 is chosen more often, followed by class 1 and finally class 2. This way we guarantee the favoring of the processes with higher priority and, by using a probabilistic algorithm, we guarantee no occurrence. from **starvation**.
