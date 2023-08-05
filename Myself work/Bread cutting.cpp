#include<bits/stdc++.h>
using namespace std;


int cut[1000][1000];
int c[1000];
int n,l;

int dp(int start,int finish,int n)
{
    if(cut[start][finish]!=-1)
        return cut[start][finish];
     int ans=99999;
     int p=0;
     for(int i=1;i<=n;i++)
      {
        if(c[i]<=start or c[i]>=finish  )
        {
            continue;
            p=1;
            ans=min(ans,(finish-start+dp(start,c[i])dp(c[i],finish)));

        }
        if(p==0)
        {
            cut[start][finish]=0;
        }
        else
        cut[start][finish]=ans;

        return cut[start][finish];
      }

}
int main()
{

  cin>>l;
  cin>>n;

  for(int i=1;i<=n;i++)
    {
      c[i]=-1;
    }

  for(int i=1;i<=n;i++)
  {
     for(int j=1;j<=n;j++)
    {
        cut[i][j]=-1;
    }
  }
  for(int i=1;i<=n;i++)
    {
       cin>>c[i];
    }

  long long  int result=dp(0,l);
  printf("Minimum cost is %lld",result);




return 0;
}
