/*
 * Estructuras.c
 *
 *  Created on: 12 oct. 2022
 *      Author: Usuario
 */

//se que está mal, pero no para de tirarme error si lo separo, y sinceramente ya no se como buscarlo en google

#include "Estructuras.h"

void InicializarActores(eActor lista[], int indice)
{
	for(int i = 0; i < indice; i++)
	{
		lista[i].estado = LIBRE;
	}
}

void CargarActor(eActor lista[], int indice, ePelicula listaPelis[], int maxPelis, eRol listaRoles[])
{
	int j;

	for(int i = 0; i < indice; i++)
	{
		if(lista[i].estado == LIBRE)
		{
			lista[i].estado = OCUPADO;
			utn_getNumero(&lista[i].codigo, "Ingrese el código de actor: ", "ERROR: Ingrese un código válido\n", 0, 2147483647, 10);
			printf("Ingrese el nombre del actor: ");
			gets(lista[i].nombre);
			printf("Ingrese el apellido del actor: ");
			gets(lista[i].apellido);
			printf("Ingrese el nombre del personaje: ");
			gets(lista[i].nombre_personaje);
			printf("Lista de roles disponibles\n");
			for(int j = 0; j < 3; j++)
			{
				printf("ID: %d -> Rol: %s\n", listaRoles[j].idRol, listaRoles[j].descripcion);
			}
			utn_getNumero(&lista[i].idRol, "Ingrese el ID: ", "ERROR: Ingresaste un ID inválido\n", 1, 3, 10);
			printf("Ingrese el valor del contrato: ");
			scanf("%f", &lista[i].valor_contrato);
			while(lista[i].valor_contrato < 0)
			{
				printf("ERROR: Ingrese un valor válido: ");
				scanf("%f", &lista[i].valor_contrato);
			}
			printf("Ingrese la fecha de inicio de contrato\n");
			utn_getNumero(&lista[i].inicio_contrato.dia, "Día: ", "Ingrese una fecha válida\n", 0, 30, 10);
			utn_getNumero(&lista[i].inicio_contrato.mes, "Mes: ", "Ingrese una fecha válida\n", 0, 12, 10);
			utn_getNumero(&lista[i].inicio_contrato.anio, "Año: ", "Ingrese una fecha válida\n", 2010, 2100, 10);
			printf("Ingrese la fecha de finalización de contrato\n");
			utn_getNumero(&lista[i].fin_contrato.dia, "Día: ", "Ingrese una fecha válida\n", 0, 30, 10);
			utn_getNumero(&lista[i].fin_contrato.mes, "Mes: ", "Ingrese una fecha válida\n", 0, 12, 10);
			utn_getNumero(&lista[i].fin_contrato.anio, "Año: ", "Ingrese una fecha válida\n", 2010, 2100, 10);
			while(lista[i].inicio_contrato.anio > lista[i].fin_contrato.anio)
			{
				utn_getNumero(&lista[i].fin_contrato.anio, "Ingrese un año válido: ", "Ingrese una fecha válida\n", 2010, 2100, 10);
			}
			utn_getNumero(&lista[i].oscar, "Ingrese la cantidad de premios oscar ganados: ", "Ingrese un valor válido\n", 0, 2147483647, 10);
			printf("Lista de películas\n");
			for(j = 0; j < maxPelis; j++)
			{
				if(listaPelis[j].estado == ALTA)
				{
					printf("ID: %d -- Pelicula: %s\n", listaPelis[j].codigo, listaPelis[j].titulo);
				}
			}
			utn_getNumero(&lista[i].idPelicula, "Ingrese el ID de la película en la que trabaja el actor: ", "ERROR: Ingrese un ID válido\n", 1000, 1004, 10);
			PrimerLetraMayuscula(lista[i].nombre);
			PrimerLetraMayuscula(lista[i].apellido);
			break;
		}
	}
}

