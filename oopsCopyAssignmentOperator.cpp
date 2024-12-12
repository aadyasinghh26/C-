#include<iostream>
#include<cstring>
using namespace std;

class car{
    public:
    char name[100];
    int model;
    int price;
    int seats;

    car()
    {
        cout<<"inside default constructor"<<endl;
    }

    car(char*n,int m,int p,int s)
    {
        cout<<"inside parametarised constructor"<<endl;
        strcpy(name,n);
        model=m;
        price=p;
        seats=s;
    }

    car(car &x)
    {
        cout<<"inside copy constructor"<<endl;
        strcpy(name,x.name);
        model=x.model;
        price=x.price;
        seats=x.seats;
    }

    void operator=(car &x)
    {
        cout<<"inside copy assignment operator"<<endl;
        strcpy(name,x.name);
        model=x.model;
        price=x.price;
        seats=x.seats;
    }

    void print()
    {
        cout<<"Name:"<<name<<endl;
        cout<<"Model:"<<model<<endl;
        cout<<"Price:"<<price<<endl;
        cout<<"Seats:"<<seats<<endl<<endl;
    }
};

int main()
{
    car A;
    strcpy(A.name,"Audi");
    A.model=2004;
    A.price=200;
    A.seats=7;

    car B("Volvo",2003,100,5);

    car C=B;
    
    C=A;

    A.print();
    B.print();
    C.print();

    return 0;
}
