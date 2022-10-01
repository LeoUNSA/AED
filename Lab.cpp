#include <iostream>
using namespace std;
struct nodo{
    int co,exp;
    nodo*next;
};
struct pol{
    nodo * head=NULL;
};
nodo *head=NULL;
void print(nodo *head){
    nodo *x=new nodo();
    x=head;
    while(x!=NULL){
        cout<<x->co<<","<<x->exp<<" - ";
        x=x->next;
    }
}
void insert(nodo *&head, int c,int e){
    nodo *new_nodo=new nodo();
    new_nodo->co=c;new_nodo->exp=e;
    if(head==NULL){ 
        new_nodo->next=NULL;}
    new_nodo->next=head;
    head=new_nodo;
    cout<<"Elemento insertado. \n";
}
void add(nodo *head, int c,int e){
    nodo *new_nodo=new nodo();
    new_nodo->co=c;
    new_nodo->exp=e;
    new_nodo=head;
    if(head==NULL){ 
        new_nodo->next=NULL;
        head=new_nodo;}
    while(new_nodo->exp>new_nodo->next->exp){
        new_nodo=new_nodo->next;
    }new_nodo->next->next=new_nodo;
    cout<<"Elemento insertado. \n";
}

void interface(){
    int a,b,c;
    do{
        cout<<"\nOpciones: \n1: Insertar elementos a la lista. \n2. Mostrar lista. \n3. Insertar en orden\n4. Salir.";cin>>a;
        switch(a){
            case 1:cout<<"Ingrese el valor del nodo: \n";cin>>b>>c;insert(head,b,c);break;
            case 2:print(head);break;
            case 3:cout<<"Ingrese el valor del nodo: \n";cin>>b>>c;add(head,b,c);break;
            case 4:cout<<"Adiós.\n";
        }
    }while(a!=4);
}
int main(){
    interface();
    return 0;
}
