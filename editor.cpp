#include "editor.h"
#include "startnew.h"
#include "import.h"
#include "export.h"
#include "creategraph.h"
#include "deletegraph.h"
#include "interface.h"

void Editor::run()
{
    std::cout << "Start Editor::run" << std::endl;
    StartNew newDoc;
    Import impDoc;
    Export expDoc;
    CreateGraph newEl;
    DeleteGraph delEl;
    Interface inter;

    bool result = true;
    inter.StartInterface();
    while (result)
    {
        int command = inter.ReadCommand();
        result = inter.RunInterface(command, newDoc, impDoc, expDoc, newEl, delEl);
    }
    
}
