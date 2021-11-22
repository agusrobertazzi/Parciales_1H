/*
 * controllers.h
 *
 *  Created on: 21 nov. 2021
 *      Author: agust
 */

#ifndef CONTROLLERS_H_
#define CONTROLLERS_H_

#include <stdio.h>
#include <stdlib.h>
#include "arcades.h"
#include "defines.h"
#include "LinkedList.h"
#include "parser.h"

// Controllers
int controller_find(LinkedList* this, int id);
int controller_printArc(LinkedList* this, int index);
int controller_listArc(LinkedList*this);
int controller_printGames(LinkedList* this);

//ABM Controller
int controller_add(LinkedList* this);
int controller_edit(LinkedList* this, int id);
int controller_delete(LinkedList* this, int id);

// Others
int controller_sort(LinkedList* this, int order);
int controller_addCsv(char* path, LinkedList* list);
int controller_saveArcades(char* path, LinkedList* list);
int controller_saveGames(char* path, LinkedList* list);
int controller_filterMultiplayer(LinkedList* this);
int controller_duplCoins(LinkedList* this);

#endif /* CONTROLLERS_H_ */
