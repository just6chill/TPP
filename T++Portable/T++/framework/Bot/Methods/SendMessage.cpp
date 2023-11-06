//
// Created by justi on 04.06.2021.
//

#include "../../MessageMethods.h"
#include "../../QueryGen/QueryGen.h"
#include <curl/curl.h>

int Message::SendText(int Type, std::string Token, std::string Text) {

    //setup the curl stuff
    CURL *Curl;
    CURLcode Result;
    curl_global_init(CURL_GLOBAL_ALL);
    Curl = curl_easy_init();

    //Generate the URl Query, convert The text to Encoded text
    std::string Header;
    std::string QueryURL = QueryGen(Token, "sendMessage");
    std::string EncodedText = Encode(Text);

    //create the full header
    Header.append("chat_id=");
    Header.append(std::to_string(this->Data.ChatID));
    Header.append("&text=");
    Header.append(EncodedText);

    // convert the C++ strings to char
    char *URL = &QueryURL[0];
    char *CharHeader = &Header[0];

    //dew it
    if (Curl) {
        curl_easy_setopt(Curl, CURLOPT_URL, URL);
        curl_easy_setopt(Curl, CURLOPT_POSTFIELDS, CharHeader);
        Result = curl_easy_perform(Curl);
    }
    curl_easy_cleanup(Curl);

    return 0;
}