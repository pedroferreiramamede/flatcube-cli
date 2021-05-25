#include <iostream>
#include "Cube.hpp"

Cube::Cube()
{
   // std::cout << "calling constructor" << std::endl;
}

int Cube::InitializeCube(){
    //Initialize all faces
    this->faceBranca.setColor(BRANCO);
    this->faceAzul.setColor(AZUL);
    this->faceVerde.setColor(VERDE);
    this->faceVermelha.setColor(VERMELHO);
    this->faceLaranja.setColor(LARANJA);
    this->faceAmarela.setColor(AMARELO);
}
