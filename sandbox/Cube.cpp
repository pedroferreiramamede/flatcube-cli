#include <iostream>
#include "Cube.hpp"

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
              std::cout << "Rotating White Face" << std::endl;

              if(orientation == 'r'){
                  //rotate the face itself
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
                  this->faceVermelha.setColor(0, tempfaceColorAzul[0]);
                  this->faceVermelha.setColor(0, tempfaceColorAzul[0]);
                  this->faceAzul.setColor(0, tempfaceColorLaranja[0]);
                  this->faceAzul.setColor(0, tempfaceColorLaranja[0]);
                  this->faceAzul.setColor(0, tempfaceColorLaranja[0]);
                  this->faceLaranja.setColor(0, tempfaceColorVerde[0]);
                  this->faceLaranja.setColor(0, tempfaceColorVerde[0]);
                  this->faceLaranja.setColor(0, tempfaceColorVerde[0]);

              } else {
#if 0       
                  this->faceBranca.setColor(0, tempfaceColorBranca[2]);
                  this->faceBranca.setColor(1, tempfaceColorBranca[5]);
                  this->faceBranca.setColor(2, tempfaceColorBranca[8]);
                  this->faceBranca.setColor(3, tempfaceColorBranca[1]);
                  this->faceBranca.setColor(5, tempfaceColorBranca[7]);
                  this->faceBranca.setColor(6, tempfaceColorBranca[0]);
                  this->faceBranca.setColor(7, tempfaceColorBranca[3]);
                  this->faceBranca.setColor(8, tempfaceColorBranca[6]);
#endif
                  for(int i = 0; i < 3; i++)
                      this->rotateFace(BRANCO, 'r'); 
              }
              break;

          case AZUL:
            std::cout << "Rotating Blue Face" << std::endl;
            break;

          case VERDE:
            std::cout << "Rotating Green Face" << std::endl;
            break;

          case VERMELHO:
            std::cout << "Rotating Red Face" << std::endl;
            break;

          case LARANJA:
            std::cout << "Rotating Orange Face" << std::endl;
            break;

          case AMARELO:
            std::cout << "Rotating Yellow Face" << std::endl;
            break;

        }
    
}

