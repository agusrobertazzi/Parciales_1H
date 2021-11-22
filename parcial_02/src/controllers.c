#include "../inc/controllers.h"
/* Brief Busca un elemento en la LinkedList mediante su ID
 *  \param LinkedList* this
 *  \param int id
 *  \return int status -1 sí no encuentra
 *  				Index del ID sí encuentra
 */
int controller_find(LinkedList* this, int id)
{
	int status = FALSE;
	Arcade* aux;
	int idAux;

	if(this != NULL && ll_len(this) > 0 && id > 0)
	{
		for(int i = 0; i < ll_len(this); i++)
		{
			aux = ll_get(this, i);
			if(aux != NULL)
			{
				if(arc_getId(aux, &idAux) == TRUE)
				{
					if(idAux == id)
					{
						status = i;
						break;
					}
				}
			}
		}
	}

	return status;
}

/* Brief Printea un elemento de la LinkedList
 *  \param LinkedList* this
 *  \param int index
 *  \return int status -1 FALSE
 *  					0 TRUE
 */
int controller_printArc(LinkedList* this, int index)
{
	int status = FALSE;

	Arcade* aux;

	int auxId;
	char auxCountry[ARCADE_COUNTRY_LEN];
	int auxType;
	int auxPlayers;
	int auxCoins;
	char auxName[ARCADE_NAME_LEN];
	char auxGame[ARCADE_GAMENAME_LEN];

	if(this != NULL)
	{
		if(index != FALSE)
		{
			aux = ll_get(this, index);
			if(aux != NULL)
			{

				// Get info
				arc_getId(aux, &auxId);
				arc_getCountry(aux, auxCountry);
				arc_getType(aux, &auxType);
				arc_getPlayers(aux, &auxPlayers);
				arc_getCoins(aux, &auxCoins);
				arc_getName(aux, auxName);
				arc_getGame(aux, auxGame);

				switch(auxType)
				{

				case ARCADE_TYPE_STEREO:
					printf("#%d | %s | País: %s | Jugadores: %d | Fichas: %d | STEREO | Juego: %s\n", auxId, auxName, auxCountry, auxPlayers, auxCoins, auxGame);
					break;
				case ARCADE_TYPE_MONO:
					printf("#%d | %s | País: %s | Jugadores: %d | Fichas: %d | MONO | Juego: %s\n", auxId, auxName, auxCountry, auxPlayers, auxCoins, auxGame);
					break;
				}

				status = TRUE;
			}
		}
	}

	return status;
}
/* Brief Printea el elemento que recibe
 *  \param void* this
 *  \return void
 */
static void printArcade(void* this)
{
	Arcade* aux = (Arcade*)this;
	int auxId;
	char auxCountry[ARCADE_COUNTRY_LEN];
	int auxType;
	int auxPlayers;
	int auxCoins;
	char auxName[ARCADE_NAME_LEN];
	char auxGame[ARCADE_GAMENAME_LEN];

	if(aux != NULL)
	{
		// Get info
		arc_getId(aux, &auxId);
		arc_getCountry(aux, auxCountry);
		arc_getType(aux, &auxType);
		arc_getPlayers(aux, &auxPlayers);
		arc_getCoins(aux, &auxCoins);
		arc_getName(aux, auxName);
		arc_getGame(aux, auxGame);

		switch(auxType)
		{
		case ARCADE_TYPE_STEREO :
			printf("#%d | %s | País: %s | Jugadores: %d | Fichas: %d | STEREO | Juego: %s\n", auxId, auxName, auxCountry, auxPlayers, auxCoins, auxGame);
			break;
		case ARCADE_TYPE_MONO :
			printf("#%d | %s | País: %s | Jugadores: %d | Fichas: %d | MONO | Juego: %s\n", auxId, auxName, auxCountry, auxPlayers, auxCoins, auxGame);
			break;
		}
	}
}

/* Brief Lista los arcades
 *  \param LinkedList* this
 *  \return int status -1 FALSE
 *  					0 TRUE
 */
int controller_listArc(LinkedList*this)
{
	int status = FALSE;

	if(this != NULL)
	{
		status = ll_map(this, printArcade);
	}

	return status;
}

/* Brief Printea un elemento de la LinkedList
 *  \param void this
 *  \return void
 */
