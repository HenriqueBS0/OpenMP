#include <cstdio>
#include <omp.h>

// A cláusula default define o comportamento padrão das variáveis que não são explicitamente listadas em outras cláusulas de dados (como private, shared, etc.). As opções para esta cláusula são:

// default(shared): todas as variáveis não listadas explicitamente em outras cláusulas são compartilhadas entre os threads.
// default(none): todas as variáveis devem ser listadas explicitamente em uma cláusula de dados; caso contrário, o compilador gera um erro.

int main() {
    int x = 10;
    
    #pragma omp parallel default(shared)
    {
        int thread_id = omp_get_thread_num();
        printf("Thread %d vê x = %d \n", thread_id, x);
    }
    
    return 0;
}