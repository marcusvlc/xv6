# xv6: A Fundamental Linux Kernel

A xv6 developed during the discipline of Operacional Systems Project.

"xv6 is a re-implementation of Dennis Ritchie's and Ken Thompson's Unix
Version 6 (v6).  xv6 loosely follows the structure and style of v6,
but is implemented for a modern x86-based multiprocessor using ANSI C."

Excerpt from official description of xv6. To check it out in full, click [here](./descriptions/OFFICIALDESCRIPTION.md).

## Getting Started

### Prerequisites
qemu installed:
```bash
sudo apt install qemu
```
gcc installed:
```bash
sudo apt install build-essential
```
### Execution

xv6 does not run directly on your machines hardware. Instead, it runs on a virtual machine provided by the qemu hypervisor (to the honor and glory of the Lord Jesus, so we will not destroy our desktop). To compile and run xv6, simply enter the root directory of the project and type the command below:
```bash
make qemu
```
With the above command, xv6 will run on another terminal. If you prefer to run on the same terminal, use the following command:
```bash
make qemu-nox
```
Okay, you are running on Xv6. To be sure, you can list your current directory, use:
```bash
ls
```
By default you will see the commands available inside your Xv6, which will look something like:
```c
.           1 1 512
..          1 1 512
README      2 2 2327
cat         2 3 13608
echo        2 4 12616
forktest    2 5 8044
grep        2 6 15484
init        2 7 13200
kill        2 8 12672
ln          2 9 12568
ls          2 10 14752
mkdir       2 11 12752
rm          2 12 12728
sh          2 13 23216
stressfs    2 14 13400
usertests   2 15 56328
wc          2 16 14148
zombie      2 17 12392
console     3 18 0
```

To finish running xv6, if you are using make terminal mode, just close the terminal window. If you are using the second mode, type ``Ctrl + a``, then ``x``.


## Contributing
Make a pull request and make clear what changes have been made and which bugs persist. Do not introduce bugs, be proactive!

## Contributors
* **Amintas Victor** - *Initial work* and [*Get Usage*](./descriptions/GETUSAGE.md) - [GitHub](https://github.com/amintasvrp)
* **Amanda Luna** - [*A Study on System Calls*](./descriptions/SYSCALLS.md) and [*Get and Set Priority*](./descriptions/GETSETPRIORITY.md) - [GitHub](https://github.com/avdluna)
* **Marcus Vinícius** - [*Clock Interruption*](./descriptions/CLOCKINTERRUPTION.md) - [GitHub](https://github.com/marcusvlc)

 If you contributed with this project, your name will be placed here. Welcome to the hall of fame :)

## Acknowledgments
* C
* Knowledge about Operacional Systems, at least Linux
* Willingness to learn, research and develop (no laziness!)
