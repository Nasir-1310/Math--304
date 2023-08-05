#include <stdio.h>
#include <math.h>

double eigen_vectors[20][20];
double V[20][20];
double u[20][20];
double E[20][20];
double eigen_values[20];
double square_value_for_normalizing[20];


int main() {
  int n, i, j, p, q, flag;
  double a[10][10], d[10][10], s[10][10], s1[10][10], s1t[10][10];
  double temp[10][10], theta, zero=1e-5, max, pi=3.141592654;

  double A[10][10],AT[10][10];
  int Arow,Acol;


  printf("Enter dimentions (row,col)->\n");
  scanf("%d%d",&Arow,&Acol);
  printf("Enter The Matrix\n");
  for(int i=0;i<Arow;i++)
    {
      for(int j=0;j<Acol;j++)
         {
          //printf("A[%d,%d]=",i+1,j+1);
          scanf("%lf",&A[i][j]);
         }
    }
     double Atrow=Acol,Atcol=Arow;
    //finding AT(A Transpose)
    for(int i=0;i<Arow;i++)
    {
      for(int j=0;j<Acol;j++)
      {
        AT[j][i]=A[i][j];
      }

    }

    printf("\nA Matrix is:\n\n");
    for(int i=0;i<Arow ;i++)
    {
      for(int j=0;j<Acol;j++)
      {
        printf("%lf  ",A[i][j]);
      }
      printf("\n");
    }

    printf("\nAT(Transpose) Matrix is:\n\n");
    for(int i=0;i<Atrow ;i++)
    {
      for(int j=0;j<Atcol;j++)
      {
        printf("%lf  ",AT[i][j]);
      }
      printf("\n");
    }

  //Forming Symmetric Matrix Multiplying (A*AT) Matrices
/*  for(int i=0;i<Arow;i++)
  {
    for(int j=0;j<Atcol;j++)
    {
      a[i][j]=0;
      for(int k=0;k<Acol;k++)
      {
        a[i][j]+=A[i][k]*AT[k][j];
      }
    }
  }
  */

  //Forming AT*A
  for(int i=0;i<Atrow;i++)
  {
      for(int j=0;j<=Acol;j++)
      {
          a[i][j]=0;
          for(int k=0;k<Atcol;k++)
          {
              a[i][j]+=AT[i][k]*A[k][j];
          }
      }
  }
  n=Atrow;
  printf("\nSymmetric Matrix is:\n\n");
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      printf("%lf  ",a[i][j]);
    }
    printf("\n");
  }

/*
  printf("Enter the elements row wise \n");
  for(i=0; i<n; i++) {
    for(j=0; j<n; j++)  scanf ("%lf", &a[i][j]);
  }
*/
  printf("\nThe given matrix is\n\n");
  for(i=0; i<n; i++) {
    for(j=0; j<n; j++)
         printf ("%8.4f ", a[i][j]);
    printf ("\n");
  }
  printf ("\n");

  for(i=0; i<n; i++) {
    for(j=0; j<n; j++) {
      d[i][j]= a[i][j];
      if(i==j)
        s[i][j]= 1;
      else
        s[i][j]= 0;
    }
  }

  do {
    flag= 0;
    p=0; q=1;
    max= fabs(d[p][q]);

    for(i=0; i<n; i++) {
      for(j=0; j<n; j++) {
        if(i!=j) {
          if (max < fabs(d[i][j])) {
            max= fabs(d[i][j]);
            p= i;
            q= j;
          }
        }
      }
    }

    if(d[p][p]==d[q][q]) {
      if (d[p][q] > 0)
        theta= pi/4;
      else
        theta= -pi/4;
    }
    else {
      theta=0.5*atan(2*d[p][q]/(d[p][p]-d[q][q]));
    }

    for(i=0; i<n; i++) {
      for(j=0; j<n; j++) {
        if(i==j) {
         s1[i][j]= 1;
         s1t[i][j]= 1;
        }
        else {
          s1[i][j]= 0;
          s1t[i][j]= 0;
        }
      }
    }

    s1[p][p]= cos(theta);
    s1t[p][p]= s1[p][p];

    s1[q][q]= cos(theta);
    s1t[q][q]= s1[q][q];

    s1[p][q]= -sin(theta);
    s1[q][p]= sin(theta);

    s1t[p][q]= s1[q][p];
    s1t[q][p]= s1[p][q];

    for(i=0; i<n; i++) {
      for(j=0; j<n; j++) {
        temp[i][j]= 0;
        for(p=0; p<n; p++)  temp[i][j]+= s1t[i][p]*d[p][j];
      }
    }

    for(i=0; i<n; i++) {
      for(j=0; j<n; j++) {
        d[i][j]= 0;
        for(p=0; p<n; p++)  d[i][j]+= temp[i][p]*s1[p][j];
      }
    }

    for(i=0; i<n; i++) {
      for(j=0; j<n; j++) {
        temp[i][j]= 0;
        for(p=0; p<n; p++)  temp[i][j]+= s[i][p]*s1[p][j];
      }
    }

    for(i=0; i<n; i++) {
      for(j=0; j<n; j++)  s[i][j]= temp[i][j];
    }

    for(i=0; i<n; i++) {
      for(j=0; j<n; j++) {
        if(i!=j)
          if(fabs(d[i][j]) > zero) flag= 1;
      }
    }
  }while(flag==1);

  printf("The eigenvalues are:\n\n");
  for(i=0; i<n; i++)
  {

    printf("%8.4lf ",d[i][i]);
    eigen_values[i]=d[i][i];
  }
  printf("\nThe corresponding eigenvectors are:\n\n");

  for(j=0; j<n; j++) {
    printf("(");
    for(i=0; i<n-1; i++)
      printf("% 8.4lf,",s[i][j]);
    printf("%8.4lf )^T\n",s[n-1][j]);
  }
  printf("\n\n");


  for(j=0; j<n; j++) {
    printf("(");
    square_value_for_normalizing[j]=0;
    for(i=0; i<n; i++){
      printf("% 8.4lf,",s[i][j]);
      eigen_vectors[j][i]=s[i][j];
      square_value_for_normalizing[j]=square_value_for_normalizing[j]+(s[i][j]*s[i][j]);
    }
      printf(")^T\n");
  }


  //Normalizing Eigenvectors
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<n;j++)
      {
          eigen_vectors[i][j]=(eigen_vectors[i][j]/(sqrt(square_value_for_normalizing[i])));
      }
  }
  //Forming V matrix
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<n;j++)
      {
          V[j][i]=eigen_vectors[i][j];
      }
  }
  //printing V matrix
  printf("V matrix is :\n");
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<n;j++)
      {
          printf("%lf\t",V[i][j]);
      }
      printf("\n");
  }
printf("E matrix is:\n");

  for(int i=0;j<3;i++)
  {
      for(int j=0;j<3;j++)
      {
          E[i][j]=1.6;
         // printf("%lf",E[i][j]);
      }
      printf("\n");

  }

  for(int i=0;j<3;i++)
  {
      for(int j=0;j<3;j++)
      {
       //   E[i][j]=0;
        printf("%lf",E[i][j]);
      }
      printf("\n");

  }


}







