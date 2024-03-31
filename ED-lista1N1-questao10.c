/*
** Função:
** Autor: Nelson Túlio de Menezes Lima
** Data: 31/03/2024
*/

#include <stdio.h>
#include <stdlib.h>

long* fibonacci(long max){
  int capacity = 2;
  long* arr = (long*)malloc(capacity * sizeof(long));

  arr[0] = 0;
  arr[1] = 1;
  int i=2;
  for (; arr[i-1] + arr[i-2] < max; i++) {
    if (i+1 >= capacity) {
      capacity *= 2;
      arr = (long*)realloc(arr, capacity * sizeof(long));
    };
    arr[i] = arr[i-1] + arr[i-2];
  }
  arr[i] = -1;
  return arr;
}

int main(){
  long* arr = fibonacci(15);
  for (int i=0; arr[i] >= -1; i++){
    printf("%ld ", arr[i]);
    if (arr[i] == -1) break;
  }
}
