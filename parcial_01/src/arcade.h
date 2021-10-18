/*
 * arcade.h
 *
 *  Created on: 16 oct. 2021
 *      Author: agust
 */

#ifndef ARCADE_H_
#define ARCADE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_ops.h"
#include "defines.h"

typedef struct{
	int isEmpty;
	int id;
	char country[100];
	int type;
	int players;
	int maxAmount;
	int idSalon;
	char gameName[63];
}Arcade;

int initArcade(Arcade* list, int len);
int findArcadeByID(Arcade* list, int len, int id);
int deleteArcade(Arcade* list, int len, int id);
int printArcades(Arcade* list, int len);
int printGames(Arcade* list, int len);
int modifyArcade(Arcade* list, int len, int id);

#endif /* ARCADE_H_ */
