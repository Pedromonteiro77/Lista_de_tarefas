#include <iostream>
#include <cctype>
#include "..\header\screen_clear.h"
#include "..\header\to_do_list.h"

// Construtor da classe Menu.
Menu::Menu() : option_(0) {}

// Função que Mostra o Menu para o usuario escolher uma opção.
unsigned int Menu::fnMenu()
{   
    std::string strOption;

    while(true)
    {
        try
        {
            std::cout << "===== Options Menu =====" << '\n';
            std::cout << "1 - Add task to list" << '\n';
            std::cout << "2 - Show To-do list" << '\n';
            std::cout << "3 - Delete a Task" << '\n';
            std::cout << "4 - Exit" << '\n';
  
            std::cout << "Choose an option: ";
            std::cin >> strOption;
            std::cin.ignore();

            if(!(strOption == "1" || strOption == "2" || strOption == "3" || strOption == "4"))
            {
                throw std::invalid_argument("INVALID! Please choose one of the options.");
            }

            break;
        }
        
        catch(const std::invalid_argument & e)
        {
            std::cerr << e.what() << '\n';
            std::cout << "Press Enter to continue...";
            std::cin.get();
            ScreenClear::clear();
            continue;
        }
    }

    option_ = std::stoi(strOption);

    return option_;
}