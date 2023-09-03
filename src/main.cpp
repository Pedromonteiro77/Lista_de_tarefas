#include <iostream>
#include "..\headers\funcs.h"
#include <string>
#include <vector>

int main() {
    std::vector<std::string> task;
    std::string text;
    char opc;
    int indice;
    
    addTask(task, text, opc);
    removeTask(task, text, opc, indice);

    std::cout << "===== Lista de Tarefas =====" << std::endl;

    for(auto i = 0; i < task.size(); i++) {
        std::cout << (i + 1) << " - " << task[i] << std::endl;
    }

    return 0;
}