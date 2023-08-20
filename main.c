#include <stdio.h>
#include <stdlib.h>

#defibe

typedef struct _ticket{
    char categoria[16];
    char concepto[200];
    float costo;
}sTicket;

typedef sTicket *Ticket;

int main(){

    //Captura de datos
    Ticket tickets;
    
    while(termina == SALIR){
        termina = menu();
        switch(termina){
            case 1:
                capturarDatos(tickets, N);
            break;
            case 2:
                mostrarAlimentos(tickets, N);
                break;
        }
    }

    mostrarDatos();

    return 0;
}