/*
** Função: Números Armstrong.
** Autor: Nelson Túlio de Menezes Lima
** Data: 31/03/2024
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

unsigned long somarDigitosCubicos(unsigned numero){
  char digitos[25];
  sprintf(digitos, "%d", numero);

  unsigned long soma=0;
  for (int i=0; i < strlen(digitos); i++){
    char digito_char = digitos[i];
    int digito = digito_char - '0';
    soma += digito * digito * digito;
  }
  return soma;
}

bool ehArmstrong(unsigned n){
  return n == somarDigitosCubicos(n);
}

int main(){
  unsigned long t = 153;
  printf("Soma dos digitos de %lu é %lu, logo, %lu ",t, somarDigitosCubicos(t), t);
  if (!ehArmstrong(t)) printf("não ");
  printf("é um numero Armstrong.\n");
  return 0;
}
