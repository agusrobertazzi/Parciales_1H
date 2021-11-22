#include "../inc/menu.h"
/** \brief Inicializa el men�
 *
 *  \param void
 *  \return void
 */
void init_menu(void)
{

	LinkedList* list = ll_newLinkedList();
	int option;
	int index;
	int idFound;
	int flagCarga = FALSE;

	puts("-----------------------------------");
	puts("Bienvenido al programa");
	puts("-----------------------------------");
	puts("\n\n\n");

	if(list != NULL)
	{
		if(controller_addCsv("data/arcadesGenerated.csv", list) == FALSE)
		{
			puts("Hay un archivo de carga CSV esperando a ser cargado. �Desea realizar la operaci�n? 1. Si 2. No");
			ingresoIntMinMax(&option, "Opci�n: ", "Error. Ingrese nuevamente: ", 1, 2);
			if(option == 1)
			{
				if(controller_addCsv("data/arcades.csv", list) != FALSE)
				{
					controller_saveArcades("data/arcadesGenerated.csv", list);
					flagCarga = TRUE;
					puts("-----------------------------------");
					puts("Archivo cargado correctamente");
					puts("-----------------------------------");
					puts("\n\n\n");
				}
				else
				{
					puts("-----------------------------------");
					puts("No s� ha podido cargar el archivo");
					puts("-----------------------------------");
					puts("\n\n\n");
				}
			}
		}



		do
		{
			// Men�
			puts("-----------------------------------");
			puts("Men�");
			puts("1. Cargar arcades (.CSV)"); // OK
			puts("2. Agregar nuevo arcade"); // OK
			puts("3. Modificar un arcade"); // OK
			puts("4. Eliminar un arcade"); // OK
			puts("5. Ordenar e imprimir arcades por juego"); // OK
			puts("6. Guardar juegos en archivo de datos"); // OK
			puts("7. Guardar arcades Multijugador en archivo");
			puts("8. Actualizar la cantidad de fichas (Doble ficha)"); // OK
			puts("9. Salir");
			puts("-----------------------------------");
			ingresoIntMinMax(&option, "Opci�n: ", "Error. N�mero inv�lido, ingrese nuevamente: ", 1, 9);
			puts("\n\n\n");

			switch(option)
			{
				case 1:
					if(flagCarga == FALSE)
					{
						if(controller_addCsv("data/arcades.csv", list) != FALSE)
						{
							flagCarga = TRUE;
							controller_saveArcades("data/arcadesGenerated.csv", list);
							puts("-----------------------------------");
							puts("Archivo cargado correctamente");
							puts("-----------------------------------");
							puts("\n\n\n");
						}
						else
						{
							puts("-----------------------------------");
							puts("No s� ha podido cargar el archivo");
							puts("-----------------------------------");
							puts("\n\n\n");
						}
					}
					else
					{
						puts("-----------------------------------");
						puts("Archivo en uso");
						puts("-----------------------------------");
						puts("\n\n\n");
					}

					break;
				case 2:
					if(controller_add(list) != FALSE)
					{
						controller_saveArcades("data/arcadesGenerated.csv", list);
						puts("-----------------------------------");
						puts("Arcade agregado correctamente");
						puts("-----------------------------------");
						puts("\n\n\n");
						index = arc_getMaxId("data/idMax.txt", list)-2;
						controller_printArc(list, index);
					}
					else
					{
						puts("-----------------------------------");
						puts("No s� ha podido agregar Arcade");
						puts("-----------------------------------");
						puts("\n\n\n");
					}
					break;
				case 3:
					if(ll_len(list) > 0)
					{
						controller_listArc(list);
						idFound = ingresoInt("Ingrese el ID a modificar: ", "Error. N�mero invalido: ");

						if(controller_edit(list, idFound) != FALSE)
						{
							controller_saveArcades("data/arcadesGenerated.csv", list);
							index = controller_find(list, idFound);
							controller_printArc(list, index);
							puts("-----------------------------------");
							puts("Arcade modificado con �xito");
							puts("-----------------------------------");
							puts("\n\n\n");
						}
						else
						{
							puts("-----------------------------------");
							puts("No s� ha podido modificar el Arcade");
							puts("-----------------------------------");
							puts("\n\n\n");
						}

					}
					else
					{
						puts("-----------------------------------");
						puts("No hay arcades cargados");
						puts("-----------------------------------");
						puts("\n\n\n");
					}
					break;
				case 4:
					if(ll_len(list) > 0)
					{
						controller_listArc(list);
						idFound = ingresoInt("Ingrese el ID a modificar: ", "Error. N�mero invalido: ");

						if(controller_delete(list, idFound) != FALSE)
						{
							controller_saveArcades("data/arcadesGenerated.csv", list);
							puts("-----------------------------------");
							puts("Arcade eliminado con �xito");
							puts("-----------------------------------");
							puts("\n\n\n");
						}
						else
						{
							puts("-----------------------------------");
							puts("No s� ha podido eliminar el Arcade");
							puts("-----------------------------------");
							puts("\n\n\n");
						}

					}
					else
					{
						puts("-----------------------------------");
						puts("No hay arcades cargados");
						puts("-----------------------------------");
						puts("\n\n\n");
					}
					break;
				case 5:
					if(ll_len(list) > 1)
					{
						ingresoIntMinMax(&option, "0.Descendente 1.Ascendente\nIngrese el orden: ",  "0.Descendente 1.Ascendente\nIngrese el orden: ", 0, 1);
						if(controller_sort(list, option) != FALSE)
						{
							puts("-----------------------------------");
							puts("Ordenamiento realizado con �xito");
							puts("-----------------------------------");
							puts("\n\n\n");
						}
						else
						{
							puts("-----------------------------------");
							puts("No s� ha podido ordenar correctamente");
							puts("-----------------------------------");
							puts("\n\n\n");
						}
					}
					else
					{
						puts("-----------------------------------");
						puts("Necesitas al menos 2 Arcades para ordenar");
						puts("-----------------------------------");
						puts("\n\n\n");
					}
					break;
				case 6:
					if(ll_len(list) > 0)
					{
						if(controller_saveGames("data/gamesGenerated.txt", list) != FALSE)
						{
							puts("-----------------------------------");
							puts("Lista de juegos guardada con �xito");
							puts("-----------------------------------");
							puts("\n\n\n");
						}
						else
						{
							puts("-----------------------------------");
							puts("No se h� podido guardar la lista");
							puts("-----------------------------------");
							puts("\n\n\n");
						}
					}
					else
					{
						puts("-----------------------------------");
						puts("No hay arcades cargados");
						puts("-----------------------------------");
						puts("\n\n\n");
					}
					break;
				case 7:
					if(ll_len(list) > 0)
					{
						if(controller_filterMultiplayer(list) != FALSE)
						{
							puts("-----------------------------------");
							puts("Operaci�n realizada");
							puts("-----------------------------------");
							puts("\n\n\n");
						}
						else
						{
							puts("-----------------------------------");
							puts("No se ha podido realizar la operaci�n");
							puts("-----------------------------------");
							puts("\n\n\n");
						}
					}
					else
					{
						puts("-----------------------------------");
						puts("No hay arcades cargados");
						puts("-----------------------------------");
						puts("\n\n\n");
					}
					break;
				case 8:
					if(ll_len(list) > 0)
					{
						if(controller_duplCoins(list) != FALSE)
						{
							puts("-----------------------------------");
							puts("Operaci�n realizada");
							puts("-----------------------------------");
							puts("\n\n\n");
						}
						else
						{
							puts("-----------------------------------");
							puts("No se ha podido realizar la operaci�n");
							puts("-----------------------------------");
							puts("\n\n\n");
						}
					}
					else
					{
						puts("-----------------------------------");
						puts("No hay arcades cargados");
						puts("-----------------------------------");
						puts("\n\n\n");
					}
					break;
				case 9:
					controller_saveArcades("data/arcadesGenerated.csv", list);
					puts("-----------------------------------");
					puts("Gracias por usar la APP");
					puts("-----------------------------------");
					break;
				}

		}while(option != 9);
	}
	else
	{
		puts("-----------------------------------");
		puts("Ha ocurrido un error al iniciar");
		puts("-----------------------------------");
	}

}
