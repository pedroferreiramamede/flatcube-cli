#include <iostream>
#include "Cube.hpp"
#include <stdio.h>
#include <cctype>
#include <unistd.h>
#include <string>
#include <fstream>

int printSavedFiles();
std::string findFile(char fileChoose);

int startUI(Cube &cubo)
{
    char actionSelect = 's';
    char faceSelected = 's';
    bool menuSelected = false;
    bool listFiles    = false;

    /* First, clear the screen */
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);

    while(1)
    {
        printf("\033[2J");
        printf("\033[%d;%dH", 0, 0);

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

        faceSelected = toupper(faceSelected);
        switch(faceSelected)
        {
          case 'S':
             cubo.faceBranca.printFace();
             break;
          case 'W':
             cubo.rotateFaceToPrint(AZUL, 'r');cubo.rotateFaceToPrint(AZUL, 'r');
             cubo.faceAzul.printFace();
             cubo.rotateFaceToPrint(AZUL, 'r');cubo.rotateFaceToPrint(AZUL, 'r');
             break;
          case 'X':
             cubo.faceVerde.printFace();
             break;
          case 'D':
             cubo.rotateFaceToPrint(VERMELHO, 'l');
             cubo.faceVermelha.printFace();
             cubo.rotateFaceToPrint(VERMELHO, 'r');
             break;
          case 'A':
             cubo.rotateFaceToPrint(LARANJA, 'r');
             cubo.faceLaranja.printFace();
             cubo.rotateFaceToPrint(LARANJA, 'l'); 
             break;
          case 'F':
             cubo.faceAmarela.printFace();
             break;
        }        

        std::cout << " |                                                                              | " << std::endl;
        std::cout << " +------------------------------------------------------------------------------+ " << std::endl;
        std::cout << " | Escolha a face que deseja ver, < > para rotacionar, (U)ndo, ou (M)enu:       | " << std::endl;
        std::cout << " +-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - -+ " << std::endl;
        std::cout << " |                                                                              | " << std::endl;

        /* Print the W ************************************************************************************************/
        if(faceSelected == 'W'){ 
        std::cout << " |     " << "\033[0;37;44m" << "[W]" << "\033[0m" <<
                     "                                             Movimentos: " << cubo.getMovimentos();
        for(int i = 0; i < (13-(std::to_string(cubo.getMovimentos()).length())); i++)
            std::cout << " ";    
        std::cout << "|" << std::endl;}
        else{        
        std::cout << " |     " << "\033[0;37;44m" << " W " << "\033[0m" <<
                     "                                             Movimentos: " << cubo.getMovimentos();
        for(int i = 0; i < (13-(std::to_string(cubo.getMovimentos()).length())); i++)
            std::cout << " ";
        std::cout << "|" << std::endl;}
        /**************************************************************************************************************/
 
        /* Print the ASDF**********************************************************************************************/
        if(faceSelected == 'A'){
        std::cout << " |  \033[0;37;45m"  << "[A]" << "\033[0m" << "\033[0;30;107m" << " S " << "\033[0m" 
                  << "\033[0;37;41m"  << " D " << "\033[0m" << "\033[0;37;43m" << " F " << "\033[0m" << 
                     "                                                                | " << std::endl;}

        else if(faceSelected == 'S'){
        std::cout << " |  \033[0;37;45m"  << " A " << "\033[0m" << "\033[0;30;107m" << "[S]" << "\033[0m" 
                  << "\033[0;37;41m"  << " D " << "\033[0m" << "\033[0;37;43m" << " F " << "\033[0m" <<
                     "                                                                | " << std::endl;}
 
        else if(faceSelected == 'D'){
        std::cout << " |  \033[0;37;45m"  << " A " << "\033[0m" << "\033[0;30;107m" << " S " << "\033[0m" 
                  << "\033[0;37;41m"  << "[D]" << "\033[0m" << "\033[0;37;43m" << " F " << "\033[0m" <<
                     "                                                                | " << std::endl;}

        else if(faceSelected == 'F'){
        std::cout << " |  \033[0;37;45m"  << " A " << "\033[0m" << "\033[0;30;107m" << " S " << "\033[0m" 
                  << "\033[0;37;41m"  << " D " << "\033[0m" << "\033[0;37;43m" << "[F]" << "\033[0m" <<
                     "                                                                | " << std::endl;}

        else{
        std::cout << " |  \033[0;37;45m"  << " A " << "\033[0m" << "\033[0;30;107m" << " S " << "\033[0m"
                  << "\033[0;37;41m"  << " D " << "\033[0m" << "\033[0;37;43m" << " F " << "\033[0m" <<
                     "                                                                | " << std::endl;}
        /**************************************************************************************************************/

        /* Print the X ************************************************************************************************/
        if(faceSelected == 'X'){
        std::cout << " |     " << "\033[0;37;42m" << "[X]" << "\033[0m" << 
                     "                                                                      |" << std::endl;}
        else{
        std::cout << " |     " << "\033[0;37;42m" << " X " << "\033[0m" <<
                     "                                                                      |" << std::endl;}
        /**************************************************************************************************************/
        
        std::cout << " |                                                                              | " << std::endl;
        std::cout << " +------------------------------------------------------------------------------+ " << std::endl;
     
        if(actionSelect == 'M' || actionSelect == 'm' || (menuSelected && !listFiles)){
            menuSelected = true; 
            std::cout << " |################################## MENU ######################################| " << std::endl;
            std::cout << " +------------------------------------------------------------------------------+ " << std::endl;
            std::cout << " | (1)Embaralhar                                                                | " << std::endl;
            std::cout << " | (2)Salvar                                                                    | " << std::endl;
            std::cout << " | (3)Carregar                                                                  | " << std::endl;
            std::cout << " |                                                                              | " << std::endl;
            std::cout << " |                                                                              | " << std::endl;
            std::cout << " +------------------------------------------------------------------------------+ " << std::endl;
        } 
        else if(menuSelected && listFiles){
            std::cout << " |################################## MENU ######################################| " << std::endl;
            std::cout << " +------------------------------------------------------------------------------+ " << std::endl;
            std::cout << " | Selecione um dos arquivos disponíveis:                                       | " << std::endl;
            std::cout << " |                                                                              | " << std::endl;
            printSavedFiles();
            std::cout << " |                                                                              | " << std::endl;
            std::cout << " +------------------------------------------------------------------------------+ " << std::endl;
        }

        std::cin >> actionSelect;

        if(actionSelect == '<' || actionSelect == ','){
            cubo.saveLastMove();            
            switch(faceSelected)
            {
              case 's':
              case 'S':
                 cubo.rotateFace(BRANCO, 'l');
                 cubo.incMovimentos();
                 break;
              case 'w':
              case 'W':
                 cubo.rotateFace(AZUL, 'l');
                 cubo.incMovimentos();
                 break;
              case 'x':
              case 'X':
                 cubo.rotateFace(VERDE, 'l');
                 cubo.incMovimentos();
                 break;
              case 'd':
              case 'D':
                 cubo.rotateFace(VERMELHO, 'l');
                 cubo.incMovimentos();
                 break;
              case 'a':
              case 'A':
                 cubo.rotateFace(LARANJA, 'l');
                 cubo.incMovimentos();
                 break;
              case 'f':
              case 'F':
                 cubo.rotateFace(AMARELO, 'l');
                 cubo.incMovimentos();
                 break;
            }    
        }
        else if(actionSelect == '>' || actionSelect == '.'){
            cubo.saveLastMove();
            switch(faceSelected)
            {
              case 's':
              case 'S':
                 cubo.rotateFace(BRANCO, 'r');
                 cubo.incMovimentos();
                 break;
              case 'w':
              case 'W':
                 cubo.rotateFace(AZUL, 'r');
                 cubo.incMovimentos();
                 break;
              case 'x':
              case 'X':
                 cubo.rotateFace(VERDE, 'r');
                 cubo.incMovimentos();
                 break;
              case 'd':
              case 'D':
                 cubo.rotateFace(VERMELHO, 'r');
                 cubo.incMovimentos();
                 break;
              case 'a':
              case 'A':
                 cubo.rotateFace(LARANJA, 'r');
                 cubo.incMovimentos();
                 break;
              case 'f':
              case 'F':
                 cubo.rotateFace(AMARELO, 'r');
                 cubo.incMovimentos();
                 break;
            }
        }
        else if(actionSelect == 'a' ||
                actionSelect == 'A' ||
                actionSelect == 's' ||
                actionSelect == 'S' ||
                actionSelect == 'w' ||
                actionSelect == 'W' ||
                actionSelect == 'x' ||
                actionSelect == 'X' ||
                actionSelect == 'd' ||
                actionSelect == 'D' ||
                actionSelect == 'f' ||
                actionSelect == 'F' ){
            faceSelected = actionSelect;
        }
        else if(actionSelect == 'u' || actionSelect == 'U'){
            cubo.undoLastMove();
        }
        else if(menuSelected && actionSelect == '1' && !listFiles){
            cubo.Scramble();
            menuSelected = false;             
        } 
        else if(menuSelected && actionSelect == '2' && !listFiles){
            cubo.saveCube();
            menuSelected = false;             
        } 
        else if(menuSelected && actionSelect == '3' && !listFiles){
            //First, list the availbles files
            listFiles = true;
            system("ls -A1 saves >> listfiles"); 
 
            //cubo.loadCube();
            //menuSelected = false; 
        }
        else if((menuSelected && listFiles)){
            std::cout << "INSIDEEEEEEEE" << std::endl;
            cubo.loadCube(findFile(actionSelect));
            
            listFiles = false;
            menuSelected = false;             
        }            
    }   
}

int printSavedFiles()
{
    std::string text;
    std::ifstream ifs("listfiles");

    int i = 1;
    while(!ifs.eof())
    {
        getline(ifs,text);
        if(!(text.empty()) && text.compare(".gitignore"))
            std::cout << " | " << "(" << i << ") "  << text << "                                                        |" << std::endl;
        i++;
    }
}

std::string findFile(char fileChoose)
{
    std::string text;
    std::ifstream ifs("listfiles");
    int fileChooseNumber = (fileChoose - '0');

    int i = 1;
    while(!ifs.eof())
    {
        getline(ifs,text);
        if(i == fileChooseNumber){
            system("rm listfiles");
            std::cout << "FILE NAME: "<< text << std::endl;
            return text;
        }
        i++;
    }

}

