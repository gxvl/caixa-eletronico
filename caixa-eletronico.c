#include <pthread.h>
#include <stdbool.h> // para conseguir usar o booleano do isCaixaLivre
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
bool isCaixaLivre = true;

void uso_caixa(int pessoa_id) {
  pthread_mutex_lock(&mutex);
  while (!isCaixaLivre) {
    printf("Pessoa %d está esperando para usar o caixa eletrônico.\n",
           pessoa_id);
    pthread_cond_wait(&cond, &mutex);
  }
  printf("Pessoa %d está usando o caixa eletrônico.\n", pessoa_id);
  isCaixaLivre = false;
  pthread_mutex_unlock(&mutex);
}

void espera_na_fila(int pessoa_id) {
  pthread_mutex_lock(&mutex);
  printf("Pessoa %d está esperando na fila.\n", pessoa_id);
  pthread_mutex_unlock(&mutex);
}

void *simula_fila(void *arg) {
  int pessoa_id = *((int *)arg);
  espera_na_fila(pessoa_id);
  uso_caixa(pessoa_id);
  // simulando tempo de uso do caixa
  sleep(2);
  pthread_mutex_lock(&mutex);
  isCaixaLivre = true; // liberando o caixa
  pthread_cond_broadcast(
      &cond); // notificando todas as threads que estavam esperando
  pthread_mutex_unlock(&mutex);
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[5]; // suponha que temos 5 pessoas na fila
  int i;
  int ids[5]; // id's individuais de cada user

  // inicializando os id's
  for (i = 0; i < 5; i++) {
    ids[i] = i + 1;
  }

  // criando as threads das pessoas da fila
  for (i = 0; i < 5; i++) {
    pthread_create(&threads[i], NULL, simula_fila, &ids[i]);
  }

  // aguardando as threads terminarem
  for (i = 0; i < 5; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
