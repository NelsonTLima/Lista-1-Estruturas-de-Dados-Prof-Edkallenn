/*
** Função: Números Perfeitos.
** Autor: Nelson Túlio de Menezes Lima
** Data: 31/03/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

long* getDivisors(long n){
  long sqr = sqrt(n);
  long* arr = (long *)malloc(sizeof(long) * sqr * 2);

  int c=0;
  for (int i=1; i <= sqr; i++){
    if (n % i == 0) {
      arr[c] = i;
      c++;
    }
  }

  for (int i=0; i < c-1; i++){
    arr[c + i] = n / arr[c-i-1];
  }
  arr[(2 * c) - 1] = -1;
  return arr;
}

long divisorsSum(long* divisorsArray){
  long sum=0;
  for(int i=0; divisorsArray[i] != -1; i++){
    sum += divisorsArray[i];
  }
  return sum;
}

bool isPerfect(long n){
  return divisorsSum(getDivisors(n)) == n;
}

int main(){
  printf("Números perfeitos entre 1 e 10 mil:\n");
  for (int i = 1; i <= 10000; i++) if (isPerfect(i)) printf("%d ", i);
  printf("\n");
}
