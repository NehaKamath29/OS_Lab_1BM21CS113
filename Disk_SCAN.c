#include<stdio.h>
#include<stdlib.h>
void main()
{
    int tr,n,total=0,curr,dir,min,max;
    printf("Enter the total no of tracks in the disk:\n");
    scanf("%d",&tr);
    printf("Enter the number of requests in the request queue:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the request sequence:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the current head positon of the disk arm:\n");
    scanf("%d",&curr);
    printf("Enter head movement direction(1 for High and 0 for Low):\n");
    scanf("%d",&dir);
    switch(dir)
    {
        case 1:
        //disk fulfills all the higher requests first, so the head reaches the higher end of disk and then changes direction.
        //That is why, we need to find the lower most request track.
        min=arr[0];
        for(int i=1;i<n;i++)
        {
            if(arr[i]<min)
            min=arr[i];
        }
        total=abs(tr-1-curr)+abs(tr-1-min);
        printf("Total head movements:%d\n",total);
        break;

        case 0:
        ////disk fulfills all the lower requests first, so the head reaches the lower end of disk and then changes direction.
        //That is why, we need to find the max request track.
        max=arr[0];
        for(int i=1;i<n;i++)
        {
            if(arr[i]>max)
            max=arr[i];
        }
        total=(curr-0)+(max-0);//0 is the lower most track
        printf("Total head movements:%d\n",total);
        break;

        default:
        printf("Invalid choice:\n");
    }
    
}