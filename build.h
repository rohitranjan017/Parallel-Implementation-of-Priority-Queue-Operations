#include<bits/stdc++.h>
using namespace std;
void build(int &NM, int* MH)
{
	for(int i=0;i<=log2(NM);i++)
	{
		#pragma omp parallel for
		for(int i=1;i<=NM;i++)
		{
			int h=0;
			
			int x=i;
		
			while(x)
			h++,x/=2;
		
			if(i%2==0 and h%2==0)
			{
				if(2*i+1<=NM and MH[i]>MH[2*i+1])
				swap(MH[i],MH[2*i+1]);
				else
				if(2*i<=NM and MH[i]>MH[2*i])
				swap(MH[i],MH[2*i]);
			
			}
		}
		
		#pragma omp parallel for
		for(int i=1;i<=NM;i++)
		{
			int h=0;
			
			int x=i;
		
			while(x)
			h++,x/=2;
		
			if(i%2==0 and h%2==1)
			{
				if(2*i+1<=NM and MH[i]>MH[2*i+1])
				swap(MH[i],MH[2*i+1]);
				else
				if(2*i<=NM and MH[i]>MH[2*i])
				swap(MH[i],MH[2*i]);
			
			}
		}
		
		
		#pragma omp parallel for
		for(int i=1;i<=NM;i++)
		{
			int h=0;
			
			int x=i;
		
			while(x)
			h++,x/=2;
		
			if(i%2==1 and h%2==0)
			{
				if(2*i+1<=NM and MH[i]>MH[2*i+1])
				swap(MH[i],MH[2*i+1]);
				else
				if(2*i<=NM and MH[i]>MH[2*i])
				swap(MH[i],MH[2*i]);
			
			}
		}
		
		#pragma omp parallel for
		for(int i=1;i<=NM;i++)
		{
			int h=0;
			
			int x=i;
		
			while(x)
			h++,x/=2;
		
			if(i%2==1 and h%2==1)
			{
				if(2*i+1<=NM and MH[i]>MH[2*i+1])
				swap(MH[i],MH[2*i+1]);
				else
				if(2*i<=NM and MH[i]>MH[2*i])
				swap(MH[i],MH[2*i]);
			
			}
		}
		
	}
}
