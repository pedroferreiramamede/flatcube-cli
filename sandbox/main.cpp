#include <iostream>
#include "Face.hpp"

int main(int argc, char **argv)
{
    Face faceBranca(BRANCO, BRANCO, BRANCO, BRANCO, BRANCO, BRANCO, BRANCO, BRANCO, BRANCO);

    faceBranca.setColor(0, AMARELO);
    faceBranca.setColor(2, VERMELHO);
    faceBranca.setColor(AZUL, AZUL, AZUL, AZUL, AZUL, AZUL, AZUL, AZUL, AZUL);

    std::cout << faceBranca.getColor(0) << " " << faceBranca.getColor(1) << " " << faceBranca.getColor(2) << std::endl;   
    std::cout << faceBranca.getColor(3) << " " << faceBranca.getColor(4) << " " << faceBranca.getColor(5) << std::endl;
    std::cout << faceBranca.getColor(6) << " " << faceBranca.getColor(7) << " " << faceBranca.getColor(8) << std::endl;
}

