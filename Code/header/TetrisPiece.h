#pragma once
#include "WindowGame.h"

using namespace std;
using namespace sf;

struct Point
{
    int x, y;
};

class TetrisPiece
{
public:
    TetrisPiece() = default;
    TetrisPiece(Texture& texture, int& color, int correct_x, int correct_y, int& typeNext);
    vector<Sprite>& getSprites() { return m_sprites; }
    vector<Point>& getSpritesCords() { return m_sprites_cords; }

   
    void moveRight();
    void moveLeft();
    void makeRotation();
    void getConsoleCords()const;

    
    void setSpritesCords(std::vector<Point>& arr);
    void drawCoordinatesTetramino(TetrisPiece& tetramino);
    void drawTetramino(WindowGame& window, TetrisPiece& tetramino);
private:

    int m_type, m_correction_x = 0, m_correction_y = 0;
    vector<vector<int>>   m_tetratype;
    vector<Sprite>        m_sprites;
    vector<Point>         m_sprites_cords;
    int m_color = 0;
    void  spriteCordCalculation(int sprite_index);

};


