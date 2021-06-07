#include <iostream>
#include "Cube.hpp"
#include <stdlib.h>
#include <fstream>
#include <ctime>

Cube::Cube()
{
   // std::cout << "calling constructor" << std::endl;
}

int Cube::InitializeCube(){
    //Initialize all faces
    this->faceBranca.setColor(BRANCO);
    this->faceAzul.setColor(AZUL);
    this->faceVerde.setColor(VERDE);
    this->faceVermelha.setColor(VERMELHO);
    this->faceLaranja.setColor(LARANJA);
    this->faceAmarela.setColor(AMARELO);

    this->setMovimentos(0);
}

int Cube::rotateFace(Colors color, char orientation)
{
/* Rotate right:        Rotate left:

      0 1 2    6 3 0     0 1 2    2 5 8
      3 4 5 -> 7 4 1     3 4 5 -> 1 4 7
      6 7 8    8 5 2     6 7 8    0 3 6
*/    
        //first, copy all elements of array into other
        Colors tempfaceColorBranca[9], tempfaceColorAzul[9],    tempfaceColorVermelha[9],
               tempfaceColorVerde[9],  tempfaceColorLaranja[9], tempfaceColorAmarela[9];

        for(int i = 0; i < 10; i++){
            tempfaceColorBranca[i]  = this->faceBranca.getColor(i);
            tempfaceColorAzul[i]   = this->faceAzul.getColor(i);
            tempfaceColorVermelha[i] = this->faceVermelha.getColor(i);
            tempfaceColorVerde[i]   = this->faceVerde.getColor(i);
            tempfaceColorLaranja[i] = this->faceLaranja.getColor(i);
            tempfaceColorAmarela[i] = this->faceAmarela.getColor(i);
        }


        switch(color)
        {
          case BRANCO:

              if(orientation == 'r'){
                  //rotate the face itself
                  //std::cout << "Rotating White Face Right" << std::endl;
                  this->faceBranca.setColor(0, tempfaceColorBranca[6]);  
                  this->faceBranca.setColor(1, tempfaceColorBranca[3]); 
                  this->faceBranca.setColor(2, tempfaceColorBranca[0]); 
                  this->faceBranca.setColor(3, tempfaceColorBranca[7]); 
                  this->faceBranca.setColor(5, tempfaceColorBranca[1]); 
                  this->faceBranca.setColor(6, tempfaceColorBranca[8]); 
                  this->faceBranca.setColor(7, tempfaceColorBranca[5]); 
                  this->faceBranca.setColor(8, tempfaceColorBranca[2]); 

                  //then, change the other faces
                  this->faceVerde.setColor(0, tempfaceColorVermelha[0]);
                  this->faceVerde.setColor(1, tempfaceColorVermelha[1]);
                  this->faceVerde.setColor(2, tempfaceColorVermelha[2]);
                  this->faceVermelha.setColor(0, tempfaceColorAzul[0]);
                  this->faceVermelha.setColor(1, tempfaceColorAzul[1]);
                  this->faceVermelha.setColor(2, tempfaceColorAzul[2]);
                  this->faceAzul.setColor(0, tempfaceColorLaranja[0]);
                  this->faceAzul.setColor(1, tempfaceColorLaranja[1]);
                  this->faceAzul.setColor(2, tempfaceColorLaranja[2]);
                  this->faceLaranja.setColor(0, tempfaceColorVerde[0]);
                  this->faceLaranja.setColor(1, tempfaceColorVerde[1]);
                  this->faceLaranja.setColor(2, tempfaceColorVerde[2]);

              } else {
                  //rotate to left is the same that rotate to right 3 times:
                  //std::cout << "Rotating White Face Left" << std::endl;
                  for(int i = 0; i < 3; i++)
                      this->rotateFace(BRANCO, 'r'); 
              }
              break;

          case VERDE:

              if(orientation == 'r'){
                  //std::cout << "Rotating Green Face Right" << std::endl;
                  //rotate the face itself
                  this->faceVerde.setColor(0, tempfaceColorVerde[6]);
                  this->faceVerde.setColor(1, tempfaceColorVerde[3]);
                  this->faceVerde.setColor(2, tempfaceColorVerde[0]);
                  this->faceVerde.setColor(3, tempfaceColorVerde[7]);
                  this->faceVerde.setColor(5, tempfaceColorVerde[1]);
                  this->faceVerde.setColor(6, tempfaceColorVerde[8]);
                  this->faceVerde.setColor(7, tempfaceColorVerde[5]);
                  this->faceVerde.setColor(8, tempfaceColorVerde[2]);

                  //then, change the other faces
                  this->faceAmarela.setColor(8, tempfaceColorVermelha[6]);
                  this->faceAmarela.setColor(7, tempfaceColorVermelha[3]);
                  this->faceAmarela.setColor(6, tempfaceColorVermelha[0]);
                  this->faceVermelha.setColor(6, tempfaceColorBranca[8]);
                  this->faceVermelha.setColor(3, tempfaceColorBranca[7]);
                  this->faceVermelha.setColor(0, tempfaceColorBranca[6]);
                  this->faceBranca.setColor(8, tempfaceColorLaranja[2]);
                  this->faceBranca.setColor(7, tempfaceColorLaranja[5]);
                  this->faceBranca.setColor(6, tempfaceColorLaranja[8]);
                  this->faceLaranja.setColor(2, tempfaceColorAmarela[8]);
                  this->faceLaranja.setColor(5, tempfaceColorAmarela[7]);
                  this->faceLaranja.setColor(8, tempfaceColorAmarela[6]);

              } else {
                  //rotate to left is the same that rotate to right 3 times:
                  //std::cout << "Rotating Green Face Left" << std::endl;
                  for(int i = 0; i < 3; i++)
                      this->rotateFace(VERDE, 'r');
              }
            break;

          case AZUL:

              if(orientation == 'r'){
                  //std::cout << "Rotating Blue Face Right" << std::endl;
                  //rotate the face itself
                  this->faceAzul.setColor(0, tempfaceColorAzul[6]);
                  this->faceAzul.setColor(1, tempfaceColorAzul[3]);
                  this->faceAzul.setColor(2, tempfaceColorAzul[0]);
                  this->faceAzul.setColor(3, tempfaceColorAzul[7]);
                  this->faceAzul.setColor(5, tempfaceColorAzul[1]);
                  this->faceAzul.setColor(6, tempfaceColorAzul[8]);
                  this->faceAzul.setColor(7, tempfaceColorAzul[5]);
                  this->faceAzul.setColor(8, tempfaceColorAzul[2]);

                  //then, change the other faces
                  this->faceAmarela.setColor(0, tempfaceColorLaranja[6]);
                  this->faceAmarela.setColor(1, tempfaceColorLaranja[3]);
                  this->faceAmarela.setColor(2, tempfaceColorLaranja[0]);
                  this->faceVermelha.setColor(2, tempfaceColorAmarela[0]);
                  this->faceVermelha.setColor(5, tempfaceColorAmarela[1]);
                  this->faceVermelha.setColor(8, tempfaceColorAmarela[2]);
                  this->faceBranca.setColor(0, tempfaceColorVermelha[2]);
                  this->faceBranca.setColor(1, tempfaceColorVermelha[5]);
                  this->faceBranca.setColor(2, tempfaceColorVermelha[8]);
                  this->faceLaranja.setColor(6, tempfaceColorBranca[0]);
                  this->faceLaranja.setColor(3, tempfaceColorBranca[1]);
                  this->faceLaranja.setColor(0, tempfaceColorBranca[2]);

              } else {
                  //rotate to left is the same that rotate to right 3 times:
                  //std::cout << "Rotating Blue Face Left" << std::endl;
                  for(int i = 0; i < 3; i++)
                      this->rotateFace(AZUL, 'r');
              }
            break;

          case VERMELHO:
           
              if(orientation == 'r'){
                  //std::cout << "Rotating Red Face Right" << std::endl;
                  //rotate the face itself
                  this->faceVermelha.setColor(0, tempfaceColorVermelha[6]);
                  this->faceVermelha.setColor(1, tempfaceColorVermelha[3]);
                  this->faceVermelha.setColor(2, tempfaceColorVermelha[0]);
                  this->faceVermelha.setColor(3, tempfaceColorVermelha[7]);
                  this->faceVermelha.setColor(5, tempfaceColorVermelha[1]);
                  this->faceVermelha.setColor(6, tempfaceColorVermelha[8]);
                  this->faceVermelha.setColor(7, tempfaceColorVermelha[5]);
                  this->faceVermelha.setColor(8, tempfaceColorVermelha[2]);

                  //then, change the other faces
                  this->faceAmarela.setColor(6, tempfaceColorAzul[6]);
                  this->faceAmarela.setColor(3, tempfaceColorAzul[3]);
                  this->faceAmarela.setColor(0, tempfaceColorAzul[0]);
                  this->faceAzul.setColor(6, tempfaceColorBranca[2]);
                  this->faceAzul.setColor(3, tempfaceColorBranca[5]);
                  this->faceAzul.setColor(0, tempfaceColorBranca[8]);
                  this->faceBranca.setColor(2, tempfaceColorVerde[2]);
                  this->faceBranca.setColor(5, tempfaceColorVerde[5]);
                  this->faceBranca.setColor(8, tempfaceColorVerde[8]);
                  this->faceVerde.setColor(2, tempfaceColorAmarela[6]);
                  this->faceVerde.setColor(5, tempfaceColorAmarela[3]);
                  this->faceVerde.setColor(8, tempfaceColorAmarela[0]);

              } else {
                  //rotate to left is the same that rotate to right 3 times:
                  //std::cout << "Rotating Red Face Left" << std::endl;
                  for(int i = 0; i < 3; i++)
                      this->rotateFace(VERMELHO, 'r');
              }
            break;

          case LARANJA:

              if(orientation == 'r'){
                  //std::cout << "Rotating Orange Face Right" << std::endl;
                  //rotate the face itself
                  this->faceLaranja.setColor(0, tempfaceColorLaranja[6]);
                  this->faceLaranja.setColor(1, tempfaceColorLaranja[3]);
                  this->faceLaranja.setColor(2, tempfaceColorLaranja[0]);
                  this->faceLaranja.setColor(3, tempfaceColorLaranja[7]);
                  this->faceLaranja.setColor(5, tempfaceColorLaranja[1]);
                  this->faceLaranja.setColor(6, tempfaceColorLaranja[8]);
                  this->faceLaranja.setColor(7, tempfaceColorLaranja[5]);
                  this->faceLaranja.setColor(8, tempfaceColorLaranja[2]);

                  //then, change the other faces
                  this->faceAmarela.setColor(2, tempfaceColorVerde[6]);
                  this->faceAmarela.setColor(5, tempfaceColorVerde[3]);
                  this->faceAmarela.setColor(8, tempfaceColorVerde[0]);
                  this->faceVerde.setColor(6, tempfaceColorBranca[6]);
                  this->faceVerde.setColor(3, tempfaceColorBranca[3]);
                  this->faceVerde.setColor(0, tempfaceColorBranca[0]);
                  this->faceBranca.setColor(6, tempfaceColorAzul[2]);
                  this->faceBranca.setColor(3, tempfaceColorAzul[5]);
                  this->faceBranca.setColor(0, tempfaceColorAzul[8]);
                  this->faceAzul.setColor(2, tempfaceColorAmarela[2]);
                  this->faceAzul.setColor(5, tempfaceColorAmarela[5]);
                  this->faceAzul.setColor(8, tempfaceColorAmarela[8]);

              } else {
                  //rotate to left is the same that rotate to right 3 times:
                  //std::cout << "Rotating Orange Face Left" << std::endl;
                  for(int i = 0; i < 3; i++)
                      this->rotateFace(LARANJA, 'r');
              }
            break;

          case AMARELO:

              if(orientation == 'r'){
                  //std::cout << "Rotating Yellow Face Right" << std::endl;
                  //rotate the face itself
                  this->faceAmarela.setColor(0, tempfaceColorAmarela[6]);
                  this->faceAmarela.setColor(1, tempfaceColorAmarela[3]);
                  this->faceAmarela.setColor(2, tempfaceColorAmarela[0]);
                  this->faceAmarela.setColor(3, tempfaceColorAmarela[7]);
                  this->faceAmarela.setColor(5, tempfaceColorAmarela[1]);
                  this->faceAmarela.setColor(6, tempfaceColorAmarela[8]);
                  this->faceAmarela.setColor(7, tempfaceColorAmarela[5]);
                  this->faceAmarela.setColor(8, tempfaceColorAmarela[2]);

                  //then, change the other faces
                  this->faceVermelha.setColor(8, tempfaceColorVerde[8]);
                  this->faceVermelha.setColor(7, tempfaceColorVerde[7]);
                  this->faceVermelha.setColor(6, tempfaceColorVerde[6]);
                  this->faceVerde.setColor(8, tempfaceColorLaranja[8]);
                  this->faceVerde.setColor(7, tempfaceColorLaranja[7]);
                  this->faceVerde.setColor(6, tempfaceColorLaranja[6]);
                  this->faceLaranja.setColor(8, tempfaceColorAzul[8]);
                  this->faceLaranja.setColor(7, tempfaceColorAzul[7]);
                  this->faceLaranja.setColor(6, tempfaceColorAzul[6]);
                  this->faceAzul.setColor(8, tempfaceColorVermelha[8]);
                  this->faceAzul.setColor(7, tempfaceColorVermelha[7]);
                  this->faceAzul.setColor(6, tempfaceColorVermelha[6]);

              } else {
                  //rotate to left is the same that rotate to right 3 times:
                  //std::cout << "Rotating Yellow Face Left" << std::endl;
                  for(int i = 0; i < 3; i++)
                      this->rotateFace(AMARELO, 'r');
              }
            break;

        }
    
}

