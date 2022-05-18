#include<stdio.h>

int main()
{
    int j,MAX,a,b,i,t;
    while(scanf("%d%d",&a,&b)==2)
    {

        MAX=0;
        if(a>b)
        {
            printf("%d %d ",a,b);     /*Input in the order of input a and b, otherwise it will be WA when submitting*/
            t=a;
            a=b;
            b=t;
        }
        else printf("%d %d ",a,b);      /*The else here cannot contain the following statement, because the following statement requires operations if a is greater than b or a is less than or equal to b*/
        for(i=a;i<=b;i++)
        {
            a=i;
            j=1;                    /*Initialize j here, j must be initialized to 1, not 0*/
            while(a!=1)
            {
                if(a%2==0)
                {
                    a/=2;
                }
                else
                {
                    a=3*a+1;
                }
                j++;
            }
            if(j>MAX)
                MAX=j;
        }
        printf("%d\n",MAX);
    }
    return 0;
}