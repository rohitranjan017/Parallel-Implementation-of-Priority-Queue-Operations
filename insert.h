int tVH[1000005],tVL[1000005];
void insert(int L,int I,int &NM,int *MH,int *ML)
{
  int h=log2(L)+1;
 
  
  #pragma omp parallel for
  for(int i=1;i<h;i++)
  {
    tVH[i]=MH[L/(1LL<<(h-i))];
    tVL[i]=ML[L/(1LL<<(h-i))];
  
  }
  tVH[0]=-INT_MAX;
  tVH[h]=INT_MAX;
  int pos=-1;
  #pragma omp parallel for
  for (int i=1;i<=h;i++)
  {
    if(tVH[i]>=I and tVH[i-1]<=I)
    {
      pos=i;
    }
  }

  if(pos==-1)
  {
    //cout<<"tValue "<<I<<" doesn't lie between "<<-INT_MAX<<' '<<INT_MAX<<endl;
    exit(0);
  }
  #pragma omp parallel for
  for(int i=pos+1;i<=h;i++)
  {
    MH[(L/(1LL<<(h-i)))]=tVH[i-1];
    ML[(L/(1LL<<(h-i)))]=L;
  }
  MH[(L/(1LL<<(h-pos)))]=I;
  ML[(L/(1LL<<(h-pos)))]=L;
  int L1,L2;
  if(pos>1)
  {
    L1=ML[L/(1LL<<(h-pos+1))];
    L2=L1;
    if(I<MH[sibling(L,h,pos)])
    {
      L2=L;
    }
    if(L2!=L1)
    {
      #pragma omp parallel for
      for(int i=1;i<pos;i++)
      {
        if(ML[L/(1LL<<(h-i))]==L1)
        {
          ML[(L/(1LL<<(h-i)))]=L2;
        }
      }
    }
  }
}
