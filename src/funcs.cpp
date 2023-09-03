#include <iostream>
#include "..\headers\funcs.h"

void addTask(std::vector<std::string> & task, std::string & text, char & opc) {
    while(true) {
        std::cout << "Digite uma tarefa para a lista: ";
        std::getline(std::cin, text);

        if(text.empty()) {
            std::cerr << "Lamento mais não posso adicionar uma tarefa vazia!" << "\n";
            std::cout << "Aperte Enter para continuar...";
            std::cin.get();
            std::system("cls");
            continue;
        }
        else {
            task.push_back(text);
            std::system("cls");
            std::cout << "Tarefa adicionada com sucesso!" << std::endl;

            std::cout << "===== Lista de Tarefas =====" << std::endl;
            for(auto i = 0; i < task.size(); i++) {
                std::cout << (i + 1) << " - " << task[i] << std::endl; 
            }

            std::cout << std::endl;

            std::cout << "Deseja adicionar outra tarefa? (s)/(n): ";
            std::cin >> opc;
            std::cin.ignore();

            if(opc == 's' || opc == 'S') {
                continue;
            }
            else {
                std::system("cls");
                break;
            }
        }
    }

    std::cout << "===== Lista de Tarefas =====" << std::endl;

    for(auto i = 0; i < task.size(); i++) {
        std::cout << (i + 1) << " - " << task[i] << std::endl;
    }

    std::cout << std::endl;
}

void removeTask(std::vector<std::string> & task, std::string & text, char & opc, int & indice) {
    std::cout << "Deseja remover alguma das tarefas? (s)/(n): ";
    std::cin >> opc;
    std::cin.ignore();

    if(opc == 's' || opc == 'S') {
        while(true) {
            std::cout << "Digite o numero da tarefa que deseja remover: ";
            std::cin >> indice;
            std::cin.ignore();

            if(indice >= 1 && indice <= task.size()) {
                task.erase(task.begin() + (indice - 1));
                std::system("cls");
                std::cout << "Tarefa excluida com sucesso!" << std::endl;
            }
            else {
                std::cerr << "Numero INVALIDO! digite o numero de uma tarefa valido." << std::endl;
                std::cout << "Aperte Enter para continuar...";
                std::cin.get();
                continue;
            }              
        
            std::cout << "===== Lista de Tarefas =====" << std::endl;

            for(auto i = 0; i < task.size(); i++) {
                std::cout << (i + 1) << " - " << task[i] << std::endl;
            }

            std::cout << "Deseja Remover mais uma tarefa? (s)/(n): ";
            std::cin >> opc;
            std::cin.ignore();
            
            if(opc == 's' || opc == 'S') {
                continue;
            }
            else {
                std::system("cls");
                break;
            }
        }
    }

    std::system("cls");
}