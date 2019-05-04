
#include<stdio.h>
#include<math.h>
int set[10],binary[50];
int k=0;n;
void create_binary(int x)
{
    int i=n-1;
    while(x)
    {
        binary[i]=x%2;
        x/=2;
        i--;
    }
    while(i>=0)
    {
        binary[i] = 0;
        i--;
    }
}
void find_set(int d)
{
    int i,j,sum=0;
    for(i=0;i<pow(2,n);i++)
    {
        create_binary(i);
        for(j=0;j<n;j++)
            if(binary[j]==1)
                sum+=set[j];
        if(sum == d)
        {
            k++;
            printf("\n");
            //printf("\n{");
            for(j=0;j<n;j++)
                if(binary[j])
                    printf("%d\t",set[j]);
            //printf("}");
        }
        sum = 0;
    }
}
void main()
{
    int i,j,d;
    printf("\nEnter the number of elements:");
    scanf("%d",&n);
    printf("\nEnter the elements:");
    for(i=0;i<n;i++)
        scanf("%d",&set[i]);
    printf("\nEnter the sum required:");
    scanf("%d",&d);
    find_set(d);
    if(k==0)
        printf("\nsubsets are not possible\n");
}