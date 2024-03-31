/*
** Função: Número Automórfico.
** Autor: Nelson Túlio de Menezes Lima
** Data: 30/03/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool eh_automorfico(long n){
  long qtDigitos=1;
  for (; qtDigitos <= n; qtDigitos*=10);

  return ((n * n) % qtDigitos == n) ? true : false ;
}

int main(){
  long n;
  scanf("%ld", &n);

  long* automorficos = (long *)malloc(n * sizeof(long));

  int c=0;
  for (long i=2; i < n; i++){
    if (eh_automorfico(i)) {
      automorficos[c] = i;
      c++;
    }
  }
  automorficos[c] = -1;

  for (int i=0; automorficos[i] != -1; i++) printf("%ld ", automorficos[i]);

  return 0;
}
