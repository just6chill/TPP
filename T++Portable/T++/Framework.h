#ifdef _WIN32
#include "Framework_Export.h"
// dummy to make sure .lib will be created
int FRAMEWORK_EXPORT dummy();

#elif __linux__
// dummy to make sure .lib will be created
int dummy();
#endif

#include "framework/BotMethods.h"
#include "framework/MessageMethods.h"






