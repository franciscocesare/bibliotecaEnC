#ifndef BIBLIOTECACESARE_H_INCLUDED
#define BIBLIOTECACESARE_H_INCLUDED

int utn_factorial(int numberA);

int utn_sum(int numberA, int numberB, char* msg);

int utn_substraction(int numberA, int numberB, char* msg);

int utn_multiply(int numberA, int numberB, char* msg);

float utn_division(int numberA, int numberB, char* msg, char* msgError);

int utn_getInt(int *pNum, char* msg, char* msgError);

int utn_getFloat(float *pNum, char* msg, char* msgError);

float utn_calculateAll(int numberA, int numberB);

int utn_getArrayInt(int *pNumberArray, int limit, char* msg, char* msgError);

int utn_getArrayNumberRanged(int *pNumberArray,int limit, int max, int min, char* msg, char* msgError, int tries);

int utn_getArrayFloat(float *pNumberArray,float limit, char* msg, char* msgError);

int add ( int x,int y);
int substract (int x, int y);
int multiply (int x, int y);
float divide (int x, int y);
int factorial (int a);

int dameEdad (int*edad, char*mensaje);
int dameEdadDos (int*edad, char*mensaje);
int dameEdadTres (int*edad, char*mensaje);
int pedirSumarMostrar();
int utn_getNumber (int*pNumero,int maximo,int minimo, char* msg, char*msgError,int reintentos);
int utn_getNumberValidandoCadena (int*pNumero,int maximo,int minimo, char* msg, char*msgError,int reintentos);



#endif // BIBLIOTECA_H_INCLUDED
