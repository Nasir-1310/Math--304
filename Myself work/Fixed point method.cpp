//Fixed  point Iteration

#include<bits/stdc++.h>
using namespace std;

#define max 100
#define f(x) cos(x)-3*(x)+1
#define g(x)  ((cos(x)+1)/3)
int main()
{
    double x0,x1,tol;
    printf("Enter guess\n");
    cin>>x0;
    printf("Enter tol(eg 0.000001)\n");
    cin>>tol;
    printf("step\t     x0     \tf(x0)        \tx1       \tf(x1)\n");

     for(int i=1;i<max;i++)
     {
         x1=g(x0);

         printf("%d\t%lf\t%lf\t%lf\t%lf\n",i,x0,f(x0),x1,f(x1));
         if(fabs(f(x1))<tol)
         {
             printf("Root is %lf ",x1);
             return 0;
         }

         x0=x1;
     }
     printf("Iteration overflow\n");
     return 0;

}
