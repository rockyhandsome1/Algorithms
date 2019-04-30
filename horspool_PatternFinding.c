#include<stdio.h>
#include<string.h>
#define MAX 500
int t[MAX];

void shiftTable(char p[])
{
    int i,j,m;
    m = strlen(p);
    for(i=0;i<MAX;i++)
        t[i] = m;
    for(j=0;j<m-1;j++)
    {
        t[p[j]] = m-1-j;
        //printf("[%c:%d] ",p[j],t[p[j]]);
    }
    
    //for(j=0;j<m-1;j++)
    //    printf("[%c:%d] ",p[j],t[p[j]]);
}

int horspool(char src[], char p[])
{
    int i,j,k,n,m;
    n = strlen(src);
    m = strlen(p);
    i=m-1;
    while(i<n)
    {
        k=0;
        while((k<m) && (p[m-1-k] == src[i-k]))
            k++;
        if(k==m)
            return(i-m+1);
        else
            i += t[src[i]];
    }
    return -1;
}

void main()
{
    char source[100],pattern[20];
    int pos;
    printf("\nEnter the source content:");
    gets(source);
    printf("\nEnter the pattern:");
    gets(pattern);
    shiftTable(pattern);
    pos = horspool(source,pattern);
    if(pos>=0)
        printf("\nfound the match at position:%d\n",pos+1);
    else
        printf("\npattern is not found\n");
}
