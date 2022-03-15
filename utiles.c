#include "tiempo.h"
#include <time.h>

#define ERROR -1

time_t tiempo;

void iniciar_cronometro(){
   if(tiempo != 0) return;
   tiempo = time(NULL);
}

int tiempo_actual(){
   if(tiempo == 0) return ERROR;
   time_t tiempo_actual = time(NULL);
   return tiempo_actual - tiempo;
}

int detener_cronometro(){
   if(tiempo == 0) return ERROR;
   time_t tiempo_actual = time(NULL);
   int tiempo_total = tiempo_actual - tiempo;
   tiempo = 0;
   return tiempo_total;
}
