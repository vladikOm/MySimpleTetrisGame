#pragma once
#include<iostream>
#include<string>
#include"SFML\Graphics.hpp"
#include <vector>
#include<array>


 
class WindowGame
{
private:
	
	const 	unsigned int widthWindow = 600;      
	const	unsigned int hightWindow = 500;     

	sf::RenderWindow m_window;     
	sf::Vector2u m_windowSize;     
	std::string m_Title;           
	bool m_isFullScreen;           
	bool m_isDone;                 


public:

	WindowGame();     
	~WindowGame();  
	bool IsDone();
	void Destroy();  
	void Create();
	void EndDraw();
	void BeginDraw();   
	bool IsFullScreen(); 
	void Draw(sf::Drawable& d); 
	void SetUp(const sf::Vector2u& size, const  std::string& title); 
	void SetSizeWindow(sf::Vector2u& size, const unsigned int& x, const unsigned int& y); 
	sf::Vector2u GetWindowSize();
	sf::RenderWindow& GetWindowGame();
};
