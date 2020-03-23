/*
 * setdist.h
 *
 *  Created on: 19 de mar de 2020
 *      Author: Heitor H V Guimarães
 */

#ifndef INIT_DIST_SETDIST_H_
#define INIT_DIST_SETDIST_H_

int periodo_inicial;
int periodo_meio;
int periodo_final;
int periodo_total = periodo_inicial+periodo_meio+periodo_final;

int distancia_inicial_tempo;
int distancia_meio_tempo;
int distancia_final_tempo;
int distancia_total= distancia_inicial_tempo+distancia_meio_tempo+distancia_final_tempo;
int distancia_media = distancia_total/3;

typedef enum {
	DIST_VALIDA,
	DIST_SEMSINAL
};

typedef init_dist_t *calibra_dist[3] = {30, 10000};

void config_dist(init_dist_t);

#endif /* INIT_DIST_SETDIST_H_ */
