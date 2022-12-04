#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
pid_t pid;
pid = fork();
if (pid != 0) {
while (1)
sleep(5);
} else {
exit(0);
}
}
