#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaCesare.h"
#include <string.h> ///no me la reconoce???



/**
*\brief Solicita al usuario un número entre cierto rango MaxMin
*\param Puntero que guarda la dirección de memoria de la variable entera
*\param Máximo rangos
*\param Minimo
*\param Mensaje para ingresar un numero
*\param Mensaje de error si el dato ingresado no corresponde
*\return 0 si es ok, -1 si está mal
*/

int utn_getNumberRanged(int *pNumber, int max, int min, char* msg, char* msgError, int tries)
{
    int number;
    int ret = -1;

    while(tries>0)
    {
        printf("%s",msg);
        if (scanf("%d", &number)==1)///letengo que pasar la dir de memoria para que scanf lo guarde en numberporque es una funcion
        {
            if (number>min && number<max)
            {
                *pNumber = number;//el number se guarda en la posicion de memoria pNumber
                ret = 0;
                break;
                //ok
            }
        }
        printf("%s\n", msgError);
        //mal
        tries--;
    }
    return ret;
}

/**
*\brief Solicita al usuario un número entero
*\param Puntero que guarda la dirección de memoria de la variable entera
*\param Mensaje para ingresar un numero
*\param Mensaje de error si el dato ingresado no corresponde
*\return 0 si es ok, -1 si está mal
*/

int utn_getInt(int *pNum, char* msg, char* msgError)
{
    int number;
    int ret = -1;

    do
    {
        printf("%s",msg);
        if (scanf("%d", &number)==1)
        {
            *pNum=number;
            ret=0;
        }
        else
        {
            printf("%s",msgError);
        }
        fflush(stdin);
        //ffpurge/stdin);
    }
    while(ret==1);
    return ret;
}

/**
*\brief Solicita al usuario un número flotante
*\param Puntero que guarda la dirección de memoria de la variable entera
*\param Mensaje para ingresar un numero
*\param Mensaje de error si el dato ingresado no corresponde
*\return 0 si es ok, -1 si está mal
*/

int utn_getFloat(float *pNumber, char* msg, char* msgError)
{
    float number;
    int ret = -1;

    do
    {
        printf("%s",msg);
        if (scanf("%f", &number)==1)
        {
            *pNumber=number;
            ret=0;
        }
        else
        {
            printf("%s",msgError);
        }
        fflush(stdin);
        //ffpurge/stdin);
    }
    while(ret==1);
    return ret;
}

/**
*\brief Realiza el factorial de cierto número
*\param Entero ingresado
*\return Resultado de la operación
*/

int utn_factorial(int numberA)
{
    int result;

    if(numberA == 1)
    {
        return 1;
    }
    result = numberA * utn_factorial(numberA - 1);
    return result;
}

/**
*\brief Realiza la suma de dos números
*\param Entero ingresado
*\param Segundo entero ingresado
*\return Resultado de la operación
*/

int utn_sum(int numberA, int numberB, char* msg)
{
    int result;
    result = numberA+numberB;
    printf("%s%d\n",msg,result);
    return 0;
}

/**
*\brief Realiza la resta entre dos números
*\param Entero ingresado
*\param Segundo entero ingresado
*\return Resultado de la operación
*/

int utn_substraction(int numberA, int numberB, char* msg)
{
    int result;

    result = numberA-numberB;
    printf("%s%d\n",msg,result);
    return 0;
}

/**
*\brief Realiza la multiplicación entre dos números
*\param Entero ingresado
*\param Segundo entero ingresado
*\return Resultado de la operación
*/

int utn_multiply(int numberA, int numberB, char* msg)
{
    int result;

    result = numberA*numberB;
    printf("%s%d\n",msg,result);
    return 0;
}

/**
*\brief Realiza la división entre dos números
*\param Entero ingresado
*\param Segundo entero ingresado
*\param Mensaje de error si el divisor llegase a ser 0
*\return Resultado de la operación
*/

float utn_division(int numberA, int numberB, char* msg, char* msgError)
{
    float result;

    if(numberA != 0 && numberB != 0)
    {
        result = numberA/numberB;
        printf("%s%.2f\n",msg, result);
    }
    else if(numberA == 0)
    {
        result = 0;
        printf("%s%.2f\n",msg, result);
    }
    else
    {
        if(numberB == 0)
        {
            printf("%s\n", msgError);
        }
    }
    return 0;
}

float utn_calculateAll(int numberA, int numberB)
{
    utn_sum(numberA,numberB,"La suma es: ");
    utn_substraction(numberA,numberB,"La diferencia es: ");
    utn_division(numberA,numberB,"La división es: ","No se permite la división por 0");
    utn_multiply(numberA,numberB,"La multiplicación es: ");
    utn_factorial(numberA);
    return 0;
}