static void printGame(void* this)
{
	Arcade* aux = (Arcade*)this;
	char auxGame[ARCADE_GAMENAME_LEN];

	if(aux != NULL)
	{
		if(arc_getGame(aux, auxGame) != FALSE)
		{
			printf("%s\n", auxGame);
		}

	}
}

/* Brief Lista los elementos de una LinkedList
 *  \param LinkedList* this
 *  \return int status -1 FALSE
 *  					0 TRUE
 */
int controller_printGames(LinkedList* this)
{
	int status = FALSE;

	if(this != NULL)
	{
		status = ll_map(this, printGame);
	}

	return status;
}
// ABM Controller

/* Brief Crea un nuevo elemento
 *  \param LinkedList* this
 *  \return int status -1 FALSE
 *  					0 TRUE
 */
int controller_add(LinkedList* this)
{
	int status = FALSE;

	Arcade* aux;

	int auxId;
	char auxCountry[ARCADE_COUNTRY_LEN];
	int auxType;
	int auxPlayers;
	int auxCoins;
	char auxName[ARCADE_NAME_LEN];
	char auxGame[ARCADE_GAMENAME_LEN];

	if(this != NULL)
	{
		aux = arc_new();
		if(aux != NULL)
		{
			auxId = arc_getMaxId("data/idMax.txt", this);
			printf("ID Asignado: %d\n", auxId);

			ingresoCadena(auxCountry, ARCADE_COUNTRY_LEN, "Ingrese país de origen: ", "País inválido, ingrese nuevamente: ");
			while(validarCadena(auxCountry) == FALSE)
			{
				ingresoCadena(auxCountry, ARCADE_COUNTRY_LEN, "Error. Ingrese país de origen: ", "País inválido, ingrese nuevamente: ");
			}

			ingresoIntMinMax(&auxType, "Ingrese: 0. Stereo | 1. Mono\nOpción: ", "Error. Ingrese: 0. Stereo | 1. Mono\nOpción: ", ARCADE_TYPE_STEREO, ARCADE_TYPE_MONO);

			auxPlayers = ingresoInt("Ingrese cantidad de jugadores: ", "Número inválido: ");
			while(auxPlayers <= 0)
			{
				auxPlayers = ingresoInt("Ingrese un número mayor a 0: ", "Número inválido: ");
			}

			auxCoins = ingresoInt("Ingrese cantidad de fichas: ", "Número inválido: ");
			while(auxCoins <= 0)
			{
				auxCoins = ingresoInt("Ingrese un número mayor a 0: ", "Número inválido: ");
			}

			ingresoCadena(auxName, ARCADE_NAME_LEN, "Ingrese el nombre del Arcade: ", "Nombre inválido, ingrese nuevamente: ");
			while(validarCadena(auxName) == FALSE)
			{
				ingresoCadena(auxName, ARCADE_NAME_LEN, "Error. Ingrese el nombre del Arcade: ", "Nombre inválido, ingrese nuevamente: ");
			}

			ingresoCadena(auxGame, ARCADE_GAMENAME_LEN, "Ingrese el nombre del juego: ", "Nombre inválido, ingrese nuevamente: ");
			while(validarCadena(auxGame) == FALSE)
			{
				ingresoCadena(auxGame, ARCADE_NAME_LEN, "Error. Ingrese el nombre del juego: ", "Nombre inválido, ingrese nuevamente: ");
			}

			arc_setId(aux, auxId);
			arc_setCountry(aux, auxCountry);
			arc_setType(aux, auxType);
			arc_setPlayers(aux, auxPlayers);
			arc_setCoins(aux, auxCoins);
			arc_setName(aux, auxName);
			arc_setGame(aux, auxGame);

			ll_add(this, aux);
			status = TRUE;
			arc_setMaxId("data/idMax.txt", this);
		}
	}

	return status;
}

/* Brief Edita un elemento
 *  \param LinkedList* this
 *  \param int id
 *  \return int status -1 FALSE
 *  					0 TRUE
 */
