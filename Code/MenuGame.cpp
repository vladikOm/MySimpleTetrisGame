#include "header//MenuGame.h"
#include "header//Game.h"
void GameMenu::setElementsMenu(vector<Text>& STextMenu, vector<string>& ElementsMenu , int X_position, int Y_position, bool selectItem)
{ 
    if (!TextMenu.font.loadFromFile("C://Users//wladu//OneDrive//Робочий стіл//TetrisMyGame//TetrisMyGame//Resource//Fonts//fontMainGame.otf"))
    {
        cout << "Problems in load font\n";   
    }
   
    STextMenu.clear();
    selectItem == true ? this->TextMenu.chosenTextColor = sf::Color::Yellow : this->TextMenu.chosenTextColor = sf::Color::White;
    this->TextMenu.menuTextColor = sf::Color::White;
    this->TextMenu.borderColor = sf::Color::Black;
    this->ElementsMenu = ElementsMenu;
    this->sfTextMenu.resize(ElementsMenu.size());
    this->sfTextMenu = STextMenu;

    for (int i = 0; i < STextMenu.size(); i++)
    {
        STextMenu[i].setString(ElementsMenu[i]);
    }
    initText(STextMenu, X_position, Y_position);
}
 


void GameMenu::RenderMenu()
{
    menuWindow.Draw(spriteTextHome);

    for (auto& element : sfTextMenu)
    {
        int i = &element - &sfTextMenu[0];
        i == MenuSelectedItem ? sfTextMenu.at(i).setFillColor(TextMenu.chosenTextColor) : sfTextMenu.at(i).setFillColor(TextMenu.menuTextColor);
    
        menuWindow.Draw(sfTextMenu[i]);
    }
    menuWindow.EndDraw();
}

void GameMenu::initText(vector<sf::Text>& text, int x, int y)
{
    for (auto& element : text)
    {
       
        element.setFont(TextMenu.font);
        element.setCharacterSize(TextMenu.sizeFont);
        element.setPosition(x + TextMenu.menuX, y);
        element.setFillColor(TextMenu.menuTextColor);
        element.setOutlineColor(TextMenu.borderColor);
        element.setOutlineThickness(2.f);
    
        y += TextMenu.menuStep;
    }
   
       MenuSelectedItem = 0;
}

void GameMenu::alignMenu(int posX)
{
    for (auto& element : sfTextMenu)
    {
        float nullx = 0.f;

        if (posX == 1)
            nullx = element.getLocalBounds().width;
        else if (posX == 2)
            nullx = element.getLocalBounds().width / 2;

        element.setPosition(element.getPosition().x - nullx, element.getPosition().y);
    }
}

void GameMenu::SetImageMenu(std::string& pathToFile)
{
    
    if (!textureTextHome.loadFromFile(pathToFile))
    {
        cout << "Problems in load texture\n"; 
    }
    spriteTextHome.setTexture(textureTextHome);
    spriteTextHome.setPosition(0, 0);
}

void GameMenu::moveUp()
{
    sfTextMenu[MenuSelectedItem].setFillColor(TextMenu.menuTextColor);
    MenuSelectedItem = (MenuSelectedItem - 1 + ElementsMenu.size()) % ElementsMenu.size();
    sfTextMenu[MenuSelectedItem].setFillColor(TextMenu.chosenTextColor);
}

void GameMenu::moveDown()
{
    sfTextMenu[MenuSelectedItem].setFillColor(TextMenu.menuTextColor);
    MenuSelectedItem = (MenuSelectedItem + 1) % ElementsMenu.size();
    sfTextMenu[MenuSelectedItem].setFillColor(TextMenu.chosenTextColor);
}

//template <typename MenuItemType>
//void GameMenu::moveDown(MenuItemType& item, const MenuItemType& firstItem, const MenuItemType& lastItem)
//{
//    item = (item == firstItem) ? lastItem : static_cast<MenuItemType>(static_cast<int>(item) - 1);
//}
//
//template <typename MenuItemType>
//void ChangeMenuItemDown(MenuItemType& item, const MenuItemType& firstItem, const MenuItemType& lastItem)
//{
//   
//    item = (item == lastItem) ? firstItem : static_cast<MenuItemType>(static_cast<int>(item) + 1);
//}
