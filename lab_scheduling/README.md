# Lab 3: Escalonador

Como os processos tem prioridades que vão de 0 a 31 (sendo 0 a prioridade máxima) dividiremos os processos em 3 classes: classe 0, que abrange os processos cuja prioridade vai de 0 a 7, a classe 1, onde a prioridade vai de 8 a 15 e a classe 2, com prioridade que vai de 16 a 31.

Uma vez divido em classes, nós iremos gerar um número aleatório entre 0 e 99, o qual será utilizado para mapear para uma das classes. Tal mapeamento será feito da seguinte forma: se o número randomico estiver entre 0 e 49, a classe 0 será escolhida; caso esteja entre 50 e 84, a classe 1 será escolhida; e entre 85 e 99, a classe 2 será escolhida. 

O mapeamento foi feito dessa forma para garantir que a classe 0 seja escolhida com mais frequência, seguido da classe 1 e por fim a classe 2. Dessa forma garantimos o favorecimento dos processos com maior prioridade e, por utilizarmos um algoritmo probabilístico, garantimos a não ocorrência de *starvation*.
