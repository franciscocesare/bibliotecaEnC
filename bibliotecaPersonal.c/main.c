#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[8] ={'1','2','3','4','5','6','7','8'};
    int val = myAtoi(str);///recibe valor por puntero de la funcion str
    printf ("%d ", val); ///imprime valor de char en int
    return 0;
    return 0;
}
///funcion atoi simple, para
int myAtoi(char *str) ///devuelve valor por puntero a str
{
    int res = 0; // Inicializar el resultado

    // Recorrer los caracteres e ir actualizando el resultado
    for (int i = 0; str[i] != '\0'; ++i)
        res = res*10 + str[i] - '0';

    // return result.
    return res;
}
