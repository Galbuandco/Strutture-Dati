#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct dato{
	int valore;
	struct dato *prossimo_nodo;
}nodo;

nodo *crealistavuota(){
	return NULL;
};

nodo *inserisci(nodo *head,int key){
	nodo *nuovo = malloc(sizeof(nodo));
	nuovo->prossimo_nodo= head;
	head = nuovo;
	nuovo->valore = key;
	return nuovo;
};

int visita(nodo *head){
	printf("%d \n",head->valore);
	if(head->prossimo_nodo==NULL){
		return 0;
	}
	visita(head->prossimo_nodo);
	return 0;
}

nodo *cerca(nodo *head,int key){
	if (head->valore==key){
		return head;
	}else{
		if(head->prossimo_nodo==NULL){
		return NULL;
	}
		cerca(head->prossimo_nodo,key);
	}
}

nodo *delete(nodo *head,int key){
	
}

int main (){
	nodo *root=crealistavuota();
	root = inserisci(root,10);
	root = inserisci(root,20);
	root = inserisci(root,30);
	visita(root);
	nodo *venti = cerca(root,20);
	printf("nodo con valore 20: %ld",(long int) venti);
    return 0;
}