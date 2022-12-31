#include<stdio.h>
#include<conio.h>
int main(){
	int n,frames[20],len,str[20],fault=0,hits=0,i,j;
	printf("Enter the length of the reference string: ");
		scanf("%d",&len);
	printf("Enter the reference string: ");
	for(i=0;i<len;i++)
		scanf("%d",&str[i]);
	printf("Enter the frame size: ");
		scanf("%d",&n);
    for (int i=0;i<n;i++)
    	frames[i]=-1;
    	int index=-1;
    for (int i=0;i<len;i++){
        int flag=0;
        for(int j=0;j<n;j++){
            if (str[i]==frames[j]){
                flag=1;
                break;
            }
        }
        if (flag==1){
            printf("\n reference string: %d  Frame: ",str[i]);
            for (int j=0;j<n;j++)
                printf("%d ",frames[j]);
            hits+=1;
        }
        else{
            index=(index+1)%n;
            frames[index]=str[i];
            fault+=1;
            printf("\n reference string: %d  Frame: ",str[i]);
            for (int j=0;j<n;j++)
                printf("%d ",frames[j]);
        }
    }
    printf("\n\n Page hits: %d",hits);
    printf("\n Page fault: %d",fault);
}