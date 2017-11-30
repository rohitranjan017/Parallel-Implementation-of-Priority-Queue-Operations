#include<bits/stdc++.h>
#include<omp.h>
#include "sibling.h"
#include "insert.h"
#include "deletemin.h"
#include "build.h"
#include "construct.h"
#ifdef G
#define mclock() omp_get_wtime()
#define clockspersec 1
#else
#define mclock() clock()
#define clockspersec CLOCKS_PER_SEC
#endif
#ifdef I
#define flagI 1
#else
#define flagI 0
#endif
#ifdef D
#define flagD 1
#else
#define flagD 0
#endif
using namespace std;
int MH[1000004],NM,ML[1000005];
int main()
{	
	//srand(time(NULL));

	cin>>NM;
	
	for(int i=1;i<=NM;i++)
	{
		MH[i]=rand()%10000;
		
	}
	
	//double tm=omp_get_wtime();
	
	//double tm=clock();
	
	build(NM,MH);
	
  	construct(NM,MH,ML);
  	
  	//cout<<(omp_get_wtime()-tm)<<endl;
  	//cout<<(clock()-tm)/CLOCKS_PER_SEC<<endl;
  	
  	cout<<"DONE\n";
  	double tot=0;
  	
  	int m;
  	
  	cin>>m;
  	
  	while(m--)
  	{
  		string s;
  		
  		//cin>>s;
  		
  		if(0)
  		{
  			int x;
  			
  			//cin>>x;
  			
  			x=rand()%10000;
  			
  			++NM;
  			
  			
  			
  			double tm=mclock();
	
	//double tm=clock();
	
	insert(NM,x,NM,MH,ML);
  	
  	//cout<<(omp_get_wtime()-tm)<<endl;
  	tot+=(mclock()-tm)/clockspersec;
  	//tot+=(clock()-tm)/CLOCKS_PER_SEC;
  	//cout<<(clock()-tm)/CLOCKS_PER_SEC<<endl;
  			
  			//cout<<endl;
  		}
  		else
  		{
  			if(NM==0)
  			{
  				cout<<"Priority Queue empty\n"<<endl;
  				
  			}
  			else
	  		{
	  				//double tm=omp_get_wtime();
	
					double tm=mclock();
	
					int x=deletemin(NM,MH,ML);
				  	
				  	//tot+=(omp_get_wtime()-tm);
				  	tot+=(mclock()-tm)/clockspersec;
				  			
  				//cout<<x<<" popped"<<endl<<endl;
  		
  			}
  			
  			
  			}
  	}
  	
  	cout<<tot<<endl;
 
	
	return 0;
}

