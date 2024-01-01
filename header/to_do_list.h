#pragma once

#include <string>
#include <vector>

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
    std::vector<std::string> list_;
    std::string text_;

public:
    To_DoList();
    ~To_DoList() = default;

    void showList();
    void addTaskToList();
    void deleteTask();

    const std::vector<std::string> getList() const;
};