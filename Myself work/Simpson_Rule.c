#include<stdio.h>
#include<math.h>
#define n 10
int main()
{
    double h=((2.0-0.0)/n);
    double x[n+1]={0.0, 0.2, 0.4, 0.6, 0.8 ,1.0, 1.2 ,1.4, 1.6, 1.8, 2.0};
    double f[n+1]={1.0, 1.04, 1.16, 1.36, 1.64, 2.0, 2.44, 2.96, 3.56, 4.24, 5.0};
    double integration=0;
    integration=f[n]+f[0];


    for(int i=1;i<n;i++)
    {
        if(i%2==0)
        integration+=2*f[i];
        else integration+=4*f[i];
    }

    integration=(h/3.0)*integration;

    printf("Trapezoidal Rule\n---------------------------\n");
    printf("Integral value =%lf",integration);
    return 0;

}

