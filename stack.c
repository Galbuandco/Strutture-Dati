#include <stdio.h>
#define LISTA struct nodo
#include <stdlib.h>


typedef struct nodo stack;

struct nodo{
    int key;
    LISTA *next;
};  

LISTA *insert(LISTA *lista,int valore){
    LISTA *temp = malloc(sizeof(LISTA));
    temp->key = valore;
    temp->next = lista;
    return temp;
}

stack *pop(stack *pila)
{
    int value = pila->key;
    printf("%d \n",value);
    stack *delete = pila;
    pila = pila->next;
    free(delete);
    return pila;
}

stack *push(stack *pila, int value)
{
    return (stack *)insert((LISTA *)pila, value);
}

int main()
{
    stack *my_stack = malloc(sizeof(stack));
    my_stack = push(my_stack, 10);
    my_stack = push(my_stack, 20);
    my_stack = push(my_stack, 30);
    my_stack = push(my_stack, 40);

    my_stack = pop(my_stack);
    my_stack = pop(my_stack);
    my_stack = pop(my_stack);

    my_stack = push(my_stack, 40);
    my_stack = pop(my_stack);
    my_stack = pop(my_stack);
}