int utn_getArrayInt(int *pNumberArray, int limit, char* msg, char* msgError)
{
    int i;
    int ret;
    int aux;

    for(i=0; i<limit; i++)
    {
        ret = utn_getInt(&aux,"Ingrese un numero : ","Error");

        if(ret)
        {
            break;
        }
        *(pNumberArray+i) = aux;
    }

    return ret;
}
///Funcion para pedir numero con limites, recorrer el Array, guardar y guardar en el sgte Array
int utn_getArrayNumberRanged(int *pNumberArray,int limit, int max, int min, char* msg, char* msgError, int tries)
{
    int i;
    int ret;
    int aux;

    for(i=0; i<limit; i++) ///va a recorrer las posiciones del array
    {
        ret = utn_getNumberRanged(&aux, max, min, msg, msgError, tries); ///llama a la funcion GetNumberRanged=ret

        if(ret!=0)
        {
            break;
        }
        *(pNumberArray+i) = aux;///siempre guarda en una posicion mas del array de la que estoy(+i)
    }

    return ret;///pudo hacerlo retorna 0, sino -1. si es -1, sale y ya. si es 0, es=a la funcion = utn_getNumberRanged

     /**
    int main() Main para pedir numeros, el Limit,Max,Min se define arriba en DEFINE y guarda uy muestra int de la funcion GetNunmberRanged
    {
    int i;
    int numbers [LIMIT];///declara un array de X posiciones(LIMIT)que guarda enteros. el numbers es el array
    utn_getArrayNumberRanged(numbers,LIMIT,MAX,MIN,"Ingrese un numero : ","Error",3);//Numbers recibe por referencia del *Pnumero
    for(i=0; i<LIMIT; i++)///iteracion para ir guardando en el array los numeros
    {
        printf("%d\n",numbers[i]);///me muestra los numeros guardados en el array
    }


    return 0;
    }
    **/
}

int swap(int *numberA, int *numberB)
{
    int aux;
    if (numberA != NULL && numberB != NULL)
    {
        aux = *numberA;
        *numberA = *numberB;
        *numberB = aux;
    }
    return 0;
}
/** \brief realiza la suma de dos enteros ingresados
 * \param primer entero ingresado por usuario
 * \param segundo entero ingresado por usuario
 * \return resultado de la operacion suma
 */

int add (int A, int B) ///prototipo en el .C no lleva ";"
{
    int result;
    result=A+B;
    return result;
}
/** \brief realiza la resta de dos enteros ingresados
 * \param primer entero ingresado por usuario
 * \param segundo entero ingresado por usuario
 * \return resultado de la operacion resta
 */
int substract (int A, int B) ///prototipo en el .C no lleva ";"

{
    int result;
    result=A-B;
    return result;
}
/** \brief realiza la multiplicacion de dos enteros ingresados
 * \param primer entero ingresado por usuario
 * \param segundo entero ingresado por usuario
 * \return resultado de la operacion multiplicacion
 */
int multiply(int A, int B)   ///prototipo en el .C no lleva ";"
{
    int result;
    result=A*B;
    return result;
}
/** \brief realiza la division entre dos enteros ingresados
 * \param primer entero ingresado por usuario
 * \param segundo entero ingresado por usuario
 * \return resultado de la operacion division, casteado por si resultado es con decimal
 */

float divide (int A, int B)   ///prototipo en el .C no lleva ";"
{
    float result;
    result = (float) A/B;
    return result;
}
/** \brief realiza el factorial de un numero ingresado
 * \param entero ingresado por usuario
 * \param var int "b" para calcular factorial
 * \param var int fact inicializada en 1
 * \return resultado factorial del numero, lueego de un bucle For
 */
int factorial (int A)  ///prototipo en el .C no lleva ";"
{
    int b;
    int fact=1;
    for (b = A; b > 1; b--)
    {
        fact = fact * b;
    }
    return fact;
}

/** \brief pide una edad y la muestra en pantalla
 * \param edad ingresada por usuario
 * \param mensaje de pedido de edad
 * \return si se pudo lo muestra en pantalla
 *
 */
