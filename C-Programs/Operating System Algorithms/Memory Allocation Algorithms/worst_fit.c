#include<stdio.h>
#include<string.h>
void worstfit(int blockSize[],int m,int processSize[],int n)
{
        int allocation[n];
        memset(allocation,-1,sizeof(allocation));
        for(int i=0;i<n;i++)
        {
                int worstIdx=-1;
                for(int j=0;j<m;j++)
                {
                        if(blockSize[j]>=processSize[i])
                        {
                                if(worstIdx == -1)
                                        worstIdx=j;
                                else if(blockSize[worstIdx]<blockSize[j])
                                        worstIdx=j;
                        }
                }
                if(worstIdx!=-1)
                {
                        allocation[i]=worstIdx;
                        blockSize[worstIdx]-=processSize[i];
                }
        }
        printf("\nProcess No. \tProcess Size\tBlock No.\n");
        for(int i=0;i<n;i++)
        {
                printf(" %d\t\t%d\t\t",(i+1),processSize[i]);
                if(allocation[i]!=-1)
                        printf("%d",allocation[i]+1);
                else
                        printf("Not Allocated");
                printf("\n");
        }
}
int main()
{
        int blockSize[]={100,500,200,300,600};
        int processSize[]={212,417,112,426};
        int m=5;
        int n=4;
        worstfit(blockSize,m,processSize,n);
        return 0;
}
