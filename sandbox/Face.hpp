#ifndef FACE_HPP
#define FACE_HPP

enum Colors
{
    BRANCO = 0,
    AZUL,
    VERDE,
    VERMELHO,
    LARANJA,
    AMARELO
};

class Face
{
//private:
public:
    enum Colors faceColors[9];
//public:
    Face(Colors, Colors, Colors, Colors, Colors, Colors, Colors, Colors, Colors);
    Colors getColor(int);
    int setColor(int, Colors);
    int setColor(Colors, Colors, Colors, Colors, Colors, Colors, Colors, Colors, Colors);
    int rotateFace(char orientation);
};

#endif //FACE_HPP
