#include<iostream>
using namespace std;

int main()
{
	int k, x=0;
	string s;
	char c='-';
	//int lit[26];
	bool was=false;
	
	cin>>k;
	
	//for(int i=0; i<26; i++)
	//{
	//	lit[i]=0;
	//}
	
	for(int i=0; i<k; i++)
	{
		cin>>s;	
		
		for(int j=0; j<s.length()-1; j++)
		{
			if(s[j]==s[j+1]&&x!=s[j]/*&&lit[s[j]-97]==0*/)
			{
				cout<<s[j];
				//lit[s[j]-97]++;
				was=true;
			}
			x=s[j];
		}
		
		if(was==false)
		cout<<"NULL";
		
		//for(int j=0; j<26; j++)
		//{
		//	lit[j]=0;
		//}	
		
		x=0;
		was=false;
		cout<<endl;
	}
	
	return 0;
}
