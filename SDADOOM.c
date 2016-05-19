#include <stdio.h>
#include <string.h>
#include <time.h>

int main(){
    FILE* cross_road_file_pointer;
    cross_road_file_pointer = fopen("Crossroad.txt","r"); //Pointer to file with our crossroads
    char Array_of_cross_roads[152][500]; //Array which stores the lines from the file
    char Name_of_cross_roads[152][200]; //Array which stores only the names of the crossroads in file
    int Distances_between_cross_roads[152][152]; //Array which stores the distances between the crossroads
    char Cross_Road[500]; //Array of char type which stores each line separately from the file
    char *token; //Pointer to char type, which is used as pointer to tokenized strings
    char name[200]; //Array of char which stores the name of each crossroad separately
    int i = 0, j = 0, contor = 0, crossroad_initial, crossroad_final; //i,j used in for loops, crossroad_initial,crossroad_final used to store the number of crossroad where are person and where he wants to go
    int number_of_crossroads = 3; //integer variable which stores the number of the crossroads in file
    int infinity = 1000000; //integer which holds a very big number because programs did not have infinity
    int Distances_of_chosen_crossroad[152] = {[0 ... 151] = infinity}; //Array of infinities, representing the distances from the selected point to every node in our graph
    int Unvisited_array[152] = {[0 ... 151] = 0}; //Array of unvisited crossroads
    int minimum,u; //Minimum variable,u variable to hold i;
    int distance_changed; //Variable which holds the changed distance of a certain node;
    time_t linear_start_time, linear_end_time; //Variables which holds the time of start and end of linear algorithm

    //Reading the file line by line and storing lines into Array_of_cross_roads
    while(!feof(cross_road_file_pointer)){
        fgets(Cross_Road, 500, cross_road_file_pointer);
        strcpy(Array_of_cross_roads[i],Cross_Road);
        i++;
    };

    fclose(cross_road_file_pointer);

    //Processing every line from the file and storing information about crossroads into arrays (Name_of_cross_roads, Distances_between_cross_roads)
    for(i = 0; i < number_of_crossroads; i++){
        strcpy(name,"");
        token = strtok(Array_of_cross_roads[i],":");
        strcat(name,token);
        j = 0;
        while(token != NULL){
            token = strtok(NULL," ");
            Distances_between_cross_roads[i][j] = atoi(token);
            j++;
        }
        strcpy(Name_of_cross_roads[i],name);
    }

    //ENTER THE NUMBER OF CROSSROAD YOU ARE AT THE MOMENT!
    puts("Enter the number of the crossroad you are at the moment :");
    for(i = 0; i < number_of_crossroads; i++){
        printf("%d.%s\n",i+1,Name_of_cross_roads[i]);
    }
    scanf("%d",&crossroad_initial);

    while(crossroad_initial < 1 || crossroad_initial > 152){
        puts("Wrong number were entered!, re-enter the number!");
        scanf("%d",&crossroad_initial);
    }

    //ENTER THE NUMBER OF CROSSROAD YOU WANT TO GO TO!
    puts("Enter the number of the crossroad you need to go :");
    for(i = 0; i < number_of_crossroads; i++){
        printf("%d.%s\n",i+1,Name_of_cross_roads[i]);
    }
    scanf("%d",&crossroad_final);
    while(crossroad_final < 1 || crossroad_final > 152){
        puts("Wrong number were entered!, re-enter the number!");
        scanf("%d",&crossroad_final);
    }

    if(crossroad_final == crossroad_initial){
        puts("You are already on the place!!");
    }

    else{

        //LINEAR PROCESSING

        linear_start_time = time(NULL);
        Distances_of_chosen_crossroad[crossroad_initial-1] = 0;
        while(contor != number_of_crossroads){
            minimum = infinity;

            for(i = 0; i < number_of_crossroads; i++){
                if(Unvisited_array[i] == 0){
                    if(Distances_of_chosen_crossroad[i] <= minimum){
                        minimum = Distances_of_chosen_crossroad[i];
                        u = i;
                    }
                }
            }

            for (i = 0; i < number_of_crossroads; i++){
                if(Distances_between_cross_roads[u][i] != 0){
                    distance_changed = Distances_of_chosen_crossroad[u] + Distances_between_cross_roads[u][i];
                    if (distance_changed < Distances_of_chosen_crossroad[i]){
                        Distances_of_chosen_crossroad[i] = distance_changed;
                    }
                }
            }
            Unvisited_array[u] = -1;
            contor++;
        }
        linear_end_time = time(NULL);

        printf("\nShortest distance %d\n",Distances_of_chosen_crossroad[crossroad_final-1]);
        printf("Linear processing of the crossroads used %f, seconds \n", difftime(linear_end_time,linear_start_time));


        //PARALLEL PROCESSING

    }
}
