#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30
#define SALIR 5

typedef struct _ticket{
    char categoria[25];
    char concepto[200];
    float costo;
}Ticket;

typedef struct _tickets{
    Ticket tickets[MAX];
    int pos;
}Tickets;

int menu();
void capturarDatos(Tickets *alimentos, Tickets *diversion, Tickets *pagos_fijos);
void mostrarGastoAlimentos(Tickets *alimentos);
void mostrarGastoDiversion(Tickets *diversion);
void mostrarGastoPagosFijos(Tickets *pagos_fijos);
void swap(Ticket *xp, Ticket *yp);
