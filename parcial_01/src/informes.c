#include "informes.h"

/*
 * brief: Imprime los salones con m?s de cuatro arcades
 * param: Salon* listSalon
 * param: Int lenSalon
 * param: Arcade* listArcade
 * param: Int lenArcade
 * return: Retorna FALSE en caso de error o TRUE s? sale bien
 * */
int informeCuatroArcades(Salon* listSalon, int lenSalon, Arcade* listArcade, int lenArcade)
{
	int status = FALSE;
	int i;
	int j;
	int cont = 0;

	if(listSalon != NULL && lenSalon > 0 && listArcade != NULL && lenArcade > 0)
	{

		puts("--------------------------------------");
		for(i = 0; i < lenSalon; i++)
		{
			if(listSalon[i].isEmpty == FALSE)
			{
				cont = 0;

				for(j = 0; j < lenArcade; j++)
				{
					if(listArcade[j].isEmpty == FALSE && listArcade[j].idSalon == listSalon[i].id)
					{
						cont++;
					}
				}

				if(cont > 4)
				{
					status = TRUE;
					switch(listSalon[i].type)
					{
					case 0:
						printf("Sal?n #%d || %s || Direcci?n: %s || LOCAL\n", listSalon[i].id, listSalon[i].name, listSalon[i].adress);
						break;
					case 1:
						printf("Sal?n #%d || %s || Direcci?n: %s || SHOPPING\n", listSalon[i].id, listSalon[i].name, listSalon[i].adress);
						break;
					}
				}

			}
		}

		puts("--------------------------------------");
	}

	return status;
}

/*
 * brief: Imprime los arcades con m?s de dos jugadores
 * param: Arcade* listArcade
 * param: Int lenArcade
 * param: Salon* listSalon
 * param: Int lenSalon
 * return: Retorna FALSE en caso de error o TRUE s? sale bien
 * */
int arcadeDosJugadores(Arcade* listArcade, int lenArcade, Salon* listSalon, int lenSalon)
{
	int status = FALSE;
	int i;
	int position;


	if(listArcade != NULL && lenArcade > 0 && listSalon != NULL && lenSalon > 0)
	{
		status = TRUE;

		puts("--------------------------------------");
		for(i = 0; i < lenArcade; i++)
		{
			if(listArcade[i].isEmpty == FALSE && listArcade[i].players > 2)
			{
				position = findSalonById(listSalon, lenSalon, listArcade[i].idSalon);
				printf("Arcade #%d || Jugadores: %d || %s || Sal?n: %s\n", listArcade[i].id, listArcade[i].players, listArcade[i].gameName, listSalon[position].name);
			}
		}
		puts("--------------------------------------");
	}

	return status;
}

/*
 * brief: Detalla la informaci?n de un sal?n y la cantidad de arcades que contiene
 * param: Salon* listSalon
 * param: Int lenSalon
 * param: Arcade* listArcade
 * param: Int lenArcade
 * param: Int id
 * return: Retorna FALSE en caso de error o TRUE s? sale bien
 * */
int infoDetailSalon(Salon* listSalon, int lenSalon, Arcade* listArcade, int lenArcade, int id)
{
	int status = FALSE;
	int i;
	int cont = 0;

	if(listSalon != NULL && lenSalon > 0 && listArcade != NULL && lenArcade > 0 && id != FALSE)
	{
		status = TRUE;

		puts("--------------------------------------");
		printf("Sal?n #%d\n", listSalon[id].id);
		printf("Nombre: %s\n", listSalon[id].name);
		switch(listSalon[id].type)
		{
		case 0:
			printf("Tipo: LOCAL\n");
			break;
		case 1:
			printf("Tipo: SHOPPING\n");
			break;
		}
		printf("Direcci?n: %s\n", listSalon[id].adress);
		for(i = 0; i < lenArcade; i++)
		{
			if(listArcade[i].isEmpty == FALSE && listArcade[i].idSalon == id)
			{
				cont++;
			}
		}
		printf("Arcades dentro del salon: %d\n", cont);
		puts("--------------------------------------");
	}

	return status;
}

