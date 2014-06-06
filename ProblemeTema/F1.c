#include <stdio.h>
#include <stdlib.h>
int nr1, nr2; 
int main(int argc, char *argv[]){
   int i = 0, k = 1, kk = 1;
   if(argv[1] == NULL) {printf("Argumente invalide\n"); return 0; }
   if(argv[2] == NULL) {printf("Argumente invalide\n"); return 0; }
   if(argv[3] != NULL) {printf("Argumente invalide\n"); return 0; }
   if(argv[1][0] == 48 && argv[1][1] != '\0') k = 0;
   if(argv[2][0] == 48 && argv[2][1] != '\0') k = 0;
   while(argv[1][i] != '\0'){ 
       if(argv[1][i] > 57 || argv[1][i] < 48) k = 0;
       else nr1 = nr1 * 10 + (argv[1][i] - 48);
       i = i + 1;
   } 
   i = 0;
   while(argv[2][i] != '\0'){ 
       if(argv[2][i] > 57 || argv[2][i] < 48) k = 0;
       else nr2 = nr2 * 10 + (argv[2][i] - 48);
       i = i + 1;
   }
     if( k == 1){
        int r = 0;
        if(nr1 == 0 && nr2 == 0) {printf("Ambele argumente sunt 0"); return 0;} 
        if(nr1 == 0) printf("Cmmdc = %d\n", nr2);
        else if(nr2 == 0) printf("Cmmdc = %d\n", nr1);
              else {
                 for(r = nr1 % nr2; r!=0; nr1 = nr2, nr2=r, r = nr1%nr2);
                 printf("Cmmdc = %d\n", nr2);
                 }
     }
     else printf("Date invalide\n");
     return 0;
}
