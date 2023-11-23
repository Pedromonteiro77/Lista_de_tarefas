#include <iostream>
#include "..\header\lista_de_tarefas.hpp"

// Construtor da Class ListaDeTarefas apenas inicializando as variaveis
ListaDeTarefas::ListaDeTarefas() : task_(" "), tasksList_({ }), yesOrNot('S') {}

// Função que permite o usuario digitar uma tarefa e adiciona a lista de tarefas
void ListaDeTarefas::writeTask() {
    while(true) {
        try {
            std::cout << "Digite a tarefa que deseja adicionar: ";
            std::getline(std::cin, task_);

            if(task_.empty()) {
                throw std::invalid_argument("Nao deixe o campo vazio!");
            }

            tasksList_.push_back(task_);

            for(auto i = 0; i < tasksList_.size(); ++i) {
                std::cout << i+1 << " - " << tasksList_[i] << '\n';
            }

            std::cout << '\n';

            std::cout << "Deseja adicionar outra tarefa? (S/N): ";
            std::cin >> yesOrNot;
            std::cin.ignore();
            
            if(yesOrNot == 'n' || yesOrNot == 'N') {
                break;
            } 

            else {
                task_.clear();
                std::system("cls");
                continue;
            }
        }

        catch(const std::invalid_argument & e) {
            std::cerr << e.what() << '\n';
            std::cout << "Aperte Enter para continuar...";
            std::cin.get();
            task_.clear();
            std::system("cls");
            continue;
        }
    }  
}

// Função que mostra a lista de tarefas
void ListaDeTarefas::showListOfTasks() {
    for(auto i = 0; i < tasksList_.size(); ++i) {
        std::cout << i+1 << " - " << tasksList_[i] << '\n'; 
    }
}

// Função que permite Deletar uma tarefa
void ListaDeTarefas::deleteTask() {
    unsigned int index;

    while(true) {
        if(tasksList_.empty()) {
            std::cout << "Lista vazia!" << '\n';
            std::cout << "Aperte Enter para continuar...";
            std::cin.get();
            break;
        }

        showListOfTasks();

        std::cout << "Digite o indice da tarefa que deseja excluir: ";
        std::cin >> index;

        if(index < 1 && index < tasksList_.size()) {
            std::cout << "Invalido!" << '\n';
            std::cout << "Aperte Enter para continuar...";
            std::cin.get();
            std::system("cls");
            continue;
        }

        tasksList_.erase(std::remove(tasksList_.begin(), 
        tasksList_.end(), 
        tasksList_[index-1]), tasksList_.end());

        std::system("cls");

        showListOfTasks();

        std::cout << "Deseja excluir outra tarefa? (S/N): ";
        std::cin >> yesOrNot;

        if(yesOrNot == 'N' || yesOrNot == 'n') {
            break;
        }

        else {
            std::system("cls");
            continue;
        }
    }
}

// Função principal que mostra a estrutura da lista mostrando o menu de opcoes e executando as funções de acordo com as escolhas do usuario
void ListaDeTarefas::listWorking() {
    while(true) {
        menuOptions();
    
        if(option == 1) {
            writeTask();
            std::system("cls");
        }  

        if(option == 2) {
            deleteTask();
            std::system("cls");
        }
        
        if(option == 3) {
            std::cout << "=== Lista de Tarefas ===" << '\n';
            showListOfTasks();
            std::cout << "Aperte Enter para continuar...";
            std::cin.get();
            std::system("cls");
        }

        if(option == 4) {
            break;
        }
    }
}