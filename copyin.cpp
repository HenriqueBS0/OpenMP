#include <cstdio>
#include <omp.h>

int global_var; // Declaração global

#pragma omp threadprivate(global_var) // Marca global_var como threadprivate

// A cláusula copyin é usada para inicializar variáveis threadprivate a partir dos valores das 
// variáveis globais correspondentes antes do início da execução de uma região paralela. 
// Esta cláusula é útil quando você deseja que cada thread tenha uma cópia inicializada de uma variável.

int main() {
    global_var = 100; // Inicialização da variável global
    
    #pragma omp parallel copyin(global_var)
    {
        int thread_id = omp_get_thread_num();
        printf("Thread %d vê global_var = %d\n", thread_id, global_var);
    }
    
    return 0;
}