void ModificarActor(eActor lista[], int indice, ePelicula listaPelis[], int maxPelis, eRol roles[])
{
	int nuevoCodigo;

	printf("Lista de actores\n");
	for(int i = 0; i < indice; i++)
	{
		if(lista[i].estado == OCUPADO)
		{
			printf("ID: %d -- %s, %s --> %s\n", lista[i].codigo, lista[i].apellido, lista[i].nombre, lista[i].nombre_personaje);
		}
	}

	printf("Ingrese el ID a modificar: ");
	scanf("%d", &nuevoCodigo);

	for(int i = 0; i < indice; i++)
	{
		if(nuevoCodigo == lista[i].codigo)
		{
			int opcionUsuario;
			utn_getNumero(&opcionUsuario, "¿Qué desea modificar?\n1) Nombre de personaje \n2) Rol \n3) Valor de contrato \n"
										  "4) Fecha de finalización de contrato \n5) Película \nOpción: ", "ERROR: Ingrese una opción válida\n", 1, 5, 10);
			switch(opcionUsuario)
			{
				case 1:
					printf("Ingrese el nuevo nombre del personaje: ");
					gets(lista[i].nombre_personaje);
					break;

				case 2:
					printf("Lista de roles\n");
					for(int i = 0; i < 3; i++)
					{
						printf("ID: %d -> %s\n", roles[i].idRol, roles[i].descripcion);
					}
					utn_getNumero(&lista[i].idRol, "Ingrese el nuevo ID del rol: ", "ERROR: Ingrese un ID válido\n", 1, 3, 10);
					break;

				case 3:
					printf("Ingrese el nuevo valor de contrato: ");
					scanf("%f", &lista[i].valor_contrato);
					while(lista[i].valor_contrato < 0)
					{
						printf("ERROR: Ingrese el nuevo valor de contrato válido: ");
						scanf("%f", &lista[i].valor_contrato);
					}
					break;

				case 4:
					printf("Ingrese la nueva fecha de finalización de contrato\n");
					utn_getNumero(&lista[i].fin_contrato.dia, "Día: ", "Error, ingrese una fecha válida\n", 0, 30, 10);
					utn_getNumero(&lista[i].fin_contrato.mes, "Mes: ", "Error, ingrese una fecha válida\n", 0, 12, 10);
					utn_getNumero(&lista[i].fin_contrato.anio, "Año: ", "Error, ingrese una fecha válida\n", 2010, 2100, 10);
					break;

				case 5:
					printf("Lista de películas\n");
					for(int j = 0; j < maxPelis; j++)
					{
						printf("ID: %d -- Pelicula: %s\n", listaPelis[j].codigo, listaPelis[j].titulo);
					}
					printf("Ingrese el ID de la película: ");
					scanf("%d", &lista[i].idPelicula);
					while(lista[i].idPelicula != listaPelis->codigo)
					{
						printf("ERROR: Ingrese un ID válido: ");
						scanf("%d", &lista[i].idPelicula);
					}
					break;
			}
		}
	}
}

void BajaActor(eActor lista[], int indice)
{
	int nuevoCodigo;
	printf("Lista de actores\n");
	for(int i = 0; i < indice; i++)
	{
		if(lista[i].estado == OCUPADO)
		{
			printf("ID: %d -- %s, %s --> %s\n", lista[i].codigo, lista[i].apellido, lista[i].nombre, lista[i].nombre_personaje);
		}
	}

	printf("Ingrese el ID a dar de baja: ");
	scanf("%d", &nuevoCodigo);

	for(int i = 0; i < indice; i++)
	{
		if(nuevoCodigo == lista[i].codigo)
		{
			lista[i].estado = LIBRE;
		}
	}
}

void BajaPelicula(ePelicula listaPelis[], int indice)
{
	int codigoBaja;
	printf("Lista de películas\n");

	for(int i = 0; i < indice; i++)
	{
		if(listaPelis[i].estado == ALTA)
		{
			printf("ID: %d - %s\n", listaPelis[i].codigo, listaPelis[i].titulo);
		}
	}

	printf("Ingrese el ID a dar de baja: ");
	scanf("%d", &codigoBaja);

	for(int i = 0; i < indice; i++)
	{
		if(listaPelis[i].codigo == codigoBaja)
		{
			listaPelis[i].estado = BAJA;
		}
	}

}

void OrdenarPeliculasAlfabeticamente(ePelicula listaPelis[], int maxPelis)
{
	char auxiliar[50];

	for(int i = 0; i < maxPelis-1; i++)
	{
		if(listaPelis[i].estado == ALTA)
		{
			for(int j = i+1; j < maxPelis; j++)
			{
				if(strcmp(listaPelis[i].titulo, listaPelis[j].titulo) > 0) //SI CAMBIO EL SIGNO '>' POR '<' ORDENA AL REVÉS
				{
					//CADENA ACTUAL A TEMPORAL
					memcpy(auxiliar, listaPelis[i].titulo, 50);

					//ACTUAL A SIGUIENTE ELEMENTO
					memcpy(listaPelis[i].titulo, listaPelis[j].titulo, 50);

					memcpy(listaPelis[j].titulo, auxiliar, 50);
				} // IF
			} //FOR J
		}
	} // FOR I
}

