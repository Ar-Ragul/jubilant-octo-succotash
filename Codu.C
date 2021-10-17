#include <stdio.h> 
#include <unistd.h>
#include <sys/types.h>
const char*file_name = "studyme.txt"; 
void process()
{
pid_t pid;
FILE*file = fopen(file_name,"r");
int N = 0;
//fscan(file, "%d", &N);
fclose(file);
if ((pid = getpid())<0) { 
    printf("N:%d Process ID:%d",N,pid); 
}
file = fopen(file_name,"w");
N++;
putw(N,file);
fflush(file);
fclose(file);
}
int main()
{
    if (fork() == 0){
        printf("Process A Starts\n"); process();
    }
    if (fork() == 0){
        printf("Process B Starts\n"); process();
    }
    if (fork() == 0){
        printf(" Process C Starts\n"); process();
    }        
    return 0;
}