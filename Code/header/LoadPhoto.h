#pragma once
#include <string>
#include "SFML/Graphics.hpp"

using namespace std;

class LoadPhoto
{
public:

	LoadPhoto() = default;
	// ����������� � ����� ���������� �� ���� ������ ���������� ���� � �������������  

	void setNamePath(const string& NamePath);
	sf::Sprite& getSprite();
	sf::Texture& getTexture();
	//void setTexturePhoto(sf::Sprite&, float  x1, float y1, float x2, float y2);
	//����� ��� ���� ��� ���������� ������� ��� ��������

private:
	string s_NamePath; // ����� � ����� ��� ���� ������������ ���� �� ����� 
	sf::Texture s_NameTexture;//�������� ���� ��� 
	sf::Sprite s_NameSprite;//������ ���� ���;
};

