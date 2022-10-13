/*
 ============================================================================
 Name        : Juan Cruz Furega
 Div		 : 'B'
 ============================================================================
 */

#include "CargaDatos.h"
#include "Estructuras.h"

int main(void)
{
	setbuf(stdout, NULL);

	long recaudacion[5];
	int opcionUsuario;
	int opcionSubMenu;
	int banderaCarga = 0;

	for(int i = 0; i < 5; i++) //BUCLE PARA GENERAR LO RECAUDADO POR CADA PELICULA
	{
		recaudacion[i] = GenerarNumeroAleatorio(150000000, 750000000);
	}

	ePelicula listaPeliculas[5] = {{1000, "Thor", 90, "Taika Waikiki", {20, 9, 2024}, recaudacion[0], 1, ALTA},
								   {1001, "Cars", 120, "Obito", {12, 10, 2024}, recaudacion[1], 2, ALTA},
								   {1002, "Interestellar 2" , 180, "Juan Furega", {13, 5, 2030}, recaudacion[2], 5, ALTA},
								   {1003, "Iron Man", 70, "Pepe", {27, 11, 2028}, recaudacion[3], 0, ALTA},
								   {1004, "Hulk", 130, "Pato", {1, 1, 2037}, recaudacion[4], 0, ALTA}};

	eActor listaActores[TAM];/* = {{100, "Juan Cruz", "Furega", "Thor", "Héroe", 100000, {15, 2, 2022}, {10, 2, 2030}, 0, OCUPADO, 1000},
								{101, "Uchiha", "Pepe", "Mate", "Héroe", 50000, {10, 11, 2021}, {1, 1, 2025}, 0, OCUPADO, 1001},
								{102, "Uzumaki", "Naruto", "Tony Stark", "Vilano", 200000, {5, 5, 2022}, {5, 5, 2030}, 0, OCUPADO, 1002}};*/

	InicializarActores(listaActores, TAM); //COMENTAR SI USO DATOS HARDCODEADOS

	do
	{
		printf("*** MARIANVEL STUDIOS *** \n\n1) Gestión de actores \n2) Gestión de películas \n3) Informes \n4) Salir\n");
		utn_getNumero(&opcionUsuario, "--> ", "ERROR: Opción inválida\n", 1, 4, 10);

		switch(opcionUsuario)
		{
			case 1:
				do
				{
					printf("1) Cargar actor \n2) Modificar actor \n3) Baja actor \n4) Salir \n");
					utn_getNumero(&opcionSubMenu, "--> ", "ERROR: Opción inválida\n", 1, 4, 10);
					switch(opcionSubMenu)
					{
						case 1:
							CargarActor(listaActores, TAM, listaPeliculas, 5);
							banderaCarga = 1;
							break;

						case 2:
							if(banderaCarga == 1)
							{
								ModificarActor(listaActores, TAM, listaPeliculas, 5);
							}
							else
							{
								printf("Primero debe ingresar datos\n");
							}
							break;

						case 3:
							if(banderaCarga == 1)
							{
								BajaActor(listaActores, TAM);
							}
							else
							{
								printf("Primero debe ingresar datos\n");
							}

							break;
					}
				}while(opcionSubMenu != 4);
			break;

			case 2:
					printf("1) Baja película \n2) Mostrar recaudación \n3) Salir \n");
					utn_getNumero(&opcionSubMenu, "--> ", "ERROR: Opción inválida\n", 1, 3, 10);
					do
					{
						switch(opcionSubMenu)
						{
							case 1:
								BajaPelicula(listaPeliculas, 5);
								break;

							case 2:
								for(int i = 0; i < 5; i++)
								{
									printf("%s recaudó: $%ld", listaPeliculas[i].titulo, recaudacion[i]);
								}
								break;
						}
					}while(opcionSubMenu != 3);
				break;

				case 3:
					do
					{
						printf("1) Listado de actores ordenados alfabéticamente por película \n2) Listado de actores ordenados por valor mensual del contrato \n"
							   "3) Premiación de actores\n4) Listado de actores que recibieron un oscar y participan en película ganadora \n"
							   "5) Listado de películas por fecha de estreno \n6) Listado de películas con personajes ordenados por rol \n"
							   "7) Listado de películas ordenadas por recaudación y duración\n8) Informe de ganancias/pérdidas por película \n9) Salir \n");
						utn_getNumero(&opcionSubMenu, "--> ", "ERROR: Opción inválida\n", 1, 9, 10);
						switch(opcionSubMenu)
						{
							case 1:
								if(banderaCarga == 1)
								{
									OrdenarPeliculasAlfabeticamente(listaPeliculas, 5);
									MostrarActoresPorPelicula(listaActores, TAM, listaPeliculas, 5);
								}
								else
								{
									printf("Primero debe ingresar datos\n");
								}

								break;

							case 2:
								if(banderaCarga == 1)
								{
									OrdenarYMostrarActoresPorContrato(listaActores, TAM);
								}
								else
								{
									printf("Primero debe ingresar datos\n");
								}
								break;

							case 3:
								if(banderaCarga == 1)
								{
									PremiarActores(listaActores, TAM);
								}
								else
								{
									printf("Primero debe ingresar datos\n");
								}
								break;

							case 4:
								if(banderaCarga == 1)
								{
									ListarGanadoresOscar(listaActores, TAM, listaPeliculas, 5);
								}
								else
								{
									printf("Primero debe ingresar datos\n");
								}
								break;

							case 5:
								ListarPeliculasPorEstreno(listaPeliculas, 5);
								break;

							case 6:
								if(banderaCarga == 1)
								{
									ListarPeliculasConPersonajesPorRol(listaActores, TAM, listaPeliculas, 5);
								}
								else
								{
									printf("Primero debe ingresar datos\n");
								}
								break;

							case 7:
								ListarPeliculasPorRecaudacionYDuracion(listaPeliculas, 5);
								break;

							case 8:
								if(banderaCarga == 1)
								{
									CalcularGananciasPelicula(listaActores, TAM, listaPeliculas, 5);
								}
								else
								{
									printf("Primero debe ingresar datos\n");
								}
								break;
						}
					}while(opcionSubMenu != 9);
				break;
		}
	}while(opcionUsuario != 4);

	return EXIT_SUCCESS;
}



