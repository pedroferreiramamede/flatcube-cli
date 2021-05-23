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

Face::Face(Colors color)
{
    for(int i = 0; i < 10; i++)
        faceColors[i] = color;
}

Face::Face()
{

}

Colors Face::getColor(int pieceNumber){
    return faceColors[pieceNumber];
}

int Face::setColor(int pieceNumber, Colors color){
    faceColors[pieceNumber] = color;
}

int Face::setColor(Colors color)
{   
    for(int i = 0; i < 10; i++)
        faceColors[i] = color;
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

int Face::rotateFace(char orientation)
{
/* Rotate right:        Rotate left:

      0 1 2    6 3 0     0 1 2    2 5 8
      3 4 5 -> 7 4 1     3 4 5 -> 1 4 7
      6 7 8    8 5 2     6 7 8    0 3 6
*/    

    //first, copy all elements of array into other
    Colors tempfaceColor[9];
    for(int i = 0; i < 10; i++){
        tempfaceColor[i] = faceColors[i];
    }

    //rotate right
    if(orientation == 'r'){
        faceColors[0] = tempfaceColor[6]; 
        faceColors[1] = tempfaceColor[3];
        faceColors[2] = tempfaceColor[0];
        faceColors[3] = tempfaceColor[7];
        faceColors[5] = tempfaceColor[1];
        faceColors[6] = tempfaceColor[8];
        faceColors[7] = tempfaceColor[5];
        faceColors[8] = tempfaceColor[2];
    }

    //rotate left
    if(orientation == 'l'){
        faceColors[0] = tempfaceColor[2];
        faceColors[1] = tempfaceColor[5];
        faceColors[2] = tempfaceColor[8];
        faceColors[3] = tempfaceColor[1];
        faceColors[5] = tempfaceColor[7];
        faceColors[6] = tempfaceColor[0];
        faceColors[7] = tempfaceColor[3];
        faceColors[8] = tempfaceColor[6];
    }
}
