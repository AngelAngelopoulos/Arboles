//
//  main.c
//  arbol
//
//  Created by Angel Alvarado on 11/7/18.
//  Copyright © 2018 Angel Alvarado. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"

typedef struct nodoAB
{
    struct nodoAB *izq;
    struct nodoAB *der;
    int dato;
}*AB;


void inicializaAB(AB *tree);
int creaNodoAB(AB *nuevo, int dato);
int insertaNodoABREC(AB *tree, int dato);
int insertaNodoABITE(AB *tree, int dato);
int insertaNodoOrdREC(AB *tree, int dato);
void preOrdenABREC(AB tree);
void enOrdenABREC(AB tree);
void posOrdenABREC(AB tree);


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

void inicializaAB(AB *tree)  //Inicializa el arbol a valores nulos
{
    (*tree) = NULL;
}

int creaNodoAB(AB *nuevo, int dato) //Funcion de creacion de nodo de tipo arbol
{
    int res = 0;
    *nuevo = (AB)malloc(sizeof(struct nodoAB));
    
    if (*nuevo)
    {
        (*nuevo)->der = NULL;
        (*nuevo)->izq = NULL;
        (*nuevo)->dato = dato;
        res = 1;
    }
    return (res);
}

int insertaNodoABREC(AB *tree, int dato)  //Funcion de insercion guiada *recursiva*
{
    int res;
    char resp;
    
    if (!*tree)
    {
        res = creaNodoAB(tree, dato);
        printf("El nodo ha sido agregado!\n");
    }
    else
    {
        printf("Izquierda o Derecha: \n");
        fflush(stdin);
        scanf("%c", &resp);
        if (resp == 'i' || resp == 'I')
        {
            res = insertaNodoABREC(&(*tree)->izq, dato);
        }
        else if (resp == 'd' || resp == 'D')
        {
            res = insertaNodoABREC(&(*tree)->der, dato);
        }
        else
        {
            printf("Inserte una opcion valida [i]/[d]\n");
            res = insertaNodoABREC(tree, dato);
        }
    }
    return(res);
}

int insertaNodoABITE(AB *tree, int dato)  //Funcion de insercion guiada *iterativa*
{
    int res = 0;
    char resp;
    
    if (!*tree)
    {
        res = creaNodoAB(tree, dato);
        printf("El nodo ha sido agregado!\n");
    }
    else
    {
        do
        {
            printf("Izquierda o Derecha: \n");
            fflush(stdin);
            scanf("%c", &resp);
            if (resp == 'i' || resp == 'I')
            {
                res = creaNodoAB(&(*tree)->izq, dato);
            }
            else if (resp == 'd' || resp == 'D')
            {
                res = creaNodoAB(&(*tree)->der, dato);
            }
            else
            {
                printf("Inserte una opcion valida [i]/[d]\n");
                res = insertaNodoABREC(tree, dato);
            }
        } while(res == 0);
    }
    return(res);
}

int insertaNodoOrdREC(AB *tree, int dato)  //Inserta nodo de manera *ordendada* (los menores a la izquierda)
{
    int res;
    
    if (!*tree)
    {
        res = creaNodoAB(tree, dato);
        printf("El dato se ha insertado con exito\n");
    }
    else
    {
        if (dato <= (*tree)->dato)
        {
            res = insertaNodoOrdREC(&(*tree)->izq, dato);
        }
        else
        {
            res = insertaNodoOrdREC(&(*tree)->der, dato);
        }
    }
    return (res);
}

void preOrdenABREC(AB tree)  //A->B->C
{
    if (tree)
    {
        printf("%d\n", tree->dato);
        preOrdenABREC(tree->izq);
        preOrdenABREC(tree->der);
    }
}

void enOrdenABREC(AB tree)  //B->A->C
{
    if (tree)
    {
        enOrdenABREC(tree->izq);
        printf("%d\n", tree->dato);
        enOrdenABREC(tree->der);
    }
}

void posOrdenABREC(AB tree)  //B->C->A
{
    if (tree)
    {
        posOrdenABREC(tree->izq);
        posOrdenABREC(tree->der);
        printf("%d\n", tree->dato);
    }
}

void preOrdenABITE(AB tree)
{
    PILA pila;
    iniPila(&pila);
    push( &pila, tree); //checar compatibilidad
    while (pop(&pila, &tree))  //checar compatibilidad
    {
        printf("%d\t", tree->dato);
        
        if (tree->der)
        {
            push(&pila, tree->der);  //checar compatibilidad
        }
        if (tree->izq)
        {
            push(&pila, tree->izq);  //checar compatibilidad
        }
    }
}

/*Calcula el numero de hojas*/
int hojasAB(AB tree)
{
    int hojas;

    if (!tree)
        hojas = 0;
    else
    {
        if (tree->der && tree->izq)
            hojas = 1;
        else
            hojas = hojasAB(tree->izq) + hojasAB (tree->der);
    }
    return(hojas);
}

/*Funcion para calcular costo*/



/*Tarea :Funcion para calcular el numero de nodos internos*/
//Determinar si un arbol esta completo
//Determoinar si dos arboles son iguales

/*Funcion  que calcula el numero de nodos internos*/
int NodosInternos(AB tree)
{
    int res;

    if (!tree)
        res = 0;
    else
        if (tree->izq && tree->der) 
            res = 1;
        else
            res = NodosInternos(tree->izq) + NodosInternos(tree->der);
    return(res);
}

/*Funcion que verifica si dos arboles son iguales*/
int sonIguales(AB tree, AB tree2)
{
    int res, band;
    if (tree == tree2)
    {
        res = sonIguales(tree->izq, tree2->izq);
        res = sonIguales(tree->der, tree2->der);
        band = 1;
    }
    else
    {
        res = 0;
        band = 0
    }
    return(res * band);
}


/*Funcion que verifica que un arbol este compelto*/
int estaCompleto(AB tree)
{
    int res, res2; 
    if (tree->izq && tree->der)
    {
        res = estaCompleto(tree->izq); 
        res2 = estaCompleto(tree->der);
        if ((res && res2) || (!res && !res2))
            res = 1
    }
    else
        res = 0;
    return(res);
}

/*Funcion para obtener altura de un arbol*/
void obtenerAltura(AB tree, int nivel, int *alt)
{
    int res;
    if (tree)
    {
        obtenerAltura(tree->der, nivel++, alt);
        
        if (nivel > alt)
        {
            *alt = nivel;
        }

        obtenerAltura(tree->izq, nivel++, altura);
    }
}

/*Funcion para buscar un nodo*/
int busquedaAB(AB tree, int valor)
{
    int res;
    if (tree)
    {
        if (valor == tree->dato)
            res = 1;
        else{
            res = busquedaAB(tree->izq, valor);
            res = busquedaAB(tree->der, valor);
        }
    }
    else
    {
        res = 0;
    }
    return(valor);
}
