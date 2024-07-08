#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#define int long long
#define down 1
#define right 2
#define left 4
#define up 8
#define WALL -1
#define NOTHING 2
using namespace std;
struct block
{
	int row,column,direction;
	block(int _row,int _column,int _direction)
	{
		row = _row;
		column = _column;
		direction = _direction;
	}
};
struct point
{
	int x;
	int y;
} start,end;

vector<block> myblock;
int x_num=1,y_num=1;
int G[100][100];

void init()
{
	memset(G,WALL,sizeof(G));
	G[1][1] = NOTHING;
	start.x = start.y = 1;
}
int n,m;
void FindBlock()
{
	if(x_num+1<=m && G[x_num+1][y_num] == WALL)  //down
	{
		myblock.push_back(block(x_num+1,y_num,down));
	}
	if(y_num+1<=n && G[x_num][y_num+1] == WALL)  //right
	{
		myblock.push_back(block(x_num,y_num+1,right));
	}
	if(x_num-1>=1 && G[x_num-1][y_num] == WALL)  //up
	{
		myblock.push_back(block(x_num-1,y_num,up));
	}
	if(y_num-1>=1 && G[x_num][y_num-1] == WALL)  //left
	{
		myblock.push_back(block(x_num,y_num-1,left));
	}
}
void tp()
{
	//将猫传送到1,1处
}
int rx,ry,coin,fx[100][3]= {{-1,-1},{-1,0},{-1,1},{1,-1},{1,1},{1,0},{0,-1},{0,1},{0,-2},{0,2},{-2,0},{2,0},{2,2},{-2,-2},{-2,-1},{-2,1},{2,1},{2,-1},{-2,2},{2,-2},{-1,-2},{1,-2},{-1,2},{1,2},{-3,-1},{-3,0},{-3,1},{3,-1},{3,0},{3,1},{-1,-3},{0,-3},{1,-3},{-1,3},{0,3},{1,3}};
const int NN=3e3+10;
string a[NN][NN];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	init();
	srand(time(0));
	cin>>n>>m;
	
	FLAG:
		
	FindBlock();
	while(myblock.size())
	{
		int BlockSize = myblock.size();
		int randnum = rand() % BlockSize;
		block SelectBlock = myblock[randnum];
		x_num = SelectBlock.row;
		y_num = SelectBlock.column;
		switch(SelectBlock.direction)
		{
			case down:
			{
				x_num++;
				break;
			}
			case right:
			{
				y_num++;
				break;
			}
			case left:
			{
				y_num--;
				break;
			}
			case up:
			{
				x_num--;
				break;
			}
		}
		if(G[x_num][y_num]==WALL)
		{
			G[SelectBlock.row][SelectBlock.column] = G[x_num][y_num] = NOTHING;
			FindBlock();
		}
		myblock.erase(myblock.begin()+randnum);
	}
	for (int i=0; i<=m+1; i++)
	{
		for (int j=0; j<=n+1; j++)
		{
			if(i == start.x && j == start.y)
			{
				a[i][j]="人";
			}
			else if(G[i][j] == NOTHING)
			{
				a[i][j]="  ";
			}
			else
			{
				a[i][j]="##";
			}
		}
	}
	rx=ry=1;
	string othr="GO";
	bool qqq=1;
	int okx=1,oky=1;
	while(a[okx][oky]!="  ")
	{
		okx=rand()%m+m/2;
		oky=rand()%n+n/2;
	}
	a[okx][oky]="OK";
	while(1)
	{

		char ch;
		ch=getch();
		system("cls");
		a[rx][ry]=othr;
		if((ch=='w'||ch=='W')&&a[rx-1][ry]!="##")
		{
			rx--;
		}
		if((ch=='s'||ch=='S')&&a[rx+1][ry]!="##")
		{
			rx++;
		}
		if((ch=='a'||ch=='A')&&a[rx][ry-1]!="##")
		{
			ry--;
		}
		if((ch=='d'||ch=='D')&&a[rx][ry+1]!="##")
		{
			ry++;
		}
		//特殊
		if(ch==' ') qqq=!qqq,coin-=1;//看地图
		if(ch=='t') tp(),coin-=2;
		if(rx==okx&&ry==oky)
		{
			system("cls");
			cout<<"Next Level~\nloading";
			for(int i=1; i<=6; i++)
			{
				Sleep(500);
				cout<<".";
			}
			cout<<"\nThe cat's speed will increase by 100%\n";
			goto FLAG; 
			Sleep(1000);
		}
		othr=a[rx][ry];
		a[rx][ry]="人";
		for(int i=0; i<=m+1; i++)
		{
			for(int j=0; j<=n+1; j++)
			{
				bool lll=1,fff=1;
				for(int w=0; w<36; w++)
				{
					if(i==rx+fx[w][0]&&j==ry+fx[w][1])
					{
						lll=0;
						break;
					}
				}
				for(int w=0; w<36; w++)
				{
					if(i==okx+fx[w][0]&&j==oky+fx[w][1])
					{
						fff=0;
						break;
					}
				}
				if(i==rx&&j==ry) cout<<"人";
				else if(i==okx&&j==oky) cout<<"OK";
				else if(lll==1&&qqq&&fff)
				{
					cout<<"  ";
				}
				else cout<<a[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}