void MostrarActoresPorPelicula(eActor lista[], int indice, ePelicula listaPelis[], int maxPelis, eRol roles[])
{
	for(int i = 0; i < maxPelis; i++)//PELICULAS
	{
		if(listaPelis[i].estado == ALTA)
		{
			printf("Película %s\n", listaPelis[i].titulo);
			for(int j = 0; j < indice; j++)//ACTORES
			{
				if(listaPelis[i].codigo == lista[j].idPelicula)
				{
					for(int y = 0; y < 3; y++)
					{
						if(roles[y].idRol == lista[j].idRol)
						{
							printf("%s, %s Interpreta a %s con el rol de %s. Su contrato inicio el %d/%d/%d y finaliza el %d/%d/%d. Ganó %d oscar(s)\n",
									lista[j].apellido, lista[j].nombre, lista[j].nombre_personaje, roles[y].descripcion, lista[j].inicio_contrato.dia, lista[j].inicio_contrato.mes,
									lista[j].inicio_contrato.anio, lista[j].fin_contrato.dia, lista[j].fin_contrato.mes, lista[j].fin_contrato.anio, lista[j].oscar);

						}
					}
				}
			}
		}
	}
}

void OrdenarYMostrarActoresPorContrato (eActor lista[], int indice, eRol roles[])
{
	float auxiliar;
	long gananciaTotal[TAM];

	for(int i = 0; i < indice-1; i++) //ORDENO
	{
		for(int j = i+1; j < indice; j++)
		{
			if(lista[i].valor_contrato > lista[j].valor_contrato)
			{
				auxiliar = lista[i].valor_contrato;

				lista[i].valor_contrato = lista[j].valor_contrato;

				lista[j].valor_contrato = auxiliar;
			} // IF
		} //FOR J
	} // FOR I

	for(int i = 0; i < indice; i++)//CALCULAR GANANCIA TOTAL
	{
		int anios[indice];
		int meses[indice];
		int cuentaMes = 0;
		int total[indice];

		anios[i] = (lista[i].fin_contrato.anio - lista[i].inicio_contrato.anio) * 12; //RESTA DE AÑOS Y MULTIPLICACION POR C/MESES
		meses[i] = lista[i].inicio_contrato.mes;
		while(meses[i] != lista[i].fin_contrato.mes) //CALCULO LA CANTIDAD DE MESES DEL AÑO QUE RESTE ANTES
		{
			cuentaMes++;
			meses[i]++;

			if(meses[i] == 12)
			{
				meses[i] = 0;
			}
		}

		total[i] = anios[i] + cuentaMes;

		gananciaTotal[i] = lista[i].valor_contrato * total[i];
	}


	for(int i = 0; i < indice; i++)//MOSTRAR
	{
		for(int j = 0; j < 3; j++)//ROLES
		{
			if(roles[j].idRol == lista[i].idRol)
			{
				printf("%s, %s con el rol de %s posee un sueldo de $%.2f ganará al finalizar el contrato $%ld\n", lista[i].apellido, lista[i].nombre, roles[j].descripcion, lista[i].valor_contrato, gananciaTotal[i]);
			}
		}
	}

}

void ListarGanadoresOscar(eActor lista[], int indice, ePelicula listaPelis[], int maxPelis, eRol roles[])
{
	for(int i = 0; i < indice; i++)//RECORRO ACTORES
	{
		for(int j = 0; j < maxPelis; j++)//RECORRO PELIS
		{
			if(listaPelis[i].estado == ALTA)
			{
				if(lista[i].oscar > 0 && lista[j].oscar > 0)
				{
					for(int y = 0; y < 3; y++)
					{
						if(roles[y].idRol == lista[i].idRol)
						{
							printf("El actor %s, %s ¡ha ganado %d oscar(s) y participó de una película ganadora!\n", lista[i].apellido, lista[i].nombre, lista[i].oscar);
							break;
						}
					}
				}
			}
		}
	}
}

void ListarPeliculasPorEstreno(ePelicula listaPelis[], int maxPelis)
{
	ePelicula auxiliar[maxPelis];

	for(int i = 0; i < maxPelis-1; i++)
	{
		for(int j = i+1; j < maxPelis; j++)
		{
			if(listaPelis[i].estreno.anio > listaPelis[j].estreno.anio)
			{
				if(listaPelis[i].estreno.anio == listaPelis[j].estreno.anio)
				{
					if(listaPelis[i].estreno.mes > listaPelis[j].estreno.mes)
					{
						auxiliar[i].estreno = listaPelis[i].estreno;

						listaPelis[i].estreno = listaPelis[j].estreno;

						listaPelis[j].estreno = auxiliar[i].estreno;
					}
				}

				auxiliar[i].estreno = listaPelis[i].estreno;

				listaPelis[i].estreno = listaPelis[j].estreno;

				listaPelis[j].estreno = auxiliar[i].estreno;

			} // IF
		} //FOR J
	} // FOR I

	for(int i = 0; i < maxPelis; i++)
	{
		if(listaPelis[i].estado == ALTA)
		{
			printf("%s, estrenada en %d/%d/%d\n", listaPelis[i].titulo, listaPelis[i].estreno.dia, listaPelis[i].estreno.mes, listaPelis[i].estreno.anio);
		}
	}
}

