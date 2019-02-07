#include<iostream>
using namespace std;
int main()
{
	int n,q,t=0,avgwt=0,avgtat=0;
	cout<<"Enter number of process";
	cin>>n;
	int bt[n],wt[n],rbt[n],tat[n];
	cout<<"Enter time quantum "<<endl;
	cin>>q;
	cout<<"Enter the burst time of process";
	for(int i=0;i<n;i++)
	{
		cin>>bt[i];
	}
	for(int i=0;i<n;i++)
	{
		wt[i]=0;
		tat[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		rbt[i]=bt[i];
	}
	while(1)
	{
	bool done=true;
		for(int i=0;i<n;i++)
		{
			if(rbt[i]>0)
			{
			done=false;
			if(rbt[i]>q)
			{
			t=t+q;
			rbt[i]=rbt[i]-q;
			}
			else
			{
				t=t+rbt[i];
				wt[i]=t-bt[i];
				rbt[i]=0;
			}
			}
		}
		if(done==true) break;
	}
	for(int i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
	}
	cout<<"Process    Burst time   Waiting time     Turnaround time"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"p"<<i+1<<"              "<<bt[i]<<"          "<<wt[i]<<"             "<<tat[i]<<endl;
	}
	for(int i=0;i<n;i++)
	{
		avgwt=avgwt+wt[i];
		avgtat=avgtat+tat[i];
	}
	cout<<"Average waiting time is"<<avgwt/n<<endl;
	cout<<"Average tat time is"<<avgtat/n<<endl;
	
}

