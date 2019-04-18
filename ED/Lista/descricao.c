#include <stdio.h>
#include <stdlib.h>



int main(){
Uma estrutura do tipo "Lista" é uma sequência
de elementos do mesmo tipo. Seus elementos
possuem estrutura interna abstraída, ou seja,
 sua complexidade é arbitrária e não afeta seu funcionamento


Uma Lista pode possuir N ( N >= 0) elementos.
Se N = 0, dizemos que a "Lista" está vazia

Aplicações:
- Cadastro de funcionários
- Itens em estoque
- Cartas do baralho
- pasme, mas geralmente usamos essa estrutura para documentar dados que podem ser dispostos numa...LISTA! é mole?

Numa Lista podemos realizar as seguintes operações básicas:
-Criação da lista
-Inserção de elementos 
-exclusão de elementos
-acesso a elementos
-destruição da lista

essas operações dependem do tipo de memória usada 
-estática
-dinâmica

---ESTÁTICA---(vetor)

-O espaço de memória é alocada no momento da compilação
- exige a definição do numero máximo de elementos da lista 
- acesso sequencial: elementos são consecutivos na memória


---Alocação Dinâmica---
-O espaço de memoria é alocada no momento de execução
- a lista cresce a medida que novos elementos são armazenados
- consequentemente, diminui a medida que os elementos são removidos
-acesso encadeado: diferente da lista estatica, os elementos podem ser alocados em locais
diferentes da memória, o que nos permite interligar os elementos é o encadeamento de ponteiros.



    return 0;
}
