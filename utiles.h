#ifndef __UTILES_H__
#define __UTILES_H__

/*
 * Inicia el cronómetro.
 */
void iniciar_cronometro();

/*
 * Retorna el tiempo actual en segundos desde que se inicio el cronómetro.
 * En caso de error, retorna un -1
 */
int tiempo_actual();

/*
 * Detiene el cronómetro, devolviendo el tiempo total desde que se inicio en segundos.
 * En caso de error, retorna un -1
 */
int detener_cronometro();


#endif /* __UTILES_H__ */
