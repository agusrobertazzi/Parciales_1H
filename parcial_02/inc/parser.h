/*
 * parser.h
 *
 *  Created on: 22 nov. 2021
 *      Author: agust
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "LinkedList.h"
#include "controllers.h"
#include "idController.h"

int parserArcades(FILE* pFile, LinkedList* list);

#endif /* PARSER_H_ */
