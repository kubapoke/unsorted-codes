#include<iostream>
#include<cmath>
#include<math.h>
#include<iomanip>
#include<algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	register int a, b=0, m=0;
	string pil;
	
	cin>>a;
	cin>>pil;
	
	for(int i=0; i<pil.length(); i++)
	if(pil[i]=='b')
	b++;
	
	for(int i=0; i<b; i++)
	if(pil[i]=='b')
	m++;
	
	cout<<b-m;
	
}
