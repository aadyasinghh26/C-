#include<iostream>
#include<cstring>
using namespace std;

class car
{
    private:
    int price;
    public:
    char name[100];
    int model;
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

    void print()
    {
        cout<<"Name:"<<name<<endl;
        cout<<"Model:"<<model<<endl;
        cout<<"Price:"<<price<<endl;
        cout<<"Seats:"<<seats<<endl<<endl;
    }

    void setPrice(int p)         //setter
    {
        if (p>100 and p<200)
        price=p;
        else
        price=150;
    }

    int getPrice()             //getter
    {
        return price;
    }

    
};

int main()
{
    car A;
    strcpy(A.name,"Audi");
    A.model=2003;
    A.setPrice(-100);
    A.seats=5;

    car B("Volvo",2004,200,5);

    car C(B);

    C=A;

    A.print();
    B.print();
    C.print();

    return 0;

}