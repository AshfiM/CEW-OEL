# include <stdio.h>
# include <stdlib.h>
# include <curl/curl.h>
# include <string.h>
# include "/media/psf/Home/Desktop/OEL/headers/fetch_header.h"


size_t write_data(void *data, size_t size, size_t nmeb, void *userdata) {
    /*nmeb is no of bytes in block of data
    must return the nmeb 
    the  "size" argument always going to be 1 
    */
   
    FILE *raw_file = fopen("/media/psf/Home/Desktop/OEL/textfile/raw_data_file.txt", "a+");
    if (raw_file == NULL) {
        printf("file open error");
        return nmeb;
    }
    size_t real_size = size * nmeb;
    for (int i = 1; i < nmeb; ++i) {
        char ch = ((char*) data)[i];
        //printf("%c\n",  *(char*)(data + i));
        if (ch == ',' || ch == '{' || ch == '}' || ch == '[' || ch == ']'){
            fprintf(raw_file,"|\n");
            } else {
                fprintf(raw_file,"%c", ((char*) data)[i]);
            }
    }
    fclose(raw_file);

    return real_size;
    
}

void fetch_data() {
    FILE *clearfile = fopen("/media/psf/Home/Desktop/OEL/textfile/raw_data_file.txt", "w");
    if (clearfile == NULL) {
        printf("clearfile error");
        return;
    }
    fclose(clearfile);

    CURL* curl;
    CURLcode response; 
    curl = curl_easy_init();



    if (curl == NULL) {
        printf("curl handler failed");
        return;
    }
    curl_easy_setopt(curl, CURLOPT_URL, "https://weather.visualcrossing.com/VisualCrossingWebServices/rest/services/timeline/London%2CUK?unitGroup=us&key=DR3N4RXUKVG775A3MNTWNEQE8");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
  
    response = curl_easy_perform(curl);
    if (response != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform returned\n%s\n", curl_easy_strerror(response));
        return;
    }

    printf("fetching completed\n");
    curl_easy_cleanup(curl);
}
