/*
** Função: Soma de divisores amigáveis.
** Autor: Nelson Túlio de Menezes Lima
** Data: 30/03/2024
**
** Observação: não ficou claro o ultimo parágrafo de questão.
** Ele quer que eu encontre todos os amigáveis até o numero
** fornecido pelo usuário? Ou quer que faça a verificação em
** todos os pares de (1,2) até (n-1, n)?
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


struct Pair{
  long x;
  long y;
};

typedef struct Pair Pair;

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

void printDivisors(long* divisors){
  for (int i=0; divisors[i] != -1; i++) printf("%ld ", divisors[i]);
}

long divisorsSum(long* divisorsArray){
  long sum=0;
  for(int i=0; divisorsArray[i] != -1; i++){
    sum += divisorsArray[i];
  }
  return sum;
}

bool isFriendly(long x, long y){
  long* x_divisors = getDivisors(x);
  long* y_divisors = getDivisors(y);

  long sum_x = divisorsSum(x_divisors);
  long sum_y = divisorsSum(y_divisors);

  printf("(%ld) - ", x);
  printDivisors(x_divisors);
  printf("-> %ld\n", sum_x);
  printf("(%ld) - ", y);
  printDivisors(y_divisors);
  printf("-> %ld\n", sum_y);

  if (sum_x == y && sum_y == x) {
    printf("São amigáveis.\n");
    return true;
  }
  else {
    printf("Não São amigáveis.\n");
    return false;
  }
}

void test_friendly(long start, long end){
  Pair* friendlyPairs = (Pair*)malloc(10 * sizeof(Pair));

  int c=0;
  for (long i=start; i < end; i++){
    if (i==start) printf("\n(n) - divisores -> soma\n");
    for (long j=i+1; j <= end; j++){
      if (isFriendly(i, j)) {
        Pair p = {i, j};
        friendlyPairs[c] = p;
        c++;
        if (c * sizeof(Pair) >= sizeof(friendlyPairs))
          friendlyPairs = (Pair *)realloc(friendlyPairs, 2 * c * sizeof(Pair));
      }
    }
  }
  Pair p = {-1, -1};
  friendlyPairs[c] = p;

  if (c != 0){
    printf("\nLista de pares amigáveis:");

    for (int i=0; friendlyPairs[i].x != -1; i++){
      printf("(%ld / %ld) ", friendlyPairs[i].x, friendlyPairs[i].y);
    }
  }
  else {
    printf("\nNão foram encontrados amigáveis neste intervalo.\n");
  }
}

int main() {
  long start, end;

  printf("Digite os valores de inicio e fim:\ninicio > ");
  scanf("%ld", &start);
  printf("Digite os valores de inicio e fim:\nfim > ");
  scanf("%ld", &end);

  test_friendly(start, end);

  return 0;
}
