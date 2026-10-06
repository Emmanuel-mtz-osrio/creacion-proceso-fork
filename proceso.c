#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // fork() crea el proceso hijo (la invocación)
    int pid_kon = fork();

    if (pid_kon == -1) {
        printf("Fallo en el contrato (Error al crear proceso)\n");
        return 1;
    }

    if (pid_kon == 0) {
        // Bloque del hijo: Imprime del 10,000 al 1
        for (int i = 10000; i >= 1; i--) {
            printf("Demonio Zorro [Hijo] atacando: %d\n", i);
        }
    } else {
        // Bloque del padre: Imprime del 1 al 10,000
        for (int i = 1; i <= 10000; i++) {
            printf("Aki Hayakawa [Padre] preparando ataque: %d\n", i);
        }
        wait(NULL); // Esperar a que la invocación termine
    }

    return 0;
}
