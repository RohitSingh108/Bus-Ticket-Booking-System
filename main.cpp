#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;
static int p = 0;
class busres
{char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];
public:
void Selecting();
  void allotment();
  void notfilled();
  void display();

  void position(int i);
}

bus[10];
void vline(char ch)
{for (int i=80;i>0;i--)
cout<<ch;
}

void busres::Selecting()
{cout<<"Enter bus no: ";
cin>>bus[p].busn;
cout<<"\nEnter Driver's name: ";
cin>>bus[p].driver;
cout<<"\nArrival timing(24 hrs clock): ";
cin>>bus[p].arrival;
cout<<"\nDeparture timing(24 hrs clock): ";
cin>>bus[p].depart;
cout<<"\nFrom: \t\t\t";
cin>>bus[p].from;
cout<<"\nTo: \t\t\t";
cin>>bus[p].to;
bus[p].notfilled();
p++;
}

void busres::allotment()
{int seat;
char number[5];
  top:
  cout<<"Bus no: ";
  cin>>number;
  int n;
  for(n=0;n<=p;n++)
  {if(strcmp(bus[n].busn, number)==0)
break;
}

while(n<=p)
{cout<<"\nSeat Number: ";
cin>>seat;
    if(seat>32)
    {cout<<"\nThere are only 32 seats available in this bus.";
    }

    else
    {if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "-")==0)
         {
            cout<<"Enter passanger's name: ";
            cin>>bus[n].seat[seat/4][(seat%4)-1];
            cout<<"You have successfully booked seat number "<<seat<< " in bus number: "<< bus[n].busn;
            break;
        }

    else
cout<<"The seat number is already reserved.\n";
}
}

if(n>p)
{cout<<"Enter correct bus number\n";
goto top;
}
}


void busres::notfilled()
{for(int i=0; i<8;i++)
{
for(int j=0;j<4;j++)
{
strcpy(bus[p].seat[i][j], "-"); //empty
}
}
}


void busres::display()
{int n;
char number[5];
cout<<"Enter bus no: ";
cin>>number;

  for(n=0;n<=p;n++)
  {if(strcmp(bus[n].busn, number)==0)
break;
  }

while(n<=p)
{vline('*');
cout<<"Bus no: \t"<<bus[n].busn
<<"\nDriver: \t"<<bus[n].driver<<"\t\tArrival time: \t"<<bus[n].arrival<<"\tDeparture time:"<<bus[n].depart<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"<<
  bus[n].to<<"\n";
  vline('*');
  bus[0].position(n);
  int a=1;
  for (int i=0; i<8; i++)
  {
for(int j=0;j<4;j++)
{
a++;
if(strcmp(bus[n].seat[i][j],"-")!=0)
cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<"."; 
}
}
break;
  }
  if(n>p)
    cout<<"Enter correct bus no: ";
}


void busres::position(int l)
{  int s=0;p=0;
for (int i =0; i<8;i++)
  {
          cout<<"\n";
for (int j = 0;j<4; j++)
    {
      s++;
      if(strcmp(bus[l].seat[i][j], "-")==0)
        {
          cout.width(5);
          cout.fill(' ');
          cout<<s<<".";
          cout.width(10);
          cout.fill(' ');
          cout<<bus[l].seat[i][j];
          p++;
        }


        else
{        cout.width(5);
cout.fill(' ');
        cout<<s<<".";
        cout.width(10);
        cout.fill(' ');
        cout<<bus[l].seat[i][j];
        }
}
    }
  cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bus[l].busn; 
  }


int main()
{
system("cls");
int w;

while(1)
{

    //system("cls");
  cout<<"\n\n\n\n\n";

 cout<<"\n\n\n\n\n";

  cout<<"\t\t\t\t\tWELCOME TO BUS RESERVATION\n";
  cout<<"\t\t\t\t\t*********************************\n\n";
  cout<<"\t\t\t\t\t* 1.CHOOSE YOUR JOURNEY         *\n";
  cout<<"\t\t\t\t\t*                               *\n";
  cout<<"\t\t\t\t\t* 2.DISPLAY THE SEATS AVAILABLE *\n";
  cout<<"\t\t\t\t\t*                               *\n";
  cout<<"\t\t\t\t\t* 3.BOOK YOUR SEAT              *\n";
  cout<<"\t\t\t\t\t*                               *\n";
  cout<<"\t\t\t\t\t* 4.DISPLAY AFTER BOOKING       *\n";
  cout<<"\t\t\t\t\t*                               *\n";
 cout<<"\t\t\t\t\t* 5.EXIT                        *\n\n";
  cout<<"\t\t\t\t\t*********************************\n";

  cout<<"\n\t\t\t\tEnter your choice:-> ";
  cin>>w;
switch(w)
  {
    case 1:  bus[p].Selecting();
      break;

    case 2:  bus[0].display();
      break;

    case 3:  bus[p].allotment();
      break;

    case 4:  bus[0].display();
      break;

    case 5:  exit(0);

  }
}

return 0;

}

