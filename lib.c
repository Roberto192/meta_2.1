#include "lib.h"

int menu()
{
    int opcion;
    int state;

    do
    {
        puts("");
        puts("1.- Capturar gasto");
        puts("2.- Mostrar gasto en alimentos");
        puts("3.- Mostrar gasto en diversión");
        puts("4.- Mostrar gasto en pagos fijos");
        puts("5.- Salir");
        printf("Ingrese la opción deseada: ");

        fflush(stdin);
        state = scanf("%d", &opcion);
    } while (!state);

    return opcion;
}

void capturarDatos(Tickets *alimentos, Tickets *diversion, Tickets *pagos_fijos)
{

    Ticket nuevo_ticket;
    Tickets *aux;
    short todoBien = 0;

    do
    {
        puts("");
        printf("Ingrese la categoría [alimentos/diversion/pagosfijos/cancelar]: ");
        fflush(stdin);
        scanf("%s", nuevo_ticket.categoria);
        todoBien = 0;
        if (strcmp(nuevo_ticket.categoria, "alimentos") == 0)
        {
            aux = (alimentos);
        }
        else if (strcmp(nuevo_ticket.categoria, "diversion") == 0)
        {
            aux = (diversion);
        }
        else if (strcmp(nuevo_ticket.categoria, "pagosfijos") == 0)
        {
            aux = (pagos_fijos);
        }
        else if (strcmp(nuevo_ticket.categoria, "cancelar") == 0)
        {
            return;
        }
        else
        {
            puts("Categoría no válida");
            todoBien = 1;
        }
    } while (todoBien);

    printf("Ingrese el concepto: ");
    fflush(stdin);
    scanf("%s", nuevo_ticket.concepto);

    printf("Ingrese el costo: ");
    fflush(stdin);
    scanf("%f", &(nuevo_ticket.costo));

    (aux->tickets)[aux->pos++] = nuevo_ticket;
}

void mostrarGastoAlimentos(Tickets *alimentos)
{

    int n = alimentos->pos;

    for (int i = 1; i < n; i++)
    {
        double key = (alimentos->tickets)[i].costo;
        int j = i - 1;

        while (j >= 0 && (alimentos->tickets)[i].costo > key)
        {
            (alimentos->tickets)[j + 1].costo = (alimentos->tickets)[i].costo;
            j--;
        }
        (alimentos->tickets)[j + 1].costo = key;
    }

    puts("Gasto en Alimentos:");
    for (int i = 0; i < n; i++)
    {
        puts("");
        printf("%s\n", (alimentos->tickets)[i].concepto);
        printf("$%.2f\n", (alimentos->tickets)[i].costo);
    }
    printf("\n");
}

void mostrarGastoDiversion(Tickets *diversion)
{

    int n = diversion->pos;

    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if ((diversion->tickets)[j].costo < (diversion->tickets)[min_index].costo)
            {
                min_index = j;
            }
        }
        swap(&((diversion->tickets)[i]), &((diversion->tickets)[min_index]));
    }
    puts("\nGasto en Diversión:");
    for (int i = 0; i < n; i++)
    {
        puts("");
        printf("%s\n", (diversion->tickets)[i].concepto);
        printf("$%.2f\n", (diversion->tickets)[i].costo);
    }
    printf("\n");
}

void mostrarGastoPagosFijos(Tickets *pagos_fijos)
{

    int n = pagos_fijos->pos;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if ((pagos_fijos->tickets)[j].concepto > (pagos_fijos->tickets)[j + 1].concepto)
            {
                swap(&((pagos_fijos->tickets)[j]), &((pagos_fijos->tickets)[j + 1]));
            }
        }
    }

    printf("%d", n);
    puts("Gasto de Pagos Fijos:");
    for (int i = 0; i < n; i++)
    {
        puts("");
        printf("%s\n", (pagos_fijos->tickets)[i].concepto);
        printf("$%.2f\n", (pagos_fijos->tickets)[i].costo);
    }
    printf("\n");
}

void swap(Ticket *xp, Ticket *yp)
{

    Ticket temp = *xp;
    *xp = *yp;
    *yp = temp;
}
