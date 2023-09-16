#include "interface.h"
#include "editor.h"
#include "startnew.h"
#include "import.h"
#include "export.h"
#include "creategraph.h"
#include "deletegraph.h"

bool Interface::RunInterface(int command,
                             StartNew newDoc,
                             Import impDoc,
                             Export expDoc,
                             CreateGraph newEl,
                             DeleteGraph delEl)
{
    bool result = false;
    switch(command)
    {
        case 1:
            newDoc.StartNewDocument();
            result = true;
            break;
        case 2:
            impDoc.ImportDocument();
            result = true;
            break;
        case 3:
            expDoc.ExportDocument();
            result = true;
            break;
        case 4:
            newEl.CreateGraphElement();
            result = true;
            break;
        case 5:
            delEl.DeleteGraphElement();
            result = true;
            break;
        case 6:
            std::cout << "exit" << std::endl;
            result = false;
            break;
        default:
            std::cout << "unused command" << std::endl;
            result = false;
            break;
    }
    return result;
}

void Interface::StartInterface()
{
    std::cout << "What do you want?" << std::endl;
    std::cout << "- S: start new document" << std::endl;
    std::cout << "- I: import document" << std::endl;
    std::cout << "- E: export document" << std::endl;
    std::cout << "- C: create new graph element" << std::endl;
    std::cout << "- D: delete graph element" << std::endl;
    std::cout << "- N: exit" << std::endl;
}

int Interface::ReadCommand()
{    
    std::string command;
    std::cin >> command;
    if(command == "S") return 1;
    else if(command == "I") return 2;
    else if(command == "E") return 3;
    else if(command == "C") return 4;
    else if(command == "D") return 5;
    else if(command == "N") return 6;
    else return 0;
}
