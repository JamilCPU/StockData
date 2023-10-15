#include <stdio.h>
#include <curl/curl.h>
#include "info.cpp"
#include <string>
int main(){

    std::string apiCall = "https://api-v2.intrinio.com/securities/AAPL/prices?api_key={" + APIKey + "}";
    CURL *curl;
    CURLcode result;

    curl = curl_easy_init();
    if(curl == NULL){
        fprintf(stderr, "HTTP request failed.\n");
        return -1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, apiCall);

    result = curl_easy_perform(curl);

    if(result != CURLE_OK){
        fprintf(stderr, "Error: %s\n", curl_easy_strerror(result));
        return -1;
    }

    curl_easy_cleanup(curl);
    return 0;
}