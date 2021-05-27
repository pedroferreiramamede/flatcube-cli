#include <iostream>
#include "Cube.hpp"
#include <stdio.h>

int startUI(Cube &cubo)
{
   /* First, clear the screen */
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);

    char actionSelect = 's';
    char faceSelected = 's';
    while(1)
    {
        std::cout << " +------------------------------------------------------------------------------+ " <<std::endl;
        std::cout << " | _/  _/    _/  _/    _/  _/    _/  _/    _/  _/    _/  _/   _/  _/   _/  _/   | " << std::endl;
        std::cout << " |   _/  _/    _/  _/    _/  _/    _/  _/    _/  _/    _/  _/   _/  _/   _/  _/ | " << std::endl;
        std::cout << " | /  _/    _/  _/    _/  _/    _/  _/    _/  _/    _/  _/   _/  _/   _/  _/    | " << std::endl;;
        std::cout << " |          __ _       _                _                         _ _           | " << std::endl;
        std::cout << " |         / _| | __ _| |_    ___ _   _| |__   ___            ___| (_)          |" << std::endl;
        std::cout << " |        | |_| |/ _` | __|  / __| | | | '_ \\ / _ \\  _____   / __| | |          |" << std::endl;
        std::cout << " |        |  _| | (_| | |_  | (__| |_| | |_) |  __/ |_____| | (__| | |          |" << std::endl;
        std::cout << " |        |_| |_|\\__,_|___|  \\___|\\__,_|_.__/ \\___|          \\___|_|_|          |" << std::endl;
        std::cout << " |                                                                              | " << std::endl;
        std::cout << " + - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -+" << std::endl;
        std::cout << " +- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +" << std::endl;
        std::cout << " |                                                                              | " << std::endl;
        std::cout << " |                                                                              | " << std::endl;

        switch(faceSelected)
        {
          case 's':
          case 'S':
             cubo.faceBranca.printFace();
             break;
          case 'w':
          case 'W':
             cubo.faceAzul.printFace();
             break;
          case 'x':
          case 'X':
             cubo.faceVerde.printFace();
             break;
          case 'd':
          case 'D':
             cubo.faceVermelha.printFace();
             break;
          case 'a':
          case 'A':
             cubo.faceLaranja.printFace();
             break;
          case 'f':
          case 'F':
             cubo.faceAmarela.printFace();
             break;
        }        

        std::cout << " |                                                                              | " << std::endl;
        std::cout << "Escolha a face que deseja ver ou < > para rotacionar: " << std::endl;
       
        std::cout << "   " << "\033[0;37;44m" << " W " << "\033[0m" << std::endl;
        std::cout << "\033[0;37;45m"  << " A " << "\033[0m" << "\033[0;30;107m" << " S " << "\033[0m" 
                  << "\033[0;37;41m"  << " D " << "\033[0m" << "\033[0;37;43m" << " F " << "\033[0m" << std::endl;
        std::cout << "   " << "\033[0;37;42m" << " X " << "\033[0m" << std::endl;
     
        std::cin >> actionSelect;
        
        if(actionSelect == '<'){
            switch(faceSelected)
            {
              case 's':
              case 'S':
                 cubo.rotateFace(BRANCO, 'l');
                 break;
              case 'w':
              case 'W':
                 cubo.rotateFace(AZUL, 'l');
                 break;
              case 'x':
              case 'X':
                 cubo.rotateFace(VERDE, 'l');
                 break;
              case 'd':
              case 'D':
                 cubo.rotateFace(VERMELHO, 'l');
                 break;
              case 'a':
              case 'A':
                 cubo.rotateFace(LARANJA, 'l');
                 break;
              case 'f':
              case 'F':
                 cubo.rotateFace(AMARELO, 'l');
                 break;
            }    
        }
        else if(actionSelect == '>'){
            switch(faceSelected)
            {
              case 's':
              case 'S':
                 cubo.rotateFace(BRANCO, 'r');
                 break;
              case 'w':
              case 'W':
                 cubo.rotateFace(AZUL, 'r');
                 break;
              case 'x':
              case 'X':
                 cubo.rotateFace(VERDE, 'r');
                 break;
              case 'd':
              case 'D':
                 cubo.rotateFace(VERMELHO, 'r');
                 break;
              case 'a':
              case 'A':
                 cubo.rotateFace(LARANJA, 'r');
                 break;
              case 'f':
              case 'F':
                 cubo.rotateFace(AMARELO, 'r');
                 break;
            }

        }else{
            faceSelected = actionSelect;
        } 
   
        printf("\033[2J");
        printf("\033[%d;%dH", 0, 0);
    }   
}
