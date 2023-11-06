#ifndef __BOT_METHODS__
#define __BOT_METHODS__

#ifdef _WIN32

#include "Framework_Export.h"
#include "MessageMethods.h"
#include <string>

class FRAMEWORK_EXPORT Bot {

        public:

        // string for saving the bot token
        std::string Token;

        // determine which type of message we want
        enum {Text, Picture, Voice, Video, Sticker};

        // loop for the bot code
        template<typename Func>
        [[noreturn]] void Online (Message& object, const Func& f) {
            while(true) {
                if (Online()) {
                    if (NewEvent()) {
                        MessageHandle(object);
                        f();
                    }
                } else {
                    // do nothing if bot is offline
                }
            }
        }

        // options
        bool Send (int id, int type, std::string value);


        private:

        // checks if there is a new event
        bool NewEvent();
        // check if bot is online
        bool Online();
        // hold Responses
        std::string ResponseToken;
        // handle Response to extract message
        // values
        void MessageHandle(Message& object);
};

#elif __linux__

#include "MessageMethods.h"
#include <string>

class Bot {

        public:

        // string for saving the bot token
        std::string Token;

        // determine which type of message we want
        enum {Text, Picture, Voice, Video, Sticker};

        // loop for the bot code
        template<typename Func>
        [[noreturn]] void Online (Message& object, const Func& f) {
            while(true) {
                if (Online()) {
                    if (NewEvent()) {
                        MessageHandle(object);
                        f();
                    }
                } else {
                    // do nothing if bot is offline
                }
            }
        }

        // options
        bool Send (int id, int type, std::string value);


        private:

        // checks if there is a new event
        bool NewEvent();
        // check if bot is online
        bool Online();
        // hold Responses
        std::string ResponseToken;
        // handle Response to extract message
        // values
        void MessageHandle(Message& object);
};

#endif

#endif
