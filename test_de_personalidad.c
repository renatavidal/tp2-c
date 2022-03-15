#include "test_de_personalidad.h"
#include <stdio.h>
#include <stdbool.h>


const char ANIME = 'A';
const char MUSICA_POP = 'M';
const char LIMPIEZA = 'L';
const int PUNTAJE_ANIME = 2;
const int PUNTAJE_MUSICA_POP = 3;
const int PUNTAJE_LIMPIEZA = 1;

const char BAMBU = 'B';
const char PESCADO = 'P';
const char FOCAS = 'F';
const int PUNTAJE_BAMBU = 6;
const int PUNTAJE_PESCADO = 9;
const int PUNTAJE_FOCAS = 3;

const int MINIMO_PISO_PERMITIDO = 1;
const int MAXIMO_PISO_PERMITIDO = 18;

const int MINIMO_GRITO_PERMITIDO = 1;
const int MAXIMO_GRITO_PERMITIDO = 18;

const int MENOR_PUNTAJE_POLAR = 5;
const int MAYOR_PUNTAJE_POLAR = 24;
const int MENOR_PUNTAJE_PANDA = 25;
const int MAYOR_PUNTAJE_PANDA = 43;
const int MENOR_PUNTAJE_PARDO = 44;
const int MAYOR_PUNTAJE_PARDO = 63;


//PRE: Opciones de canal de television: ANIME, MUSICA POP O LIMPIEZA.
//POST: Devuelve TRUE si se elije ANIME, MUSICA POP O LIMPIEZA como canal de television.
bool es_canal_de_television_valido(char canal_de_television){
	return (canal_de_television == ANIME || canal_de_television == MUSICA_POP || canal_de_television == LIMPIEZA);
}

//PRE: Recibe un caracter.
//POST: Imprime por pantalla y scanea el canal elegido. Si el canal no esta dentro de las opciones dadas, lo vuelve a preguntar.
void pedir_canal_de_television(char* canal_de_television){
	printf("Vas a ver television un rato, pones el canal de: (%c,%c,%c):", ANIME, MUSICA_POP, LIMPIEZA);
	scanf(" %c", canal_de_television);

	while(!es_canal_de_television_valido(*canal_de_television)){
		printf("Ese canal de television no existe. Te doy otra oportunidad. (%c,%c,%c):", ANIME, MUSICA_POP, LIMPIEZA);
		scanf(" %c", canal_de_television);
	}
}

//PRE: Canales de television posibles son ANIME, MUSICA POP, LIMPIEZA. Cada uno tiene puntajes distintos.
//POST: Se adquiere cierto puntaje dependiendo de que canal se elije.
void elegir_canal_television (char canal_de_television, int* puntaje_por_canal){
	if (canal_de_television == ANIME){
		(*puntaje_por_canal) = PUNTAJE_ANIME;
	}else if (canal_de_television == MUSICA_POP){
		(*puntaje_por_canal) = PUNTAJE_MUSICA_POP;
	}else{
		(*puntaje_por_canal) = PUNTAJE_LIMPIEZA;
	}
}	


//PRE: Opciones de alimento son BAMBU, PESCADO o FOCA.
//POST: Devuelve TRUE si el alimento elegido esta en las opciones.
bool es_alimento_valido (char alimento){
	return (alimento == BAMBU || alimento == PESCADO || alimento == FOCAS);
}

//PRE: Recibe un caracter.
//POST: Imprime por pantalla y scanea el alimento elegido. Si el alimento no esta dentro de las opciones dadas, lo vuelve a preguntar.
void pedir_alimento (char* alimento){
	printf("Solo podes guardar un alimento en tu vianda: (%c,%c,%c):", BAMBU, PESCADO, FOCAS);
	scanf(" %c", alimento);

	while(!es_alimento_valido(*alimento)){
		printf("Ese alimento es muy grande, no entra. Elegi otro: (%c,%c.%c):", BAMBU, PESCADO, FOCAS);
		scanf(" %c", alimento);
	}
}

//PRE: Hay 3 opciones de alimento: BAMBU, OESCADO Y FOCAS, cada uno con distinto puntaje.
//POST: Se adquiere cierto puntaje en base al alimento elegido.
void elegir_alimento (char alimento, int* puntaje_por_alimento){
	if(alimento == BAMBU){
		(*puntaje_por_alimento) = PUNTAJE_BAMBU;
	}else if (alimento == PESCADO){
		(*puntaje_por_alimento) = PUNTAJE_PESCADO;
	}else{
		(*puntaje_por_alimento) = PUNTAJE_FOCAS;
	}
}


//PRE: El rango de piso es mayor o igual a 1 o menor o igual a 18.
//POST: Devuelve TRUE si el numero elegido de piso esta entre 1 y 18, ambos inclusives.
bool es_piso_valido (int piso_de_la_torre){
	return ((piso_de_la_torre >= MINIMO_PISO_PERMITIDO) && (piso_de_la_torre <= MAXIMO_PISO_PERMITIDO));
}

