#include <cstdlib>
#include "..\header\screen_clear.h"

// Função static que Limpa a tela dependendo do sistema
void ScreenClear::clear()
{
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}