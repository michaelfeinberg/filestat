#include <stdlib.h>
#include <stdio.h>

#include <string.h>
#include <errno.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


int main(){
  //Create and open file
  int fd = open( "newfile.txt" , O_CREAT , 0644 );
  
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
  printf( "Size of file: %d\n" , buff -> st_size );

  //Free memory and close files
  free( buff );
  close( fd );
}
