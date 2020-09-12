#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#define MASK 00000000000000000000000000000001
#define figlioSx(a) (a<<1)
#define figlioDx(a) ((a<<1)|MASK)
#define padre(a) (a>>1)
#define LUNGHEZZA(x)  (sizeof(x) / sizeof((x)[0]))


void swap(int *a,int i,int max){
	int temp=a[max];
	a[max]=a[i];
	a[i]=temp;
}


void MaxHeapify(int *A, int size, int i)
{
	int massimo;
	int sx=figlioSx(i);
	int dx=figlioDx(i);

	if(sx<=size && A[sx]>A[i]){
		massimo = sx;
	} else {
		massimo = i;
	};
	
	if(dx<=size && A[dx]>A[massimo]){
		massimo = dx;
	}

	if(massimo!=i){
		swap(A,i,massimo);
		MaxHeapify(A,size,massimo);
	}
	
}


void BuildMaxHeap(int *A, int size)
{
	int i;
	for(i = size/2; i >= 1; i--){
		MaxHeapify(A, size, i);
	}
}

void heapsort(int *A,int size){
	BuildMaxHeap(A,size);
	int length=size;
	while(length>=2){
		swap(A,1,length);
		length= length-1;
		for(int i=1;i<10;i++){
			printf("%d ,",A[i]);
		}
		printf("\n");
		MaxHeapify(A,length,1);
	}
}



int main(){
	int a[]={0,98,45,7,78,3,10,5,37,66};
	heapsort(a,LUNGHEZZA(a)-1);
	for(int i=1;i<10;i++){
		printf("%d \n",a[i]);
	}
}