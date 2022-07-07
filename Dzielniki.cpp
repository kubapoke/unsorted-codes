#include<iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, c=0, s, l=0;
	
	cin>>n;
	
	int dzi[100];
	
	for(int i=1; i*i<=n; i++)
    if (n%i==0)
    {
        cout<<i<<endl;
        s=i;
        dzi[c]=n/i;
        c++;
    }
    
    sort(dzi, dzi+100);
    
    for(int i; i<100; i++)
	{
		if(dzi[i]!=i && dzi[i]!=0)
		cout<<dzi[i]<<endl;
	} 
	
	return 0;
}
