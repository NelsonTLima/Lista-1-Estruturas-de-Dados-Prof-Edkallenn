/*
** Função: Soma de fatoriais inversos.
** Autor: Nelson Túlio de Menezes Lima
** Data: 30/03/2024
** Observações: 1 + 1/2 + 1/6 = 10/6;
*/

#include <stdio.h>

double soma_fatoriais_inversos(long n){
  double f=1;
  double soma = 0;
  for (long i=1; i <= n; i++) {
    f *= i;
    soma += 1 / f;
  }
  return soma;
}

int main(){
  printf("%lf\n", soma_fatoriais_inversos(3));
  printf("%lf\n", 10.0/6.0);
}
