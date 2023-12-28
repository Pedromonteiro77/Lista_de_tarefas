#pragma once

#include <list>
#include <string>

class Menu
{
private:
    unsigned int option_;
    
public:
    Menu();
    ~Menu() = default;

    unsigned int fnMenu();
};

class To_DoList
{
private:
    std::list<std::string> list_;
    std::string text_;

public:
    To_DoList();
    ~To_DoList() = default;

    std::list<std::string> showList();
    void addTaskToList();
    void deleteTask();
};