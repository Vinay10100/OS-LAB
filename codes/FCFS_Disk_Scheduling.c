#include <stdio.h>
#include <stdlib.h>
int main()
{
int i,n,head;
printf("Enter the number of requests: ");
scanf("%d",&n);
int request[n];
printf("Enter the requests: ");
for (i = 0; i < n; ++i){
scanf("%d",&request[i]);
}
printf("Enter initial position of R/W head: ");
scanf("%d",&head);

int seek=0;
printf("%d -> ",head );
for(i=0;i<n;i++){	
if(i == n-1)
printf("%d\n", request[i] );
else
printf("%d -> ", request[i] );
seek += abs(request[i] - head);
head = request[i];
}
printf("total head movement : %d\n", seek);
}