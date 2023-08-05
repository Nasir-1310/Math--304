
#include<bits/stdc++.h>
using namespace std;
int ne=1,u,v,vertex1,vertex2,Nvertex,Nedge,a,b,s;
int parent[10],cost[10][10];

int find_previous(int i)
{
    while(parent[i])
        i=parent[i];
    return i;
}



int union_(int i,int j)
  {
      if(i!=j)
    {
        parent[j]=i;
        return 1;
    }
    return 0;
}

int main()
{

    printf("Enter number of Vertices\n");
    scanf("%d",&Nvertex);
    printf("Enter number of Edge\n");
    int Nedge;
    cin>>Nedge;

    for(int i=1;i<=Nvertex;i++)
    {
        for(int j=1;j<=Nvertex;j++)
        {
            cost[i][j]=999;

        }
        parent[i]=0;
    }
    printf("Enter vertices and corresponding weight\n");
    while(Nedge--)
    {
         cin>>vertex1>>vertex2;
         cin>>cost[vertex1][vertex2];
         cost[vertex2][vertex1]=cost[vertex1][vertex2];

    }

    printf("The given Graph is \n");
    for(int i=1;i<=Nvertex;i++)
    {
        for(int j=1;j<=Nvertex;j++)
        {
            printf("%d\t",cost[i][j]);
        }
        printf("\n");
    }

  printf("Edges and corresponding Spanning Tree are\n");
int min_value,mincost=0;
    while(ne<Nvertex)
    {
        min_value=999;
        for(int i=1;i<=Nvertex;i++)
        {
            for(int j=1;j<=Nvertex;j++)
         {
            if(cost[i][j]<min_value)
            {
                min_value=cost[i][j];
                a=u=i;
                b=v=j;
               // printf("cost[%d][%d]==min_value is %d\n",i,j,min_value);
            }

        }
    }
   // u=find_previous(u);
   // v=find_previous(v);
    if(union_(u,v))
    {
        printf("%d th edge(%d<---->%d)=%d\n",ne++,a,b,min_value);
        mincost+=min_value;

    }
    cost[a][b]=cost[b][a]=999;

    }
    printf("\nMinimum cost =%d\n",mincost);


}
/*

9
14

1 2 4
2 3 8
3 4 7
4 5 9
5 6 10
6 7 2
7 8 1
8 1 8
2 8 11
3 9 2
9 8 7
7 9 6
3 6 4
4 6 14

*/
