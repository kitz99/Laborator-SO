#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <dirent.h>
void parcurgere(char *desc, int nivel)
{
    DIR *dir_actual = NULL;
    if( (dir_actual = opendir(desc)) == NULL)
        if(!(errno == ENOTDIR || errno == ENOENT || errno == EACCES)){ perror(desc); exit(1); }
          else;
    else
    {
        struct dirent *data_dir_actual = NULL;
        while( (data_dir_actual = readdir(dir_actual)) != NULL)
        {
            if(strcmp(data_dir_actual->d_name, ".") == 0 || strcmp(data_dir_actual->d_name, "..") == 0)
                continue;

            int i;
            for(i=0; i<nivel; i++)
                printf("\x1B[31m|  ");
            if(data_dir_actual->d_type == DT_DIR)
                 printf("\x1B[34m%s\n\x1B[37m", data_dir_actual->d_name);
            else
                 printf("\x1B[32m%s\n\x1B[37m", data_dir_actual->d_name);
            int dim_dir = strlen(data_dir_actual->d_name);
            char *desc_nou = malloc(sizeof(char) * (strlen(desc) + dim_dir + 2));

            strcpy(desc_nou, desc);
            if(strcmp(desc, "/"))
                strcat(desc_nou, "/");
            strcat(desc_nou, data_dir_actual->d_name);

            parcurgere(desc_nou, nivel+1);
            free(desc_nou);
        }
        closedir(dir_actual);
    }
}

int main(int argc, char *argv[])
{
    if(argc != 2) { printf("Argument invalid\n"); return -1; }
    char nume[256];
    strcpy(nume, argv[1]);
    parcurgere(nume, 0);
    return 0;
}
