#include "menu.h"
/*
 * brief: Inicia el menú
 * */
void initMenu(void)
{
	Salon salon[SALONES_LEN];
	Arcade arcade[ARCADE_LEN];
	int option;
	int subOption;
	int contSalon = 0;
	int contArcade = 0;
	int auxCont = 0;
	int id;
	int pos;
	int val;
	char entry[63];

	puts("--------------------------------------");
	puts("BIENVENIDO AL PROGRAMA");
	puts("--------------------------------------");
	puts("");
	puts("");

	initSalon(salon, SALONES_LEN);
	initArcade(arcade, ARCADE_LEN);

	// ALTAS FORZADAS

	salonForzado(salon, SALONES_LEN, 0, 0, "SalonUno", "SalonUno", 0);
	salonForzado(salon, SALONES_LEN, 1, 1, "SalonDos", "SalonDos", 0);
	salonForzado(salon, SALONES_LEN, 2, 2, "SalonTres", "SalonTres", 0);
	contSalon += 3;

	arcadeForzado(arcade, ARCADE_LEN, 0, 0, "Arg", 0, 6, 10, 0, "Mario Bros");
	arcadeForzado(arcade, ARCADE_LEN, 1, 1, "Arg", 0, 6, 10, 0, "Pac man");
	arcadeForzado(arcade, ARCADE_LEN, 2, 2, "Arg", 0, 6, 10, 0, "CS:GO");
	arcadeForzado(arcade, ARCADE_LEN, 3, 3, "Arg", 0, 6, 10, 0, "Rocket League");
	arcadeForzado(arcade, ARCADE_LEN, 4, 4, "Arg", 0, 6, 10, 0, "Mario Bros");
	arcadeForzado(arcade, ARCADE_LEN, 5, 5, "Arg", 0, 6, 10, 0, "Mario Bros");
	arcadeForzado(arcade, ARCADE_LEN, 6, 6, "Arg", 0, 6, 10, 0, "Mario Bros");
	arcadeForzado(arcade, ARCADE_LEN, 7, 7, "Arg", 0, 6, 10, 0, "Mario Bros");
	arcadeForzado(arcade, ARCADE_LEN, 8, 8, "Arg", 0, 6, 10, 0, "Mario Bros");
	arcadeForzado(arcade, ARCADE_LEN, 9, 9, "Arg", 0, 6, 10, 1, "Mario Bros");
	arcadeForzado(arcade, ARCADE_LEN, 10, 10, "Arg", 0, 6, 10, 1, "Mario Bros");
	arcadeForzado(arcade, ARCADE_LEN, 11, 11, "Arg", 0, 6, 10, 1, "Mario Bros");
	arcadeForzado(arcade, ARCADE_LEN, 12, 12, "Arg", 0, 6, 10, 1, "Mario Bros");
	arcadeForzado(arcade, ARCADE_LEN, 13, 13, "Arg", 0, 6, 10, 1, "Mario Bros");
	arcadeForzado(arcade, ARCADE_LEN, 14, 14, "Arg", 0, 6, 10, 1, "Rocket League");
	arcadeForzado(arcade, ARCADE_LEN, 15, 15, "Arg", 0, 6, 10, 1, "Mario Bros");
	arcadeForzado(arcade, ARCADE_LEN, 16, 16, "Arg", 0, 6, 10, 1, "Mario Bros");
	arcadeForzado(arcade, ARCADE_LEN, 17, 17, "Arg", 0, 6, 10, 1, "Mario Bros");
	contArcade+=12;

	do
	{
		// Comienza menú
		puts("--------------------------------------");
		puts("1. ALTA DE SALÓN");
		puts("2. ELIMINAR SALÓN");
		puts("3. IMPRIMIR SALONES");
		puts("4. ALTA DE ARCADE");
		puts("5. EDITAR ARCADE");
		puts("6. ELIMINAR ARCADE");
		puts("7. IMRPIMIR ARCADES");
		puts("8. IMPRIMIR JUEGOS");
		puts("9. MENÚ DE INFORMES");
		puts("10. SALIR");
		puts("--------------------------------------");

		ingresoIntMinMax(&option, "Ingrese opción: ", "Número no válido. Ingrese nuevamente: ", 1, 10);
		// Cierre de menú

		switch(option)
		{
		case 1:
			if(contSalon < SALONES_LEN)
			{
				if(addSalon(salon, SALONES_LEN) != FALSE)
				{
					contSalon++;
					puts("--------------------------------------");
					puts("¡Salón agregado con éxito!");
					puts("--------------------------------------");
				}
				else
				{
					puts("--------------------------------------");
					puts("¡Algo salió mal!");
					puts("--------------------------------------");
				}
			}
			else
			{
				puts("--------------------------------------");
				puts("¡Ya no puedes agregar más salones!");
				puts("--------------------------------------");
			}
			break;
		case 2:
			if(contSalon > 0)
			{
				printSalon(salon, SALONES_LEN);
				id = ingresoInt("Ingrese el ID del salón que desea eliminar: ", "Número no válido. Ingrese nuevamente: ");
				pos = findSalonById(salon, SALONES_LEN, id);
				auxCont = deleteSalon(salon, SALONES_LEN, pos, arcade, ARCADE_LEN);

				if(auxCont != FALSE)
				{
					contSalon--;
					contArcade -= auxCont;
					puts("--------------------------------------");
					puts("¡Salón eliminado con éxito!");
					puts("--------------------------------------");
				}
				else
				{
					puts("--------------------------------------");
					puts("¡Algo salió mal!");
					puts("--------------------------------------");
				}
			}
			else
			{
				puts("--------------------------------------");
				puts("¡No hay salones que eliminar!");
				puts("--------------------------------------");
			}
			break;
		case 3:
			if(contSalon > 0)
			{
				if(printSalon(salon, SALONES_LEN) != FALSE)
				{
					puts("--------------------------------------");
					puts("¡Impresión finalizada!");
					puts("--------------------------------------");
				}
				else
				{
					puts("--------------------------------------");
					puts("¡Algo salió mal!");
					puts("--------------------------------------");
				}
			}
			else
			{
				puts("--------------------------------------");
				puts("¡No hay salones que mostrar!");
				puts("--------------------------------------");
			}
			break;
		case 4:
			if(contArcade < ARCADE_LEN && contSalon > 0)
			{
				if(addArcade(arcade, ARCADE_LEN, salon, SALONES_LEN) != FALSE)
				{
					contArcade++;
					puts("--------------------------------------");
					puts("¡Arcade agregado con éxito!");
					puts("--------------------------------------");
				}
				else
				{
					puts("--------------------------------------");
					puts("¡Algo salió mal!");
					puts("--------------------------------------");
				}
			}
			else
			{
				puts("--------------------------------------");
				puts("¡Ya no puedes agregar más arcades o no has creado un salon aún!");
				puts("--------------------------------------");
			}
			break;
		case 5:
			if(contArcade > 0 && contSalon > 0)
			{
				printArcades(arcade, ARCADE_LEN);
				id = ingresoInt("Ingrese el ID del arcade que desea modificar: ", "Número no válido. Ingrese nuevamente: ");
				pos = findArcadeByID(arcade, ARCADE_LEN, id);

				if(modifyArcade(arcade, ARCADE_LEN, pos) != FALSE)
				{
					puts("--------------------------------------");
					puts("¡Modificación realizada con éxito!");
					puts("--------------------------------------");
				}
				else
				{
					puts("--------------------------------------");
					puts("¡Algo salió mal!");
					puts("--------------------------------------");
				}
			}
			else
			{
				puts("--------------------------------------");
				puts("¡No hay arcades que modificar!");
				puts("--------------------------------------");
			}
			break;
		case 6:
			if(contArcade > 0 && contSalon > 0)
			{
				printArcades(arcade, ARCADE_LEN);
				id = ingresoInt("Ingrese el ID del arcade que desea eliminar: ", "Número no válido. Ingrese nuevamente: ");
				pos = findArcadeByID(arcade, ARCADE_LEN, id);

				if(deleteArcade(arcade, ARCADE_LEN, pos) != FALSE)
				{
					contArcade--;
					puts("--------------------------------------");
					puts("¡Arcade eliminado con éxito!");
					puts("--------------------------------------");
				}
				else
				{
					puts("--------------------------------------");
					puts("¡Algo salió mal!");
					puts("--------------------------------------");
				}
			}
			else
			{
				puts("--------------------------------------");
				puts("¡No hay arcades que eliminar!");
				puts("--------------------------------------");
			}
			break;
		case 7:
			if(contArcade > 0)
			{
				if(printArcades(arcade, ARCADE_LEN) != FALSE)
				{
					puts("--------------------------------------");
					puts("¡Fin de la impresión!");
					puts("--------------------------------------");
				}
				else
				{
					puts("--------------------------------------");
					puts("¡Algo salió mal!");
					puts("--------------------------------------");
				}
			}
			else
			{
				puts("--------------------------------------");
				puts("¡No hay arcades que imprimir!");
				puts("--------------------------------------");
			}
			break;
		case 8:
			if(contArcade > 0)
			{
				if(printGames(arcade, ARCADE_LEN) != FALSE)
				{
					puts("--------------------------------------");
					puts("¡Fin de la impresión!");
					puts("--------------------------------------");
				}
				else
				{
					puts("--------------------------------------");
					puts("¡Algo salió mal!");
					puts("--------------------------------------");
				}
			}
			else
			{
				puts("--------------------------------------");
				puts("¡No hay juegos cargados que imprimir!");
				puts("--------------------------------------");
			}
			break;
		case 9:
			if(contArcade > 0 && contSalon > 0)
			{
				puts("--------------------------------------");
				puts("1. Listar los salones con más de 4 arcades");
				puts("2. Listar los arcades para más de 2 jugadores");
				puts("3. Listar toda la información de un salón en específico ");
				puts("4. Listar todos los arcades de un salón determinado");
				puts("5. Imprimir el salón con más cantidad de arcades");
				puts("6. Imprimir el monto máximo en pesos que puede recaudar un salón");
				puts("7. ¿Cuantos arcades tiene un juego?");
				puts("8. ¿Cuantos salones completos existen?");
				puts("9. Promedio de arcades por salon");
				puts("--------------------------------------");

				ingresoIntMinMax(&subOption, "Ingrese opción: ", "Número no válido. Ingrese nuevamente: ", 1, 9);

				switch(subOption)
				{
				case 1:
					if(contSalon > 0)
					{
						if(informeCuatroArcades(salon, SALONES_LEN, arcade, ARCADE_LEN) != FALSE)
						{
							puts("--------------------------------------");
							puts("¡Impresión finalizada!");
							puts("--------------------------------------");
						}
						else
						{
							puts("--------------------------------------");
							puts("¡Algo salió mal!");
							puts("--------------------------------------");
						}
					}
					else
					{
						puts("--------------------------------------");
						puts("¡No hay salones cargados!");
						puts("--------------------------------------");
					}
					break;
				case 2:
					if(contArcade > 0)
					{
						if(arcadeDosJugadores(arcade, ARCADE_LEN, salon, SALONES_LEN) != FALSE)
						{
							puts("--------------------------------------");
							puts("¡Impresión finalizada!");
							puts("--------------------------------------");
						}
						else
						{
							puts("--------------------------------------");
							puts("¡Algo salió mal!");
							puts("--------------------------------------");
						}
					}
					else
					{
						puts("--------------------------------------");
						puts("¡No hay arcades cargados!");
						puts("--------------------------------------");
					}
					break;
				case 3:
					if(contSalon > 0)
					{
						id = ingresoInt("Ingrese el ID del salón a mostrar: ", "Número no válido. Ingrese nuevamente: ");
						pos = findSalonById(salon, SALONES_LEN, id);

						if(infoDetailSalon(salon, SALONES_LEN, arcade, ARCADE_LEN, pos) != FALSE)
						{
							puts("--------------------------------------");
							puts("¡Impresión finalizada!");
							puts("--------------------------------------");
						}
						else
						{
							puts("--------------------------------------");
							puts("¡Algo salió mal!");
							puts("--------------------------------------");
						}
					}
					else
					{
						puts("--------------------------------------");
						puts("¡No hay salones cargados!");
						puts("--------------------------------------");
					}
					break;
				case 4:
					if(contSalon > 0)
					{
						id = ingresoInt("Ingrese el ID del salón que desea informar: ", "Número no válido. Ingrese nuevamente: ");
						pos = findSalonById(salon, SALONES_LEN, id);

						if(listarArcades(arcade, ARCADE_LEN, salon, SALONES_LEN, pos) != FALSE)
						{
							puts("--------------------------------------");
							puts("¡Impresión finalizada!");
							puts("--------------------------------------");
						}
						else
						{
							puts("--------------------------------------");
							puts("¡Algo salió mal!");
							puts("--------------------------------------");
						}
					}
					else
					{
						puts("--------------------------------------");
						puts("¡No hay salones cargados!");
						puts("--------------------------------------");
					}
					break;
				case 5:
					if(contSalon > 0)
					{
						if(listarMasCantidad(arcade, ARCADE_LEN, salon, SALONES_LEN) != FALSE)
						{
							puts("--------------------------------------");
							puts("¡Impresión finalizada!");
							puts("--------------------------------------");
						}
						else
						{
							puts("--------------------------------------");
							puts("¡Algo salió mal!");
							puts("--------------------------------------");
						}
					}
					else
					{
						puts("--------------------------------------");
						puts("¡No hay salones cargados!");
						puts("--------------------------------------");
					}
					break;
				case 6:
					if(contSalon > 0)
					{
						id = ingresoInt("Ingrese el ID del salón que desea calcular: ", "Número no válido. Ingrese nuevamente: ");
						pos = findSalonById(salon, SALONES_LEN, id);
						val = ingresoInt("¿Cuanto sale cada ficha en este salon?", "Número no válido. Ingrese nuevamente: ");
						while(val < 1)
						{
							val = ingresoInt("Número no válido. Ingrese nuevamente: ", "Número no válido. Ingrese nuevamente: ");
						}

						if(calcularValor(arcade, ARCADE_LEN, pos, val) == FALSE)
						{
							puts("--------------------------------------");
							puts("¡Algo salió mal!");
							puts("--------------------------------------");
						}
					}
					else
					{
						puts("--------------------------------------");
						puts("¡No hay salones cargados!");
						puts("--------------------------------------");
					}
					break;
				case 7:
					if(contSalon > 0 && contArcade > 0)
					{

						ingresoCadena(entry, 63, "Ingrese el nombre del juego que desea buscar: ", "Error. Intente nuevamente: ");

						if(contadorJuegos(arcade, ARCADE_LEN, entry) == FALSE)
						{
							puts("--------------------------------------");
							puts("¡Algo salió mal!");
							puts("--------------------------------------");
						}
					}
					else
					{
						puts("--------------------------------------");
						puts("¡No hay salones y/o arcades cargados!");
						puts("--------------------------------------");
					}

					break;
				case 8:
					if(contSalon > 0 && contArcade > 0)
					{
						if(salonCompleto(salon, SALONES_LEN, arcade, ARCADE_LEN) != FALSE)
						{
							puts("--------------------------------------");
							puts("¡Impresión finalizada!");
							puts("--------------------------------------");
						}
						else
						{
							puts("--------------------------------------");
							puts("¡Algo salió mal!");
							puts("--------------------------------------");
						}

					}
					else
					{
						puts("--------------------------------------");
						puts("¡No hay salones y/o arcades cargados!");
						puts("--------------------------------------");
					}
					break;
				case 9:
					if(contSalon > 0 && contArcade > 0)
					{
						if(promedioSalonArcade(salon, SALONES_LEN, arcade, ARCADE_LEN) == FALSE)
						{
							puts("--------------------------------------");
							puts("¡Algo salió mal!");
							puts("--------------------------------------");
						}
					}
					else
					{
						puts("--------------------------------------");
						puts("¡No hay salones y/o arcades cargados!");
						puts("--------------------------------------");
					}
					break;
				}
			}
			else
			{
				puts("--------------------------------------");
				puts("¡No puedes acceder aquí hasta tener al menos un salón y un arcade!");
				puts("--------------------------------------");
			}
			break;
		case 10:
			puts("--------------------------------------");
			puts("Saliendo... por favor espere.");
			puts("--------------------------------------");
			break;

			}

	}while(option != 10);

	puts("");
	puts("");
	puts("--------------------------------------");
	puts("GRACIAS POR USAR EL PROGRAMA");
	puts("--------------------------------------");

}


