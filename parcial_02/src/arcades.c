#include "../inc/arcades.h"

// Setters
/** \brief Setea ID dentro del auxiliar enviado
 *
 *  \param Arcade* this
 *  \param int id
 *  \return int Retorna 0 = OK
 *                      -1 = Error
 */
int arc_setId(Arcade* this,int id)
{
	int status = FALSE;
	char idAux[20];

	sprintf(idAux, "%d", id);
	if(validarEntero(idAux) == TRUE && this != NULL)
	{
		status = TRUE;
		this->id = id;
	}

	return status;
}

/** \brief Setea Country dentro del auxiliar enviado
 *
 *  \param Arcade* this
 *  \param char* country
 *  \return int Retorna 0 = OK
 *                      -1 = Error
 */
int arc_setCountry(Arcade* this, char* country)
{
	int status = FALSE;

	if(validarCadena(country) == TRUE && this != NULL)
	{
		status = TRUE;
		strncpy(this->country, country, ARCADE_COUNTRY_LEN);
	}

	return status;
}

/** \brief Setea Type dentro del auxiliar enviado
 *
 *  \param Arcade* this
 *  \param int type
 *  \return int Retorna 0 = OK
 *                      -1 = Error
 */
int arc_setType(Arcade* this,int type)
{
	int status = FALSE;
	char typeAux[20];

	sprintf(typeAux, "%d", type);
	if(validarEntero(typeAux) == TRUE && this != NULL)
	{
		status = TRUE;
		this->type = type;
	}

	return status;
}

/** \brief Setea Players dentro del auxiliar enviado
 *
 *  \param Arcade* this
 *  \param int players
 *  \return int Retorna 0 = OK
 *                      -1 = Error
 */
int arc_setPlayers(Arcade* this,int players)
{
	int status = FALSE;
	char playerAux[20];

	sprintf(playerAux, "%d", players);
	if(validarEntero(playerAux) == TRUE && this != NULL)
	{
		status = TRUE;
		this->players = players;
	}

	return status;
}

/** \brief Setea Coins dentro del auxiliar enviado
 *
 *  \param Arcade* this
 *  \param int coins
 *  \return int Retorna 0 = OK
 *                      -1 = Error
 */
int arc_setCoins(Arcade* this,int coins)
{
	int status = FALSE;
	char coinAux[20];

	sprintf(coinAux, "%d", coins);
	if(validarEntero(coinAux) == TRUE && this != NULL)
	{
		status = TRUE;
		this->maxCoins = coins;
	}

	return status;
}

/** \brief Setea Name dentro del auxiliar enviado
 *
 *  \param Arcade* this
 *  \param char* name
 *  \return int Retorna 0 = OK
 *                      -1 = Error
 */
int arc_setName(Arcade* this, char* name)
{
	int status = FALSE;

	if(validarCadena(name) == TRUE && this != NULL)
	{
		status = TRUE;
		strncpy(this->name, name, ARCADE_NAME_LEN);
	}

	return status;
}

/** \brief Setea Game dentro del auxiliar enviado
 *
 *  \param Arcade* this
 *  \param char* gameName
 *  \return int Retorna 0 = OK
 *                      -1 = Error
 */
int arc_setGame(Arcade* this, char* gameName)
{
	int status = FALSE;

	if(validarCadena(gameName) == TRUE && this != NULL)
	{
		status = TRUE;
		strncpy(this->gameName, gameName, ARCADE_GAMENAME_LEN);
	}

	return status;
}

// Getters

/** \brief Getea ID a la variable enviada
 *
 *  \param Arcade* this
 *  \param int* id
 *  \return int Retorna 0 = OK
 *                      -1 = Error
 */
int arc_getId(Arcade* this, int* id)
{
	int status = FALSE;

	if(this != NULL)
	{
		status = TRUE;
		*id = this->id;
	}

	return status;
}

/** \brief Getea Country a la variable enviada
 *
 *  \param Arcade* this
 *  \param char* country
 *  \return int Retorna 0 = OK
 *                      -1 = Error
 */
int arc_getCountry(Arcade* this, char* country)
{
	int status = FALSE;

	if(this != NULL)
	{
		status = TRUE;
		strncpy(country, this->country, ARCADE_COUNTRY_LEN);
	}

	return status;
}

