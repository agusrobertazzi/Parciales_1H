/*
 * arcades.h
 *
 *  Created on: 21 nov. 2021
 *      Author: agust
 */

#ifndef ARCADES_H_
#define ARCADES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defines.h"
#include "LinkedList.h"
#include "idController.h"
#include "utn_ops.h"

struct {

int id;
char country[ARCADE_COUNTRY_LEN];
int type;
int players;
int maxCoins;
char name[ARCADE_NAME_LEN];
char gameName[ARCADE_GAMENAME_LEN];

}typedef Arcade;

// Settters
int arc_setId(Arcade* this,int id);
int arc_setCountry(Arcade* this, char* country);
int arc_setType(Arcade* this,int type);
int arc_setPlayers(Arcade* this,int players);
int arc_setCoins(Arcade* this,int coins);
int arc_setName(Arcade* this, char* name);
int arc_setGame(Arcade* this, char* gameName);

// Getters
int arc_getId(Arcade* this, int* id);
int arc_getCountry(Arcade* this, char* country);
int arc_getType(Arcade* this, int* type);
int arc_getPlayers(Arcade* this, int* players);
int arc_getCoins(Arcade* this, int* coins);
int arc_getName(Arcade* this, char* name);
int arc_getGame(Arcade* this, char* gameName);

// Arcades
Arcade* arc_new(void);
Arcade* arc_newParameter(char* id, char* country, char* type, char* players, char* maxCoins, char* name, char* gameName);
void arc_delete(Arcade* this, LinkedList* list, int index);
#endif /* ARCADES_H_ */
