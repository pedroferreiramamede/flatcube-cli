#include <iostream>
#include <stdio.h>
#include "Face.hpp"
#include "Cube.hpp"

//#define DEBUG_FACE

int main(int argc, char **argv)
{
    Cube cubo; 
    cubo.InitializeCube();
    //Initialize all faces
/*    cubo.faceBranca.setColor(BRANCO);
    cubo.faceAzul.setColor(AZUL);
    cubo.faceVerde.setColor(VERDE);
    cubo.faceVermelha.setColor(VERMELHO);
    cubo.faceLaranja.setColor(LARANJA);
    cubo.faceAmarela.setColor(AMARELO);
*/
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
    
    cubo.rotateFace(BRANCO, 'l');
    cubo.rotateFace(VERDE, 'r');
    //cubo.faceBranca.rotateFace('r');
    //faceBranca.rotateFace('l');
    //faceBranca.rotateFace('l');
    //faceBranca.rotateFace('l');
    
    /* First, clear the screen */
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);

    int faceNumber = 0;
    while(1)
    {
        std::cout << std::endl;
        std::cout << "  _/  _/    _/  _/    _/  _/    _/  _/    _/  _/    _/  _/   _/  _/   _/  _/  " << std::endl;
        std::cout << "     _/  _/    _/  _/    _/  _/    _/  _/    _/  _/    _/  _/   _/  _/   _/  _/" << std::endl;
        std::cout << "  _/  _/    _/  _/    _/  _/    _/  _/    _/  _/    _/  _/   _/  _/   _/  _/  " << std::endl;;
        std::cout << "            __ _       _                _                         _ _         " << std::endl;
        std::cout << " |         / _| | __ _| |_    ___ _   _| |__   ___            ___| (_)        |" << std::endl;
        std::cout << " |        | |_| |/ _` | __|  / __| | | | '_ \\ / _ \\  _____   / __| | |        |" << std::endl;
        std::cout << " |        |  _| | (_| | |_  | (__| |_| | |_) |  __/ |_____| | (__| | |        |" << std::endl;
        std::cout << " |        |_| |_|\\__,_|___|  \\___|\\__,_|_.__/ \\___|          \\___|_|_|        |" << std::endl << std::endl; 
        std::cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- " << std::endl;
        std::cout << " -- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;
        //std::cout << "   _/  _/    _/  _/    _/  _/    _/  _/    _/  _/    _/  _/   _/  _/   _/  _/" << std::endl;  
        //std::cout << "_/  _/    _/  _/    _/  _/    _/  _/    _/  _/    _/  _/   _/  _/   _/  _/  " << std::endl;
        std::cout << std::endl << std::endl;

        switch(faceNumber)
        {
          case 0:
             cubo.faceBranca.printFace();
             break;
          case 1:
             cubo.faceAzul.printFace();
             break;
          case 2:
             cubo.faceVerde.printFace();
             break;
          case 3:
             cubo.faceVermelha.printFace();
             break;
          case 4:
             cubo.faceLaranja.printFace();
             break;
          case 5:
             cubo.faceAmarela.printFace();
             break;
        }        

        std::cout << "Escolha a face que deseja ver(0-5): " << std::endl;
        std::cin >> faceNumber;
        //std::cout.flush(); 
        printf("\033[2J");
        printf("\033[%d;%dH", 0, 0);
        std::cout<<std::endl; 
    }
}

