#include<iostream>
#include<cstring>
using namespace std;
class car{
    public:
    //variables are called as data members
    char name[100];
    int model;
    int price;
    int seats;
    
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

    A.print();

    car B;
    strcpy(B.name,"Volvo");
    B.model=2004;
    B.price=200;
    B.seats=7;

    B.print();

    
    
    
    /*
    car A;
    strcpy(A.name,"Audi");
    A.model=2003;
    A.price=100;
    A.seats=5;

    cout<<"Name:"<<A.name<<endl;
    cout<<"Model:"<<A.model<<endl;
    cout<<"Price:"<<A.price<<endl;
    cout<<"Seats:"<<A.seats<<endl;

    car B;
    strcpy(B.name,"Volvo");
    B.model=2004;
    B.price=200;
    B.seats=7;

    cout<<"Name:"<<B.name<<endl;
    cout<<"Model:"<<B.model<<endl;
    cout<<"Price:"<<B.price<<endl;
    cout<<"Seats:"<<B.seats<<endl;
*/


    return 0;
}
