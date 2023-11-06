#include <curl/curl.h>
#include "../../Assets/json/json.h"
#include "Get.h"

int EventID = 0;
bool PendingEvent;

//buffer for the response we dont want on stdout
size_t ResponseBuffer(void *ptr, size_t size, size_t nmemb, std::string* data) {
    data->append((char*) ptr, size * nmemb);
    return size * nmemb;
}

std::string Get(std::string Token, int Action) {

    // holds the value for the Action to perform
    std::string Request;
    // holds the URL query
    std::string URLString;
    // response strings
    std::string Response;
    std::string Header;

    /***********************************
     * Check the given action and      *
     * create the Request according to *
     * the given action                *
     ***********************************/
    if(Action == 0) {
        Request = "getMe";
    }
    else if(Action == 1) {

        if(PendingEvent) {
            // add offset to delete old events
            Request.append("getUpdates?offset=");
            Request.append(std::to_string(EventID));
        } else {
            Request = "getUpdates";
        }
    }

    // create the URL Query
    URLString.append("https://api.telegram.org/bot");
    URLString.append(Token);
    URLString.append("/");
    URLString.append(Request);

    // convert the Query string to char
    char *URL = &URLString[0];

    // create curl handler
    auto curl = curl_easy_init();

    // set curl options
    curl_easy_setopt(curl, CURLOPT_URL, URL);
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50L);
    curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, ResponseBuffer);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &Response);
    curl_easy_setopt(curl, CURLOPT_HEADERDATA, &Header);

    // execute curl request
    curl_easy_perform(curl);
    // cleanup request handler
    curl_easy_cleanup(curl);
    // reset request handle
    curl = NULL;

    // if action is a getUpdates request
    if(Action == 1) {
        // a response bigger than 30 chars
        // means that there is a new
        // update pending
        if (Response.length() > 30) {
            // get the new event id
            Json::Value root;
            Json::Reader reader;
            reader.parse(Response, root);
            auto JsonArray = root["result"];
            auto FirstElement = JsonArray[0];
            EventID = FirstElement["update_id"].asInt();

            // increment the id to get a new offset
            EventID++;

            // set the pending event flag
            // to make sure the event get deleted
            // once Get is called again
            PendingEvent = true;
        } else {
            // set flag to false to make
            // sure we perform a normal
            // request on the next call
            PendingEvent = false;
        }
    }

    return Response;
}