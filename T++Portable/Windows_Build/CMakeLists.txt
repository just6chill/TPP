cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 17)
include(GenerateExportHeader)
include(ExternalProject)

project(T++ C CXX)
INCLUDE_DIRECTORIES("${CMAKE_CURRENT_BINARY_DIR}")

add_library(Framework SHARED ../T++/Framework.cpp ../T++/Framework.h Framework_Export.h ../T++/framework/HttpClient/GetRequests/Get.cpp ../T++/framework/HttpClient/GetRequests/Get.h ../T++/framework/EventHandler/Events.cpp ../T++/framework/Bot/ResponseHandler.cpp ../T++/framework/BotMethods.h ../T++/framework/MessageMethods.h ../T++/framework/Bot/Methods/SendMessage.cpp ../T++/framework/QueryGen/QueryGen.cpp ../T++/framework/QueryGen/QueryGen.h ../T++/framework/Bot/Methods/ReplyMessage.cpp ../T++/framework/Bot/Methods/CopyMessage.cpp ../T++/framework/Bot/Methods/SendFile.cpp ../T++/framework/Assets/jsoncpp.cpp ../T++/framework/Assets/json/json-forwards.h ../T++/framework/Assets/json/json.h)

set_target_properties(Framework PROPERTIES LINKER_LANGUAGE CXX)
generate_export_header(Framework
        BASE_NAME Framework
        EXPORT_MACRO_NAME FRAMEWORK_EXPORT
        EXPORT_FILE_NAME Framework_Export.h
        STATIC_DEFINE SHARED_EXPORTS_BUILD_AS_STATIC)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG 3b15fa82ea74739b574d705fea44959b58142eb8) # The commit hash for 1.10.x. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

target_link_libraries(Framework PRIVATE cpr::cpr)

add_executable(Bot ../main.cpp)
target_link_libraries(Bot Framework)