void ListarPeliculasConPersonajesPorRol(eActor lista[], int indice, ePelicula listaPelis[], int maxPelis, eRol roles[])
{
	int auxiliar;

	for(int i = 0; i < indice-1; i++)
	{
		for(int j = i+1; j < indice; j++)
		{
			if(lista[i].idRol > lista[j].idRol)
			{
				auxiliar = lista[i].idRol;

				lista[i].idRol = lista[j].idRol;

				lista[j].idRol = auxiliar;
			} // IF
		} //FOR J
	} // FOR I

	for(int i = 0; i < maxPelis; i++)//RECORRO PELIS
	{
		if(listaPelis[i].estado == ALTA)
		{
			printf("Película: %s\n", listaPelis[i].titulo);
			for(int j = 0; j < indice; j++)//RECORRO ACTORES
			{
				if(listaPelis[i].codigo == lista[j].idPelicula)
				{
					for(int y = 0; y < 3; y++)//RECORRO ROLES
					{
						if(lista[j].idRol == roles[y].idRol)
						{
							printf("Rol: %s, Personaje: %s\n", roles[y].descripcion, lista[j].nombre_personaje);
						}
					}
				}
			}
		}
	}
}

void ListarPeliculasPorRecaudacionYDuracion(ePelicula listaPelis[], int maxPelis)
{

	ePelicula auxiliar[maxPelis];

	for(int i = 0; i < maxPelis-1; i++)
	{
		if(listaPelis[i].estado == ALTA)
		{
			for(int j = i+1; j < maxPelis; j++)
			{
				if(listaPelis[i].recaudacion > listaPelis[j].recaudacion)
				{
					if(listaPelis[i].recaudacion == listaPelis[j].recaudacion)  //SOLO SI SON IGUALES
					{
						if(listaPelis[i].duracion > listaPelis[j].duracion)
						{
							auxiliar[i].duracion = listaPelis[i].duracion;

							listaPelis[i].duracion = listaPelis[j].duracion;

							listaPelis[j].duracion = auxiliar[i].duracion;
						}
					}
					auxiliar[i].recaudacion = listaPelis[i].recaudacion;

					listaPelis[i].recaudacion = listaPelis[j].recaudacion;

					listaPelis[j].recaudacion = auxiliar[i].recaudacion;
				} // IF
			} //FOR J
		} // FOR I
	}

	for(int i = 0; i < maxPelis; i++)
	{
		if(listaPelis[i].estado == ALTA)
		{
			printf("Película %s, recaudó $%ld y dura %d minutos\n", listaPelis[i].titulo, listaPelis[i].recaudacion, listaPelis[i].duracion);
		}
	}
}

void CalcularGananciasPelicula(eActor lista[], int indice, ePelicula listaPelis[], int maxPelis)
{
	long gananciaActor[TAM];
	long gananciaPelicula[maxPelis];

	for(int i = 0; i < indice; i++)//CALCULAR GANANCIA TOTAL
	{
		int anios;
		int meses;
		int cuentaMes = 0;
		int total;

		anios = (lista[i].fin_contrato.anio - lista[i].inicio_contrato.anio - 1) * 12; //RESTA DE AÑOS Y MULTIPLICACION POR C/MESES
		meses = lista[i].inicio_contrato.mes;
		while(meses != lista[i].fin_contrato.mes) //CALCULO LA CANTIDAD DE MESES DEL AÑO QUE RESTE ANTES
		{
			cuentaMes++;
			meses++;

			if(meses == 12)
			{
				meses = 0;
			}
		}

		total = anios + cuentaMes;

		gananciaActor[i] = lista[i].valor_contrato * total;
	}

	for(int i = 0; i < maxPelis; i++)//PELIS
	{
		if(listaPelis[i].estado == ALTA)
		{
			for(int j = 0; j < indice; j++)//ACTORES
			{
				if(listaPelis[i].codigo == lista[j].idPelicula)
				{
					gananciaPelicula[i] = listaPelis[i].recaudacion - gananciaActor[j];
				}
			}

			if(gananciaPelicula[i] > 0)
			{
				printf("La película %s ganó $%ld\n", listaPelis[i].titulo, gananciaPelicula[i]);
			}
			else
			{
				printf("La película %s perdió $%ld\n", listaPelis[i].titulo, gananciaPelicula[i]);
			}
		}
	}
}

void PremiarActores(eActor lista[], int indice)
{
	int numeroAleatorio[5];

	for(int i = 0; i < 5; i++)
	{
		numeroAleatorio[i] =  GenerarNumeroAleatorio(0, TAM);
	}

	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < TAM; j++)
		{
			if(numeroAleatorio[i] == j && lista[j].oscar == 0)
			{
				printf("¡Enhorabuena! %s, %s ha ganado un premio\n", lista[j].apellido, lista[j].nombre);
				lista[j].oscar++;
			}
		}
	}
}
