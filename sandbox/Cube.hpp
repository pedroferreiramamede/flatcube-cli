#ifndef CUBE_H
#define CUBE_H

#include "Face.hpp"

class Cube
{
public:
    Cube();
    int InitializeCube();
    Face faceBranca;
    Face faceAzul;
    Face faceVerde;
    Face faceVermelha;
    Face faceLaranja;
    Face faceAmarela;
};

#endif
