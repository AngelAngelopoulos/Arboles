//
//  Pilla.h
//  arbol
//
//  Created by Angel Alvarado on 11/12/18.
//  Copyright © 2018 Angel Alvarado. All rights reserved.
//

#ifndef Pila_h
#define Pila_h

typedef struct nodo //Estructura de tipo elemento
{
    int data;  //Contenido de la estructura (datos)
    struct nodo *sig;  //nodo de tipo nodo que sera la liga de enlace
}*PILA;  //Tipo de estructura nodo (apuntador)


void iniPila(PILA *top);
int push(PILA *top, int dato);
void capturaPila(PILA *top);
int creaNodo(PILA *nuevo, int dato);
int pop(PILA *top, int *dato);
void imprimePila(PILA top);

#endif /* Pilla_h */

void iniPila(PILA *top)
{
    *top = NULL;
}

int push(PILA *top, int dato)
{
    int res = 0;
    PILA nuevo;
    
    res = creaNodo(&nuevo, dato);
    
    if (res == 1)
    {
        if (*top != NULL)
        {
            nuevo->sig = *top;
        }
        *top = nuevo;
    }
    return (res);
}


void capturaPila(PILA *top)
{
    int dato, res = 0;
    int resp;
    
    do
    {
        printf("Esribe el dato:\n");
        scanf("%d", &dato);
        res = push(top, dato);
        
        if (res)
            printf("Dato ingresado\n");
        else
            printf("Dato no ingresado\n");
        
        printf("1.Otro dato\n0.Terminar\n");
        scanf("%d", &resp);
    } while (resp == 1);
}

int creaNodo(PILA *nuevo, int dato)
{
    int res = 0;
    
    *nuevo = (struct nodo*)malloc(sizeof(struct nodo));
    
    if (*nuevo != NULL)
    {
        res = 1;
        (*nuevo)->data = dato;
        (*nuevo)->sig = NULL;
    }
    return (res);
}

int pop(PILA *top, int *dato)
{
    int res = 0;
    PILA aux;
    
    if (*top)
    {
        aux = *top;
        *dato = aux->data;
        *top = (*top)->sig;
        free(aux);
        res = 1;
    }
    return (res);
}

void imprimePila(PILA top)
{
    int res = 0, valor;
    printf("Los datos de la pila son: \n");
    
    while (top)
    {
        res = pop(&top, &valor);
        printf(" %d ", valor);
    }
}
