#include "header//LoadPhoto.h"

#include<iostream>

void LoadPhoto::setNamePath(const string& NamePath)
{   //������������ ���� 
	this->s_NamePath = NamePath;


	if (s_NameTexture.loadFromFile(s_NamePath) == false)
	{
		cout << "�� ������� ������� ����������\n";
	}
	else
	{
		s_NameTexture.loadFromFile(s_NamePath);
		s_NameSprite.setTexture(s_NameTexture);
	}

}

sf::Sprite& LoadPhoto::getSprite()
{
	return s_NameSprite;
}
sf::Texture& LoadPhoto::getTexture()
{
	return s_NameTexture;
}

//void LoadPhoto::setTexturePhoto(sf::Sprite & sprite , float x1  , float y1, float x2, float y2)
//{
//	
//	sprite.setTextureRect(sf::IntRect(x1,  y1, x2, y2));
//}
//
