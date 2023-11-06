#include <string>

#ifndef T_GET_H
#define T_GET_H

// enum to choose the action needed
enum Action {Me, Update};

std::string Get(std::string Token, int Action);

#endif //T_GET_H
