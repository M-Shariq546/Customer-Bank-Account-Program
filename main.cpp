#include<iostream>
#include<cstring>
#include<stdio.h>
#include<fstream>
using namespace std;
class Cust
{
    private:
    double id;
    char name[30];
    char balance[10];
    public:
        double account;
        Cust(){};
        Cust(double i, char n[] , char b[]);
        void in();
        void out();
        void storedata();
        void alert();
        void setBalance(char b[]);
        char getBalance();
};
Cust :: Cust(double i, char n[] , char b[])
{
    id = i;
    strcpy(name , n);
    strcpy(balance , b);
}
void Cust:: setBalance(char b[])
{
    strcpy(balance , b);
}
char Cust::getBalance()
{
    return balance[5];
}

void Cust ::in()
{
    start:
    cout<<"Enter the details of the new customer"<<endl;
    cout<<"Enter Customer's unique (Integer Type) ID: ";
    cin>>id;
    cin.ignore(1);
    cout<<"Enter name of account owner: ";
    cin.getline(name , 30);
    cin.ignore(0);
    cout<<"Enter the customer's Balance in RS.: ";
    cin>>balance;
}
void Cust::out()
{
    cout<<""<<endl;
    cout<<"ID: "<<id<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Balance: "<<balance<<endl;
}
void Cust :: storedata()
{
        ofstream fout;
        fout.open("DATA.txt" , ios::app);
        fout<<"The Collected data is given below"<<endl;
        fout<<"ID: "<<id<<endl;
        fout<<"NAME: "<<name<<endl;
        fout<<"BALANCE: "<<balance<<endl;
        fout<<"---------------------------------"<<endl;
        fout.close();
}
int main()
{
    Cust c[2]  , c2 , c1;
    char n;
    double cacc;
    menu:
    cout<<"\t"<<"\t"<<"-:MAIN MENU:-"<<endl;
    cout<<"I- NEW ENTRY"<<endl;
    cout<<"O- OUTPUT"<<endl;
    cout<<"C- CHECK THE DATA IN FILE"<<endl;
    cout<<"S- CHECK CREDIT SCORE"<<endl;
    cout<<"E- EXIT"<<endl;
    cout<<endl;

    cout<<"Enter your choice by Entering corresponding Letter: ";
    cin>>n;
    if(n == 'i' || n == 'I')
        goto I;
        else if(n == 'o' || n == 'O')
        goto o;
        else if(n == 'c' || n == 'C')
        goto C;
        else if(n == 'e' || n == 'E')
        goto e;
        else if(n == 's' || n == 'S')
        goto cscore;
    I:
    for(int i=0 ; i<2 ; i++)
    {
        cout<<"Sr No. "<<(i + 1)<<endl;
        cout<<"Enter Account Number: ";
        cin>>c2.account;
        c[i].in();
        c[i].storedata();
    }
    goto menu;
    o:
    cout<<"The Entered data are : "<<endl;

    for(int i=0 ; i<2 ; i++)
    {
        cout<<"Sr No. "<<(i + 1)<<endl;
        c[i].out();
    }
    goto menu;
    C:
         cout<<"Enter Account number of customer: ";
         cin>>cacc;
         if(cacc != c2.account)
         {
            goto I;
         }
         else
          {
            cout<<"This customer found in the list.";
          }
        goto menu;
      cscore:
              if(c1.getBalance() > 0 || c1.getBalance() < 100)
              {
                  cout<<"The Following customers have low Credit Score."<<endl;
                  for(int i=0 ; i<2 ; i++)
                  {
                      c[i].out();
                  }
              }
              else{
                cout<<"The Following Customers have Good Credit Scores."<<endl;
                for(int i=0 ; i<2 ; i++)
                  {
                      c[i].out();
                  }

              }
              goto menu;
    e:
        exit(0);


}
