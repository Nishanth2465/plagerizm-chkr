#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>



int get_file_size(char *file_name){
    FILE *file = fopen(file_name, "r");
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    rewind(file);
    fclose(file);
    return file_size;
}
char *read_file(char *file_name){

    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening file");
        
    }

    
    int file_size=get_file_size(file_name);     //using function

  
    char *filec = (char*)malloc(file_size + 1);  
    if (filec == NULL) {
        printf("Memory allocation has failed");
    
    }

    
    fread(filec, sizeof(char), file_size, file);
    filec[file_size] = '\0';  

    fclose(file);
    
    return filec;

    

}

void tokenize(char *filec){
    char *token[];
    int i=0;
    token[i]=strtok(filec," \t\n.,!?;:\"()[]{}<>&*#");
    while(i!=NULL){
        // printf("%s\n",token[i]);
        i++;
        token[i]=strtok(NULL," \t\n.,!?;:\"()[]{}<>&*#");
    }


}

int main(){
    char *bat=read_file("alpha.txt");
    tokenize(bat);

}

