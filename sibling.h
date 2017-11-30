int sibling(int L,int h,int i)
{
	int K=L/(1<<(h-i));
	
	if(K%2)
	return K-1;
	else
	return K+1;
}
