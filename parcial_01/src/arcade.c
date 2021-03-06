#include "arcade.h"
/*
 * brief: Inicializa la estructura de Arcades
 * param: Arcade* list
 * param: Int len
 * return: Retorna FALSE en caso de error o TRUE s? sale bien
 * */
int initArcade(Arcade* list, int len)
{
	int status = FALSE;
	int i;

	if(list != NULL && len > 0)
	{
		status = TRUE;
		for(i = 0; i < len; i++)
		{
			list[i].isEmpty = TRUE;
		}
	}

	return status;
}

/*
 * brief: Busca la posici?n de un Arcade mediante su ID
 * param: Arcade* listArcade
 * param: Int lenArcade
 * param: Int id
 * return: Retorna FALSE en caso de error o la posici?n del Arcade buscado
 * */
int findArcadeByID(Arcade* list, int len, int id)
{
	int status = FALSE;
	int i;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].id == id && list[i].isEmpty == FALSE)
			{
				status = i;
				break;
			}
		}
	}

	return status;
}
/*
 * brief: Elimina un arcade
 * param: Arcade* listArcade
 * param: Int lenArcade
 * param: Int id
 * return: Retorna FALSE en caso de error o TRUE s? sale bien
 * */
int deleteArcade(Arcade* list, int len, int id)
{
	int status = FALSE;
	int idValidator;

	if(list != NULL && len > 0 && id != FALSE)
	{
		status = TRUE;
		idValidator = ingresoInt("Vuelva a ingresar el ID a eliminar para confirmar: ", "Error. N?mero no v?lido: ");
		while(idValidator != id)
		{
			idValidator = ingresoInt("Error. Vuelva a ingresar el ID a eliminar para confirmar: ", "Error. N?mero no v?lido: ");
		}
		list[id].isEmpty = TRUE;
	}


	return status;
}

/*
 * brief: Imprime los arcades ocupados
 * param: Arcade* listArcade
 * param: Int lenArcade
 * return: Retorna FALSE en caso de error o TRUE s? sale bien
 * */
int printArcades(Arcade* list, int len)
{
	int status = FALSE;
	int i;

	if(list != NULL && len > 0)
	{
		status = TRUE;

		puts("--------------------------------------");
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				switch(list[i].type)
				{
				case 0:
					printf("Arcade #%d || %s || MONO || Jugadores %d || Cantidad m?xima de fichas: %d|| Percenece al sal?n #%d\n", list[i].id, list[i].country, list[i].players, list[i].maxAmount, list[i].idSalon);
					break;
				case 1:
					printf("Arcade #%d || %s || ESTER?O || Jugadores %d || Cantidad m?xima de fichas: %d|| Percenece al sal?n #%d\n", list[i].id, list[i].country, list[i].players, list[i].maxAmount, list[i].idSalon);
					break;
				}
			}
		}
		puts("--------------------------------------");
	}

	return status;
}

/*
 * brief: Imprime los juegos sin repetir
 * param: Arcade* listArcade
 * param: Int lenArcade
 * return: Retorna FALSE en caso de error o TRUE s? sale bien
 * */
int printGames(Arcade* list, int len)
{
	int status = FALSE;
	int i;
	int j;
	int flag;

	if(list != NULL && len > 0)
	{
		status = TRUE;

		puts("--------------------------------------");
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				flag = FALSE;
				for(j = i+1; j < len; j++)
				{
					if(strcmp(list[i].gameName, list[j].gameName) == 0)
					{
						flag = TRUE;
						break;
					}
				}
				if(flag == FALSE)
				{
					printf("%d || %s\n", list[i].id, list[i].gameName);
				}
			}
		}
		puts("--------------------------------------");
	}

	return status;
}

/*
 * brief: Modifica el Arcade a trav?s de su ID
 * param: Arcade* listArcade
 * param: Int lenArcade
 * param: Int id
 * return: Retorna FALSE en caso de error o TRUE s? sale bien
 * */
int modifyArcade(Arcade* list, int len, int id)
{
	int status = FALSE;
	int option;

	if(list != NULL && len > 0 && id != FALSE)
	{
		ingresoIntMinMax(&option, "?Que desea modificar?\n1. Cantidad de jugadores\n2. Juego que contiene\n", "Error. N?mero inv?lido", 1, 2);
		switch(option)
		{
		case 1:
			ingresoIntMinMax(&list[id].players, "?Cuantos jugadores tiene el arcade? M?ximo 6: ", "Error. N?mero no v?lido: ", 1, 6);
			break;
		case 2:
			printGames(list, len);
			ingresoCadena(list[id].gameName, 63, "?C?mo se llama el nuevo juego de este arcade?", "Error. Ingrese nuevamente: ");
			break;
		}
		status = TRUE;
	}

	return status;
}
