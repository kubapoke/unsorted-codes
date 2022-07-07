#include<bits/stdc++.h>
using namespace std;



int main()
{
	
	char snode1[4][4], snode2[4][4], snode3[4][4], snode4[4][4], snode5[4][4];
 	for(int i=0; i<4; i++)
 	for(int j=0; j<4; j++)
 	cin>>snode1[i][j];
 	for(int i=0; i<4; i++)
 	for(int j=0; j<4; j++)
 	cin>>snode2[i][j];
 	for(int i=0; i<4; i++)
 	for(int j=0; j<4; j++)
 	cin>>snode3[i][j];
 	for(int i=0; i<4; i++)
 	for(int j=0; j<4; j++)
 	cin>>snode4[i][j];
 	for(int i=0; i<4; i++)
 	for(int j=0; j<4; j++)
 	cin>>snode5[i][j];
 	
 	char yen1[4][4];
 	for(int i=0; i<4; i++)
 	for(int j=0; j<4; j++)
 	{
 		if(snode1[i][j]=='#'&&snode2[i][j]!='#')
 		yen1[i][j]='#';
 		else
 		yen1[i][j]='+';
	}
	
	char move1[4][4];
	for(int i=0; i<4; i++)
 	for(int j=0; j<4; j++)
 	{
 		int a=j-1;
 		if(a<0) a=3;
 		move1[i][j]=snode2[i][a];
	}
	
	char rot1[4][4];
	rot1[0][0]=snode3[0][3];
	rot1[0][1]=snode3[1][3];
	rot1[0][2]=snode3[2][3];
	rot1[0][3]=snode3[3][3];
	rot1[1][0]=snode3[0][2];
	rot1[1][1]=snode3[1][2];
	rot1[1][2]=snode3[2][2];
	rot1[1][3]=snode3[3][2];
	rot1[2][0]=snode3[0][1];
	rot1[2][1]=snode3[1][1];
	rot1[2][2]=snode3[2][1];
	rot1[2][3]=snode3[3][1];
	rot1[3][0]=snode3[0][0];
	rot1[3][1]=snode3[1][0];
	rot1[3][2]=snode3[2][0];
	rot1[3][3]=snode3[3][0];
	
	char rot2[4][4];
	rot2[0][0]=snode4[0][3];
	rot2[0][1]=snode4[1][3];
	rot2[0][2]=snode4[2][3];
	rot2[0][3]=snode4[3][3];
	rot2[1][0]=snode4[0][2];
	rot2[1][1]=snode4[2][1];
	rot2[1][2]=snode4[1][1];
	rot2[1][3]=snode4[3][2];
	rot2[2][0]=snode4[0][1];
	rot2[2][1]=snode4[2][2];
	rot2[2][2]=snode4[1][2];
	rot2[2][3]=snode4[3][1];
	rot2[3][0]=snode4[0][0];
	rot2[3][1]=snode4[1][0];
	rot2[3][2]=snode4[2][0];
	rot2[3][3]=snode4[3][0];
	
	char split1[4][4], split2[4][4];
	
	for(int i=0; i<4; i++)
 	for(int j=0; j<4; j++)
 	{
 		split1[i][j]='+'; 
 		split2[i][j]='+';
	}
	
	int counter1=1;
	for(int i=0; i<4; i++)
 	for(int j=0; j<4; j++)
 	{
 		if(yen1[i][j]=='#')
 		{
 			if(counter1%2==1)
 			split1[i][j]='#';
 			else
 			split2[i][j]='#';
 			counter1++;
		}
	}
	
	char cube1[4][4];
	for(int i=0; i<4; i++)
 	for(int j=0; j<4; j++)
 	if(move1[i][j]=='#'&&rot1[i][j]=='#')
 	cube1[i][j]='#';
 	else
 	cube1[i][j]='+';
 	
 	char apo1[4][4];
 	for(int i=0; i<4; i++)
 	for(int j=0; j<4; j++)
 	if(rot2[i][j]!=snode5[i][j])
 	apo1[i][j]='#';
 	else
 	apo1[i][j]='+';
 	
	char rot3[4][4];
	rot3[0][0]=split1[0][3];
	rot3[0][1]=split1[1][3];
	rot3[0][2]=split1[2][3];
	rot3[0][3]=split1[3][3];
	rot3[1][0]=split1[0][2];
	rot3[1][1]=split1[2][1];
	rot3[1][2]=split1[1][1];
	rot3[1][3]=split1[3][2];
	rot3[2][0]=split1[0][1];
	rot3[2][1]=split1[2][2];
	rot3[2][2]=split1[1][2];
	rot3[2][3]=split1[3][1];
	rot3[3][0]=split1[0][0];
	rot3[3][1]=split1[1][0];
	rot3[3][2]=split1[2][0];
	rot3[3][3]=split1[3][0];
	
	char move2[4][4];
	for(int i=0; i<4; i++)
 	for(int j=0; j<4; j++)
 	{
 		int a=j-1;
 		if(a<0) a=3;
 		move2[i][j]=split2[i][a];
	}
	
	char join1[4][4];
	for(int i=0; i<4; i++)
 	for(int j=0; j<4; j++)
 	if(rot3[i][j]=='#'||move2[i][j]=='#')
 	join1[i][j]='#';
 	else
 	join1[i][j]='+';
 	
 	char yen2[4][4];
 	for(int i=0; i<4; i++)
 	for(int j=0; j<4; j++)
 	{
 		if(move2[i][j]=='#'&&apo1[i][j]!='#')
 		yen2[i][j]='#';
 		else
 		yen2[i][j]='+';
	}
	
	
	char split3[4][4], split4[4][4];
	
	for(int i=0; i<4; i++)
 	for(int j=0; j<4; j++)
 	{
 		split3[i][j]='+'; 
 		split4[i][j]='+';
	}
	
	int counter2=1;
	for(int i=0; i<4; i++)
 	for(int j=0; j<4; j++)
 	{
 		if(cube1[i][j]=='#')
 		{
 			if(counter2%2==1)
 			split3[i][j]='#';
 			else
 			split4[i][j]='#';
 			counter2++;
		}
	}
	
	
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		cout<<join1[i][j];
		cout<<"\n";
	}
	cout<<"\n";
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		cout<<yen2[i][j];
		cout<<"\n";
	}
	cout<<"\n";
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		cout<<split3[i][j];
		cout<<"\n";
	}
	cout<<"\n";
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		cout<<split4[i][j];
		cout<<"\n";
	}
	cout<<"\n";
 	
 	
	
	
 	
}