int Cube::rotateFaceToPrint(Colors color, char orientation)
{
/* Rotate right:        Rotate left:

      0 1 2    6 3 0     0 1 2    2 5 8
      3 4 5 -> 7 4 1     3 4 5 -> 1 4 7
      6 7 8    8 5 2     6 7 8    0 3 6
*/    
        //first, copy all elements of array into other
        Colors tempfaceColorBranca[9], tempfaceColorAzul[9],    tempfaceColorVermelha[9],
               tempfaceColorVerde[9],  tempfaceColorLaranja[9], tempfaceColorAmarela[9];

        for(int i = 0; i < 10; i++){
            tempfaceColorBranca[i]  = this->faceBranca.getColor(i);
            tempfaceColorAzul[i]   = this->faceAzul.getColor(i);
            tempfaceColorVermelha[i] = this->faceVermelha.getColor(i);
            tempfaceColorVerde[i]   = this->faceVerde.getColor(i);
            tempfaceColorLaranja[i] = this->faceLaranja.getColor(i);
            tempfaceColorAmarela[i] = this->faceAmarela.getColor(i);
        }


        switch(color)
        {
          case BRANCO:

              if(orientation == 'r'){
                  //std::cout << "Rotating White Face Right - To Print" << std::endl;
                  //rotate the face itself
                  this->faceBranca.setColor(0, tempfaceColorBranca[6]);  
                  this->faceBranca.setColor(1, tempfaceColorBranca[3]); 
                  this->faceBranca.setColor(2, tempfaceColorBranca[0]); 
                  this->faceBranca.setColor(3, tempfaceColorBranca[7]); 
                  this->faceBranca.setColor(5, tempfaceColorBranca[1]); 
                  this->faceBranca.setColor(6, tempfaceColorBranca[8]); 
                  this->faceBranca.setColor(7, tempfaceColorBranca[5]); 
                  this->faceBranca.setColor(8, tempfaceColorBranca[2]); 

              } else {
                  //rotate to left is the same that rotate to right 3 times:
                  //std::cout << "Rotating White Face Left - To Print" << std::endl;
                  for(int i = 0; i < 3; i++)
                      this->rotateFaceToPrint(BRANCO, 'r'); 
              }
              break;

          case VERDE:

              if(orientation == 'r'){
                  //std::cout << "Rotating Green Face Right - To Print" << std::endl;
                  //rotate the face itself
                  this->faceVerde.setColor(0, tempfaceColorVerde[6]);
                  this->faceVerde.setColor(1, tempfaceColorVerde[3]);
                  this->faceVerde.setColor(2, tempfaceColorVerde[0]);
                  this->faceVerde.setColor(3, tempfaceColorVerde[7]);
                  this->faceVerde.setColor(5, tempfaceColorVerde[1]);
                  this->faceVerde.setColor(6, tempfaceColorVerde[8]);
                  this->faceVerde.setColor(7, tempfaceColorVerde[5]);
                  this->faceVerde.setColor(8, tempfaceColorVerde[2]);

              } else {
                  //rotate to left is the same that rotate to right 3 times:
                  //std::cout << "Rotating Green Face Left - To Print" << std::endl;
                  for(int i = 0; i < 3; i++)
                      this->rotateFaceToPrint(VERDE, 'r');
              }
            break;

          case AZUL:

              if(orientation == 'r'){
                  //std::cout << "Rotating Blue Face Right - To Print" << std::endl;
                  //rotate the face itself
                  this->faceAzul.setColor(0, tempfaceColorAzul[6]);
                  this->faceAzul.setColor(1, tempfaceColorAzul[3]);
                  this->faceAzul.setColor(2, tempfaceColorAzul[0]);
                  this->faceAzul.setColor(3, tempfaceColorAzul[7]);
                  this->faceAzul.setColor(5, tempfaceColorAzul[1]);
                  this->faceAzul.setColor(6, tempfaceColorAzul[8]);
                  this->faceAzul.setColor(7, tempfaceColorAzul[5]);
                  this->faceAzul.setColor(8, tempfaceColorAzul[2]);

              } else {
                  //rotate to left is the same that rotate to right 3 times:
                  //std::cout << "Rotating Blue Face Left - To Print" << std::endl;
                  for(int i = 0; i < 3; i++)
                      this->rotateFaceToPrint(AZUL, 'r');
              }
            break;

          case VERMELHO:
           
              if(orientation == 'r'){
                  //std::cout << "Rotating Red Face Right - To Print" << std::endl;
                  //rotate the face itself
                  this->faceVermelha.setColor(0, tempfaceColorVermelha[6]);
                  this->faceVermelha.setColor(1, tempfaceColorVermelha[3]);
                  this->faceVermelha.setColor(2, tempfaceColorVermelha[0]);
                  this->faceVermelha.setColor(3, tempfaceColorVermelha[7]);
                  this->faceVermelha.setColor(5, tempfaceColorVermelha[1]);
                  this->faceVermelha.setColor(6, tempfaceColorVermelha[8]);
                  this->faceVermelha.setColor(7, tempfaceColorVermelha[5]);
                  this->faceVermelha.setColor(8, tempfaceColorVermelha[2]);

              } else {
                  //rotate to left is the same that rotate to right 3 times:
                  //std::cout << "Rotating Red Face Left - To Print" << std::endl;
                  for(int i = 0; i < 3; i++)
                      this->rotateFaceToPrint(VERMELHO, 'r');
              }
            break;

          case LARANJA:

              if(orientation == 'r'){
                  //std::cout << "Rotating Orange Face Right - To Print" << std::endl;
                  //rotate the face itself
                  this->faceLaranja.setColor(0, tempfaceColorLaranja[6]);
                  this->faceLaranja.setColor(1, tempfaceColorLaranja[3]);
                  this->faceLaranja.setColor(2, tempfaceColorLaranja[0]);
                  this->faceLaranja.setColor(3, tempfaceColorLaranja[7]);
                  this->faceLaranja.setColor(5, tempfaceColorLaranja[1]);
                  this->faceLaranja.setColor(6, tempfaceColorLaranja[8]);
                  this->faceLaranja.setColor(7, tempfaceColorLaranja[5]);
                  this->faceLaranja.setColor(8, tempfaceColorLaranja[2]);

              } else {
                  //rotate to left is the same that rotate to right 3 times:
                  //std::cout << "Rotating Orange Face Left - To Print" << std::endl;
                  for(int i = 0; i < 3; i++)
                      this->rotateFaceToPrint(LARANJA, 'r');
              }
            break;

          case AMARELO:

              if(orientation == 'r'){
                  //rotate the face itself
                  //std::cout << "Rotating Yellow Face Right - To Print" << std::endl;
                  this->faceAmarela.setColor(0, tempfaceColorAmarela[6]);
                  this->faceAmarela.setColor(1, tempfaceColorAmarela[3]);
                  this->faceAmarela.setColor(2, tempfaceColorAmarela[0]);
                  this->faceAmarela.setColor(3, tempfaceColorAmarela[7]);
                  this->faceAmarela.setColor(5, tempfaceColorAmarela[1]);
                  this->faceAmarela.setColor(6, tempfaceColorAmarela[8]);
                  this->faceAmarela.setColor(7, tempfaceColorAmarela[5]);
                  this->faceAmarela.setColor(8, tempfaceColorAmarela[2]);

              } else {
                  //rotate to left is the same that rotate to right 3 times:
                  //std::cout << "Rotating Yellow Face Left - To Print" << std::endl;
                  for(int i = 0; i < 3; i++)
                      this->rotateFaceToPrint(AMARELO, 'r');
              }
            break;

        }
}

