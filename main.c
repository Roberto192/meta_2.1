#include "lib.h"

int main(){

    int opcion = 0;
    Tickets alimentos = {.pos = 0};
    Tickets diversion = {.pos = 0};
    Tickets pagos_fijos = {.pos = 0};

    while(opcion != SALIR){
        opcion = menu();

        switch(opcion){
            case 1:
                capturarDatos(&alimentos, &diversion, &pagos_fijos);
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
        }
    }

    return 0;
}