/** \brief Getea Type a la variable enviada
 *
 *  \param Arcade* this
 *  \param int* type
 *  \return int Retorna 0 = OK
 *                      -1 = Error
 */
int arc_getType(Arcade* this, int* type)
{
	int status = FALSE;

	if(this != NULL)
	{
		status = TRUE;
		*type = this->type;
	}

	return status;
}

/** \brief Getea players a la variable enviada
 *
 *  \param Arcade* this
 *  \param int* players
 *  \return int Retorna 0 = OK
 *                      -1 = Error
 */
int arc_getPlayers(Arcade* this, int* players)
{
	int status = FALSE;

	if(this != NULL)
	{
		status = TRUE;
		*players = this->players;
	}

	return status;
}

/** \brief Getea Coins a la variable enviada
 *
 *  \param Arcade* this
 *  \param int* coins
 *  \return int Retorna 0 = OK
 *                      -1 = Error
 */
int arc_getCoins(Arcade* this, int* coins)
{
	int status = FALSE;

	if(this != NULL)
	{
		status = TRUE;
		*coins = this->maxCoins;
	}

	return status;
}

/** \brief Getea Name a la variable enviada
 *
 *  \param Arcade* this
 *  \param char* name
 *  \return int Retorna 0 = OK
 *                      -1 = Error
 */
int arc_getName(Arcade* this, char* name)
{
	int status = FALSE;

	if(this != NULL)
	{
		status = TRUE;
		strncpy(name, this->name, ARCADE_NAME_LEN);
	}

	return status;
}

/** \brief Getea Game a la variable enviada
 *
 *  \param Arcade* this
 *  \param char* gameName
 *  \return int Retorna 0 = OK
 *                      -1 = Error
 */
int arc_getGame(Arcade* this, char* gameName)
{
	int status = FALSE;

	if(this != NULL)
	{
		status = TRUE;
		strncpy(gameName, this->gameName, ARCADE_GAMENAME_LEN);
	}

	return status;
}

// Altas, Bajas, Modificación

/** \brief Crea un espacio de memoria para Arcade
 *
 *  \param void
 *  \return Arcade* (NULL)
 *					Espacio de memoria del Arcade
 */
Arcade* arc_new(void)
{

	Arcade* status = malloc(sizeof(Arcade));

	return status;

}
/** \brief Setea los parametros enviados dentro de la dirección de memoria enviada
 *
 *  \param char* id
 *  \param char* country
 *  \param char* type
 *  \param char* players
 *  \param char* maxCoins
 *  \param char* name
 *  \param char* gameName
 *  \return Arcade* (NULL)
 *					Espacio de memoria del Arcade
 */
Arcade* arc_newParameter(char* id, char* country, char* type, char* players, char* maxCoins, char* name, char* gameName)
{
	Arcade* aux = arc_new();

	int auxId;
	int auxType;
	int auxPlayers;
	int auxCoins;

	if(aux != NULL)
	{
		if(validarEntero(id) == TRUE &&
		validarCadena(country) == TRUE &&
		validarEntero(type) == TRUE &&
		validarEntero(players) == TRUE &&
		validarEntero(maxCoins) == TRUE &&
		validarCadena(name) == TRUE &&
		validarCadena(gameName) == TRUE)
		{

			auxId = atoi(id);
			auxType = atoi(type);
			auxPlayers = atoi(players);
			auxCoins = atoi(maxCoins);

			arc_setId(aux, auxId);
			arc_setCountry(aux, country);
			arc_setType(aux, auxType);
			arc_setPlayers(aux, auxPlayers);
			arc_setCoins(aux, auxCoins);
			arc_setName(aux, name);
			arc_setGame(aux, gameName);

		}
	}


	return aux;
}

/** \brief Elimina un elemento de la LinkedList
 *
 *  \param Arcade* this
 *  \param LinkedList* list
 *  \param  int index
 *  \return void
 */
void arc_delete(Arcade* this, LinkedList* list, int index)
{
	if(this != NULL && list != NULL && ll_len(list) > 0 && index >= 0)
	{
		free(this);
		ll_remove(list, index);
	}
}
