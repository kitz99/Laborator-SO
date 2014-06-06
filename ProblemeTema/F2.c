#include <stdio.h>
#include <stdlib.h>
int nr;
int prim (int x){
   int d;
   for(d = 2; d <= x/2; d++)
	if( x % d == 0) return 0;
   return 1;
}
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
     if(nr < 2) printf("Numarul nu este prim\n");
      else 
       if (prim(nr) == 1) printf("Numarul este prim\n");
        else printf("Numarul nu este prim\n");
   }
   else {printf("Data introdusa nu este un intreg\n");  return -1;}
   return 0;
}