int Cube::Scramble(){
    char orientation;
    int face;

    srand(time(NULL));
 
    for(int i = 0; i < 50; i++){
        face = rand() % 6;

        ((rand() % 11) % 2 == 0) ? orientation = 'r' : orientation = 'l';
        //std::cout << "face: " << face << "" << orientation << std::endl;
           
	this->rotateFace((Colors)face, orientation);
    }
}

int Cube::getMovimentos(){
    return this-> Movimentos;
}

int Cube::setMovimentos(int moves){
   this->Movimentos = moves;
}

int Cube::incMovimentos(){
   this->Movimentos++;
}

int Cube::saveCube(){
    //Create a file to write the faces colors
    std::time_t now = std::time(NULL);
    std::tm * ptm = std::localtime(&now);
    char buffer[32];
    std::strftime(buffer, 32, "saves/%Y%m%d_%H_%M_%S", ptm);  

    std::ofstream outfile (buffer);
   
    for(int i = 0; i < 9; i++){
        outfile << std::to_string(this->faceBranca.getColor(i)) << ",";
    }
    for(int i = 0; i < 9; i++){
        outfile << std::to_string(this->faceAzul.getColor(i)) << ",";
    }
    for(int i = 0; i < 9; i++){
        outfile << std::to_string(this->faceVerde.getColor(i)) << ",";
    }
    for(int i = 0; i < 9; i++){
        outfile << std::to_string(this->faceVermelha.getColor(i)) << ",";
    }
    for(int i = 0; i < 9; i++){
        outfile << std::to_string(this->faceLaranja.getColor(i)) << ",";
    }
    for(int i = 0; i < 9; i++){
        outfile << std::to_string(this->faceAmarela.getColor(i)) << ",";
    }
}

