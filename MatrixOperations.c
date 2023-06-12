#include<stdio.h>
#include<stdlib.h>
void matrix_add(int m1[][20],int m2[][20],int row1,int row2,int col1,int col2)
{
    int i,j;
    if(row1!=row2 ||col1!=col2)
    {
        printf("These matrices cannot be added!\n");
        return;
    }
    else if(row1==row2 && col1==col2)
    {
        int ans[20][20];
        for(i=0;i<row1;i++)
        {
            for(j=0;j<col1;j++)
            {
                ans[i][j]=m1[i][j]+m2[i][j];
            }
        }
        for(i=0;i<row1;i++)
        {
            for(j=0;j<col1;j++)
            {
                printf("%d ",ans[i][j]);
            }
            printf("\n");
        }
    }
}
void matrix_sub(int m1[][20],int m2[][20],int row1,int row2,int col1,int col2)
{
    int i,j;
    if(row1!=row2 ||col1!=col2)
    {
        printf("These matrices cannot be subtracted!\n");
        return;
    }
    else if(row1==row2 && col1==col2)
    {
        int ans[20][20];
        for(i=0;i<row1;i++)
        {
            for(j=0;j<col1;j++)
            {
                ans[i][j]=m1[i][j]-m2[i][j];
            }
        }
        for(i=0;i<row1;i++)
        {
            for(j=0;j<col1;j++)
            {
                printf("%d ",ans[i][j]);
            }
            printf("\n");
        }
    }
}
void matrix_multiply(int m1[][20],int m2[][20],int row1,int row2,int col1,int col2)
{
    int i,j;
    if(col1!=row2)
    {
        printf("These matrices cannot be multiplied!\n");
        return;
    }
    else if(col1==row2)
    {
        int ans[20][20],k;
        for(i=0;i<row1;i++)
        {
            for(j=0;j<col2;j++)
            {
                ans[i][j]=0;
                for(k=0;k<col2;k++)
                {
                    int temp=m1[i][k]*m2[k][j];
                    ans[i][j]+=temp;
                }
            }
        }

        for(i=0;i<row1;i++)
        {
            for(j=0;j<col1;j++)
            {
                printf("%d ",ans[i][j]);
            }
            printf("\n");
        }
    }
}
void transpose(int m1[][20],int row1,int col1)
{
    int ans[20][20],i,j,k=0;
    for(i=0;i<col1;i++)
    {
        for(j=0;j<row1;j++)
        {
            ans[i][j]=m1[k][i];
            k++;
        }
        k=0;
    }
    for(i=0;i<col1;i++)
    {
        for(j=0;j<row1;j++)
        {
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
}
void main()
{
    int row1,col1,row2,col2,i,j,n;
    printf("Enter the number of rows and columns in matrix 1:\n");
    scanf("%d %d",&row1,&col1);
    printf("Enter the number of rows and columns in matrix 2:\n");
    scanf("%d %d",&row2,&col2);
    int m1[20][20];
    int m2[20][20];
    printf("Enter the elements of matrix 1:\n");
    for(i=0;i<row1;i++)
    {
        for(j=0;j<col1;j++)
        {
            scanf("%d",&m1[i][j]);
        }
    }
    printf("Enter the elements of matrix 2:\n");
    for(i=0;i<row2;i++)
    {
        for(j=0;j<col2;j++)
        {
            scanf("%d",&m2[i][j]);
        }
    }
    while(1)
    {
         printf("Enter 1 to add matrices:\nEnter 2 subtract matrices:\nEnter 3 to multiply matrices:\nEnter 4 to find the transpose of the matrix:\nEnter 5 to exit.\n");
         scanf("%d",&n);
         switch(n)
         {
         case 1:
             matrix_add(m1,m2,row1,row2,col1,col2);
             break;

         case 2:
             matrix_sub(m1,m2,row1,row2,col1,col2);
             break;

         case 3:
             matrix_multiply(m1,m2,row1,row2,col1,col2);
             break;

         case 4:
            transpose(m1,row1,col1);
            break;

         case 5:
            exit(0);

         default:
            printf("Invalid choice!\n");
        }
    }
}
