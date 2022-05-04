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
    string cod;
    cout<<"\nLibro da cercare (inserire ISBN): ";
    cin>>cod;
    int i=0;
    do{
        if(libro[i].isbn==cod)
        {
            cout<<"\nLibro trovato.";
           return i;
        }
        i++;
    }while(i<n);
    cout<<"\nLibro non trovato.";
    return 0;
}

void modifica_campi(Anag libro[], int n)
{
    int campo;
    
    int cod=ric(libro, n);
    
    stampa(libro, n);
    
    cout<<"\nCampo da modificare:"<<endl<<"1) Codice ISBN"<<endl<<"2) Titolo"<<endl<<"3) Autore"<<endl<<"4) Editore";
    cout<<endl<<"5) Anno di Pubblicazione"<<endl<<"6) Prezzo"<<endl<<"7) Tag del Genere"<<endl;
    cin>>campo;

    if(campo==1)
    {
        cout<<"Codice ISBN:";
        cin>>libro[cod].isbn;
    }

    if(campo==2)
    {
        cout<<"Titolo : ";
        cin>>libro[cod].titolo;
    }

    if(campo==3)
    {
        cout<<"Autore : ";
        cin>>libro[cod].autore;
    }

    if(campo==4)
    {
        cout<<"Editore : ";
        cin>>libro[cod].editore;
    }

    if(campo==5)
    {
        cout<<"Anno di Pubblicazione : ";
        cin>>libro[cod].anno;
    }
    if(campo==6)
    {
        cout<<"Prezzo : ";
        cin>>libro[cod].prezzo;
    }

    if(campo==7)
    {
        cout<<"Tag del Genere : ";
        cin>>libro[cod].tag;
    }
}

int elimina_record(Anag libro[], int n)
{
    int cod=ric(libro, n);
    if(cod!=0)
        cout<<" Libro cancellato.";
    else
        cout<<" Libro non cancellato, non è stato trovato.";
    
    libro[cod].isbn="";
    libro[cod].titolo="";
    libro[cod].autore="";
    libro[cod].editore="";
    libro[cod].anno="";
    libro[cod].prezzo="";
    libro[cod].tag="";

    return n-1;
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
        n=elimina_record(libro, n);
        cout<<endl;

    if(m==4)
        int i=ric(libro, n);
        cout<<endl;

    if(m==5)
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
