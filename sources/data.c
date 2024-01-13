#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/media/psf/Home/Desktop/OEL/headers/dataprocess_header.h"
void process_data() {

    FILE *file = fopen("/media/psf/Home/Desktop/OEL/textfile/raw_data_file.txt", "r");
    if (file == NULL) {
        printf("raw data file file open error");
        return;
    }
    FILE *processFile = fopen("/media/psf/Home/Desktop/OEL/textfile/process_data.txt", "w");
    if (processFile == NULL) {
        printf("prcoess data file open error");
        return;
    }
    char *data = (char*) malloc(sizeof(char) * 10000);

    if (data == NULL) {
        printf("malloc error");
        return;
    }

    fseek(file, 0, SEEK_SET);
    while ((fgets (data, 100, file))){ 
    char *temp = (char*) malloc(sizeof(char) * 200);
        //printf("%s", data);
        int k =1;
        int j =0;
        
        while (data[k] != '"'){
            *(temp + j) = data[k]; 
            //printf("%c", data[k]);
            k += 1;
            j += 1; 
        }
        //printf("\n");
        //printf("%s\n", temp);
        if (strcmp(temp, "feelslike") == 0) {
            //printf("temp: " );
            int m = k + 1;
            fputs("temp", processFile);
            while(data[m] != '|'){
                //printf("%c", data[m]);
                fputc(data[m], processFile);
                m +=1;
            }
            fprintf(processFile, "\n");
            //printf("\n");
        }

        if (strcmp(temp, "datetime") == 0) {
            //printf("datetime");
            int m = k + 1;
            fputs(temp, processFile);
            while(data[m] != '|'){
                //printf("%c", data[m]);
                fputc(data[m], processFile);
                m +=1;
            }
            fprintf(processFile, "\n");
            //printf("\n");
        }
        
    free(temp);
    }
    printf("data processing completed\n");
    free(data);
    fclose(file);
    fclose(processFile);
}
