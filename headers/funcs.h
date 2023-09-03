#ifndef FUNCS_H
#define FUNCS_H

#include <string>
#include <vector>

void addTask(std::vector<std::string> & task, std::string & text, char & opc);

void removeTask(std::vector<std::string> & task, std::string & text, char & opc, int & indice);

#endif