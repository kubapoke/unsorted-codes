#include<bits/stdc++.h>
using namespace std; 

int n, who[20001];

struct str{
	int a;//zwolnienia
	int b;//zatrudnienia
}dni[20001];

/*
5
0 5
0 5
2 0
3 1
5 15

5
0 4
3 3
1 2
3 4
6 3
*/

stack<pair<int, int> > x;//ilu pracowników zatrudnionych przez kogo

bool wyn(int ile, int kto, int pos, stack<pair<int, int> > pra)
{
	/*
	cout<<ile<<"\n";
	for(int i=1; i<=n; i++)
	cout<<who[i]<<" ";
	if(!pra.empty())
	cout<<"\n"<<pra.top().first<<" "<<pra.top().second<<"\n"<<dni[pos].a<<" "<<dni[pos].b<<"\n\n";
	*/
	
	who[pos]=kto;
	stack<pair<int, int> > sec;
	int zw=dni[pos].a;
	
	while(!pra.empty()&&zw>0)
	{
		if(pra.top().second==kto)
		{
			if(kto==ile)
			{
				return false;
			}
			else
			{
				while(!sec.empty())
				{
					pra.push(sec.top());
					sec.pop();
				}
				return wyn(ile,kto+1,pos,pra);
			} 
		}
		else
		{
			if(zw>=pra.top().first)
			{
				zw-=pra.top().first;
				sec.push(pra.top());
				pra.pop();
			}
			else
			{
				pra.top().first-=zw;
				zw=0;
			}
		}	
	}
	if(dni[pos].b>0)
	pra.push({dni[pos].b,kto});
	if(pos==n)
	return true;
	else if(wyn(ile,1,pos+1,pra)==true)
	return true;
	else if(kto==ile)
	return false;
	else
	{
		pra.top().second++;
		return wyn(ile,kto+1,pos,pra);
	}
	
}

int main()
{
	cin>>n;
	
	for(int i=1; i<=n; i++)
	cin>>dni[i].a>>dni[i].b;
	
	int ile=1;
	
	while(1)
	{
		if(wyn(ile,1,1,x)==true)
		break;
		ile++;
	}
	
	cout<<ile<<"\n";
	for(int i=1; i<=n; i++)
	cout<<who[i]<<" ";
	
}
