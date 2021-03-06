#include "salon.h"

/*
 * brief: Inicializa un contador global que incrementa en uno y retorna el mismo
 * return: Contador incrementado en 1
 * */
static int getNewIdSalon(void)
{
	static int counter = 0;

	return(counter++);
}

/*
 * brief: Inicializa la estructura de Salon
 * param: Salon* list
 * param: Int len
 * return: Retorna FALSE en caso de error o TRUE s? sale bien
 * */
int initSalon(Salon* list, int len)
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
 * brief: Crea un nuevo Sal?n
 * param: Salon* list
 * param: Int len
 * return: Retorna FALSE en caso de error o TRUE s? sale bien
 * */
int addSalon(Salon* list, int len)
{
	int status = FALSE;
	int i;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == TRUE)
			{
				status = TRUE;
				list[i].isEmpty = FALSE;
				list[i].id = getNewIdSalon();
				ingresoCadena(list[i].name, 100, "Ingrese el nombre del salon: ", "Error. Intente nuevamente: ");
				ingresoCadena(list[i].adress, 100, "Ingrese la direcci?n del salon: ", "Error. Intente nuevamente: ");
				ingresoIntMinMax(&list[i].type, "Ingrese el tipo de salon\n0. Local\n1. Shopping\n", "Error. Ingrese un n?mero v?lido: ", SALON, SHOPPING);

				puts("--------------------------------------");
				switch(list[i].type)
				{
				case 0:
					printf("Sal?n #%d || %s || Direcci?n: %s || LOCAL\n", list[i].id, list[i].name, list[i].adress);
					break;
				case 1:
					printf("Sal?n #%d || %s || Direcci?n: %s || SHOPPING\n", list[i].id, list[i].name, list[i].adress);
					break;
				}
				puts("--------------------------------------");
				break;
			}
		}
	}

	return status;
}

/*
 * brief: Busca la posici?n del Sal?n mediante el ID
 * param: Salon* list
 * param: Int len
 * param: Int ID
 * return: Retorna FALSE en caso de error o la posici?n del sal?n
 * */
int findSalonById(Salon* list, int len, int id)
{
	int status = FALSE;
	int i;

	if(list != NULL && len > 0 && id > -1)
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
 * brief: Busca la posici?n del Sal?n mediante el ID
 * param: Salon* list
 * param: Int len
 * return: Retorna FALSE en caso de error o TRUE s? sale bien
 * */
int printSalon(Salon* list, int len)
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
					printf("Sal?n #%d || %s || Direcci?n: %s || LOCAL\n", list[i].id, list[i].name, list[i].adress);
					break;
				case 1:
					printf("Sal?n #%d || %s || Direcci?n: %s || SHOPPING\n", list[i].id, list[i].name, list[i].adress);
					break;
				}
			}
		}
		puts("--------------------------------------");
	}

	return status;
}
