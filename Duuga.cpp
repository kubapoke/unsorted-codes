#include<iostream>
using namespace std;

int main()
{
	string n, w;
	int x=0;
	bool czyzero=true;
	bool czydod=false;
	
	cin>>n>>w;
	
	char bruh[n.size()+1];
	char bruh2[n.size()+1];
	int j=w.size()-1;
	
	int z[1]={1};
	
	for(int i=0; i<n.size()+1; i++)
	{
		bruh[i]=0;
		bruh2[i]=0;
	}
	
	if(n[n.length()-1]%2!=0)
	czydod=true;
	
	//dzielenie przez 2
	
	for(int i=0; i<n.size(); i++)
	{
		n[i]-=48;
		
		if(n[i]>=2)
		{
			n[i+1]+=(n[i]%2)*10;
			n[i]=n[i]/2;
		}
		else
		{
			n[i+1]+=n[i]*10;
			n[i]=0;
		}
		
		n[i]+=48;
		
		while(n[i]>57)
		n[i]-=10;
	}
		
	for(int i=0; i<w.size(); i++)
	{
		w[i]-=48;
		
		if(w[i]>=2)
		{
			w[i+1]+=(w[i]%2)*10;
			w[i]=w[i]/2;
		}
		else
		{
			w[i+1]+=w[i]*10;
			w[i]=0;
		}
		
		w[i]+=48;
		
		while(w[i]>57)
		w[i]-=10;
	}
	
	//dodawanie
	
	for(int i=n.size()-1; i>=0; i--)
	{
		if(j>=0)
		{
			n[i]-=48;
			w[j]-=48;
			
			bruh[i]+=n[i]+w[j];
			
			while(bruh[i]>=10)
			{
				bruh[i]-=10;
				bruh[i-1]++;
			}
			
			n[i]+=48;
			w[j]+=48;
			bruh[i]+=48;
			j--;
		}
		else
		{
			n[i]-=48;
			
			bruh[i]+=n[i];
			
			while(bruh[i]>=10)
			{
				bruh[i]-=10;
				bruh[i-1]++;
			}
			
			n[i]+=48;
			bruh[i]+=48;
		}
	}
	
	j=w.size()-1;
	
	//odejmowanie
	
	for(int i=n.size()-1; i>=0; i--)
	{
		if(j>=0)
		{
			n[i]-=48;
			w[j]-=48;
			
			bruh2[i]+=n[i]-w[j];
			
			n[i]+=48;
			w[j]+=48;
			bruh2[i]+=48;
			j--;
		}
		else
		{
			n[i]-=48;
			
			bruh2[i]+=n[i];
	
			n[i]+=48;
			bruh2[i]+=48;
		}
		
		while(bruh2[i]<48)
		{
			bruh2[i]+=10;
			bruh2[i-1]--;
		}
	}
	
	//dodawanie 1
	
	j=0;
	
	if(czydod==true)
	for(int i=n.size()-1; i>=0; i--)
	{
		if(j>=0)
		{
			bruh[i]-=48;
			
			bruh[i]+=z[j];
			
			while(bruh[i]>=10)
			{
				bruh[i]-=10;
				bruh[i-1]++;
			}
			
			bruh[i]+=48;
			j--;
		}
		else
		{
			bruh[i]-=48;
			
			
			while(bruh[i]>=10)
			{
				bruh[i]-=10;
				bruh[i-1]++;
			}
			
			bruh[i]+=48;
		}
	}
	
	
	//wypisywanie
	
	for(int i=0; i<n.size()+1; i++)
	{
		if(bruh[i]!=48)
		czyzero=false;
		
		if(czyzero==false)
		cout<<bruh[i];
	}
	
	cout<<endl;
	czyzero=true;
	
	for(int i=0; i<n.size()+1; i++)
	{
		if(bruh2[i]!=48)
		czyzero=false;
		
		if(czyzero==false)
		cout<<bruh2[i];
	}
	
	
	return 0;
}
