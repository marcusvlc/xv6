<!-- # Lab 3: Escalonador

Como os processos tem prioridades que vão de 0 a 31 (sendo 0 a prioridade máxima) dividiremos os processos em 3 classes: classe 0, que abrange os processos cuja prioridade vai de 0 a 7, a classe 1, onde a prioridade vai de 8 a 15 e a classe 2, com prioridade que vai de 16 a 31.

Uma vez divido em classes, nós iremos gerar um número aleatório entre 0 e 99, o qual será utilizado para mapear para uma das classes. Tal mapeamento será feito da seguinte forma: se o número randomico estiver entre 0 e 49, a classe 0 será escolhida; caso esteja entre 50 e 84, a classe 1 será escolhida; e entre 85 e 99, a classe 2 será escolhida. 

O mapeamento foi feito dessa forma para garantir que a classe 0 seja escolhida com mais frequência, seguido da classe 1 e por fim a classe 2. Dessa forma garantimos o favorecimento dos processos com maior prioridade e, por utilizarmos um algoritmo probabilístico, garantimos a não ocorrência de *starvation*.











Escalonamento com prioridade:
Atribuímos um valor randômico a uma das classes (0, 1 ou 2) o qual vai determinar qual classe foi escolhida. Dessa forma, escolhemos o primeiro processo RUNNABLE daquela classe e colocamos para rodar (Round-Robin dentro das classes).
Not Starvation:
Por se tratar de um algoritmo probabilístico, sempre há a possibilidade de um processo da classe 2 ser escolhido ao invés de um processo da classe 0. 
Priorizar processos que deixaram de estar bloqueados:
Foi adicionado ao processo o atributo initPriority que, assim como o priority, quando processo é criado possui o valor 31.
Quando o valor do priority é modificado através do setPriority, o initPriority também é modificado.
Quando o processo é bloqueado, o priority é alterado para 0, de forma que ele ganha prioridade máxima, tendo maior probabilidade de ser escalonado.
Quando o processo é escalonado, é verificado se o initPriority e o priority são iguais. Caso não forem, o initPriority é setado com o valor do priority. -->
