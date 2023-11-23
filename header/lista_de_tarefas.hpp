#ifndef LISTA_DE_TAREFAS
#define LISTA_DE_TAREFAS

#include <string>
#include <vector>
#include <algorithm>

class Menu {
protected:
    unsigned int option;

    void menuOptions();

public:
    Menu();
};

class ListaDeTarefas : public Menu {
private:
    std::string task_;
    std::vector<std::string> tasksList_;
    char yesOrNot;

    void writeTask();
    void showListOfTasks();
    void deleteTask();

public:
    ListaDeTarefas();
    void listWorking();
};

#endif