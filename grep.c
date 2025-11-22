#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAX 8192
FILE* open_file(char *filename){
    FILE *f=fopen(filename,"r"); //deschidem fisierul pentru citire
    if(!f){
        perror("Eroare la deschiderea fisierului");
        exit(1);
    }
    return f; //returnam pointerul catre fisier
}
void search_start(FILE *f1, FILE *f2, char *buffer_f2,char *buffer_f1, int buffer_size){
    while(fgets(buffer_f2,buffer_size,f2)){
        rewind(f1); //ne intoarcem la inceputul fisierului f1
        while(fgets(buffer_f1,buffer_size,f1)){
            buffer_f1[strcspn(buffer_f1,"\n")] = 0; // eliminam caracterul de newline
            if(strlen(buffer_f1)>0){
                if(strstr(buffer_f2,buffer_f1)){
                    printf("%s",buffer_f2);
                    break;
        }
    }    
 }

}
}
int main(int argc, char *argv[]){
    //argc imi numara argumentele din linia de comanda
    //argv retine numele fisierelor din linia de comanda
    if(argc<3){
        fprintf(stderr,"Numar insuficient de argumente\n");
        return 1;
    }
    FILE *f1=open_file(argv[1]);
    FILE *f2=open_file(argv[2]);
    char *buffer_f2=(char*)malloc(MAX*sizeof(char));
    if(!buffer_f2){
        perror("Eroare la alocarea memoriei");
        fclose(f1);
        fclose(f2);
        return 1;
    }
    char *buffer_f1=(char*)malloc(MAX*sizeof(char));
    if(!buffer_f1){
        perror("Eroare la alocarea memoriei");
        free(buffer_f2);
        fclose(f1);
        fclose(f2);
        return 1;
    }
    search_start(f1,f2,buffer_f2,buffer_f1,MAX);
    free(buffer_f1);
    free(buffer_f2); //eliberam memoria alocata pentru buffer
    if(fclose(f1)!=0){
        perror("Eroare la inchiderea fisierului");
        fclose(f2);
        return 1;
    }
    if(fclose(f2)!=0){
        perror("Eroare la inchiderea fisierului");
        return 1;
    }
    return 0;
}