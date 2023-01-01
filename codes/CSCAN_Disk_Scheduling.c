#include<stdio.h>
int find(int d[],int n,int head)
{
int i;
for(i=0;i<n-1;i++)
{
if(d[i]>head)
{
  return i;
  break;
}
}
}

int main()
{
int i,j,n;
int head;   
int temp,max;
int ptr;   
int no_t;

printf("\n enter total number of tracks\n");
scanf("%d",&no_t);

printf("\n enter number of location\n");
scanf("%d",&n);

int d[n+1]; 

printf("\n enter position of head\n");
scanf("%d",&head);

printf("\n enter elements of head queue\n");
for(i=0;i<n;i++)
{
scanf("%d",&d[i]);
}
for(i=0;i<n-1;i++)   
{
for(j=i+1;j<n;j++)
{
if(d[i]>d[j])
{
temp=d[i];
d[i]=d[j];
d[j]=temp;
}
}
}

printf("elements after sorting\n");

for(i=0;i<n;i++)
{
printf("%d ",d[i]);
}

int prev_head;
printf("\nenter previous head position\n");
scanf("%d",&prev_head);

int c;
int sum=0;

if(prev_head>head)
c=1;
else
c=2;

if(c==1)
{
int previous = find(d,n,head);

previous = previous-1;


sum+=abs(head-d[previous]);


printf("%d->",head);

for(i=previous;i>=0;i--)
{
printf("%d ->",d[i]);
if(i!=0)
{
   int dr=abs(d[i]-d[i-1]);
   sum+=dr;
}
else if(i==0)
   {
       sum+=d[i];
   }
}
printf("0 ->");

printf("%d ->",no_t-1);

sum+=no_t-1-d[n-1];


for(i=n-1;i>=previous+1;i--)
{
   printf("%d ->",d[i]);

   if(i!=previous+1)
   {
    int dr=abs(d[i]-d[i-1]);
    sum+=dr;
   }
}


printf("\nTotal Head Movement %d\n",sum);
}

else if(c==2)
{
int previous = find(d,n,head);

printf("%d\n",previous);

sum+=abs(d[previous]-head);

printf("%d->",head);

for(i=previous;i<n;i++)
{
printf("%d ->",d[i]);
if(i!=n-1)
   sum+=abs(d[i+1]-d[i]);
else if(i==n-1)
   sum+=abs(no_t-1-d[i]);
}
printf("%d ->",no_t-1);

printf("0 ->");

sum+=d[0];

for(i=0;i<=previous-1;i++)
{
   printf("%d ->",d[i]);

   if(i!=previous-1)
    sum+=abs(d[i+1]-d[i]);
}



printf("\nTotal Head Movement %d\n",sum);
}

return 0;
}
