#include <omp.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("Ola 1 - Fora da Regiao Paralela ... \n");
    int t = omp_get_max_threads();
    printf("T = %d \n", t);

    printf("Antes primeiro if \n");
    #pragma omp parallel if (t >= 4) // Inicia um bloco paralelo condicionalmente, se o número máximo de threads for maior ou igual
    {
        int id = omp_get_thread_num();
        int nt = omp_get_num_threads();
        printf("Sou a thread %d de um total de %d \n", id, nt);
    }

    printf("Antes segundo if \n");
    #pragma omp parallel if (t < 4) //Inicia outro bloco paralelo condicionalmente, se o número máximo de threads for menor que 4
    {
        int id = omp_get_thread_num();
        int nt = omp_get_num_threads();
        printf("Sou a thread %d de um total de %d \n", id, nt);
    }


    return 0;
}