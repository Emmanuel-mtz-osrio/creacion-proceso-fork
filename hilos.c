#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* imprimir_descendente(void* arg) {
    for (int i = 10000; i >= 1; i--) {
        printf("Hilo: %d\n", i);
    }
    return NULL;
}

int main() {
    pthread_t hilo;
    if (pthread_create(&hilo, NULL, imprimir_descendente, NULL) != 0) {
        perror("Error al crear el hilo");
        return 1;
    }
    for (int i = 1; i <= 10000; i++) {
        printf("Principal: %d\n", i);
    }
    if (pthread_join(hilo, NULL) != 0) {
        perror("Error al unir el hilo");
        return 1;
    }
    return 0;
}