int Cube::loadCube(std::string fileChoose)
{
    //Verify if the file is there
    std::string fileFullPath = "saves/";
    fileFullPath.append(fileChoose);
    std::ifstream file(fileFullPath);
    std::string data = "";

    if(file.is_open()){
        for(int i = 0; i < 9; i++){
            getline(file, data, ',');
            this->faceBranca.setColor(i, (Colors) stoi(data));   
        }
        for(int i = 0; i < 9; i++){
            getline(file, data, ',');
            this->faceAzul.setColor(i, (Colors) stoi(data));   
        }
        for(int i = 0; i < 9; i++){
            getline(file, data, ',');
            this->faceVerde.setColor(i, (Colors) stoi(data));   
        }
        for(int i = 0; i < 9; i++){
            getline(file, data, ',');
            this->faceVermelha.setColor(i, (Colors) stoi(data));   
        }
        for(int i = 0; i < 9; i++){
            getline(file, data, ',');
            this->faceLaranja.setColor(i, (Colors) stoi(data));   
        }
        for(int i = 0; i < 9; i++){
            getline(file, data, ',');
            this->faceAmarela.setColor(i, (Colors) stoi(data));   
        }
                 
    } else {
        std::cout << "Arquivo não encontrado!" << std::endl;
    }
}
