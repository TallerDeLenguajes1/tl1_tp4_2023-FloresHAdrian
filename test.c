#include<stdio.h>

int main(int argc, double * argv[])
{
  double doble;
  double * p = &doble, *q;
  int i;
  unsigned long base;
  printf("La dirección de doble es           %u\n", (unsigned int)p);
  q = p + 1;
  printf("La dirección dada por q = p + 1 es %u\n", (unsigned int)q);
  q = p + 2;
  printf("La dirección dada por q = p + 2 es %u\n", (unsigned int)q);
  q = p + 3;
  printf("La dirección dada por q = p + 3 es %u\n", (unsigned int)q);
  q = p + 4;
  printf("La dirección dada por q = p + 4 es %u\n", (unsigned int)q);
  printf("Escriba el valor de i: ");
  scanf("%d", &i);
  q = p + i;
  printf("q = p + %d vale                     %u\n", i, (unsigned int)q);
  base = (unsigned long)p;
  printf("El valor calculado es: %u\n",base + i*sizeof(double));
  return 0;
}