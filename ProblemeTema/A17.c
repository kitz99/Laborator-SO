 #include <stdio.h>
 #include <string.h>
 #include <unistd.h>
 #include <stdlib.h>
 int main(){
    char cwd[256], nwd[256], t[256], var[256];
    getcwd(cwd, sizeof(cwd));
    printf("Valoare returnata de getcwd: %s\n", cwd);
    printf("PWD=%s\n", (char *)getenv("PWD"));
    printf("Valoarea cu care se inlocuieste PWD: ");
    fgets(t, 255, stdin);//gets(t);
    strcpy(var, "PWD=");
    strcat(var, t);
    putenv(var);
    printf("PWD=%s\n", (char *)getenv("PWD"));
    getcwd(nwd, sizeof(nwd));
    printf("Valoare getcwd dupa modificarea PWD: %s\n", nwd);
    if(strcmp(nwd, cwd) == 0) printf("Valoarea returnata nu se modifica\n");
    else printf("Valoarea returnata se modifica\n");
   return 0;
 }
