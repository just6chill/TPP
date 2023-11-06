#ifndef __MESSAGE_METHODS__
#define __MESSAGE_METHODS__

#ifdef _WIN32

#pragma once
#include "Framework_Export.h"
#include <string>

class FRAMEWORK_EXPORT Message {

public:
    // determine which type of message we want
    enum Types {Text, Picture, Voice, Video, Sticker};

    // Options for actions to do
    int SendText(int Type, std::string Token, std::string Text);
    int TextReply(int Type, std::string Token, std::string Text);
    int CopyText(std::string Token);
    int SendFile(std::string Token, std::string FilePath);

    // subclass for the values of
    // a incoming event
    class MessageData {
    public:
        /******************************
         * objects that belong to the *
         * actual message related to  *
         * the recent Event           *
         ******************************/
        long long int ChatID;
        int UserID;
        int MessageID;
        int Date;
        std::string UserName;
        std::string UserFirstName;
        std::string UserLastName;
        std::string ChatName;
        std::string Text;

        /********************************
         * Message objects which belong *
         * to the message we replied to *
         * IF we replied to             *
         ********************************/
        bool IsReply;
        int ReplyChatID;
        int ReplyUserID;
        int ReplyMessageID;
        int ReplyDate;
        std::string ReplyUserName;
        std::string ReplyUserFirstName;
        std::string ReplyUserLastName;
        std::string ReplyChatName;
        std::string ReplyText;
    };

    // create a new object to make data values
    // available from the Message class
    MessageData Data;
};

#elif __linux__

#include <string>

class Message {

public:
    // determine which type of message we want
    enum Types {Text, Picture, Voice, Video, Sticker};

    // Options for actions to do
    int SendText(int Type, std::string Token, std::string Text);
    int TextReply(int Type, std::string Token, std::string Text);
    int CopyText(std::string Token);
    int SendFile(std::string Token, std::string FilePath);

    // subclass for the values of
    // a incoming event
    class MessageData {
    public:
        /******************************
         * objects that belong to the *
         * actual message related to  *
         * the recent Event           *
         ******************************/
        long long int ChatID;
        int UserID;
        int MessageID;
        int Date;
        std::string UserName;
        std::string UserFirstName;
        std::string UserLastName;
        std::string ChatName;
        std::string Text;

        /********************************
         * Message objects which belong *
         * to the message we replied to *
         * IF we replied to             *
         ********************************/
        bool IsReply;
        int ReplyChatID;
        int ReplyUserID;
        int ReplyMessageID;
        int ReplyDate;
        std::string ReplyUserName;
        std::string ReplyUserFirstName;
        std::string ReplyUserLastName;
        std::string ReplyChatName;
        std::string ReplyText;
    };

    // create a new object to make data values
    // available from the Message class
    MessageData Data;
};

#endif

#endif
