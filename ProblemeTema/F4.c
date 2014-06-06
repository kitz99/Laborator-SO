#include <stdio.h>
#include <stdlib.h>
int nr;
int main(int argc, char* argv[]){
   int i = 0, k = 1;
   if(argv[1] == NULL) {printf("Argument invalid\n"); return -1; }
   if(argv[1][0] == 48 && argv[1][1] != '\0') k = 0;
   if(argv[2] != NULL) {printf("Argumente invalid\n"); return -1; }
   while(argv[1][i] != '\0'){ 
       if(argv[1][i] > 57 || argv[1][i] < 48) k = 0;
       else nr = nr * 10 + (argv[1][i] - 48);
       i = i + 1;
   } 
   if( k == 1){
      int s = 0;
      while(nr > 0){
	s = s + (nr % 10);
        nr = nr / 10;
      }
      printf("S=%d\n", s);
   }
   else {printf("Argument invalid\n");  return -1;}
   return 0;
}
