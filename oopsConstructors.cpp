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
        cout<<"Inside parametarised constructor"<<endl;
        strcpy(name,n);
        model=m;
        price=p;
        seats=s;
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
    A.model=2003;
    A.price=100;
    A.seats=5;

    car B("Volvo",2004,200,7);

    A.print();
    B.print();

    return 0;
    
}