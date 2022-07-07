#include<iostream>
#include <iomanip>      
using namespace std;

int main()
{
	ios_base::sync_with_stdio;
	cin.tie(0);
	
	register float D, N, suma=0, najw=0, najm=21, W, score=60, K, BS, BK;
	
	cin>>D>>K;
	
	if(D>=K)
	score+=((D-K)*1.8);
	else
	score-=((K-D)*1.8);
	
	for(int i=0; i<5; i++)
	{
		cin>>N;
		suma+=N;
		if(N>najw)
		najw=N;
		if(N<najm)
		najm=N;
	}
	
	suma-=(najw+najm);
	
	score+=suma;
	
	cin>>BS>>BK;
	
	if(BS>BK)
	score-=((BS-BK)*3.2);
	else
	score+=((BK-BS)*3.2);
	
	cin>>W;
	
	score+=W;
	
	cout<<std::fixed;
	
	cout<<std::setprecision(1)<<score;
	
	
	return 0;
}
