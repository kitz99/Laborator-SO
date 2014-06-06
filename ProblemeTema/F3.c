#include <stdio.h>
#include <errno.h>
int nr;
int main(int argc, char* argv[]){
   int i = 0, k = 1;
   if(argv[1] == NULL) {printf("Argumente invalide\n"); return -1; }
   if(argv[1][0] == 48 && argv[1][1] != '\0') k = 0;
   if(argv[2] != NULL) {printf("Argumente invalide\n"); return -1; }
   while(argv[1][i] != '\0'){ 
       if(argv[1][i] > 57 || argv[1][i] < 48) k = 0;
       else nr = nr * 10 + (argv[1][i] - 48);
       i = i + 1;
   } 
   if( k == 1){
     if(nr == 0) {printf("Descompunere imposibila\n"); return -1;}
     if(nr == 1) {printf("Descompunere imposibila\n"); return -1;}
     int p, d = 2;
     while(nr>1){
        p=0;
        while(nr%d==0){
            p=p+1;
            nr=nr/d;
        }
        if(p) printf("%d la puterea %d\n", d, p);
        d=d+1;
     }
   }
   else {printf("Argumente invalide\n"); return -1;}
   return 0;
}
