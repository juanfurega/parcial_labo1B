/*
 * CargaDatos.c
 *
 *  Created on: 10 oct. 2022
 *      Author: Usuario
 */

#include "CargaDatos.h"

/// @brief Genera un número aleatorio entre un minimo y un maximo
///
/// @param min Número mínimo
/// @param max Número máximo
/// @return devuelve el número aleatorio

long GenerarNumeroAleatorio (long min, long max)
{
	long numAleatorio;

	numAleatorio = min + rand() % (max - min +1);

	return numAleatorio;
}

/************************************************************************************/

/// @brief Verifica si el valor recibido es numerico
///
/// @param str Array con la cadena a ser analizada
/// @return 1 si es numerico, 0 si no lo es

int esNumerico(char str[])
{
	int i = 0;

	while(str[i] != '\0')
	{
		if(str[i] < '0' || str[i] > '9')
		{
			return 0;
		}//IF
		i++;
	}//WHILE
	return 1;
}//FUNCION

/************************************************************************************/

/// @brief Verifica si el valor recibido contiene solo letras
///
/// @param str Array con la cadena a ser analizada
/// @return 1 si contiene solo ' ' y letras, 0 si no lo es

int esSoloLetras(char str[])
{
	int i = 0;

	while(str[i] != '\0')
	{
		if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
		{
			return 0;
		}//IF
		i++;
	}//WHILE
	return 1;
}//FUNCION

/************************************************************************************/

/// @brief Verifica si el valor recibido contiene solo letras y numeros
///
/// @param str Array con la cadena a ser analizada
/// @return 1 si contiene solo espacios o letras, 0 si no lo es

int esAlfaNumerico(char str[])
{
	int i = 0;

	while(str[i] != '\0')
	{
		if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] <'0' || str[i] > '9'))
		{
			return 0;
		}//IF
		i++;
	}//WHILE
	return 1;
}//FUNCION

/************************************************************************************/

/// @brief Verifica si el valor recibido contiene solo números, y -
///
/// @param str Array con la cadena a ser analizada
/// @return 1 si contiene solo números, espacios y guión. 0 si no lo es

int esTelefono(char str[])
{
	int i = 0;
	int contadorGuiones = 0;

	while(str[i] != '\0')
	{
		if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
		{
			return 0;
		}//IF

		if(str[i] == '-')
		{
			contadorGuiones++;
		}//IF
		i++;
	}//WHILE
	if(contadorGuiones == 1)
	{
		return 1;
	}//If
	return 0;
}//FUNCION

/************************************************************************************/

/// @brief Crea una lista con los números de un vector ordenados de menor a mayor
///
/// @param numeros Array que contiene los números a ordenar
/// @param MAX Total de números que puede contener el array indicado

void OrdenarDeMenorAMayor(int numeros[], int MAX)
{
	int auxiliar;

	for(int i = 0; i < MAX-1; i++)
	{
		for(int j = i+1; j < MAX; j++)
		{
			if(numeros[i] > numeros[j])
			{
				auxiliar = numeros[i];

				numeros[i] = numeros[j];

				numeros[j] = auxiliar;
			} // IF
		} //FOR J
	} // FOR I

	for(int i = 0; i < MAX; i++)
	{
		printf("%d\n", numeros[i]);
	}

}

/************************************************************************************/
/// @brief Converte el primer 'char' de cada palabra a mayuscula, el resto, minuscula
///
/// @param palabra Puntero a la palabra a modificar

void PrimerLetraMayuscula(char* palabra)
{
	for(int primeraLetra = 1; *palabra; palabra++)
	{
		if(primeraLetra && isalpha(*palabra))
		{
			*palabra = toupper(*palabra);
			primeraLetra = 0;
		}
		else
		{
			*palabra = tolower(*palabra);
		}

		if(*palabra == ' ')
		{
			primeraLetra = 1;
		}
	}
}

/************************************************************************************/

/// @brief
///
/// @param cadena
/// @param longitud
/// @return

int myGets(char* cadena, int longitud)
{
	fflush(stdin);
	fgets(cadena, longitud, stdin);

	cadena[strlen(cadena)-1] = '\0';

	return 0;
}

/************************************************************************************/

/// @brief Converte el valor recibido a entero
///
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return 0 (Exito), -1 (Error)

int getInt(int* pResultado)
{
	int retorno = -1;
	char buffer[4096];

	if(myGets(buffer, sizeof(buffer)) == 0 && esNumerico(buffer))
	{
		retorno = 0;
		*pResultado = atoi(buffer);
	}

	return retorno;
}

/************************************************************************************/

/// @brief Verifica si la cadena ingresada es numerica
///
/// @param cadena Cadena de caracteres a ser analizada
/// @return 1 (verdadero), 0 (falso)

int esNumerica(char* cadena)
{
	int retorno = 1;
	int i = 0;

	if(cadena[0] == '-')
	{
		i = 1;
	}

	for( ; cadena[i] != '\0'; i++)
	{

		if(cadena[i] < '0' || cadena[i] > '9')
		{
			retorno = 0;
			break;
		}
	}

	return retorno;
}

/************************************************************************************/

/// @brief Función que devuelve un número, preguntando antes con un 'mensaje' o, en caso de dar error, con un 'mensajeError'
/// 	   también otorga la posibilidad de validar entre un mínimo y un máximo, con determinada cantidad de intentos
/// @param pResultado Puntero al resultado que devuelve
/// @param mensaje Cadena con un mensaje mostrado al pedir el número
/// @param mensajeError Cadena con un mensaje mostrado al cargar mal el número
/// @param minimo Valor mínimo que se es capaz de introducir
/// @param maximo Valor máximo que se es capaz de introducir
/// @param reintentos Cantidad de reintentos posibles
/// @return -1 (ERROR), 0 (EXITO)

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0)
	{
		do
		{
			printf("%s", mensaje);
			if(getInt(&buffer) == 0 && buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			reintentos--;
			printf("%s", mensajeError);
		}while(reintentos >= 0);
	}

	return retorno;
}
