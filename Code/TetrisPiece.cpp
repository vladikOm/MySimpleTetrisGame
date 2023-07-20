#include "header//TetrisPiece.h"
#include <vector>

void  TetrisPiece::getConsoleCords()const
{
    for (int i = 0; i < m_sprites_cords.size(); i++)
        cout << "Sprite " << i << " coordinates: x = " << m_sprites_cords[i].x << ", y = " << m_sprites_cords[i].y << endl;
}

TetrisPiece::TetrisPiece(Texture& texture, int& color, int correct_x, int correct_y, int& typeNext) :
    m_type{ typeNext }, m_sprites_cords(4),
    m_sprites(4), m_correction_x{ correct_x },
    m_color{ color }, m_correction_y{ correct_y }
{
    this->m_tetratype = {
        { 1, 3, 5, 7 },  // I
        { 2, 4, 5, 7 },  // S
        { 3, 5, 4, 6 },  // Z
        { 3, 5, 4, 7 },  // T
        { 2, 3, 5, 7 },  // L
        { 3, 5, 7, 6 },  // J
        { 2, 3, 4, 5 }   // O
    };

    for (int i = 0; i < m_sprites_cords.size(); ++i)
    {
        m_sprites_cords[i].x = m_tetratype[m_type][i] % 2;
        m_sprites_cords[i].y = m_tetratype[m_type][i] / 2;
        m_sprites[i].setTexture(texture);
        m_sprites[i].setTextureRect(IntRect(color * 18, 0, 18, 18));;
        spriteCordCalculation(i);
    }
}

void TetrisPiece::setSpritesCords(vector<Point>& arr)
{
    m_sprites_cords = arr;
    for (int i = 0; i < m_sprites.size(); i++)
    {
        spriteCordCalculation(i);
    }
}

void TetrisPiece::moveRight()
{
    for (int i = 0; i < m_sprites.size(); i++)
    {
        m_sprites_cords[i].x += 1;
        spriteCordCalculation(i);
    }
}

void TetrisPiece::moveLeft()
{
    for (int i = 0; i < m_sprites.size(); i++)
    {
        m_sprites_cords[i].x -= 1;
        spriteCordCalculation(i);
    } 
}

void TetrisPiece::makeRotation()
{
    Point center = m_sprites_cords[2]; 
    for (int i = 0; i < m_sprites_cords.size(); i++)
    {
        int x = m_sprites_cords[i].y - center.y; // y - y0
        int y = m_sprites_cords[i].x - center.x; // x - x0
        m_sprites_cords[i].x = center.x - x;
        m_sprites_cords[i].y = center.y + y;
        spriteCordCalculation(i);
    }
}

void TetrisPiece::spriteCordCalculation(int sprite_index)
{
    m_sprites.at(sprite_index).setPosition(m_correction_x + m_sprites_cords.at(sprite_index).x * 18, m_correction_y + m_sprites_cords.at(sprite_index).y * 18);
}


void DrawCoordinatesTetramino(TetrisPiece& tetramino)
{
    cout << "DrawCoordinatesTetramino\n";

    vector<Point> sprite_cords = tetramino.getSpritesCords();
    for (int i = 0; i < sprite_cords.size(); i++)
    {
        cout << "Sprite " << i << " coordinates: x = " << sprite_cords[i].x << ", y = " << sprite_cords[i].y << endl;
    }
}

void TetrisPiece::drawTetramino(WindowGame& window, TetrisPiece& tetramino)
{
 vector <Sprite > temp_sprites{ tetramino.getSprites() };
    if (!temp_sprites.empty())
    {
        for (int i = 0; i < m_sprites.size(); i++)
        {
            window.Draw(temp_sprites.at(i));
        }
    }
}


