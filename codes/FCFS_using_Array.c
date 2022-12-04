#include <malloc.h>
#include <stdio.h>
#include <string.h>
#define SIZE 100
int main() {
char p[SIZE][5]; 
int pt[SIZE]; 
int c = 0, i, j, n;
float at = 0.0, turn = 0.0;
printf("\n Enter no of processes:");
scanf("%d", &n);
for (i = 0; i < n; i++) {
printf("\n Enter process %d name: ", i + 1);
scanf("%s", &p[i][0]);
printf("\n Enter Burst time: ");
scanf("%d", &pt[i]);
}
printf("\n");
for (i = 0; i < n; i++) {
printf("\t%s\t", p[i]);
}
printf("\n");
for (i = 0; i < n; i++) {
printf("\t(%d)\t", pt[i]);
}
printf("\n0\t-");
for (i = 0; i < n; i++) {
at += c;
turn += c + pt[i];
c = c + pt[i];
printf("-\t(%d)\t-", c);
}
printf("\n");
printf("Average time: %f\n", at / n);
printf("Turn around time: %f\n", turn / n);
return 0;
}

