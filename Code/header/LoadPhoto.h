#pragma once
#include <string>
#include "SFML/Graphics.hpp"

using namespace std;

class LoadPhoto
{
public:

	LoadPhoto() = default;
	// Конструктор з одним параметром ми йому будемо передавати шлях і встановлювати  

	void setNamePath(const string& NamePath);
	sf::Sprite& getSprite();
	sf::Texture& getTexture();
	//void setTexturePhoto(sf::Sprite&, float  x1, float y1, float x2, float y2);
	//Метод для того чоб встановити позицію для картинки

private:
	string s_NamePath; // Змінна в через яку буде передаватись шлях до файлу 
	sf::Texture s_NameTexture;//Текстура фону гри 
	sf::Sprite s_NameSprite;//Спрайт фону гри;
};

