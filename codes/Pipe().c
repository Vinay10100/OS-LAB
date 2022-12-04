#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define SIZE 100
int main() {
pid_t pid;
char arr[SIZE], str[SIZE];
int fd[2]; 
int nbr, nbw; 
pipe(fd);
pid = fork();
if (pid == 0) {
printf("Enter a string: ");
fgets(str, SIZE, stdin);
nbw = write(fd[1], str, strlen(str));
printf("Child wrote %d bytes\n", nbw);
exit(0);
} else {
nbr = read(fd[0], arr, sizeof(arr));
arr[nbr] = ’\0’;
printf("Parent read %d bytes : %s\n", nbr, arr);
}
return 0;
}

