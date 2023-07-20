#pragma once
#include "Event.h"
#include<iostream>
#include<string>
struct TextMenuSettings
{
    sf::Font font;
    sf::Color menuTextColor;
    sf::Color chosenTextColor;
    sf::Color borderColor;
    int sizeFont = 50;
    int menuX = 0;
    int menuY = 0;
    int menuStep = 60;
    
};

class GameMenu
{
public:
    GameMenu() = default;
    ~GameMenu() = default;
    bool    selectedItem;
    int     MenuSelectedItem;  
    WindowGame  menuWindow; 
    TextMenuSettings TextMenu;
    sf::Texture textureTextHome;   
    std::vector<sf::Text> sfTextMenu;
    void moveUp();
    void moveDown();
    void RenderMenu();
    void setElementsText(const std::vector<std::string>& ElementsMenu);
    void alignMenu(int posX);
    void SetImageMenu(std::string& pathToFile);
    void setElementsMenu(vector<Text>& STextMenu, vector<string>& ElementsMenu, int X_position, int Y_position, bool selectedItem);
     

private:
    sf::Sprite spriteTextHome;
    std::vector<std::string> ElementsMenu;
 
    void initText(std::vector<sf::Text>& text, int x, int y);
  
};




