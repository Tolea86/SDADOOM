#include <stdio.h>

int main(){
    FILE* cross_road_file_pointer;
    cross_road_file_pointer = fopen("Crossroad.txt","r");
    char Array_of_cross_roads[152][500];
    char Cross_Road[500];
    int i = 0;
    while(!feof(cross_road_file_pointer)){
        fgets(Cross_Road, 500, cross_road_file_pointer);
        strcpy(Array_of_cross_roads[i],Cross_Road);
        i++;
    };
    fclose(cross_road_file_pointer);
    for(i = 0; i < 3; i++){
        printf("%s",Array_of_cross_roads[i]);
    }
}