int dameEdad (int*edad, char*mensaje) ///funcion que iria en .c
{
    int aux=0;
    int sePudo=0;
    printf(mensaje);
    sePudo = scanf("%d", &aux);    ///var sePudo, si se pudo se carga con valor de aux. para ver si se pudo
    if (sePudo==1)  ///si se pudo == a 1, *edad se carga con valor de aux.
    {
        *edad=aux;
    }
    return sePudo;
}
/** \brief solicita edad, con validacion de Char
 *
 * \param edad ingresada por usuario
 * \param mensaje de pedido de edad
 * \param sePudo para ver si ingreso dato correcto
 * \return sePudo, validacion
 *
 */

int dameEdadDos (int*edad, char*mensaje) ///funcion que iria en .c
{
    char cadenaCargada[20];
    int sePudo=1;
    printf(mensaje);
    scanf("%s", cadenaCargada);    ///guardas en cadenaCargada
    *edad=atoi(cadenaCargada); ///atoi transorma int en Char

    return sePudo;
}

///funcion para pedir edad validada sin char, saber cuantos caracteres ingreso. y si edad es menor a 120
int dameEdadTres (int*edad, char*mensaje) ///funcion que iria en .c
{
    char cadenaCargada[20];
    int i;
    int aux;
    int sePudo=1;
    printf(mensaje);
    scanf("%s", cadenaCargada);

    int cantidadDeCaracteres = strlen(cadenaCargada);///funcion para saber cuantos caracteres ingreso el usuario

    for (i=0; i<cantidadDeCaracteres; i++) ///iteracion For para recorrer el array
    {
        if ((cadenaCargada[i]<'0' || cadenaCargada[i]>'9')&& cadenaCargada [i]!= '\0')
        {
            sePudo=0;
            printf("No es un dato valido %c \n", cadenaCargada[i]); ///validado, el dato char ingresado
            printf("la cantidad de caracteres es %d \n",cantidadDeCaracteres);///la cantidad de caracteres ingresadas
            break;
        }
    }
    if (sePudo==1)
    {
        aux=atoi (cadenaCargada);///cambia caracterers a int, de cadenaCargada y lo carga a aux

        if (aux<120) ///para validar la edad menos a 120
        {
            *edad=aux; ///si valido edad menos de 120, carga *edad con valor de aux
        }
    }
    else
    {
        sePudo=0;
    }
    return sePudo;
}


/*
int main() ///main usado para dameEdadTres por ejemplo
{
    int edad;
    int sePudo;

    do
    {
        sePudo=dameEdadTres(&edad, "ingrese la edad :");///igualo a sePudo para ver si dameEdad funciona

    }
    while (sePudo==0);
    printf("La edad ingresada es :%d", edad);

    /*USADO PARA dameEdadDos!
    if (sePudo == 1) ///lo igualo a 1, xq si se pudo, devuelve 1
    {
        printf("su edad es %d", edad);
    }
    else
    {
        printf("no se pudo");
    }

    return 0;
}
*/
int pedirSumarMostrar()
{
    int numeroUno;
    int numeroDos;
    int resultado;

    printf("Ingrese el primer numero\n");
    scanf("%d",&numeroUno);
    printf("Ingrese el segundo numero\n");
    scanf("%d",&numeroDos);
    resultado=numeroUno+numeroDos;
    printf("El resultado es: %d", resultado);
    return 0;
}

   /** \brief pedir numero y validarlo entre 0 y 100
     * con reintentos
     * \param numero/en caso de ser valido setea por referncia
     * \param numero maximo y minimo
     *\param msg y msg error/
     * \return resultado
     */
int utn_getNumber (int*pNumero,int maximo,int minimo, char* msg, char*msgError,int reintentos)
{
    int numero;
    int res=-1;


    while (reintentos>0)
    {
        printf("%s", msg);
        if (scanf("%d",&numero)==1)
        {
            if (numero>=minimo && numero<=maximo)
            {
                res=0;
                (*pNumero)=numero;
                break;
            }

        }
        fflush(stdin);
        printf("%s", msgError);
        reintentos --;

    }

    return res;
}

/** \brief pedir numero y validarlo entre 0 y 100
     *
     * \param numero/en caso de ser valido setea por referncia
     * \param numero maximo y minimo
     *\param msg y msg error/
     * \return resultado
     */

/*int utn_getNumberValidandoCadena (int*pNumero,int maximo,int minimo, char* msg, char*msgError,int reintentos)

{
    int numero;
    int res=-1;

    while (reintentos>0)
    {
        printf("%s", msg);
        if getInt(&numero)==1)
        {
            if (numero>=minimo && numero<=maximo)
            {
                res=0;
                (*pNumero)=numero;
                break;
            }

        }
        fflush(stdin);
        printf("%s", msgError);
        reintentos --;

    }

    return res;
} */

