#include <omp.h>
#include <stdio.h>
#include <stdlib.h> // Para rand()

int main() {
    int numThreads;
    int minValue, maxValue;
    printf("Digite o número de threads que deseja usar: ");
    scanf("%d", &numThreads);

    printf("Digite o valor mínimo para os números aleatórios: ");
    scanf("%d", &minValue);

    printf("Digite o valor máximo para os números aleatórios: ");
    scanf("%d", &maxValue);

    // Verifica se os valores mínimos e máximos são válidos
    if(minValue > maxValue || numThreads <= 0) {
        printf("Valores inválidos. MinValue deve ser menor que MaxValue e o número de threads deve ser maior que zero.\n");
        return 1; // Encerra o programa com um código de erro
    }

    int total = 0;

    // Loop para cada thread
    #pragma omp parallel num_threads(numThreads) reduction(+:total)
    {
        int threadId = omp_get_thread_num(); // Obtém o ID da thread atual
        printf("Thread %d iniciada.\n", threadId);

        // Gerar e imprimir 10 números aleatórios para cada thread
        for(int i = 0; i < 10; ++i) {
            int randomNumber = rand() % (maxValue - minValue + 1) + minValue; // Gera um número aleatório entre minValue e maxValue
            total = total + randomNumber;
            printf("Thread %d: Número gerado: %d\n", threadId, randomNumber);
        }
    }

    printf("Total: %d\n", total);

    return 0;
}
