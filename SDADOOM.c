#include <stdio.h>
#include <string.h>

int main(){
    FILE* cross_road_file_pointer;
    cross_road_file_pointer = fopen("Crossroad.txt","r");
    char Array_of_cross_roads[152][500];
    char Name_of_cross_roads[152][200];
    char Cross_Road[500];
    char *token;
    char name[200];
    int i = 0,contor;
    while(!feof(cross_road_file_pointer)){
        fgets(Cross_Road, 500, cross_road_file_pointer);
        strcpy(Array_of_cross_roads[i],Cross_Road);
        i++;
    };
    fclose(cross_road_file_pointer);
    for(i = 0; i < 3; i++){
        strcpy(name,"");
        contor = 0;
        token = strtok(Array_of_cross_roads[i],":");
        strcat(name,token);
        while(token != NULL){
            token = strtok(NULL," ");
        }
        strcpy(Name_of_cross_roads[i],name);
        printf("%s\n",Name_of_cross_roads[i]);
    }
}
