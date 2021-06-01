#include <iostream>
#include <stdio.h>
#include "Face.hpp"
#include "Cube.hpp"
#include "UI.hpp"

//#define DEBUG_FACE

int main(int argc, char **argv)
{
    Cube cubo; 
    cubo.InitializeCube();
    
    startUI(cubo);
}
