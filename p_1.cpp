#include <iostream>
#define DIM 50

using namespace std;

struct Anag
{
    string isbn, titolo, autore, editore, anno, prezzo, tag;
};

int inserimento(Anag libro[])
{
    int n;
    cout<<"Quanti libri vuoi inserire?";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<"Libro n."<<i+1<<endl;
        cout<<"Codice ISBN : ";
        cin>>libro[i].isbn;
        cout<<"Titolo : ";
        cin>>libro[i].titolo;
        cout<<"Autore : ";
        cin>>libro[i].autore;
        cout<<"Editore : ";
        cin>>libro[i].editore;
        cout<<"Anno di Pubblicazione : ";
        cin>>libro[i].anno;
        cout<<"Prezzo : ";
        cin>>libro[i].prezzo;
        cout<<"Tag del Genere : ";
        cin>>libro[i].tag;
    }
    return n;
}

void stampa (Anag libro[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<"\nLibro n."<<i+1;
        cout<<"\nCodice ISBN : "<<libro[i].isbn;
        cout<<"\nTitolo :"<<libro[i].titolo;
        cout<<"\nAutore : "<<libro[i].autore;
        cout<<"\nEditore : "<<libro[i].editore;
        cout<<"\nAnno di Pubblicazione : "<<libro[i].anno;
        cout<<"\nPrezzo : "<<libro[i].prezzo;
        cout<<"\nTag del Genere : "<<libro[i].tag;
    }
}

int ric(Anag libro[], int n)
{
    return 0;
}

void modifica_campi(Anag libro[], int n)
{

}

void elimina_record(Anag libro[], int n)
{
    
}

void menu(int n, Anag libro[], int m)
{
    do{
    cout<<"1) Inserire libro "<<endl<<"2) Visualizzare l’intero catalogo della biblioteca "<<endl<<"3) Cancellare un libro "<<endl<<"4) Ricercare un particolare libro "<<endl<<"5) Effettuare delle modifiche"<<endl<<"6) Uscita"<<endl;
    cin>>m;

    if(m==1)
        n=inserimento(libro);
        cout<<endl;

    if(m==2)
        stampa (libro, n);
        cout<<endl;

    if(m==3)
        elimina_record(libro, n);
        cout<<endl;

    if(m==4)
        int i=ric(libro, n);
        cout<<endl;

    if(m==5)
        int i=ric(libro, n);
        cout<<endl;
        
        modifica_campi(libro, n);
        cout<<endl;

    if(m==6)
        cout<<"Uscito.";

    }while(m!=6);
}

int main()
{
    int n, m;
    Anag libro[DIM];
    menu(n, libro, m);
    
    return 0;
}
