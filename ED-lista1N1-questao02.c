/*
** Função: Fatorial duplo
** Autor: Nelson Túlio de Menezes Lima
** Data: 30/03/2024
*/

#include <stdio.h>

long fatorial_duplo(long n){
  long fd = n;
  for (long i=2; i < n; i+=2){
    fd *= (n - i);
  }
  return fd;
}

long fatorial(long n){
  long fd = n;
  for (long i=1; i < n; i++){
    fd *= (n - i);
  }
  return fd;
}

int main(){

  long fd[21];
  long f[21];

  for (long i=0; i < 21; i++) {
    f[i] = fatorial(i);
    fd[i] = fatorial_duplo(i);
  }

  printf("FATORIAIS DUPLOS:\n\n(n) -> fatorial duplo : fatorial\n\n");
  for (long i = 2; i <= 20; i++)
    printf("(%ld) -> %ld : %ld\n", i, fd[i], f[i]);

  return 0;
}
