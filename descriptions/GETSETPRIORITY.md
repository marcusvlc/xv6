<!-- Task 03 - Implementar getpriority e setpriority

Passos seguidos:

Entrar no proc.h, que tem as propriedades dos processos, tais como nome e pid, e adicionar a propriedade prioridade. Decidi que a prioridade de um processo deve variar entre 0 e 10, por motivos de: foi o que veio na minha cabeça e fez mais sentido. E, no caso, quanto menor o valor, maior a prioridade;
Ainda em proc.c, deve-se modificar a função allocproc, pois o papel dela é alocar recursos para um novo processo e precisamos alocar a prioridade, que não havia antes. A prioridade padrão é 10, ou seja, a menor prioridade possível;
Entrar em proc.c, que tem as funções que podem ser aplicadas a esses processos. Para facilitar nossa vida e a visualização dos processos em execução, é bom ter um comando ps;
Após adicionar o comando ps nas system calls, foi adicionado o getpriority, que consiste basicamente em varrer a tabela de processos atrás do processo desejado e retornar o valor da prioridade dele;
Por fim, foi feita a syscall setpriority, que consiste basicamente na mesma coisa da getpriority, porém ao encontrar o processo desejado, é atribuído o valor escolhido pelo usuário como novo valor da prioridade. 


-->