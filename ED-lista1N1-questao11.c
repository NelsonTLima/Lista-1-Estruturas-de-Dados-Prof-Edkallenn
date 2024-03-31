/*
** Função: Permutação Circular.
** Autor: Nelson Túlio de Menezes Lima
** Data: 31/03/2024
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool permutacao_circular(int* arr_a, int* arr_b, int n){
  bool a = true;

  if (arr_a[0] != arr_b[n-1]) a = false;
  else for (int i=1; i < n; i++) if(arr_a[i] != arr_b[i - 1]) a = false;

  if (a == true) return true;

  // Se a for permutação em relação a b retorna direto
  // caso contrário, testa no sentido reverso.

  if (arr_b[0] != arr_a[n-1]) return false;
  else for (int i=1; i < n; i++) if(arr_b[i] != arr_a[i - 1]) return false;
  return true;

}

int main(){
  int n = 4;
  int* a = (int*)malloc(n * sizeof(int));
  int* b = (int*)malloc(n * sizeof(int));

  a[0] = 1; b[0] = 4;
  a[1] = 2; b[1] = 1;
  a[2] = 3; b[2] = 2;
  a[3] = 4; b[3] = 3;

  printf("%d\n", permutacao_circular(a, b, n));
  printf("%d\n", permutacao_circular(b, a, n));

  a[0] = 1; b[0] = 4;
  a[1] = 3; b[1] = 1;
  a[2] = 4; b[2] = 2;
  a[3] = 2; b[3] = 3;

  printf("%d\n", permutacao_circular(a, b, n));
  printf("%d\n", permutacao_circular(b, a, n));

  return 0;
}
