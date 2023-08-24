#include "lib.h"

int main(){

    int opcion = 0, n;
    Tickets alimentos = {.pos = 0};
    Tickets diversion = {.pos = 0};
    Tickets pagos_fijos = {.pos = 0};

    while(opcion != SALIR){
        opcion = menu();

        switch(opcion){
            case 1: {
                capturarDatos(&alimentos, &diversion, &pagos_fijos);
                break;
            }
            case 2: {
                mostrarGastoAlimentos(&alimentos);
                break;
            }
            case 3:{
                mostrarGastoDiversion(&diversion);
                break;
            }
            case 4:{
                mostrarGastoPagosFijos(&pagos_fijos);
                break;
            }
        }
    }

    return 0;
}