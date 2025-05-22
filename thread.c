#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* task(void* arg) {
    int time = *(int*)arg;
    sleep(time);
    printf("Поток работал %d секунд\n", time);
    free(arg);
    return NULL;
}

int main() {
    pthread_t tid[5];
    int times[5];
    
    // Ввод времени
    for (int i = 0; i < 5; i++) {
        printf("Введите время для потока %d: ", i+1);
        scanf("%d", &times[i]);
    }
    
    // Создание потоков
    for (int i = 0; i < 5; i++) {
        int* arg = malloc(sizeof(int));
        *arg = times[i];
        pthread_create(&tid[i], NULL, task, arg);
    }
    
    // Ожидание завершения
    for (int i = 0; i < 5; i++) {
        pthread_join(tid[i], NULL);
    }
    
    printf("Все потоки завершены!\n");
    return 0;
}
