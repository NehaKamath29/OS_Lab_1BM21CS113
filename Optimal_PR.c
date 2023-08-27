#include<stdio.h>
int isHit(int fr[], int pg, int m)
{
    int hit=0;
    for(int i=0;i<m;i++)
    {
        if(fr[i]==pg)
        {
            hit=1;
            break;
        }
    }
    return hit;
}
void main()
{
    int i,n,m,k,j,pagefault=0,max=-1,x,y,flag=0;
    printf("Enter the length of reference sequence:\n");
    scanf("%d",&n);
    int ref[n];
    printf("Enter the page reference sequence:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&ref[i]);
    }
    printf("Enter the number of frames:\n");
    scanf("%d",&m);
    int fr[m];
    for(y=0;y<m;y++)
    {
        fr[y]=ref[y];
        pagefault++;
        printf("%d:Page Fault\n",ref[y]);
    }
    for(i=y;i<n;i++)
    {
        if(isHit(fr,ref[i],m)==0)
        {
            for(j=0;j<m;j++)
            {
                for(k=i+1;k<n;k++)
                {
                    if(fr[j]==ref[k])//as soon as match happens, break.
                    {
                        flag=1;
                        break;
                    }
                    else if(k==n-1 && fr[j]!=ref[k])//if there is no demand of a particular page in future, just replace that.
                    {
                        flag=-1;
                        fr[j]=ref[i];
                        break;
                    }
                }
                if(flag==-1)//if there is no demand, directly replaced, no need to check other pages in the frames.
                break;
                else if(flag==1 && k>max)/*we need to find that page jiski demand sabse baad mein ho, isiliye, agar pg no ki demand
                                          basically uski index max se zyada ho, tabhi update karna*/
                {
                    max=k;
                    x=j;
                }
            }
            max=-1; //reset max for other iterations
            if(flag!=-1)//agar demand nahi hai, toh already replace ho chuka hoga.
            {
                fr[x]=ref[i];
            }
            pagefault++;
            printf("%d:Page fault\n",ref[i]);
        }
        else
        {
            printf("%d:No page fault\n",ref[i]);
        }
    }
    printf("Total no of page faults:%d\n",pagefault);
}