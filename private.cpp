#include <cstdio>
#include <omp.h>

int main(int argc, char *argv[]) {
    // Variável original
    int num = 10;
    printf("Número antes dO paralelo %d \n", num);
    
    // Define que o bloco paralelo será executado com 4 threads e que num será private
    #pragma omp parallel num_threads(4) private(num)
    {

        int id = omp_get_thread_num();

        // printa num que não foi inicializado
        printf("Thread %d, num = %d \n", id, num);
        
        // Define valor para num
        num = 1;

        //printa num inicializado
        printf("Thread %d, num = %d \n", id, num);
    }

    // printa o valor da variável orifinal
    printf("Serial %d \n", num);

    return 0;
}