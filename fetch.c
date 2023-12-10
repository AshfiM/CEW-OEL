# include <stdio.h>
# include <curl/curl.h>
size_t write_data(void *data, size_t data_size, size_t nmeb, void *userdata) {
    /*nmeb is no of bytes in block of data

    */
    FILE *raw_file = fopen("raw_data_file.txt", "a");
    if (raw_file == NULL) {
        printf("file open error");
        return nmeb;
    }
    size_t real_size = data_size * nmeb;
    for (int i = 0; i < nmeb; ++i) {
        fprintf(raw_file,"%c", ((char*) data)[i]);
        printf("%c", ((char*)(data ))[i] );

    }
    fclose(raw_file);

    return nmeb;
    
}
int main () {

    /*store result from curl api
    curl_easy_init() return curl handler, the curl handler create and manage the http request
    curl_easy_setopt(handler, CURLOPT_URL, "url" ) enalbes the option for the http request
    curl_easy_setopt(handler, CURLOPT_WRITEFUNCTION, function) curl_easy_perform() call the "function"
    repeatedly, The "function" has perticular prototype

    curl_easy_perform() get the data from url
    curl_easy_clenup()close the curl api
    */
    //api key DR3N4RXUKVG775A3MNTWNEQE8
    CURL* curl;
    CURLcode response; 
    curl = curl_easy_init();

    if (curl == NULL) {
        printf("curl handler failed");
        return -1;
    }
    FILE *raw_file = fopen("raw_data_file.txt", "a");
    curl_easy_setopt(curl, CURLOPT_URL, "https://weather.visualcrossing.com/VisualCrossingWebServices/rest/services/timeline/London%2CUK?unitGroup=us&key=DR3N4RXUKVG775A3MNTWNEQE8");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    response = curl_easy_perform(curl);
    if (response != CURLE_OK) {
        printf("curl_easy_perform failed");
        return -1;
    }
    else {

    }
    fclose(raw_file);
    curl_easy_cleanup(curl);
    return 0;
}