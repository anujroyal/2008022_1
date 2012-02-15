#include<stdio.h>
#include<stdlib.h>
#define MAX 1000000
int pop();
void push(int);
void display(int );
void generate(int);
int Final(int);
int start=0;
int end=0;
int track;
int que[MAX];
int map[MAX];
int initial[3][3];
int final[3][3];
int graph[MAX][3][3];
int getx(int a[3][3]);
int gety(int a[3][3]);
void generate(int prt)
{
	int i,j;
	if(getx(graph[prt])+1<3)
	{
		track++;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
		graph[track][i][j]=graph[prt][i][j];
			}
		}
		graph[track][getx(graph[prt])+1][gety(graph[prt])]=graph[prt][getx(graph[prt])][gety(graph[prt])];
		graph[track][getx(graph[prt])][gety(graph[prt])]=graph[prt][getx(graph[prt])+1][gety(graph[prt])];
		push(track);
		map[track]=prt;
	}
	if(gety(graph[prt])+1<3)
	{
		track++;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
		graph[track][i][j]=graph[prt][i][j];
			}
		}
		graph[track][getx(graph[prt])][gety(graph[prt])+1]=graph[prt][getx(graph[prt])][gety(graph[prt])];
		graph[track][getx(graph[prt])][gety(graph[prt])]=graph[prt][getx(graph[prt])][gety(graph[prt])+1];
		push(track);
		map[track]=prt;
	}
	if(getx(graph[prt])-1>=0)
	{
		track++;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
		graph[track][i][j]=graph[prt][i][j];
			}
		}
		graph[track][getx(graph[prt])-1][gety(graph[prt])]=graph[prt][getx(graph[prt])][gety(graph[prt])];
		graph[track][getx(graph[prt])][gety(graph[prt])]=graph[prt][getx(graph[prt])-1][gety(graph[prt])];
		push(track);
		map[track]=prt;
	}
	if(gety(graph[prt])-1>=0)
	{
		track++;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
		graph[track][i][j]=graph[prt][i][j];
			}
		}
		graph[track][getx(graph[prt])][gety(graph[prt])-1]=graph[prt][getx(graph[prt])][gety(graph[prt])];
		graph[track][getx(graph[prt])][gety(graph[prt])]=graph[prt][getx(graph[prt])][gety(graph[prt])-1];
		push(track);
		map[track]=prt;
	}
}

int pop()
{
	start=(start+1)%MAX;
	if(start>end)
	{
		printf("\nqueue empty\n");
		exit(0);
	}else
	{
		return que[start];
	}
}

void push(int a)
{
	end=(end+1)%MAX;
	if(end==start)
	{
		printf("\nqueue full\n");
		exit(0);
	}else
	{
		que[end]=a;
	}
}

int getx(int a[3][3])
{
	int i,j;
	for(i=0;i<3;i++)
	{
			for(j=0;j<3;j++)
			{
				if(a[i][j]==0)
					return i;
			}
	}
}

int gety(int a[3][3])
{
	int i,j;
	for(i=0;i<3;i++)
	{
			for(j=0;j<3;j++)
			{
				if(a[i][j]==0)
					return j;
			}
	}
}

void display(int prt)
{
	int i,j,k;
printf("\n");
	while(prt!=-1)
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				printf("%d ",graph[prt][i][j]);
			}
			printf("\n");
		}
			printf("\n");
			prt=map[prt];
	}
}


void solve()
{
int prt;
A: prt=pop();

if(Final(prt))
{
display(prt);
}
else 
	{
		generate(prt);
		goto A;
	}
}

int Final(int prt)
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(graph[prt][i][j]!=final[i][j])
				return 0;
		}
	}
	return 1;
}
int main()
{
	int i,j,k;
	map[0]=-1;
	for(i=0;i<15;i+=3);
		printf("%d",i);
	printf("foo","bar");
	if(i=-1)
		printf("%d",1<!i);
	else printf("i!=7");
	printf("enter initial state\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&initial[i][j]);
			graph[0][i][j]=initial[i][j];
		}
	}
	printf("enter goal state\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&final[i][j]);
		}
	}
	push(0);
	solve();
}
