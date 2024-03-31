#include "jogo.hpp"

int main()
{
    Jogo *jogo = new Jogo();

    jogo->iniciarJogo();
    
    delete jogo;
    
    return 0;
}