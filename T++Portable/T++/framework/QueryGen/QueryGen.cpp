//
// Created by justi on 21.08.2021.
//

#include "QueryGen.h"
#include <curl/curl.h>

std::string QueryGen(std::string Token, std::string RequestType) {

    // holds the URL query
    std::string URLString;

    // create the URL Query
    URLString.append("https://api.telegram.org/bot");
    URLString.append(Token);
    URLString.append("/");
    URLString.append(RequestType);

    return URLString;
}

std::string Encode(std::string Text) {

    //setup the CURL handle
    CURL *curl;
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    //convert the C++ string to a C char string
    char *CText = &Text[0];

    //convert the Text to a valid Encoded Query text
    char* encoded = curl_easy_escape(curl, CText, 0);

    //assign the C char to a C++ string
    std::string EncodedText = encoded;

    //free the handle
    curl_free(encoded);
    curl_easy_cleanup(curl);

    return EncodedText;
}