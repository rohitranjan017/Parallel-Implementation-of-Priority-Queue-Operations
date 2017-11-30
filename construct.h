void construct(int &NM,int *MH,int *ML)
{
  int h=log2(NM)+1;	
	
  while(h>0)
  {
  
    #pragma omp parallel for 
    for(int i=(1<<(h-1));i<(1<<(h));i++)
    {
      
      if(i<=NM)
      { 
      	//cout<<i<<endl;
      
		  if(2*i<=NM)
		  {
				if(2*i+1<=NM)
				{
					  if(MH[2*i]<MH[2*i+1])
					  ML[i]=ML[2*i];
					  else
					  ML[i]=ML[2*i+1];
				}
				else
				ML[i]=2*i;
		  }
		  else
		  ML[i]=i;
		
		}
    
    }
    
 	h--;
  }
  
}
