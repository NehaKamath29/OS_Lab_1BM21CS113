#include<stdio.h>
void main()
{
    int n,m,all[10][10],max[10][10],need[10][10],ava[10],flag[10],prev[10],arr[10];
    int k,z=0,c,count=0;
    printf("Enter the number of processes and number of resources:\n");
    scanf("%d %d",&n,&m);
    printf("Enter the max number of resources required by the processes:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter the allocated number of resources to the processes:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&all[i][j]);
        }
    }
    printf("Enter the available number of resources:\n");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&ava[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-all[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        flag[i]=1;
    }
    k=1;
    while(k)
    {
        k=0;
        for(int i=0;i<n;i++)
        {
            if(flag[i])
            {
                c=0;
                for(int j=0;j<m;j++)
                {
                    if(need[i][j]<=ava[j])
                    c++;
                }
                if(c==m)
                {
                    arr[z++]=i;
                    for(int j=0;j<m;j++)
                    {
                        ava[j]+=all[i][j];
                        all[i][j]=0;
                    }
                    flag[i]=0;
                    count++;

                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(flag[i]!=prev[i])
            {
                k=1;
                break;
            }
        }
        for(int i=0;i<n;i++)
        {
            prev[i]=flag[i];
        }
    }
    if(count==n)
    {
        printf("The proccesses are in safe state:\n");
        printf("The safe sequence is:\n");
        for(int i=0;i<n;i++)
        {
            printf("P%d ",arr[i]+1);
        }
        printf("\n");

    }
    else
    {
        printf("The processes are in deadlock condition:\n");
    }
}