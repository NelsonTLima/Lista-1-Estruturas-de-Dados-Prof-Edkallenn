/*
** Função: Números felizes.
** Autor: Nelson Túlio de Menezes Lima
** Data: 31/03/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

long somarDigitosQuadrados(int numero){
  char digitos[25];
  sprintf(digitos, "%d", numero);

  long soma=0;
  for (int i=0; i < strlen(digitos); i++){
    char digito_char = digitos[i];
    long digito = digito_char - '0';
    soma += digito * digito;
  }
  return soma;
}

bool inLista(int n, int* lista){
  for (int i=0; lista[i] != 0; i++) if (lista[i] == n) return true;
  return false;
}

bool ehFeliz(int n){
  int capacity = 1;
  int* testados = (int *)calloc(capacity, sizeof(int));

  int contagem=1;
  while (!inLista(n, testados)){
    if (contagem * sizeof(int) >= capacity * sizeof(int)){
      capacity *= 2;
      testados = (int *)realloc(testados, capacity * sizeof(testados));
    }
    testados[contagem - 1] = n;
    n = somarDigitosQuadrados(n);
    if (n == 1) return true;
    contagem++;
  }
  return false;
}

int main(){
  printf("%d\n", ehFeliz(4));
  printf("%d\n", ehFeliz(19));
  return 0;
}
