<!-- 
Task 04 - Implementar getusage

Passos seguidos:

Foi criado o atributo cputimes que será uma espécie de contador, guardando a informação de quantas vezes o processo ganhou a CPU;
Em allocproc o valor de cputimes foi setado para 0 assim que ele criado como UNUSED, pois apesar do processo ter sido criado ele ainda não ganhou a CPU;
 No escalonador, assim que o processo tem seu estado setado como RUNNING, o cputimes é incrementado;
Seguindo o procedimento de criação de uma system call, ao utilizarmos o ps para listar os processos e obter seus ids, e chamarmos o getusage passando o id como parâmetro, obtemos o valor de cputimes;
O id precisa ser maior do que 0 (tratado em getusage.c).
Assim, saberemos quantas vezes o processo ganhou a CPU.


 -->
