#ifndef INFORMES_H_
#define INFORMES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_ops.h"
#include "defines.h"
#include "abmSalonArcade.h"

int informeCuatroArcades(Salon* listSalon, int lenSalon, Arcade* listArcade, int lenArcade);
int arcadeDosJugadores(Arcade* listArcade, int lenArcade, Salon* listSalon, int lenSalon);
int infoDetailSalon(Salon* listSalon, int lenSalon, Arcade* listArcade, int lenArcade, int id);
int listarArcades(Arcade* listArcade, int lenArcade, Salon* listSalon, int lenSalon, int id);
int listarMasCantidad(Arcade* listArcade, int lenArcade, Salon* listSalon, int lenSalon);
int calcularValor(Arcade* list, int len, int id, int value);
int contadorJuegos(Arcade* list, int len, char ingreso[]);
// PARTE 2 DEL EXAMEN
int salonCompleto(Salon* listSalon, int lenSalon, Arcade* listArcade, int lenArcade);
int promedioSalonArcade(Salon* listSalon, int lenSalon, Arcade* listArcade, int lenArcade);

#endif /* INFORMES_H_ */
