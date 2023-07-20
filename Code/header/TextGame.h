#pragma once
#include"header//TetrisPiece.h"

using namespace sf;
class TextGame
{
	sf::Font          m_font; 
	sf::Text          m_text;
	void  SetText();
	void  SetFontGame();
public:
	TextGame();
	void SetSize(int Size);
	void SetColor(sf::Color  color, sf::Color  borderColor);
	void SetTextPosition(int x, int y);
	void PrintText(WindowGame* window);
	void SetString(const std::string& str);
	void SetString(const wchar_t& str);
	sf::Text getText() { return m_text; }

};
