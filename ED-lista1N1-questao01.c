/*
** Função: Potencias fatoriais
** Autor: Nelson Túlio de Menezes Lima
** Data: 30/03/2024
*/

#include <stdio.h>

long potencia_fatorial_crescente(long x, long n){
  long rf = 1;
  for (long i=x; i < x + n; i++){
    rf *= i;
  }
  return rf;
}

long potencia_fatorial_decrescente(long x, long n){
  int df = 1;
  for (long i=x; i > x - n; i--){
    df *= i;
  }
  return df;
}

int main() {

  printf("POTENCIA FATORIAL CRESCENTE:\n\n(x, n) -> (resultado)\n");

  long x = 2;
  long n = 10;

  for (long i = 2; i <= 10; i++)
    printf("(%ld, %ld) -> %ld\n", x, i, potencia_fatorial_crescente(x,i));

  for (long i = 2; i <= 10; i++)
    printf("(%ld, %ld) -> %ld\n", i, n, potencia_fatorial_crescente(i,n));


  printf("\nPOTENCIA FATORIAL DECRESCENTE:\n\n(x, n) -> (resultado)\n");


  x = 10;
  n = 2;
  for (long i = 2; i <= 10; i++)
    printf("(%ld, %ld) -> %ld\n", x, i, potencia_fatorial_decrescente(x,i));

  for (long i = 2; i <= 10; i++)
    printf("(%ld, %ld) -> %ld\n", i, n, potencia_fatorial_decrescente(i,n));

  return 0;
}
