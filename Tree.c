#include <stdio.h>
#include <dirent.h>
#include <string.h>

void tree(char s[1000]);

void tree(char str[1000]){
    static int count = 0;
    DIR *dir;
    struct dirent *dirp;
    char *fn = str;
    dir = opendir(fn);
    while((dirp = readdir(dir)) != NULL){
        if ( !strcmp(dirp->d_name, ".") || !strcmp(dirp->d_name, "..") ){}
        else{
            for (int j=0; j<count; j++)
                    printf("\t");
            printf("%s\n",dirp->d_name);
            char strp[1000];
            strcpy(strp,str);
            strcat(strp,"/");
            strcat(strp,dirp->d_name);
            //printf("%s\n",strp);
            if ((opendir(strp)) != NULL){
                count++;
                //printf("Incremented count %d\n",count);
                //for (int j=0; j<count; j++)
                    //printf("\t");
                tree(strp);
            }
        }
    }  
    closedir(dir);
    count--;
    //printf("Decremented count %d\n",count);
}

int main(){
    char s[1000];
    gets(s);
    for (int i=0; i<strlen(s); i++){
        if (s[i]=='\\')
            s[i]='/';
    }
    tree(s);
    return 0;
}