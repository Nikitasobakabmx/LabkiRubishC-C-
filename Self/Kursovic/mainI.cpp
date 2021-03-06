#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#define n 5
#define m 3
void koeff(float x[n], float y[n], float A[m][m], float B[m]);
void value(float C[m], float x[n], float y[n], float &Kr, float Yl[n], float D[n]);
void maxi(float D[n], float x[n], float &Dmax, int &IM);
float fi(float x,int g);
void zeydel(float A[m][m], float B[m], float C[m]); 
int Shod(float A[m][m]); 
float R[m][m];
int main(){ 
    int l,k,i,IM;
    float A[m][m],B[m],C[m],Yl[n],D[n],Kr,Dmax,x[n],y[n];
    for(i=0;i<n;i++)
        scanf("%f",&x[i]);
    printf("\n y ");
    for(i=0;i<n;i++)
        scanf("%f",&y[i]);
    koeff(x,y,A,B);
    printf("Matrix A vector B:\n");
    for(i=0;i<m;i++){
        for(k=0;k<m;k++)
            printf("%9.3f ",A[i][k]);
            printf("%9.3f \n",B[i]);
        printf("\t");
    }
    zeydel(A,B,C);
    printf("\nVector C:\n");
    for(i=0;i<m;i++) printf("C[%d]=%6.3f\n",i,C[i]);
    value(x,y,C,Kr,Yl,D);
    printf("\n\n approximation criterion J = %.3f",Kr);
    maxi(D,x,Dmax,IM);
    printf("\n\n maximum deviation = %.3f, ïðè x[%i] = %.1f\n\n",fabs(Dmax),IM+1,x[IM]);
    system("pause");
    return 0;
}
float fi(float x,int i){
    switch(i){
        case 0 :
            return 1;
        case 1: 
            return 2 * x;
        default :
            return 4 * x * x - 2;
    }
}
void koeff(float *x,float *y,float A[m][m],float *B){
    for( int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            A[i][j]=0;
            for(int k=0;k<n;k++)
                A[i][j] += fi(x[k], i) * fi(x[k], j);
        }
        B[i]=0;
        for(int k=0;k<n;k++)
            B[i] += y[k]*fi(x[k],i);
    }
}
void value(float x[n], float y[n], float C[m], float &Kr, float Yl[n], float D[n]){
    int k,i;
    Kr=0;
   k=0;
   Yl[0]=0;
    for(i=0;i<n;i++){
        Yl[i]=C[0]*fi(x[i],k)+C[1]*fi(x[i],k+1)+C[2]*fi(x[i],k+2);
        D[i]=y[i]-Yl[i];
        Kr=Kr+D[i]*D[i];
    }
    printf("\n values approximating function\n");
    for(i=0;i<=n-1;i++)
        printf("%.3f ",Yl[i]);
    printf("\n\n deviation values approximating function\n");
    for(i=0;i<=n-1;i++)
        printf("%.3f ",D[i]);
 }
void maxi(float D[n], float x[n], float &Dmax, int &IM){
    int i;
    Dmax=D[0];
    IM=0;
    for(i=0;i<n;i++)
        if(fabs(D[i])>fabs(Dmax)){
            Dmax=D[i];
            IM=i;
        }
    printf("\n");
}

void zeydel (float A[m][m], float B[m], float C[m])
{
	int Key;
    float eps = 0.001;
    Key=Shod(A);
    if (Shod(A)) return;
    for (int i=0;i<m;i++)
       C[i]=B[i];
    float test;
    do
    {
      test=0;
      for (int i=0;i<m;i++)
      {
         float sum=0;
         for (int j=0;j<m;j++)
            if (j!=i) sum+=A[i][j]*C[j];
            float bpx = (B[i]-sum)/A[i][i];
            test+=fabs(bpx-C[i]);
            C[i]=bpx;
      }
    }
    while (test>eps);
}
