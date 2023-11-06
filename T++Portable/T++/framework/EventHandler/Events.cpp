#include "../BotMethods.h"
#include "../HttpClient/GetRequests/Get.h"
#include "../Assets/json/json.h"

// get the newest Updates and in case
// the response holds an valid event
// return true
bool Bot::NewEvent() {

    auto Response = Get(Token, Update);

    // if the Response is longer than 30 char there
    // is definitely a new event pending
    if (Response.length() > 30) {
        ResponseToken = Response;
        return true;
    } else {
        return false;
    }
}

bool Bot::Online() {
    // get status
    auto Response = Get(Token, Me);

    // if bot is online ok should be true
    Json::Value root;
    Json::Reader reader;
    reader.parse(Response, root);
    std::string IsOk = root["ok"].asString();

    if (IsOk == "true") {
        return true;
    } else {
        return false;
    }

}

