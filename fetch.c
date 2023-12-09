# include <stdio.h>
# include <curl/curl.h>

int main () {
    CURL* curl;
    CURLcode response;
    // api key DR3N4RXUKVG775A3MNTWNEQE8

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://weather.visualcrossing.com/VisualCrossingWebServices/rest/services/timeline/London%2CUK/2022-07-15/2022-07-20?unitGroup=metric&key=DR3N4RXUKVG775A3MNTWNEQE8" );
        response = curl_easy_perform(curl);
        if (response != CURLE_OK) {
            printf(stderr, "Request failed %s\n", curl_easy_strerror(response));

        }else {
            printf(response);
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return 0;
}