/*
 * brief: Lista los arcades que est?n enlazados al ID buscado
 * param: Arcade* listArcade
 * param: Int lenArcade
 * param: Salon* listSalon
 * param: Int lenSalon
 * param: Int id
 * return: Retorna FALSE en caso de error o TRUE s? sale bien
 * */
int listarArcades(Arcade* listArcade, int lenArcade, Salon* listSalon, int lenSalon, int id)
{
	int status = FALSE;
	int i;

	if(listArcade != NULL && lenArcade > 0 && listSalon != NULL && lenSalon > 0 && id != FALSE)
	{
		status = TRUE;
		puts("--------------------------------------");
		printf("Salon #%d\n", listSalon[id].id);
		switch(listSalon[id].type)
		{
		case 0:
			printf("Nombre: %s || Tipo: LOCAL\n\n", listSalon[id].name);
			break;
		case 1:
			printf("Nombre: %s || Tipo: SHOPPING\n\n", listSalon[id].name);
			break;
		}

		puts("Juegos");
		for(i = 0; i < lenArcade; i++)
		{
			if(listArcade[i].isEmpty == FALSE && listArcade[i].idSalon == id)
			{
				switch(listArcade[i].type)
				{
				case 0:
					printf("Arcade #%d || %s || MONO || Jugadores: %d || Fichas m?ximas: %d || Juego: %s\n", listArcade[i].id, listArcade[i].country, listArcade[i].players, listArcade[i].maxAmount, listArcade[i].gameName);
					break;
				case 1:
					printf("Arcade #%d || %s || ESTER?O || Jugadores: %d || Fichas m?ximas: %d || Juego: %s\n", listArcade[i].id, listArcade[i].country, listArcade[i].players, listArcade[i].maxAmount, listArcade[i].gameName);
					break;
				}
			}
		}

		puts("--------------------------------------");
	}

	return status;
}

/*
 * brief: Imprime el sal?n con m?s cantidad de Arcades
 * param: Arcade* listArcade
 * param: Int lenArcade
 * param: Salon* listSalon
 * param: Int lenSalon
 * return: Retorna FALSE en caso de error o TRUE s? sale bien
 * */
int listarMasCantidad(Arcade* listArcade, int lenArcade, Salon* listSalon, int lenSalon)
{
	int status = FALSE;
	int i;
	int j;
	int cont;
	int idMaximo;
	int contMaximo;
	int flag = FALSE;

	if(listArcade != NULL && lenArcade > 0 && listSalon != NULL && lenSalon > 0)
	{
		status = TRUE;
		for(i = 0; i < lenSalon; i++)
		{
			if(listSalon[i].isEmpty == FALSE)
			{
				cont = 0;
				for(j = 0; j < lenArcade; j++)
				{
					if(listArcade[j].isEmpty == FALSE && listArcade[j].idSalon == listSalon[i].id)
					{
						cont++;
					}
				}
				if(flag == FALSE || cont > contMaximo)
				{
					idMaximo = i;
					contMaximo = cont;
					flag = TRUE;
				}
			}
		}

		puts("--------------------------------------");
		printf("Sal?n #%d\n", listSalon[idMaximo].id);
		printf("Nombre: %s\n", listSalon[idMaximo].name);
		printf("Direcci?n: %s\n", listSalon[idMaximo].adress);
		switch(listSalon[idMaximo].type)
		{
		case 0:
			printf("Tipo: LOCAL\n");
			break;
		case 1:
			printf("Tipo: SHOPPING\n");
			break;
		}
		printf("Arcades: %d\n", contMaximo);

		puts("--------------------------------------");

	}

	return status;
}

