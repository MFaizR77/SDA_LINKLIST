#include <limits.h>
#include <malloc.h>
#include "header.h"

boolean ListEmpty (List L)

{
	 return (First(L) == Nil);
}


void CreateList (List * L)

{
	 First(*L) = Nil;
}

address Alokasi (infotype X)

{
	 address P;
	 P = (address) malloc (sizeof (ElmtList));
	 if (P != Nil)		
	 {
	Info(P) = X;
	Next(P) = Nil;
	 }
	 return (P);
}

void DeAlokasi (address P)

{
	 if (P != Nil)
	 {
	free (P);
	 }
}


address Search (List L, infotype X)

{
	
	 address P;
	 boolean found =  false;
	
	 P = First(L);
	 while ((P != Nil) && (!found))
	 {
		if (Info(P) == X)
		{	found = true; 	}
		else
		{	P = Next(P);	}
	 }
	
	 return (P);
}

boolean FSearch (List L, address P)

{
	 
	 boolean found=false;
	 address PSearch;
	
	 PSearch = First(L);
	 while ((PSearch != Nil) && (!found))
	 {
		if (PSearch == P)
		{	found = true; 	}
		else
		{	PSearch = Next(PSearch);	}
	 }	
	 
	 return (found);
}

address SearchPrec (List L, infotype X)
{
	
	address Prec, P;
	boolean found=false;
	
	Prec = Nil;
	P = First(L);
	while ((P != Nil) && (!found))
	{
		 if (Info(P) == X)
		 {	found = true;	}
		 else
		 {
			Prec = P;
			P = Next(P);
		 }
	}    
	if (found)
	{	return (Prec);		}
	else
	{	return (Nil);		}
}


void InsVFirst (List * L, infotype X)
{
	address P;
    P = Alokasi(X);
	if (P != Nil){
       Next(P)= First(*L);
	   First(*L)= P;
	}

}

void InsVLast (List * L, infotype X)
{
	 address P;
	 address temp;
	 P = Alokasi(X);
	 if (P!= Nil){
	    if (ListEmpty(*L)){
			First(*L)= P;
		} else{
			temp = First(*L);
			while (Next(temp)!= Nil)
			{
				temp = Next(temp);
			}
			Next(temp) = P;
		}
    }
}

void DelVFirst (List * L, infotype * X)
{
	address P;
    P = First(*L);
	*X = Info(P);
	First(*L)= Next(P);
	DeAlokasi(P);
}

void DelVLast (List * L, infotype * X)
{
	address PDel, Prec;
	PDel = First(*L);
    if (Next(PDel) == Nil){
		*X = Info(PDel);
		First(*L)= Nil;
		DeAlokasi(PDel);
	} else{
       Prec = Nil;
	   while(Next(PDel) != Nil){
         Prec = PDel;
         PDel = Next(PDel);
	    }
		*X = Info(PDel);
		Next(Prec) = Nil;
		DeAlokasi(PDel);
	}
}


void InsertFirst (List * L, address P)
{
	Next(P) = First(*L);
	First(*L) =P;
}

void InsertAfter (List * L, address P, address Prec)
{
	Next(P)=Next(Prec);
	Next(Prec) = P;
}

void InsertLast (List * L, address P)
{
	address Last;
	Last = First(*L);

	if (ListEmpty(*L)) {
        First(*L) = P;  
    } else {
        Last = First(*L);
        while (Next(Last) != Nil) {
            Last = Next(Last);
        }
        Next(Last) = P;
    }
}



void DelFirst (List * L, address * P)
{
	*P = First(*L);
	First(*L) = Next (*P);
	DeAlokasi(*P);
} 


void DelP (List * L, infotype X)
{
	address P, Prec;
	boolean found=false;
	P = First (*L);
	Prec = Nil;

    while (P!= Nil && found == false){
	   if(Info(P) == X){
           found = true;
	   } else {
		  Prec = P;
		  P = Next(P);
	   }
	}

	if (found){
		if (Prec == Nil){
           First(*L) = Next(P);
		} else
		{
			Next(Prec)= Next(P);
		}
		DeAlokasi(P);
	}
}

void DelLast (List * L, address * P)
{
	address Prec;
    *P = First(*L);
	if (Next(*P) == Nil){
        First(*L) = Nil;
	} else{
	    Prec = Nil;
		while (Next(*P) != Nil){
			Prec = *P;
			*P = Next (*P);
		}
		Next(Prec) = Nil;
	}
	DeAlokasi(*P);
}

void DelAfter(List *L, address *Pdel, address Prec) {
    if (Prec != Nil && Next(Prec) != Nil) {
        *Pdel = Next(Prec);
        Next(Prec) = Next(*Pdel);
        DeAlokasi(*Pdel);
    }
}

void PrintInfo(List L) {\

    address P = First(L); 

    if (P == NULL) {
        printf("List kosong\n");
        return;
    }

    while (P != NULL) {
        printf("%d -> ", Info(P));
        P = Next(P);
    }

    printf("NULL\n");
}



void DelAll (List * L)
{
	address PDel;
	while (First(*L)!= Nil){
		PDel = First(*L);
		First(*L) = Next (PDel);
		DeAlokasi(PDel);
	}
}

void DelAllGanjil (List *L)
{
    address PDel, Prec, P;
    P = First(*L);
    Prec = Nil;

    while (P != Nil) {
        if (Info(P) % 2 != 0) { 
            PDel = P;
            if (Prec == Nil) { 
                First(*L) = Next(P);
            } else {
                Next(Prec) = Next(P);
            }
            P = Next(P);
            DeAlokasi(PDel);
        } else {
            Prec = P; 
            P = Next(P); 
        }
    }
}
