cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

project(T++ C CXX)
INCLUDE_DIRECTORIES("${CMAKE_CURRENT_BINARY_DIR}")
add_executable(Bot ../main.cpp ../T++/Framework.cpp ../T++/Framework.h ../T++/framework/HttpClient/GetRequests/Get.cpp ../T++/framework/HttpClient/GetRequests/Get.h ../T++/framework/EventHandler/Events.cpp ../T++/framework/Bot/ResponseHandler.cpp ../T++/framework/BotMethods.h ../T++/framework/MessageMethods.h ../T++/framework/Bot/Methods/SendMessage.cpp ../T++/framework/QueryGen/QueryGen.cpp ../T++/framework/QueryGen/QueryGen.h ../T++/framework/Bot/Methods/ReplyMessage.cpp ../T++/framework/Bot/Methods/CopyMessage.cpp ../T++/framework/Bot/Methods/SendFile.cpp ../T++/framework/Assets/jsoncpp.cpp ../T++/framework/Assets/json/json-forwards.h ../T++/framework/Assets/json/json.h)

set_target_properties(Bot PROPERTIES LINKER_LANGUAGE CXX)

find_package(CURL CONFIG REQUIRED)
target_link_libraries(Bot PRIVATE CURL::libcurl)