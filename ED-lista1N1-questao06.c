/*
** Função: Numero de Carmichael
** Autor: Nelson Túlio de Menezes Lima
** Data: 31/03/2024
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int min(int a, int b){
  if (a < b) return a;
  return b;
}

int gcd(int a, int b)
{
  int result = min(a, b);
  while (result > 0) {
    if (a % result == 0 && b % result == 0) {
      break;
    }
    result--;
  }
  return result;
}

bool coprimos(int a, int b){
  return gcd(a, b) == 1;
}

int exp_modular(int a, int b, int n) {
  int result = 1;
  a = a % n;
  while (b > 0) {
    if (b % 2 == 1) {
      result = (result * a) % n;
    }
    b = b >> 1;
    a = (a * a) % n;
  }
  return result;
}

bool eh_carmichael(long n){
  for (long a=2; a < n; a++){
    pw = pow(a,n);
    if (coprimos(a, n) && exp_modular(a, n-1, n) != 1) return false;
  }
  return true;
}

int main(){
  printf("%d\n", eh_carmichael(561));
  printf("%d\n", eh_carmichael(10));
}
