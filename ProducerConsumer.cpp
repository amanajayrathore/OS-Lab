#include<iostream>
using namespace std;
	int a[5],item,T=1,s = 1, e = 5, f = 0,option;
int wait(int s)
{
	return(--s);
}
int signal(int s)
{
	return(++s);
}
void producer()
{

e=wait(e);
s=wait(s);
cout<<"Produce:";
cin>>item;
a[f]=item;
s=signal(s);
f=signal(f);

}
void consumer()
{


f=wait(f);
s=wait(s);
cout<<"Consume:";
e--;
s=signal(s);
e=signal(e);

}



main()
{

	while(1)
	{
		cout<<"1. producer  2. consumer  3.  exit";
		cin>>option;
		switch(option)
		{case 1 : if(s==1 && (e != 0))
		producer();
		else cout<<"buffer is full "; break;
		case 2 : if(s==1 && (f != 0))
		consumer();
		else cout<<"buffer is empty "; break;
		case 3 : exit(0); break;
		}
		
	}
}