/*
 * brief: Calcula el valor que ganar?a cada sal?n seg?n el precio que le coloques
 * param: Arcade* list
 * param: Int len
 * param: Int id
 * param: Int value
 * return: Retorna FALSE en caso de error o TRUE s? sale bien
 * */
int calcularValor(Arcade* list, int len, int id, int value)
{
	int status = FALSE;
	int i;
	int cont = 0;
	int valMax;

	if(list != NULL && len > 0 && id != FALSE)
	{
		status = TRUE;
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].idSalon == id)
			{
				cont += list[i].maxAmount;
			}
		}

		valMax = cont * value;
		puts("--------------------------------------");
		printf("El salon #%d acumular?a $%d\n", id, valMax);
		puts("--------------------------------------");
	}

	return status;
}

/*
 * brief: Busca el juego y retorna la cantidad de veces que se utiliza en los arcades
 * param: Arcade* list
 * param: Int len
 * param: Char ingreso[]
 * return: Retorna FALSE en caso de error o TRUE s? sale bien
 * */
int contadorJuegos(Arcade* list, int len, char ingreso[])
{
	int status = FALSE;
	int i;
	int cont = 0;
	char aux[63];

	if(list != NULL && len > 0 && strlen(ingreso) > 0)
	{
		status = TRUE;
		strlwr(ingreso);
		for(i = 0; i < len; i++)
		{
			strcpy(aux, list[i].gameName);
			strlwr(aux);

			if(list[i].isEmpty == FALSE && strcmp(ingreso, aux) == 0)
			{
				cont++;
			}
		}
		puts("--------------------------------------");
		printf("Cantidad de arcades que contienen el juego: %d\n", cont);
		puts("--------------------------------------");
	}

	return status;
}


// PARTE 2 DEL EXAMEN
int salonCompleto(Salon* listSalon, int lenSalon, Arcade* listArcade, int lenArcade)
{
	int status;
	int i;
	int j;
	int cont;

	if(listSalon != NULL && lenSalon > 0 && listArcade != NULL && lenArcade > 0)
	{
		status = TRUE;

		puts("--------------------------------------");
		for(i = 0; i < lenSalon; i++)
		{
			if(listSalon[i].isEmpty == FALSE)
			{
				cont = 0;
				for(j = 0; j < lenArcade; j++)
				{
					if(listSalon[i].id == listArcade[j].idSalon && listArcade[j].players > 2 && listArcade[j].isEmpty == FALSE)
					{
						cont++;
					}
				}

				if(cont >= 8)
				{
					switch(listSalon[i].type)
					{
					case 0:
						printf("Sal?n #%d || Nombre: %s || Direcci?n: %s || LOCAL\n", listSalon[i].id, listSalon[i].name, listSalon[i].adress);
						break;
					case 1:
						printf("Sal?n #%d || Nombre: %s || Direcci?n: %s || SHOPPING\n", listSalon[i].id, listSalon[i].name, listSalon[i].adress);
						break;
					}
				}
			}
		}
		puts("--------------------------------------");

	}

	return status;
}

int promedioSalonArcade(Salon* listSalon, int lenSalon, Arcade* listArcade, int lenArcade)
{
	int status = FALSE;
	int i;
	int j;
	int contSalon = 0;
	int contArcade = 0;
	float promedio;

	if(listSalon != NULL && lenSalon > 0 && listArcade != NULL && lenArcade > 0)
	{
		status = TRUE;

		for(i = 0; i < lenSalon; i++)
		{
			if(listSalon[i].isEmpty == FALSE)
			{
				contSalon++;
				for(j = 0; j < lenArcade; j++)
				{
					if(listSalon[i].id == listArcade[j].idSalon && listArcade[j].isEmpty == FALSE)
					{
						contArcade++;
					}
				}

			}
		}

		promedio = (float)contArcade / contSalon;


		puts("--------------------------------------");
		printf("La cantidad de arcades por sal?n promedio es de: %f\n", promedio);
		puts("--------------------------------------");

	}

	return status;
}
