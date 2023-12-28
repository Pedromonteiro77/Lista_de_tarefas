#include <iostream>
#include "..\header\screen_clear.h"
#include "..\header\to_do_list.h"

int main()
{
    Menu objMenu;
    To_DoList objList;

    ScreenClear::clear();
    
    while(true)
    {
        int menuChoose = objMenu.fnMenu();

        if(menuChoose == 1)
        {
            ScreenClear::clear();
            objList.addTaskToList();
        }

        if(menuChoose == 2)
        {
            ScreenClear::clear();
            std::list<std::string> isTheListEmpty = objList.showList();
            std::cout << '\n';
            
            if(!isTheListEmpty.empty())
            {
                std::cout << "Press Enter to continue...";
                std::cin.get();
                ScreenClear::clear();
            }
        }

        if(menuChoose == 3)
        {

        }

        if(menuChoose == 4)
        {
            break;
        }
    }

    return 0;
}