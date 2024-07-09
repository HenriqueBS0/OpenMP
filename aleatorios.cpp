#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numThreads;
    printf("Digite o número de threads que deseja usar: ");
    scanf("%d", &numThreads);

    // Verifica se o número de threads solicitado é válido
    if(numThreads <= 0) {
        printf("Número inválido de threads.\n");
        return 1; // Encerra o programa com um código de erro
    }

    // Loop para cada thread
    #pragma omp parallel num_threads(numThreads)
    {
        int threadId = omp_get_thread_num(); // Obtém o ID da thread atual
        printf("Thread %d iniciada.\n", threadId);

        // Gerar e imprimir 10 números aleatórios para cada thread
        for(int i = 0; i < 10; ++i) {
            int randomNumber = rand() % 1001; // Gera um número aleatório entre 0 e 1000
            printf("Thread %d: Número gerado: %d\n", threadId, randomNumber);
        }
    }

    return 0;
}
