#include <iostream>
#include "..\header\lista_de_tarefas.hpp"

// Construtor da Class Menu
Menu::Menu() : option(0) {}

// Função que mostra o menu e permite o usuario escolher uma opção
void Menu::menuOptions() {
    std::cout << "=== Lista de Tarefas ===" << '\n';
    std::cout << "1 - Adicionar tarefa" << '\n';
    std::cout << "2 - Excluir tarefa" << '\n';
    std::cout << "3 - Mostrar lista de tarefas" << '\n';
    std::cout << "4 - Sair" << '\n';

    std::cout << "Escolha uma das opcoes: ";
    std::cin >> option;
    std::cin.ignore();
    std::system("cls");
}