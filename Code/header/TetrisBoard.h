#pragma once
#include "WindowGame.h"
#include"TetrisPiece.h"
#include"Score.h"
#include<array>


using namespace std;
using namespace sf;


const   int heightField = 21;
const   int widthField = 10;
const   int sizeImage = 18;
const   int correctionX_Piece =  widthField / 2 - 1;

class FieldGame
{
public:

    using boll2DArray    = array<array<bool, heightField>, widthField>;
    using Sprite2DVector = vector<vector<Sprite>>;

    FieldGame();
    ~FieldGame() = default;

    void  SearchAndDelLines(Score& Scores);
    void  DeleteLine(int line);
    void  drawField(WindowGame* w);
    bool  IsGameOver(TetrisPiece& tetramino);
    void  ShowBoardBusy(boll2DArray& Board) const;
    void  CheckField(TetrisPiece& figure, vector<Point >& good_points);
    bool  GoDown(TetrisPiece& figure, float& timer, float& delay, Clock& clock, FieldGame& field);
    
    

    boll2DArray   & get_is_FieldSprite() { return is_field_sprite; }
    Sprite2DVector& getPlayField()       { return  playField;      }
    Sprite2DVector& getSpritesOnField()  { return SpritesOnField;  }
    int getPositionField_X()             { return pos_x; }
    int getPositionField_Y()             { return pos_y; }
  
private:
    int pos_x = 250, pos_y = 80;  
    Texture         textureSquare; 
    Sprite2DVector  SpritesOnField;
    Sprite2DVector  playField;
    boll2DArray     is_field_sprite { false };


    void  drawSetFieldSprites(WindowGame* w);
    void SetField(Sprite2DVector& field, Texture& t_BoxField, int posx, int posy);
};

