#pragma once
#include <iostream>
#include "startnew.h"
#include "import.h"
#include "export.h"
#include "creategraph.h"
#include "deletegraph.h"
#include "document.h"

class Interface
{
public:
    bool RunInterface(int command,
                      StartNew newDoc,
                      Import impDoc,
                      Export expDoc,
                      CreateGraph newEl,
                      DeleteGraph delEl);
    int ReadCommand();
    void StartInterface();
private:
    Document* doc;
};
