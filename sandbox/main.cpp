#include <iostream>
#include "Face.hpp"
#include "Cube.hpp"

int main(int argc, char **argv)
{
    Cube cubo;
    cubo.faceBranca.setColor(AZUL);

    std::cout << cubo.faceBranca.getColor(0) << " " << cubo.faceBranca.getColor(1) << " " << cubo.faceBranca.getColor(2) << std::endl;   
    std::cout << cubo.faceBranca.getColor(3) << " " << cubo.faceBranca.getColor(4) << " " << cubo.faceBranca.getColor(5) << std::endl;
    std::cout << cubo.faceBranca.getColor(6) << " " << cubo.faceBranca.getColor(7) << " " << cubo.faceBranca.getColor(8) << std::endl;

    //faceBranca.rotateFace('r');
    //faceBranca.rotateFace('l');
    //faceBranca.rotateFace('l');
    //faceBranca.rotateFace('l');

//    std::cout << std::endl;
//    std::cout << cubo.faceBranca.getColor(0) << " " << cubo.faceBranca.getColor(1) << " " << cubo.faceBranca.getColor(2) << std::endl;
//    std::cout << cubo.faceBranca.getColor(3) << " " << cubo.faceBranca.getColor(4) << " " << cubo.faceBranca.getColor(5) << std::endl;
//    std::cout << cubo.faceBranca.getColor(6) << " " << cubo.faceBranca.getColor(7) << " " << cubo.faceBranca.getColor(8) << std::endl;

}

