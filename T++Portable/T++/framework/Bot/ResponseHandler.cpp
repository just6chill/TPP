#include "../BotMethods.h"
#include "../Assets/json/json.h"
#include <string>
#include <iostream>

void Bot::MessageHandle(Message &object) {

    std::string Response = ResponseToken;
     std::cout << Response << std::endl;
    Json::Value root;
    Json::Reader reader;
    reader.parse(Response, root);
    auto JsonArray = root["result"];
    auto FirstElement = JsonArray[0];

    object.Data.ChatID = FirstElement["message"]["chat"]["id"].asLargestInt();
    object.Data.UserName = FirstElement["message"]["from"]["username"].asString();
    object.Data.MessageID = FirstElement["message"]["message_id"].asInt64();
    object.Data.Date = FirstElement["message"]["date"].asInt64();
    object.Data.Text = FirstElement["message"]["text"].asString();
    object.Data.UserID = FirstElement["message"]["from"]["id"].asInt64();
    object.Data.UserFirstName = FirstElement["message"]["from"]["first_name"].asString();
    object.Data.UserLastName = FirstElement["message"]["from"]["last_name"].asString();
    object.Data.ChatName = FirstElement["message"]["chat"]["title"].asString();

    object.Data.ReplyChatID = FirstElement["message"]["reply_to_message"]["chat"]["id"].asInt64();
    object.Data.ReplyChatName = FirstElement["message"]["reply_to_message"]["chat"]["title"].asString();
    object.Data.ReplyDate = FirstElement["message"]["reply_to_message"]["date"].asInt64();
    object.Data.ReplyMessageID = FirstElement["message"]["reply_to_message"]["message_id"].asInt64();
    object.Data.ReplyText = FirstElement["message"]["reply_to_message"]["text"].asString();
    object.Data.ReplyUserFirstName = FirstElement["message"]["reply_to_message"]["from"]["first_name"].asString();
    object.Data.ReplyUserLastName = FirstElement["message"]["reply_to_message"]["from"]["last_name"].asString();
    object.Data.ReplyChatID = FirstElement["message"]["reply_to_message"]["chat"]["id"].asInt64();
    object.Data.ReplyUserID = FirstElement["message"]["reply_to_message"]["from"]["id"].asInt64();

}