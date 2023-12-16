# include <stdio.h>
# include <curl/curl.h>
size_t write_data(void *data, size_t size, size_t nmeb, void *userdata) {
    /*nmeb is no of bytes in block of data
    must return the nmeb 
    the  "size" argument always going to be 1 
    */
   
    FILE *raw_file = fopen("raw_data_file.txt", "a");
    if (raw_file == NULL) {
        printf("file open error");
        return nmeb;
    }
    size_t real_size = size * nmeb;
    for (int i = 0; i < nmeb; ++i) {
        fprintf(raw_file,"%c", ((char*) data)[i]);
    }
    fclose(raw_file);

    return nmeb;
    
}
int main () {

    /*store result from curl api
    curl_easy_init() return curl handler, the curl handler create and manage the http request
    curl_easy_setopt(handler, CURLOPT_URL, "url" ) enalbes the option for the http request
    curl_easy_setopt(handler, CURLOPT_WRITEFUNCTION, function) curl_easy_perform() call the "function"
    curl_easy_setpot(handler, CURLOPT_WRITEDATA, pointer) fourth argument in function 
    repeatedly, The "function" has perticular prototype
    curl_easy_perform() get the data from url
    curl_easy_clenup()close the curl api
    <gcc libcurl_test.c curl/libcurl_a.lib> to run link the curl library in windows
    <gcc -lcurl -o d filename.c> compile the program in mac
    <./d> execute the program in mac
    necessary files to run curl in linux
        sudo apt update && sudo apt upgrade
        sudo apt install build-essential
        sudo apt install libcurl4-gnutls-dev
        sudo apt-get install libcurl4-openssl-dev
        sudo apt-get install libcurl4-nss-dev
    <gcc fetch.c -o fetch -O2 -Wall -lcurl> to compile in linux
    <./fetch> to excute in linux
    */
    //api key DR3N4RXUKVG775A3MNTWNEQE8
    CURL* curl;
    CURLcode response; 
    curl = curl_easy_init();

    if (curl == NULL) {
        printf("curl handler failed");
        return -1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, "https://weather.visualcrossing.com/VisualCrossingWebServices/rest/services/timeline/London%2CUK?unitGroup=us&key=DR3N4RXUKVG775A3MNTWNEQE8");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    response = curl_easy_perform(curl);
    if (response != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform returned\n%s\n", curl_easy_strerr(response));
        return -1;
    }

    curl_easy_cleanup(curl);
    return 0;
}