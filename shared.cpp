#include <cstdio>
#include <omp.h>

int main(int argc, char *argv[]) {
    // Variável original
    int num = 0;
    printf("Número antes do paralelo %d \n", num);
    
    // Define que o bloco paralelo será executado com 4 threads e que num será shared
    #pragma omp parallel num_threads(4) shared(num)
    {

        int id = omp_get_thread_num();

        // incrementa num
        num = num + 1;

        //printa num
        printf("Thread %d, num = %d \n", id, num);
    }

    // printa o valor da variável orifinal
    printf("Serial %d \n", num);

    return 0;
}