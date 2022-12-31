#include<stdio.h>
int main(){
	int n,frames[20],len,str[20],fault=0,hits=0;
	printf("Enter the length of the reference string: ");
		scanf("%d",&len);
	printf("Enter the reference str: ");
	for(int i=0;i<len;i++)
		scanf("%d",&str[i]);
	printf("Enter the frame n: ");
		scanf("%d",&n);
    for (int i=0;i<n;i++)
    	frames[i]=-1;
    	int index=-1;
    for (int i=0;i<len;i++)
    {
        int symbol=str[i];
        int flag=0;
        int full=0;

        for(int j=0;j<n;j++)
        {
            if (symbol==frames[j])
            {
                flag=1;
                break;
            }
        }

        if (flag==1)
        {
            printf("\nSymbol: %d  Frame: ",symbol);
            for (int j=0;j<n;j++)
                printf("%d ",frames[j]);
            hits+=1;
        }
        else
        {
            if (full==0)
            {
                index=(index+1)%n;
                frames[index]=symbol;
                fault+=1;
                printf("\nSymbol: %d  Frame: ",symbol);
                for (int j=0;j<n;j++)
                    printf("%d ",frames[j]);
            }
            else
            {
                int pos=999;
                int index=-1;

                for(int j=0;j<n;j++)
                {
                    for (int k=0;k<len;k++)
                    {
                        if (frames[j]==str[k])
                        {
                            if (pos>k)
                            {
                                pos=k;
                                index=j;
                                break;
                            }
                        } 
                    }
                }

                frames[index]=symbol;

            }
        }
    }
    printf("\nPage hits: %d",hits);
    printf("\nPage misses: %d",fault);
}