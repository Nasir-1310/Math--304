#include<bits/stdc++.h>
using namespace std;
int rod_cutting(int price[],int n)
{
    int result[n+1];
    for(int i=0;i<=n;i++)
        result[i]=0;

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                result[i]=max(result[i],price[j]+result[i-j]);

            }
        }
        return result[n];
}

int main()
{
    printf("Enter length\n:");
    int n;
    cin>>n;
    printf("Enter prices of the corresponding rod size\n");
    int price[n];
    printf("Size     price\n--------------------------------\n");
    for(int i=0;i<=n;i++)
    {
        printf("%d->>",i);
        cin>>price[i];
        printf("\n");
    }
    int ans=rod_cutting(price,n);

    printf("Maximum value is %d",ans);

    return 0;
}
