#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void LinearRegression(double *LinRegY,double *LinRegX,int n,double x)
{
    double Ymean=0,Xmean=0,CovarXY=0,VarX=0,a=0,b=0,y=0;
    for(int i=0;i<n;i++)
    {
        Ymean +=LinRegY[i];
        Xmean += LinRegX[i];
    }
    Ymean /= n;
    Xmean /= n;
    for(int k=0;k<n;k++)
    {
        VarX += pow(LinRegX[k]-Xmean,2);
    }
    VarX /= (n-1);
    for(int m=0;m<n;m++)
    {
        CovarXY += (LinRegX[m]-Xmean)*(LinRegY[m]-Ymean);
    }
    CovarXY /= (n-1);
    if(VarX != 0)
    {
        b = CovarXY/VarX;
    }else{
        printf("Variance found to be 0...\n");
        return;
    }
    
    a = Ymean - (b*Xmean);
    printf("Final equation: y = %lf + %lfx\n",a,b);
    y = a + (b*x);
    printf("y = %lf\n",y);
}

int main()
{
    double *LinRegY, *LinRegX;
    int n;
    double x;

    printf("Enter number of readings: \n");
    scanf("%d",&n);

    LinRegX = calloc(n,sizeof(double));
    LinRegY = calloc(n,sizeof(double));

    if(LinRegX== NULL || LinRegY == NULL)
    {
        printf("Memory Allocation failed!\n");
        return 1;
    }

    for(int i=0;i<n;i++)
    {
        printf("Enter X value number %d: \n",i+1);
        scanf("%lf",&LinRegX[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("Enter Y value number %d: \n",i+1);
        scanf("%lf",&LinRegY[i]);
    }
    printf("Enter the value of x for which you want to find the value of y: ");
    scanf("%lf",&x);
    LinearRegression(LinRegY,LinRegX,n,x);

    free(LinRegX);
    LinRegX = NULL;
    free(LinRegY);
    LinRegY = NULL;

    return 0;
}