/*
 *	Calculator
 */

#include <stdio.h>

#include "calculator.h"

int main()
{
   int a = 6;
   int b = 2;

   printf("\x0C"); // clear screen (12)

   printf("Introduce el numero a:");
   scanf("%d", &a);
   printf("\n\nIntroduce el numero b:");
   scanf("%d", &b);

   printf("\n\nLa suma de %d + %d es %d\n", a, b, add(a, b));
   printf("La resta de %d - %d es %d\n", a, b, minus(a, b));
   printf("La multiplicacion de %d * %d es %d\n", a, b, multiply(a, b));
   printf("La division de %d / %d es %d\n",a, b, divide(a, b));

   return 0;
}
