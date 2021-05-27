#ifndef CUBE_H
#define CUBE_H

#include "Face.hpp"

class Cube
{
public:
    Cube();
    int InitializeCube();
    int rotateFace(Colors, char);
    int rotateFaceToPrint(Colors, char);
 
    Face faceBranca;
    Face faceAzul;
    Face faceVerde;
    Face faceVermelha;
    Face faceLaranja;
    Face faceAmarela;
};

#endif
