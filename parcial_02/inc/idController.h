/*
 * idController.h
 *
 *  Created on: 21 nov. 2021
 *      Author: agust
 */

#ifndef IDCONTROLLER_H_
#define IDCONTROLLER_H_

#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "LinkedList.h"
#include "arcades.h"

int arc_setMaxId(char* path, LinkedList* list);
int arc_getMaxId(char* path, LinkedList* list);

#endif /* IDCONTROLLER_H_ */
