#include "header//Score.h"

Score::Score(): value(0)
{   }

void Score::AddLines(int lines)
{
    int x = 0;
    switch (lines)
    {
    case 1:
        x = 100;
        break;
    case 2:
        x = 200;
        break;
    case 3:
        x = 400;
        break;
    case 4:
        x = 800;
        break;
    case 5:
        x = 1600;
        break;
    default:
        x = 0;
    }
   value+= x;
}
void Score::AddPoints(int points)
{
    if (points > 0)
    {
        value += points;
    }
}

int Score::Value() const
{
	return value;
}

void Score::Reset()
{
	value = 0;
}

void Score::DrawScores(WindowGame* window)
{ 
    SetString();
    textValue.PrintText(window);
}

std::string Score::ToString() const
{
    std::string scoreStr;

    if (value >= 100 && value < 1000)
    {
        scoreStr = "0" + std::to_string(value);
    }
    else if (value == 0)
    { 
        scoreStr = "0000"; 
    }

    else 

        scoreStr = std::to_string(value);

    return scoreStr;
}
 
void  Score::SetString()  
{    	textValue.SetString("Score    \n" + std::to_string(value));
        textValue.SetTextPosition(30, 58);
        textValue.SetSize(50);
        textValue.SetColor(Color::Green,Color::Black);
}

bool operator==(const Score& score1, const Score& score2)
{
	return score1.Value() == score2.Value();
}

bool operator>(const Score& score1, const Score& score2)
{
	return score1.Value() > score2.Value();
}
