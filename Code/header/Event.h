#pragma once
#include "header//TetrisPiece.h"

enum class TypeInPut
{
    UP_KEY,
    DOWN_KEY,
    LEFT_KEY,
    RIGHT_KEY,
    ENTER_KEY,
    ESC_KEY,
    SPACE,
    CLOSE,
    WAIT_KEY
};


enum class GameWindow
{
    Menu,      // Коли в головному меню
    GameScene  // Коли процес гри
};

class EventGame
{
private:
    sf::Event m_Event;

public:
    TypeInPut typeInputKey;
    WindowGame* m_window;

    void SetWindowGame(WindowGame* w);
    void CheckEvent();
    sf::Event GetEvent();

};
