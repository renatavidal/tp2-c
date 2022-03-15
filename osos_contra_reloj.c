#include "test_de_personalidad.h"
#include <time.h>

#define MAX_FILAS 30
#define MAX_COLUMNAS 20
#define VELA 'V'
#define LINTERNA 'L'
#define PILA 'B'
#define BENGALA 'E'
#define MINIBOSQUE 'M'
#define PIEDRA 'R'
#define KOALAS 'K'
#define CHLOE 'C'

void inicializar_personaje(personaje_t* personaje){
		personaje->tipo= tipo_personaje;
		personaje->posicion.fil= rand ()%MAX_FILAS;
		personaj->posicion.col= rand ()%MAX_COLUMNAS;
		personaje->elemento_en_uso= -1;
		personaje->tiempo_perdido=0;
		personaje->mochila[0].tipo= LINTERNA;
		personaje->mochila[1].tipo= VELA;
		personaje->mochila[1].tipo= VELA;
		personaje->mochila[2].tipo= VELA;
		personaje->mochila[3].tipo= VELA;
		personaje->mochila[4].tipo= VELA;
	if(personaje->tipo== PARDO){
		personaje->mochila[0].movimientos_restantes= 15;
		personaje->mochila[1].movimientos_restantes= 5;
		personaje->mochila[2].movimientos_restantes= 5;
		personaje->mochila[3].movimientos_restantes= 5;
		personaje->mochila[4].movimientos_restantes= 5;
	}
	else if (personaje->tipo == POLAR){
		personaje->mochila[5].tipo= VELA;
		personaje->mochila[6].tipo= VELA;
		personaje->mochila[0].movimientos_restantes= 10;
		personaje->mochila[1].movimientos_restantes= 5;
		personaje->mochila[2].movimientos_restantes= 5;
		personaje->mochila[3].movimientos_restantes= 5;
		personaje->mochila[4].movimientos_restantes= 5;
		personaje->mochila[5].movimientos_restantes= 5;
		personaje->mochila[6].movimientos_restantes= 5;
	}
	else{
		personaje->mochila[5].tipo= BENGALA;
		personaje->mochila[6].tipo= BENGALA;
		personaje->mochila[0].movimientos_restantes= 10;
		personaje->mochila[1].movimientos_restantes= 5;
		personaje->mochila[2].movimientos_restantes= 5;
		personaje->mochila[3].movimientos_restantes= 5;
		personaje->mochila[4].movimientos_restantes= 5;
		personaje->mochila[5].movimientos_restantes= 3;
		personaje->mochila[6].movimientos_restantes= 3;
	}
}

bool se_pisa(char obstaculos[MAX_OBSTACULOS], coordenada_t amiga, int fil, int col, int tope, char herramientas[MAX_HERRAMIENTAS],int tope_herramientas){
	for (int i = 0; i < tope; ++i){
		if(obstaculos[i].fil == fil && obstaculos[i].col == col)
			return true;
	}
	if (amiga.fil == fil && amiga.col ==col)
		return true;
	for (int i = 0; i < tope_herramientas; ++i){
		if(herramientas[i].fil == fil && herramientas[i].col == col)
			return true;
	}
	return false;
}
void inicializar_obstaculos(juego_t* juego){
	for (int i = 0; i < 50; ++i){
		juego->obstaculos[i].tipo= MINIBOSQUE;
		juego->obstaculos[i].fil= rand()%MAX_FILAS;
		juego->obstaculos[i].col= rand()%MAX_COLUMNAS;
		while(juego->obstaculos[i].col == uego->amiga_chloe.col &&  juego->obstaculos[i].fil == uego->amiga_chloe.fil){
			juego->obstaculos[i].fil= rand()%MAX_FILAS;
			juego->obstaculos[i].col= rand()%MAX_COLUMNAS;
		}
		juego->cantidad_obstaculos++;	
	}
	for (int i = 0; i < 80; ++i){
		juego->obstaculos[i].tipo= PIEDRA;
		juego->obstaculos[i].fil=rand()%MAX_FILAS;
		juego->obstaculos[i].col=rand()%MAX_COLUMNAS;
		while(se_pisa(juego->obstaculos, juego->amiga_chloe, i ,j, juego->cantidad_obstaculos)){
			juego->obstaculos[i].fil= rand()%MAX_FILAS;
			juego->obstaculos[i].col= rand()%MAX_COLUMNAS;
		}
		juego->cantidad_obstaculos++;	
	}
}

void inicializar_herramientas(juego_t* juego){
	for (int i = 0; i < 30; ++i){
		juego->herramientas[i].tipo= PILA;
		juego->herramientas[i].fil=rand()%MAX_FILAS;
		juego->herramientas[i].col=rand()%MAX_COLUMNAS;
		while(se_pisa(juego->obstaculos, juego->amiga_chloe, i ,j, juego->cantidad_obstaculos, juego->herramientas, juego->cantidad_herramientas)){
			juego->herramientas[i].fil= rand()%MAX_FILAS;
			juego->herramientas[i].col= rand()%MAX_COLUMNAS;
		}
		juego->cantidad_herramientas++;	
	}
	for (int i = 0; i < 30; ++i){
		juego->herramientas[i].tipo= VELA;
		juego->herramientas[i].fil=rand()%MAX_FILAS;
		juego->herramientas[i].col=rand()%MAX_COLUMNAS;
		while(se_pisa(juego->obstaculos, juego->amiga_chloe, i ,j, juego->cantidad_obstaculos, juego->herramientas, juego->cantidad_herramientas)){
			juego->herramientas[i].fil= rand()%MAX_FILAS;
			juego->herramientas[i].col= rand()%MAX_COLUMNAS;
		}
		juego->cantidad_herramientas++;	
	}
	for (int i = 0; i < 30; ++i){
		juego->herramientas[i].tipo= BENGALA;
		juego->herramientas[i].fil=rand()%MAX_FILAS;
		juego->herramientas[i].col=rand()%MAX_COLUMNAS;
		while(se_pisa(juego->obstaculos, juego->amiga_chloe, i ,j, juego->cantidad_obstaculos, juego->herramientas, juego->cantidad_herramientas)){
			juego->herramientas[i].fil= rand()%MAX_FILAS;
			juego->herramientas[i].col= rand()%MAX_COLUMNAS;
		}
		juego->cantidad_herramientas++;	
	}

}
void inicializar_juego(juego_t* juego , char tipo_personaje){
	inicializar_personaje(juego.personaje);
	juego->amiga_chloe.fil= rand()%MAX_FILAS;
	juego->amiga_chloe.col= rand()%MAX_COLUMNAS;
	inicializar_obstaculos(juego);
	inicializar_herramientas(juego);
}

int estado_juego(juego_t juego){
	if(juego.amiga_chloe.fil != juego.personaje.posicion.fil || juego.amiga_chloe.col != juego.personaje.posicion.col)
		return 0;
	else if(juego.amiga_chloe.fil == juego.personaje.posicion.fil && juego.amiga_chloe.col== juego.personaje.posicion.col && juego.personaje.tiempo_perdido> 120)
		return -1;
	else if(juego.amiga_chloe.fil == juego.personaje.posicion.fil && juego.amiga_chloe.col== juego.personaje.posicion.col && juego.personaje.tiempo_perdido<= 120)
		return 1;
	return 2;
}

void realizar_jugada(juego_t* juego , char jugada){
	
}