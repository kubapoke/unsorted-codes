#include<bits/stdc++.h>
using namespace std;

int n, xp, yp, xa, ya, xb, yb;

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>xp>>yp>>xa>>ya>>xb>>yb;
		
		int S=(xp-xa)*(yb-ya)-(yp-ya)*(xb-xa);
		
		if(S==0 && xp>=min(xa,xb) && xp<=max(xa,xb) && yp>=min(ya,yb) && yp<=max(ya,yb))
		cout<<"TAK\n";
		else cout<<"NIE\n";
	}
}