int controller_edit(LinkedList* this, int id)
{
	int status = FALSE;
	int index = controller_find(this, id);
	int option;
	Arcade* aux;

	int auxPlayers;
	char auxGame[ARCADE_GAMENAME_LEN];

	if(this != NULL && index != FALSE)
	{
		aux = ll_get(this, index);
		if(aux != NULL)
		{
			puts("-----------------------------------");
			puts("¿Que desea modificar?");
			puts("1. Cantidad de jugadores");
			puts("2. Juego en el sistema");
			puts("-----------------------------------");
			ingresoIntMinMax(&option, "Opción: ", "Error. Número inválido: ", 1, 2);
			puts("\n\n\n");

			switch (option) {
			case 1:
				auxPlayers = ingresoInt("Ingrese cantidad de jugadores: ", "Número inválido: ");
				while(auxPlayers <= 0)
				{
					auxPlayers = ingresoInt("Ingrese un número mayor a 0: ", "Número inválido: ");
				}
				arc_setPlayers(aux, auxPlayers);
				break;
			case 2:
				controller_printGames(this);
				ingresoCadena(auxGame, ARCADE_GAMENAME_LEN, "Ingrese el nombre del juego: ", "Nombre inválido, ingrese nuevamente: ");
				while(validarCadena(auxGame) == FALSE)
				{
					ingresoCadena(auxGame, ARCADE_NAME_LEN, "Error. Ingrese el nombre del juego: ", "Nombre inválido, ingrese nuevamente: ");
				}
				arc_setGame(aux, auxGame);
				break;
			}

			status = TRUE;
		}
	}

	return status;
}

/* Brief Elimina un elemento
 *  \param LinkedList* this
 *  \param int id
 *  \return int status -1 FALSE
 *  					0 TRUE
 */
int controller_delete(LinkedList* this, int id)
{
	int status = FALSE;
	int index = controller_find(this, id);
	int confirm;
	Arcade* aux;

	if(this != NULL && index != FALSE)
	{
		aux = ll_get(this, index);
		if(aux != NULL)
		{
			controller_printArc(this, index);
			ingresoIntMinMax(&confirm, "¿Está seguro que quiere eliminar este Arcade? 1. Si 2. No:\n", "Error. Ingrese un número válido 1. Si 2. No:\n", 1, 2);
			if(confirm == 1)
			{
				arc_delete(aux, this, index);
				status = TRUE;
			}
		}
	}

	return status;
}

/* Brief Ordena dos elementos
 *  \param void* pElemnt
 *  \param void* pElement2
 *  \return int status -1 Menor que
 *  					0 Igual
 *  					1 Mayor que
 */
static int sort(void* pElement, void* pElement2)
{
	int status = 0;
	Arcade* pElementAux = (Arcade*) pElement;
	Arcade* pElement2Aux = (Arcade*) pElement2;
	char gameAux[ARCADE_GAMENAME_LEN];
	char gameAux2[ARCADE_GAMENAME_LEN];

	if(pElementAux != NULL && pElement2 != NULL)
	{
		arc_getGame(pElementAux, gameAux);
		arc_getGame(pElement2Aux, gameAux2);

		status = stricmp(gameAux, gameAux2);

	}

	return status;
}

/* Brief Ordena la LinkedList
 *  \param LinkedList* this
 *  \param int order
 *  \return int status -1 FALSE
 *  					0 TRUE
 */
int controller_sort(LinkedList* this, int order)
{
	int status = FALSE;
	LinkedList* aux = ll_clone(this);

	if(this != NULL)
	{
		status = ll_sort(aux, sort, order);
		if(status != FALSE)
		{
			controller_listArc(aux);
		}
	}

	return status;
}

/* Brief Lee y carga un archivo de texto
 *  \param char* path
 *  \param LinkedList* this
 *  \return int status -1 FALSE
 *  					0 TRUE
 */
int controller_addCsv(char* path, LinkedList* list)
{

	int status = FALSE;
	FILE* pFile = fopen(path, "r");

	status = parserArcades(pFile, list);

	if(pFile != NULL)
	{
		fclose(pFile);
		arc_setMaxId("data/idMax.txt", list);
	}

	return status;

}

/* Brief Guarda un archivo de texto
 *  \param char* path
 *  \param LinkedList* this
 *  \return int status -1 FALSE
 *  					0 TRUE
 */
