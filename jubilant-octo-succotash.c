#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

int main(){
    int fd,fd2;
    char buffer[1000000];
    clock_t time_taken ;
    for(int i = 2 ; i <= 1024 ; i*=2){
    time_taken = clock();
    fd = open("Sample5.txt",O_RDONLY);//opening the source file
    printf(" file descriptor is fd = %d\n",fd );
       if(fd != 1){
    printf("the file is opened succesfully in read and write mode\n");
    read(fd,buffer,i);
    fd2 =  creat("Output.txt", O_RDWR);                              // reading the source file
    fd2 = open("Output.txt", O_WRONLY);                    //opening the target file in thread and write mode
    write(fd2,buffer,i);                   //writing on the target file
    close(fd);                     //closing the source file
    close(fd2);                  // closing the target file 
    time_taken = clock()- time_taken;
    double total_time_taken = ((double)time_taken)/CLOCKS_PER_SEC;
    printf("the time taken to transfer %d bytes is  %f \n" ,i,total_time_taken);
    }
}
return 0;
}