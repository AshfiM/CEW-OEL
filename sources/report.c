#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/media/psf/Home/Desktop/OEL/headers/report_header.h"
#include "/media/psf/Home/Desktop/OEL/headers/resultstruct_header.h"


struct Result* report_data() {
    FILE *processfile = fopen("/media/psf/Home/Desktop/OEL/textfile/process_data.txt", "r");
    FILE *reportfile = fopen("/media/psf/Home/Desktop/OEL/textfile/report_file.txt", "w");

    if (processfile == NULL) {
        printf("process data file open error");
    }
    int *temparatures = (int*)calloc(1000, sizeof(char));

    fseek(processfile, 0, SEEK_SET);
    char *data = (char*)malloc(sizeof(char) * 1000);
    int count = 0;
    int te = 0;
    char date[100] = "";
    int datecount = 0;
    while ((fgets(data, 100, processfile))) {
        //printf("%s\n", data);
        int i =0;
        int j =0;
        char temp[100] = "";
        
        while (*(data + i) != ':'){
            //printf("%c", *(data +i ));
            temp[j] = *(data +i );
            i += 1;
            j += 1;
        }
        //printf("%s\n", temp);
        if (strcmp(temp, "datetime") == 0 ){
            
            if (datecount == 1) {
                continue;
            }
            datecount += 1;
            //printf("%s", temp);
            int d = i + 2;
            int dt = 0;
            while (*(data + d) != '"'){
                //printf("%c", *(data + d));
                date[dt] = *(data + d);
                dt += 1;
                d+=1;
            }
            // printf("%s", date);
            // printf("\n");
        }
        if (strcmp(temp, "temp") == 0) {
            count += 1;
            
            //printf("found %s", temp);
            int m = i + 1;
            int n = 0;
            char number[100] = {};
            while (data[m]){
                number[n] = data[m];
                //printf("%c", data[m]);
                m += 1;
                n += 1;
            }
            
            //printf("%s", number);
            temparatures[te] = atoi(number);
            if (count == 24){
                //printf("%d",temparatures[te]);
                break;
            }
            te += 1;
        }
        
    }
    int tep = 0;
    int l= 44;
    //printf("%s", temparatures);
    while(temparatures[tep]) {
        //printf("%d ", temparatures[tep]);
        if (temparatures[tep] < l) {
            //printf("l%d ",temparatures[tep]);
            l = temparatures[tep];
        }

        tep +=1;
    }
    //printf("\n");
    //printf("minimum temparature today %d F\n", l);
    static struct Result r;
    r.min = l;
    r.date = date;
    //printf("%s", date);
    printf("date %s min temp %d F\n", r.date , r.min);
    fprintf(reportfile, "Date %s min Temp %d F\n", r.date, r.min);
    
    free(temparatures);
    free(data);
    fclose(reportfile);
    fclose(processfile);
    

    return &r;
}