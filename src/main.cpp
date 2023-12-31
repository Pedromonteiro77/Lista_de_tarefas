#include <iostream>
#include "..\header\screen_clear.h"
#include "..\header\to_do_list.h"

int main()
{
    Menu objMenu;
    To_DoList objList;

    while(true)
    {
        ScreenClear::clear();
        
        int menuChoose = objMenu.fnMenu();

        if(menuChoose == 1)
        {
            ScreenClear::clear();
            objList.addTaskToList();
        }

        if(menuChoose == 2)
        {
            ScreenClear::clear();
            
            objList.showList();

            if(!objList.getList().empty())
            {
                std::cout << "Press Enter to continue...";
                std::cin.get();
            }
        }

        if(menuChoose == 3)
        {
            ScreenClear::clear();
            objList.deleteTask();
        }

        if(menuChoose == 4)
        {
            break;
        }
    }

    return 0;
}