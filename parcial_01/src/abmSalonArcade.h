#ifndef ABMSALONARCADE_H_
#define ABMSALONARCADE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_ops.h"
#include "defines.h"
#include "arcade.h"
#include "salon.h"

int addArcade(Arcade* listArcade, int lenArcade, Salon* listSalon, int lenSalon);
int deleteSalon(Salon* listSalon, int lenSalon, int id, Arcade* listArcade, int lenArcade);
// Forzadas
int salonForzado(Salon* list, int len, int pos, int id,char* name, char* adress, int type);
int arcadeForzado(Arcade* list, int len, int pos, int id, char* country, int type, int player, int maxAmount, int idSalon, char* gameName);

#endif /* ABMSALONARCADE_H_ */
