/*
 * Estructuras.h
 *
 *  Created on: 12 oct. 2022
 *      Author: Usuario
 */

#ifndef ESTRUCTURAS_H_
#define ESTRUCTURAS_H_

#include "CargaDatos.h"

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
	int codigo;
	char nombre[51];
	char apellido[51];
	char nombre_personaje[51];
	char rol[15];
	float valor_contrato;
	eFecha inicio_contrato;
	eFecha fin_contrato;
	int oscar;
	int estado;
	int idPelicula;
}eActor;

typedef struct
{
	int codigo; //IDPELICULA
	char titulo[51];
	int duracion; //MINUTOS
	char director[51];
	eFecha estreno;
	long recaudacion;
	int oscar;
	int estado;
}ePelicula;

#define ALTA 1
#define BAJA 0

void InicializarActores(eActor lista[], int indice);
void CargarActor(eActor lista[], int indice, ePelicula listaPelis[], int maxPelis);
void ModificarActor(eActor lista[], int indice, ePelicula listaPelis[], int maxPelis);
void BajaActor(eActor lista[], int indice);
void BajaPelicula(ePelicula listaPelis[], int indice);
void OrdenarPeliculasAlfabeticamente(ePelicula listaPelis[], int maxPelis);
void MostrarActoresPorPelicula(eActor lista[], int indice, ePelicula listaPelis[], int maxPelis);
void OrdenarYMostrarActoresPorContrato (eActor lista[], int indice);
void PremiarActores(eActor lista[], int indice);
void ListarGanadoresOscar(eActor lista[], int indice, ePelicula listaPelis[], int maxPelis);
void ListarPeliculasPorEstreno(ePelicula listaPelis[], int maxPelis);
void ListarPeliculasConPersonajesPorRol(eActor lista[], int indice, ePelicula listaPelis[], int maxPelis);
void ListarPeliculasPorRecaudacionYDuracion(ePelicula listaPelis[], int maxPelis);
void CalcularGananciasPelicula(eActor lista[], int indice, ePelicula listaPelis[], int maxPelis);

#endif /* ESTRUCTURAS_H_ */
