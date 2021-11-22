#include "../inc/idController.h"

/** \brief Setea en un ARCHIVO el ID máximo
 *
 * \param char* path
 * \param LinkedList* list
 * \return int
 *
 */
int arc_setMaxId(char* path, LinkedList* list)
{
	int status = FALSE;
	int idMax;
	FILE* f = fopen(path, "w");

	if(f != NULL)
	{
		idMax = arc_getMaxId(path, list);
		idMax--;
		fprintf(f,"%d",idMax);
		status = idMax;
		fclose(f);
	}

	return status;
}

/** \brief Pide el ID máximo y lo incrementa en 1 para su utilización
 *
 * \param char* path
 * \param LinkedList* list
 * \return int
 *
 */
int arc_getMaxId(char* path, LinkedList* list)
{
	int status = FALSE;
	char idMax[20];
	int i;
	int idAux;
	int idAuxMax;
	int maxId;
	int flagIngreso = FALSE;
	Arcade* aux = arc_new();
	FILE* f = fopen(path, "r");

	if(ll_len(list) > 0)
	{
		if(f != NULL)
		{
			fscanf(f,"%s", idMax);
			idAux = atoi(idMax);
			idAux++;

			for(i = 0; i < ll_len(list); i++)
			{
				aux = ll_get(list, i);
				if(aux != NULL)
				{
					arc_getId(aux, &idAuxMax);
					if(flagIngreso == FALSE || idAuxMax > maxId)
					{
						flagIngreso = TRUE;
						maxId = idAuxMax;
					}
				}
			}

			maxId++;
			if(idAux > maxId)
			{
				status = idAux;
			}
			else
			{
				status = maxId;
			}

			fclose(f);
		}
		else
		{
			for(i = 0; i < ll_len(list); i++)
			{
				aux = ll_get(list, i);
				if(aux != NULL)
				{
					arc_getId(aux, &idAux);
					if(flagIngreso == FALSE || idAux > maxId)
					{
						flagIngreso = TRUE;
						maxId = idAux;
					}
				}
			}

			maxId++;
			status = maxId;

			fclose(f);
		}
	}
	else
	{
		status = 1;
	}

	return status;
}
