#include <iostream>
#include "Face.hpp"

Face::Face(Colors faceColor0, Colors faceColor1, Colors faceColor2,
           Colors faceColor3, Colors faceColor4, Colors faceColor5,
           Colors faceColor6, Colors faceColor7, Colors faceColor8)
{
    faceColors[0] = faceColor0;
    faceColors[1] = faceColor1;
    faceColors[2] = faceColor2;
    faceColors[3] = faceColor3;
    faceColors[4] = faceColor4;
    faceColors[5] = faceColor5;
    faceColors[6] = faceColor6;
    faceColors[7] = faceColor7;
    faceColors[8] = faceColor8;
}

Colors Face::getColor(int pieceNumber){
    return faceColors[pieceNumber];
}

int Face::setColor(int pieceNumber, Colors color){
    faceColors[pieceNumber] = color;
}

int Face::setColor(Colors faceColor0, Colors faceColor1, Colors faceColor2,
                   Colors faceColor3, Colors faceColor4, Colors faceColor5,
                   Colors faceColor6, Colors faceColor7, Colors faceColor8)
{
    faceColors[0] = faceColor0;
    faceColors[1] = faceColor1;
    faceColors[2] = faceColor2;
    faceColors[3] = faceColor3;
    faceColors[4] = faceColor4;
    faceColors[5] = faceColor5;
    faceColors[6] = faceColor6;
    faceColors[7] = faceColor7;
    faceColors[8] = faceColor8;
}

/*
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
*/
