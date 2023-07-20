#include "header//TextGame.h" 

TextGame::TextGame()
{
	SetFontGame();
}
void TextGame::SetSize(int Size) { m_text.setCharacterSize(Size); }

void TextGame::SetString(const std::string& str) {

	SetText();
	m_text.setString(str);
}
void TextGame::SetString(const wchar_t& str) {

	SetText();
	m_text.setString(str);
}

void TextGame::SetTextPosition(int x, int y)
{
	m_text.setPosition(x, y);
}

void TextGame::PrintText(WindowGame* window)
{
	window->Draw(m_text);
}
void TextGame::SetText()
{
	m_text.setFont(m_font);
	m_text.setCharacterSize(40);
	m_text.setStyle(sf::Text::Bold | sf::Text::Italic);
	//m_text.setFillColor(sf::Color::White);             
	SetColor(Color::Green, Color::Black);
}
void TextGame::SetFontGame()
{
	 
	m_font.loadFromFile("C://Users//wladu//OneDrive//Робочий стіл//TetrisMyGame//TetrisMyGame//Resource//Fonts//fontMainGame.otf");
}
void TextGame::SetColor(sf::Color  color, sf::Color  borderColor)
{
	m_text.setFillColor(color);
	m_text.setOutlineColor(borderColor);
	m_text.setOutlineThickness(3.f);
}