int controller_saveArcades(char* path, LinkedList* list)
{
	int status = TRUE;

	FILE* f = NULL;
	Arcade* aux;

	int auxId;
	char auxCountry[ARCADE_COUNTRY_LEN];
	int auxType;
	int auxPlayers;
	int auxCoins;
	char auxName[ARCADE_NAME_LEN];
	char auxGame[ARCADE_GAMENAME_LEN];

	if(list != NULL)
	{
		f = fopen(path, "w");
		if(f != NULL)
		{

			fprintf(f, "id,nacionalidad,tipo_sonido,cant_jug,fichas_max,salon,game\n");

			for(int i = 0; i < ll_len(list); i++)
			{
				aux = ll_get(list, i);
				if(aux != NULL)
				{
					arc_getId(aux, &auxId);
					arc_getCountry(aux, auxCountry);
					arc_getType(aux, &auxType);
					arc_getPlayers(aux, &auxPlayers);
					arc_getCoins(aux, &auxCoins);
					arc_getName(aux, auxName);
					arc_getGame(aux, auxGame);

					switch(auxType)
					{
					case ARCADE_TYPE_STEREO :
						fprintf(f,"%d,%s,STEREO,%d,%d,%s,%s\n", auxId, auxCountry, auxPlayers, auxCoins, auxName, auxGame);
						break;
					case ARCADE_TYPE_MONO :
						fprintf(f,"%d,%s,STEREO,%d,%d,%s,%s\n", auxId, auxCountry, auxPlayers, auxCoins, auxName, auxGame);
						break;
					}
				}
				else
				{
					status = FALSE;
					break;
				}
			}

			fclose(f);
		}
		else
		{
			status = FALSE;
		}
	}
	else
	{
		status = FALSE;
	}

	return status;
}

/* Brief Guarda un archivo de texto
 *  \param char* path
 *  \param LinkedList* this
 *  \return int status -1 FALSE
 *  					0 TRUE
 */
int controller_saveGames(char* path, LinkedList* list)
{
	int status = TRUE;
	int flag;

	FILE* f = NULL;
	Arcade* aux;
	Arcade* aux2;

	char auxGame[ARCADE_GAMENAME_LEN];
	char auxGame2[ARCADE_GAMENAME_LEN];

	if(list != NULL)
	{
		f = fopen(path, "w");
		if(f != NULL)
		{

			for(int i = 0; i < ll_len(list); i++)
			{
				flag = FALSE;
				aux = ll_get(list, i);
				if(aux != NULL)
				{
					arc_getGame(aux, auxGame);
					for(int j = i+1; j < ll_len(list); j++)
					{
						aux2 = ll_get(list, j);
						if(aux2 != NULL)
						{
							arc_getGame(aux2, auxGame2);
							if(stricmp(auxGame, auxGame2) == 0)
							{
								flag = TRUE;
								break;
							}
						}
					}

					if(flag == FALSE)
					{
						fprintf(f,"%s\n", auxGame);
					}

				}
				else
				{
					status = FALSE;
					break;
				}
			}

			fclose(f);
		}
		else
		{
			status = FALSE;
		}
	}
	else
	{
		status = FALSE;
	}

	return status;
}

/* Brief Filtra una linkedList
 *  \param void* list
 *  \return int status -1 FALSE
 *  					0 TRUE
 */
static int filterMultiplayer(void* this)
{
	int status = FALSE;
	Arcade* aux = (Arcade*) this;
	int playerAux;

	if(aux != NULL)
	{
		arc_getPlayers(aux, &playerAux);
		if(playerAux > 1)
		{
			status = TRUE;
		}
	}

	return status;
}

/* Brief Filtra una linkedList
 *  \param LinkedList* this
 *  \return int status -1 FALSE
 *  					0 TRUE
 */
int controller_filterMultiplayer(LinkedList* this)
{
	int status = FALSE;
	LinkedList* aux;

	if(this != NULL)
	{
		aux = ll_filter(this, filterMultiplayer);
		if(aux != NULL)
		{
			if(controller_saveArcades("data/multiplayerGenerated.csv", aux) != FALSE)
			{
				status = TRUE;
			}

		}
	}

	return status;

}

/* Brief Duplica un elemento
 *  \param void* this
 *  \return void
 */
static void duplCoins(void* this)
{

	Arcade* aux;
	aux = (Arcade*) this;
	int auxCoin;

	if(aux != NULL)
	{
		arc_getCoins(aux, &auxCoin);
		auxCoin = auxCoin * 2;
		arc_setCoins(aux, auxCoin);
	}

}

/* Brief Duplica un elemento
 *  \param LinkedList* this
 *  \return int status -1 FALSE
 *  					0 TRUE
 */
int controller_duplCoins(LinkedList* this)
{
	int status = FALSE;

	if(this != NULL)
	{
		status = ll_map(this, duplCoins);
	}

	return status;
}
