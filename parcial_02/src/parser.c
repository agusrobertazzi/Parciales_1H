#include "../inc/parser.h"

/** \brief Lee el archivo recibido y da alta a los nuevos arcades
 *
 *  \param FILE* pFile
 *  \param LinkedList* list
 *  \return int Retorna 0 = OK
 *                      -1 = Error
 */
int parserArcades(FILE* pFile, LinkedList* list)
{
	int status = FALSE;
	char id[20];
	int newId;
	char country[ARCADE_COUNTRY_LEN];
	char type[20];
	char auxType[20];
	int auxInt;
	char players[20];
	char coins[20];
	char name[ARCADE_NAME_LEN];
	char game[ARCADE_GAMENAME_LEN];
	Arcade* aux;

	if(pFile != NULL && list != NULL)
	{

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id , country, type, players, coins, name, game);
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id , country, type, players, coins, name, game) == 7)
			{
				if(stricmp(type, "stereo") == 0)
				{
					auxInt = ARCADE_TYPE_STEREO;
					sprintf(auxType, "%d", auxInt);
				}
				else if(stricmp(type, "mono") == 0)
				{
					auxInt = ARCADE_TYPE_MONO;
					sprintf(auxType, "%d", auxInt);
				}
				else
				{
					status = FALSE;
					break;
				}

				aux = arc_newParameter(id, country, auxType, players, coins, name, game);
				if(aux != NULL)
				{
					if(controller_find(list, atoi(id)) == FALSE)
					{
						ll_add(list, aux);
						status = TRUE;
					}
					else
					{
						newId = arc_getMaxId("data/idMax.txt", list);
						arc_setId(aux, newId);
						ll_add(list, aux);
					}
				}
				else
				{
					status = FALSE;
				}
			}

		}while(feof(pFile) == 0 && status != FALSE);
	}
	else
	{
		status = FALSE;
	}

	return status;

}
