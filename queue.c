#include "queue.h"

/*Membuat sebuah queue baru dengan Front dan Rear NULL*/
void CreateQueue (Queue *Q)
{
	Q->First = NULL;
}

/*Memeriksa apakah queue kosong */
boolean is_Empty (Queue Q)
{
	 return (isEmpty(Q));
}

/*Memeriksa apakah queue penuh */
boolean is_Full (Queue Q)
{
	 return (IsFull(Q));
}

/*Melekukan insertion pada queue*/
void EnQueue (Queue *Q, infotype X)
{
	InsVLast(&(*Q), X);	//nama modul disesuaikan dengan pseudocode linked list pribadi
}

/*Melakukan deletion pada queue*/
void deQueue (Queue *Q, infotype *X)
{
	 DelVFirst(&(*Q),&(*X)); //nama modul disesuaikan dengan pseudocode linked list pribadi
}

