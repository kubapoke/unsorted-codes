#include<bits/stdc++.h>
using namespace std;

int N, dlu[500005], wys[500005], wyn[500005], w;
stack<pair<int,int> > S;

int main()
{
	cin>>N;
	for(int i=0; i<N; i++)
	{
		cin>>dlu[i];
	}
	for(int i=0; i<N; i++)
	{
		cin>>wys[i];
	}
	
	for(int i=0; i<N; i++)
	{
		if(S.empty())
		S.push({wys[i],i});
		else
		{
			if(wys[i]<S.top().first)
			S.push({wys[i],i});
			else
			{
				while(!S.empty()&&wys[i]>S.top().first)
				{
					wyn[S.top().second]+=i-S.top().second;
					S.pop();
				}
				S.push({wys[i],i});
			}
			
		}
	}
	while(!S.empty())
	{
		wyn[S.top().second]+=10000000;
		S.pop();
	}
	
	for(int i=N-1; i>=0; i--)
	{
		if(S.empty())
		S.push({wys[i],i});
		else
		{
			if(wys[i]<S.top().first)
			S.push({wys[i],i});
			else
			{
				while(!S.empty()&&wys[i]>S.top().first)
				{
					wyn[S.top().second]+=S.top().second-i;
					S.pop();
				}
				S.push({wys[i],i});
			}
			
		}
	}
	while(!S.empty())
	{
		wyn[S.top().second]+=10000000;
		S.pop();
	}
	
	sort(wyn, wyn+N);
	sort(dlu, dlu+N);
	int j=0;
	
	for(int i=0; i<N, j<N; i++)
	{
		if(wyn[j]>dlu[i])
		{
			//cout<<wyn[i]<<dlu[j]<<endl;
			w++; j++;
		}
		else
		{
			while(wyn[j]<=dlu[i]&&j<N)
			j++;
			if(wyn[j]>dlu[i])
			{
				//cout<<wyn[i]<<dlu[j]<<endl;
				w++; j++;
			}
		}
	}
	
	cout<<w;
}
