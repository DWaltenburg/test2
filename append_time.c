#include <stdio.h>
#include <time.h>

char time_arr[21];

char* format_time(){
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    sprintf(time_arr,"[%d %d %d %d:%d:%d]",timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    return time_arr;
}

void main(){
    float vals[5] = {12.3, 4.56, 7.89};
    FILE *f = fopen("file.txt", "a");
    if (f == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    for(int i = 0; i < 10; i++){
        fprintf(f, " %s %f \n", format_time(), vals[i]);
    }
    
    fclose(f);
}