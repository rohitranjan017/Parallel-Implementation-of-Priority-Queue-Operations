using namespace std;
int VH[1000004],RANK1[1000004],RANK2[1000004],RANK3[1000004],RANK4[1000004],VL[1000004];
int temp[1000004],tempnex[1000004],nex[1000004];
int deletemin(int &NM,int* MH,int* ML)
{
	int ret=MH[1];
	
	int L=ML[1];
	
	int h=floor(log2(L))+1;

	
	
	
	#pragma omp parallel for
	for(int i=1;i<=h-1;i++)
	{
		VH[i]=MH[L/(1<<(h-i-1))];
		
	}
	
	VH[h]=INT_MAX,RANK1[1]=0,RANK2[1]=0;
	
	#pragma omp parallel for
	for(int i=2;i<=h;i++)
	{
		if(sibling(L,h,i)>NM or VH[i]>=MH[sibling(L,h,i)])
		RANK1[i]=1;
		else
		RANK1[i]=0;
		
		RANK2[i]=RANK1[i];
	}
	

	

	
	#pragma omp parallel for
	for(int i=1;i<=h;i++)
	nex[i]=i+1;
	
	nex[h]=-1;
	
	for(int cnt=0;cnt<=log2(h);cnt++)
	{
		#pragma omp parallel for
		for(int i=1;i<=h;i++)
		temp[i]=RANK2[i],tempnex[i]=nex[i];
	
		#pragma omp parallel for
		for(int i=1;i<=h;i++)
		{
			if(nex[i]!=-1)
			{
				temp[nex[i]]=RANK2[nex[i]]+RANK2[i];
				tempnex[i]=nex[nex[i]];
			}

		}
		
		#pragma omp parallel for
		for(int i=1;i<=h;i++)
		RANK2[i]=temp[i],nex[i]=tempnex[i];
	
	}
	

	
	#pragma omp parallel for
	for(int i=2;i<=h;i++)
	{
		if(RANK1[i]==1)
		RANK3[RANK2[i]]=i;
		
	}

	
	#pragma omp parallel for
	for(int i=1;i<=h-1;i++)
	{
		RANK4[i]=RANK3[RANK2[i]+1];
		
		if(sibling(L,h,RANK4[i])>NM)
		VL[i]=sibling(L,h,RANK4[i])/2;
		else
		if(sibling(L,h,RANK4[i])==NM)
		VL[i]=L/(1<<(h-RANK4[i]));
		else
		VL[i]=ML[sibling(L,h,RANK4[i])];

	}
	
	#pragma omp parallel for
	for(int i=1;i<=h-1;i++)
	{
		MH[L/(1<<(h-i))]=VH[i];
		
		ML[L/(1<<(h-i))]=VL[i];
	}
	
	
	
	int I=MH[NM];
	
	MH[NM]=ML[NM]=INT_MAX;
	
	insert(L,I,NM,MH,ML);
	
	#pragma omp parallel for
	for(int i=1;i<=h-1;i++)
	if(ML[NM/(1<<(h-i))]==NM)
	ML[NM/(1<<(h-i))]=NM/2;
	
	NM=NM-1;
	
	

	return ret;	
	
}
