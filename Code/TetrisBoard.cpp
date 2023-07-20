#include "header//TetrisBoard.h"
#include"header//MenuManager.h"
FieldGame::FieldGame() 
{
    this->SpritesOnField = Sprite2DVector(widthField, vector<Sprite>(heightField - 1));
    this->playField = Sprite2DVector(widthField, vector<Sprite>(heightField));
    SetField(SpritesOnField, textureSquare, pos_x, pos_y);

}

void  FieldGame::drawField(WindowGame* w)
{
    drawSetFieldSprites(w);
    for (int i = 0; i < playField.size(); i++)

        for (int j = 0; j < playField.at(i).size(); j++)
        {
            w->Draw(playField.at(i).at(j));
        }
}

void FieldGame::drawSetFieldSprites(WindowGame* w) 
{
    for (int i = 0; i < getSpritesOnField().size(); i++)

        for (int j = 0; j < getSpritesOnField().at(i).size(); j++)
        {
            w->Draw(getSpritesOnField().at(i).at(j));
        }
}


void FieldGame::SetField(Sprite2DVector& field, Texture& textureBoxField, int posx, int posy)
{
    textureBoxField.loadFromFile("C://Users//wladu//OneDrive//Робочий стіл//TetrisMyGame//TetrisMyGame//Resource//Images//fieldBox.png");

  for (int i = 0; i <  field.size(); i++)
    
      for (int j = 0; j < field[i].size(); j++)
      {
      Sprite boxSprite(textureBoxField); 
      boxSprite.setTextureRect(IntRect(0, 0, 18, 18)); 
      boxSprite.setPosition(posx + i * 18, posy + j * 18); 
      field.at(i).at(j) = boxSprite; 
      }
}

bool  FieldGame::IsGameOver(  TetrisPiece& tetramino)
{
    vector<Point> temp  { tetramino.getSpritesCords()};

    for (const auto& row : temp)
    {
        if (is_field_sprite.at(row.x + correctionX_Piece).at(row.y) != false)
            return true;
    }
    return false;
}

void FieldGame::ShowBoardBusy(boll2DArray& fieldGame) const
{
    cout << "ShowBoardBusy()" << endl;
   for (int i = 0; i < fieldGame.at(0).size(); i++)
    {
        for (int j = 0; j < fieldGame.size(); j++)
        {
            cout << "  " << fieldGame.at(j).at(i);
        }
        cout << endl;
    }
}

 

void FieldGame::CheckField(TetrisPiece& figure, vector<Point>& good_points)
{
    vector<Point> temp = figure.getSpritesCords();

    int count = count_if(temp.begin(), temp.end(), [this](const Point& p) 
        {
        return p.x < widthField - correctionX_Piece && p.x >= 0 - correctionX_Piece && p.y < heightField - 1 
            &&!is_field_sprite[p.x + correctionX_Piece][p.y + 1];
        });

    if (count == 4)      
         good_points = temp;
    else
         figure.setSpritesCords(good_points);
}


void FieldGame::SearchAndDelLines(Score& Scores)
{
    int addDeleteLines = 0;  
    int count = 0;

    for (int y = 1; y < get_is_FieldSprite().at(0).size(); y++)
    {
        count = 0;  

        for (int x = 0; x < get_is_FieldSprite().size(); x++)
        {
            if (!get_is_FieldSprite().at(x).at(y))
                break;
            else
                count++;
        }

         
        if (count == get_is_FieldSprite().size())
        {
            DeleteLine(y);
            addDeleteLines++;
        }
    }

    Scores.AddLines(addDeleteLines);
}

void FieldGame::DeleteLine(int line)
{
    for (int y = line; y > 0; y--)
    {
        for (int x = 0; x < get_is_FieldSprite().size(); x++)
        {
            get_is_FieldSprite().at(x).at(y) = get_is_FieldSprite().at(x).at(y - 1);
            getPlayField().at(x).at(y) = getPlayField().at(x).at(y - 1);
            getPlayField().at(x).at(y).move(0, 18);
        }
    }

    // Clear rows
    for (int x = 0; x < get_is_FieldSprite().size(); x++)
    {
        get_is_FieldSprite().at(x).at(0) = false;
        getPlayField().at(x).at(0) = { Sprite() };
    }
}

bool FieldGame::GoDown(TetrisPiece& tetramino, float& timer, float& delay, Clock& clock, FieldGame& field)
{
    bool result = true;
    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    timer += time;

    vector<Point> sprites_cords = tetramino.getSpritesCords();
    if (timer > delay)
    {
        for (int i = 0; i < sprites_cords.size(); i++)
        {
            sprites_cords.at(i).y += 1;

            if (sprites_cords.at(i).y == heightField - 1 ||
                (sprites_cords.at(i).y > 0 && field.get_is_FieldSprite().at(sprites_cords.at(i).x + correctionX_Piece).at(sprites_cords.at(i).y + 1)))
            {
                delay = 0.3f;
                result = false;
            }
        }
        if (!result)
            for (int i = 0; i < sprites_cords.size(); i++)
            {
                field.get_is_FieldSprite().at(sprites_cords.at(i).x + correctionX_Piece).at(sprites_cords.at(i).y) = true;
                field.getPlayField().at(sprites_cords.at(i).x + correctionX_Piece).at(sprites_cords.at(i).y) = tetramino.getSprites().at(i);
            }
        timer = 0;
        tetramino.setSpritesCords(sprites_cords);
    }
    return result;
}