#pragma once

#include "Modules/Base/Module.h"
#include <unordered_map>

class Console{

    static std::unordered_map<char, Module*> modules;
    static Module* mainModule;
    static Module* currentModule;

    static void clear();
    static void showModuleName();
    static void showModuleContent();
    static void showModuleNavigation();
    static void showError(const char* error);

    public:
    static void init();
    static void reset();
    static void show();
    static void show(const char* error);
    static void receiveKey(char&& key);

};