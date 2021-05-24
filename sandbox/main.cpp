#include <iostream>
#include "Face.hpp"
#include "Cube.hpp"

#define DEBUG_FACE

int main(int argc, char **argv)
{
    Cube cubo;
    //Initialize all faces
    cubo.faceBranca.setColor(BRANCO);
    cubo.faceAzul.setColor(AZUL);
    cubo.faceVerde.setColor(VERDE);
    cubo.faceVermelha.setColor(VERMELHO);
    cubo.faceLaranja.setColor(LARANJA);
    cubo.faceAmarela.setColor(AMARELO);

#ifdef DEBUG_FACE
    cubo.faceBranca.setColor(BRANCO);
    cubo.faceBranca.setColor(2,AZUL);
    cubo.faceBranca.setColor(3,AMARELO);
    cubo.faceBranca.setColor(4,VERDE);
    cubo.faceBranca.setColor(5,VERMELHO);
    cubo.faceBranca.setColor(6,LARANJA);
    cubo.faceBranca.setColor(0, VERMELHO);
    cubo.faceBranca.printFace();
#endif

    //std::cout << "\033[0;33;42m" << cubo.faceBranca.getColor(0) << "\033[0m" << " " << cubo.faceBranca.getColor(1) << " " << cubo.faceBranca.getColor(2) << std::endl;   
    //std::cout << color::rize( cubo.faceBranca.getColor(0), "Yellow", "Green" )  << " " << cubo.faceBranca.getColor(1) << " " << cubo.faceBranca.getColor(2) << std::endl;   
    //std::cout << cubo.faceBranca.getColor(3) << " " << cubo.faceBranca.getColor(4) << " " << cubo.faceBranca.getColor(5) << std::endl;
    //std::cout << cubo.faceBranca.getColor(6) << " " << cubo.faceBranca.getColor(7) << " " << cubo.faceBranca.getColor(8) << std::endl;

    //cubo.faceBranca.rotateFace('r');
    //faceBranca.rotateFace('l');
    //faceBranca.rotateFace('l');
    //faceBranca.rotateFace('l');

    //std::cout << std::endl;
    //std::cout << cubo.faceBranca.getColor(0) << " " << cubo.faceBranca.getColor(1) << " " << cubo.faceBranca.getColor(2) << std::endl;
    //std::cout << cubo.faceBranca.getColor(3) << " " << cubo.faceBranca.getColor(4) << " " << cubo.faceBranca.getColor(5) << std::endl;
    //std::cout << cubo.faceBranca.getColor(6) << " " << cubo.faceBranca.getColor(7) << " " << cubo.faceBranca.getColor(8) << std::endl;

}

