#include <stdlib.h>
#include <stdio.h>

#include <string.h>
#include <errno.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


int main(){
  umask(0);
  //open file
  int fd = open( "stat.c" , O_RDWR );
  
  //Check for errors
  if( fd < 0 ) {
    printf("%d - %s",errno,strerror(errno));
    return 0;
  }

  //Allocate memory
  struct stat *buff = (struct stat *)malloc(sizeof(struct stat));
  

  //Store file information in buff
  int err = fstat( fd , buff );
  

  //Check for errors
  if( err < 0 ) {
    printf( "%d - %s" , errno , strerror( errno ) );
    return 0;
  }

  //Print file information

  double bsize = buff -> st_size;
  double kbsize = bsize / 1000.0;
  double mbsize = kbsize / 1000.0;
  double gbsize = mbsize / 1000.0;
  if(bsize < 1000){
    printf( "Size of file: %lf B\n" , bsize );
  }else if(bsize < 1000000){
    printf( "Size of file: %lf KB\n" , kbsize ); 
  }else if(bsize < 1000000000){
    printf( "Size of file: %lf MB\n" , mbsize );
  }else{
    printf( "Size of file: %lf GB\n" , gbsize );
  }
  


  printf( "Time of last access: %s\n" , ctime(&(*buff).st_atim) );

  mode_t mode = buff -> st_mode;
  
  printf("File permissions: ");
  if(mode & S_IRUSR){
    printf("r");
  }else{
    printf("-");
  }
  
  if(mode & S_IWUSR){
    printf("w");
  }else{
    printf("-");
  }

  if(mode & S_IXUSR){
    printf("x");
  }else{
    printf("-");
  }

  if(mode & S_IRGRP){
    printf("r");
  }else{
    printf("-");
  }

  if(mode & S_IWGRP){
    printf("w");
  }else{
    printf("-");
  }

  if(mode & S_IXGRP){
    printf("x");
  }else{
    printf("-");
  }

  if(mode & S_IROTH){
    printf("r");
  }else{
    printf("-");
  }

  if(mode & S_IWOTH){
    printf("w");
  }else{
    printf("-");
  }

  if(mode & S_IXOTH){
    printf("x");
  }else{
    printf("-");
  }

  printf("\n");
  

  //Free memory and close files
  free( buff );
  close( fd );
}
