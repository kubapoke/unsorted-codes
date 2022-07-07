#include<iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, c=0, s=0;
	
	cin>>n;
	
	int dzi[1000];
	
	for(int i; i<1000; i++)
	{
		dzi[i]=0;
	}
	
	
	for(int i = 1; i * i <= n; i++)
    if (n % i == 0)
    {
        dzi[c]=i;
        dzi[c+1]=n/i;
        c=c+2;
    }
    
    sort(dzi, dzi+1000);
    
    for(int i; i<1000; i++)
	{
		if(dzi[i]!=s && dzi[i]!=0)
		{
			cout<<dzi[i]<<endl;
			s=dzi[i];
		}
	} 
	
	return 0;
}