//PRE: Recibe un numero.
//POST: Imprime y scanea el numero de piso elegido, si el numero no esta dentro del rango, lo vuelve a pedir hasta que 
//se cumpla la condicion.
void pedir_piso (int* piso_de_la_torre){
	printf("Te compras una torre con tus hermanos de 18 pisos. ¿En que piso te gustaria"\
	" vivir? (entre %i - %i):", MINIMO_PISO_PERMITIDO, MAXIMO_PISO_PERMITIDO);
	scanf(" %i", piso_de_la_torre);

	while(!es_piso_valido(*piso_de_la_torre)){
		printf("Ese piso no existe. Elegi otro (entre %i - %i):", MINIMO_PISO_PERMITIDO, MAXIMO_PISO_PERMITIDO);
		scanf(" %i", piso_de_la_torre);
	}
}

//PRE: El rango de piso es entre 1 a 18, ambos inclusives.
//POST: Se obtiene un puntaje igual al piso elegido. 
void elegir_piso (int piso_de_la_torre, int* puntaje_por_piso){
	if(es_piso_valido(piso_de_la_torre)){
		(*puntaje_por_piso) = (piso_de_la_torre);
	}
}

//PRE: El rango de fuerza de grito es mayor o igual a 1 o menor o igual a 18.
//POST: Devuelve TRUE si el numero de grito elegido esta entre 1 y 18, ambos inclusives.
bool es_grito_valido (int grito){
	return ((grito >= MINIMO_GRITO_PERMITIDO) && (grito <= MAXIMO_GRITO_PERMITIDO));
}

//PRE: Recibe un numero.
//POST: Imprime y scanea el numero elegido, si este esta fuera del rango, lo vuelve a pedir hasta que 
//se cumpla la condicion.
void preguntar_fuerza_del_grito (int* grito){
	printf("¡Oh, una rata! ¿Que tan fuerte gritas del 1 al 18? Siendo 1 no gritar y 18 desgarrarse"\
	" la garganta.(entre %i - %i):", MINIMO_GRITO_PERMITIDO, MAXIMO_GRITO_PERMITIDO);
	scanf(" %i", grito);

	while(!es_grito_valido(*grito)){
		printf("Ese nivel de fuerza no existe. Te dejo elegir de "\
		" vuelta (entre %i - %i):", MINIMO_GRITO_PERMITIDO, MAXIMO_GRITO_PERMITIDO);
		scanf(" %i", grito);
	}
}

//PRE: Rango valido de fuerza de grito de 1 a 18 inclusives.
//POST: Se determina un puntaje igual al numero de piso elegido.
void gritar_o_no (int grito, int* puntaje_por_grito){
	if(es_grito_valido(grito)){
		(*puntaje_por_grito) = (grito);
	}
}


//PRE: Recibe los datos con sus respectivos puntajes.
//POST: Resuelve un puntaje total.
void calcular_puntaje_total(int* puntaje_total, int puntaje_por_alimento, int puntaje_por_canal, int puntaje_por_grito, int puntaje_por_piso){
	(*puntaje_total) = (puntaje_por_alimento * puntaje_por_canal) + puntaje_por_piso + puntaje_por_grito;
}

//PRE: Puntaje total entre 5 y 4 (inclusives) da POLAR, entre 25 y 43 (inclusives), PANDA, y entre 44 y 63 (inclusives), PARDO.
//POST: Dependiendo el puntaje obtenido, imprime resultado de POLAR, PANDA o PARDO.
char determinar_tipo_de_oso (int puntaje_total){
	if((puntaje_total >= MENOR_PUNTAJE_POLAR) && (puntaje_total <= MAYOR_PUNTAJE_POLAR)){
		printf("Despues de un arduo analisis, se determino que la personalidad mas adecuada para definirte es: - Polar (%c) -."\
		"Podes ser el mas joven, pero eso no te quita tu madurez.", POLAR);
		return POLAR;
	}else if((puntaje_total >= MENOR_PUNTAJE_PANDA) && (puntaje_total <= MAYOR_PUNTAJE_PANDA)){
		printf("Parece que sos el mas tierno y delicado del trio. El super test de personalidad determino que tu personalidad "\
		"escandalosa coincide con la de - Panda (%c) -.", PANDA);
		return PANDA;
	}else{
		printf("- Pardo (%c) - es el oso escandaloso mas coincidente con tu personalidad. ¿Como te va siendo el lider del trio?", PARDO);
		return PARDO;
	}
}


char personaje(){

	char canal_de_television;
	int puntaje_por_canal = 0;

	pedir_canal_de_television(&canal_de_television);
	elegir_canal_television(canal_de_television, &puntaje_por_canal);
	
	char alimento;
	int puntaje_por_alimento = 0;

	pedir_alimento(&alimento);
	elegir_alimento(alimento, &puntaje_por_alimento);
	
	int piso_de_la_torre = 0;
	int puntaje_por_piso = 0;

	pedir_piso(&piso_de_la_torre);
	elegir_piso(piso_de_la_torre, &puntaje_por_piso);
	
	int grito = 0;
	int puntaje_por_grito = 0;

	preguntar_fuerza_del_grito(&grito);
	gritar_o_no(grito, &puntaje_por_grito);

	int puntaje_total = 0;
	calcular_puntaje_total(&puntaje_total, puntaje_por_alimento, puntaje_por_canal, puntaje_por_piso, puntaje_por_grito);
	return determinar_tipo_de_oso(puntaje_total);
}