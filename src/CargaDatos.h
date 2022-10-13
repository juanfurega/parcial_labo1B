/*
 * CargaDatos.h
 *
 *  Created on: 10 oct. 2022
 *      Author: Usuario
 */

#ifndef CARGADATOS_H_
#define CARGADATOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define LIBRE 0
#define OCUPADO 1
#define TAM 5

int esNumerico(char str[]);
int esTelefono(char str[]);
int esAlfaNumerico(char str[]);
int esSoloLetras(char str[]);
void PrimerLetraMayuscula(char* palabra);
int myGets(char* cadena, int longitud);
int getInt(int* pResultado);
int esNumerica(char* cadena);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
long GenerarNumeroAleatorio (long min, long max);

#endif /* CARGADATOS_H_ */
