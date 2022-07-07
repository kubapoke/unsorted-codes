#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio;
	cin.tie(0);
	
	string godzina;
	
	cin>>godzina;
	
	if(godzina[0]=='0')
	{
		if(godzina[1]=='0'||godzina[1]=='1'||godzina[1]=='2'||godzina[1]=='3'||godzina[1]=='4'||godzina[1]=='5')
		cout<<"noc";
		else
		cout<<"rano";
	}
	else if(godzina[0]=='1')
	{
		if(godzina[1]=='0'||godzina[1]=='1')
		cout<<"rano";
		else if(godzina[1]=='2'||godzina[1]=='3')
		cout<<"poludnie";
		else if(godzina[1]=='4'||godzina[1]=='5'||godzina[1]=='6'||godzina[1]=='7')
		cout<<"popoludnie";
		else
		cout<<"wieczor";
	}
	else if(godzina[0]=='2')
	{
		if(godzina[1]=='0'||godzina[1]=='1')
		cout<<"wieczor";
		else
		cout<<"noc";
	}
	
	
	
	return 0;
}
