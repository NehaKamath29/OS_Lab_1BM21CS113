#include<stdio.h>
#include<stdlib.h>

void main()
{
   int n,i,j;
   float sum_tat=0,sum_wt=0;
   int position,swap;
   printf("Enter the number of processes:\n");
   scanf("%d",&n);
   //sort(n);
   float bt[n],wt[n],tat[n];
   for(i=0;i<n;i++)
   {
      printf("Enter the burst time of process %d:\n",(i+1));
      scanf("%f",&bt[i]);
   }

   for (i = 0; i < n-1; i++) {
      position = i;
      for (j = i + 1; j < n; j++) {
         if (bt[position] > bt[j])
            position = j;
      }
      if (position != i) {
         swap = bt[i];
         bt[i] = bt[position];
         bt[position] = swap;
      }
   }

   wt[0]=0;
   for(i=1;i<n;i++)
   {
      wt[i]=wt[i-1]+bt[i-1];
      sum_wt+=wt[i];
   }
   for(i=0;i<n;i++)
   {
      tat[i]=wt[i]+bt[i];
      sum_tat+=tat[i];
   }
   printf("BurstTime\tWaitingTime\tTurnAroundtime\n");
   for(i=0;i<n;i++)
   {
      printf("%0.2f\t\t%0.2f\t\t%0.2f\n",bt[i],wt[i],tat[i]);
   }
   printf("Average waiting time:%f\n",(sum_wt)/n);
   printf("Average turn around time:%f\n",(sum_tat)/n);
}
