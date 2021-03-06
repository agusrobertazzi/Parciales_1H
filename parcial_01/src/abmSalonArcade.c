#include "abmSalonArcade.h"

/*
 * brief: Inicializa un contador global que incrementa en uno y retorna el mismo
 * return: Contador incrementado en 1
 * */
static int getNewIdArcade(void)
{
	static int counter = 0;

	return(counter++);
}

/*
 * brief: Crea un nuevo usuario
 * param: Arcade* listArcade
 * param: Int lenArcade
 * param: Salon* listSalon
 * param: Int lenSalon
 * return: Retorna FALSE en caso de error y TRUE s? sale OK
 * */
int addArcade(Arcade* listArcade, int lenArcade, Salon* listSalon, int lenSalon)
{
	int status = FALSE;
	int i;

	if(listArcade != NULL && lenArcade > 0 && listSalon != NULL && lenSalon > 0)
	{
		for(i = 0; i < lenArcade; i++)
		{
			if(listArcade[i].isEmpty == TRUE)
			{
				status = TRUE;
				listArcade[i].isEmpty = FALSE;
				listArcade[i].id = getNewIdArcade();
				ingresoCadena(listArcade[i].country, 100, "Ingrese nacionalidad del arcade: ", "Error. Ingrese nuevamente: ");
				ingresoIntMinMax(&listArcade[i].type, "Ingrese el sonido del arcade\n0. Mono\n1. Ester?o\n", "Error. Numero no v?lido: ", 0, 1);
				ingresoIntMinMax(&listArcade[i].players, "?Cuantos jugadores tiene el arcade? M?ximo 6: ", "Error. N?mero no v?lido: ", 1, 6);
				listArcade[i].maxAmount = ingresoInt("?Cuantas fichas tiene el arcade?: ", "Error. No v?lido: ");
				while(listArcade[i].maxAmount < 1)
				{
					listArcade[i].maxAmount = ingresoInt("No debe ser n?mero negativo: ", "Error. No v?lido: ");
				}
				printSalon(listSalon, lenSalon);
				listArcade[i].idSalon = ingresoInt("?A qu? sal?n pertenece este arcade?: ", "Error. No v?lido: ");
				while(findSalonById(listSalon, lenSalon, listArcade[i].idSalon) == FALSE)
				{
					listArcade[i].idSalon = ingresoInt("El sal?n no ex?ste. Ingrese otro ID: ", "Error. No v?lido: ");
				}
				ingresoCadena(listArcade[i].gameName, 63, "?C?mo se llama el juego de este arcade?", "Error. Ingrese nuevamente: ");

				break;
			}
		}
	}

	return status;
}
/*
 * brief: Elimina un sal?n y sus arcades enlazados
 * param: Salon* listSalon
 * param: Int lenSalon
 * param: Int id
 * param: Arcade* listArcade
 * param: Int lenArcade
 * return: Retorna FALSE en caso de error o la cantidad de arcades que elimina
 * */
int deleteSalon(Salon* listSalon, int lenSalon, int id, Arcade* listArcade, int lenArcade)
{
	int status = FALSE;
	int i;
	int cont = 0;

	if(listSalon != NULL && lenSalon > 0 && listArcade != NULL && lenArcade > 0 && id != FALSE)
	{
		listSalon[id].isEmpty = TRUE;

		for(i = 0; i < lenArcade; i++)
		{
			if(listArcade[i].isEmpty == FALSE && listArcade[i].idSalon == id)
			{
				listArcade[i].isEmpty = TRUE;
				cont++;
			}
		}

		status = cont;
	}

	return status;
}

int salonForzado(Salon* list, int len, int pos, int id,char* name, char* adress, int type)
{
	int status = FALSE;

	if(pos >= 0 && pos <= len)
	{
		status = TRUE;

		list[pos].isEmpty = FALSE;
		list[pos].id = id;
		strncpy(list[pos].name, name, 100);
		strncpy(list[pos].adress, adress, 100);
		list[pos].type = type;
	}

	return status;
}

int arcadeForzado(Arcade* list, int len, int pos, int id, char* country, int type, int player, int maxAmount, int idSalon, char* gameName)
{
	int status = FALSE;

	if(pos >= 0 && pos <= len)
	{
		status = TRUE;

		list[pos].isEmpty = FALSE;
		list[pos].id = id;
		strncpy(list[pos].country, country, 100);
		list[pos].type = type;
		list[pos].players = player;
		list[pos].maxAmount = maxAmount;
		list[pos].idSalon = idSalon;
		strncpy(list[pos].gameName, gameName, 63);
	}

	return status;
}
