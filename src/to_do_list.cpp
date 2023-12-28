#include <iostream>
#include "..\header\screen_clear.h"
#include "..\header\to_do_list.h"

// Constructor da classe To_DoList inicializando as variaveis.
To_DoList::To_DoList() : list_({}), text_("") {}

// Função que mostra a Lista de tarefas e mostra um aviso caso ela esteja vazia.
std::list<std::string> To_DoList::showList()
{
    if(list_.empty())
    {
        std::cout << "Empty List!" << '\n';
        std::cout << "Press Enter to continue...";
        std::cin.get();
        ScreenClear::clear();
    }

    unsigned int i = 0;
    std::cout << "=== To-do List ===" << '\n';
    for(auto it = list_.begin(); it != list_.end(); it++)
    {
        std::cout << ++i << " - " << *it << '\n';      
    }

    return list_;
}

// Função que adiciona uma tarefa a lista 
void To_DoList::addTaskToList()
{
    std::string yesOrNot;

    while(true)
    {
        try
        {   
            if(!list_.empty())
            {
                showList();
                std::cout << '\n';
            }

            std::cout << "Type the task: ";
            std::getline(std::cin, text_);

            if(text_.empty())
            {
                throw std::invalid_argument("INVALID! Don't leave the field empty.");
            }

            while(true)
            {
                std::cout << "The Task is: " << text_ << '\n';
                std::cout << '\n';
                std::cout << "Are you sure? (Y/N): ";
                std::cin >> yesOrNot;
                std::cin.ignore();

                if(!(yesOrNot == "y" || yesOrNot == "Y" || yesOrNot == "n" || yesOrNot == "N"))
                {
                    std::cout << "Please type Y or N" << '\n';
                    std::cout << "Press Enter to continue...";
                    std::cin.get();
                    ScreenClear::clear();
                    continue;
                }

                break;
            }

            if(yesOrNot == "n" || yesOrNot == "N")
            {
                text_.clear();
                ScreenClear::clear();
                continue;
            }

            list_.push_back(text_);

            ScreenClear::clear();
            
            while(true)
            {
                showList();
                std::cout << '\n';

                std::cout << "Do you want to add another task? (Y/N): ";
                std::cin >> yesOrNot;
                std::cin.ignore();
                
                if(!(yesOrNot == "y" || yesOrNot == "Y" || yesOrNot == "n" || yesOrNot == "N"))
                {
                    std::cout << "Please type Y or N" << '\n';
                    std::cout << "Press Enter to continue...";
                    std::cin.get();
                    ScreenClear::clear();
                    continue;
                }

                break;
            }

            if(yesOrNot == "y" || yesOrNot == "Y")
            {
                text_.clear();
                ScreenClear::clear();
                continue;
            }

            ScreenClear::clear();

            break;
        }

        catch(const std::invalid_argument & e)
        {
            std::cerr << e.what() << '\n';
            std::cout << "Press Enter to continue...";
            std::cin.get();
            text_.clear();
            ScreenClear::clear();
            continue;
        }
    }
}

// Função que deleta uma tarefa da lista.
void To_DoList::deleteTask()
{
    while(true)
    {
        showList();
    }
}