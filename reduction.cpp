#include <cstdio>
#include <omp.h>

int main(int argc, char *argv[]) {
    int num = 0;
    printf("num: %d \n", num);

    // Define que o bloco será executado por 4 threads e que será executado a operação de adição sobre num
    #pragma omp parallel num_threads(4) reduction(+:num)
    {
        int id = omp_get_thread_num();
        num = id + 1;
        printf("Thread %d, num: %d \n", id, num);
    }

    // Resultado de num
    printf("num %d \n", num);
    return 0;
}