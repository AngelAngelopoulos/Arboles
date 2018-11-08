//
//  main.c
//  arbol
//
//  Created by Angel Alvarado on 11/7/18.
//  Copyright © 2018 Angel Alvarado. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct nodoAB
{
    struct nodoAB *izq;
    struct nodoAB *der;
    int dato;
}*AB;

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


