#include "header//Event.h"

void EventGame::SetWindowGame(WindowGame* w)
{
    typeInputKey = TypeInPut::WAIT_KEY;
    this->m_window = w;

}

void EventGame::CheckEvent()
{
    while (m_window->GetWindowGame().pollEvent(m_Event))
    {
       
        switch (m_Event.type)
        {
        case sf::Event::Closed:
            typeInputKey = TypeInPut::CLOSE;
            break;

        case sf::Event::KeyPressed:

            switch (m_Event.key.code)
            {

            case sf::Keyboard::Escape:
                typeInputKey = TypeInPut::ESC_KEY;
                break;

            case sf::Keyboard::Enter:
                typeInputKey = TypeInPut::ENTER_KEY;

                break;

            case sf::Keyboard::Down:
                typeInputKey = TypeInPut::DOWN_KEY;
                break;

            case sf::Keyboard::Up:
                typeInputKey = TypeInPut::UP_KEY;
                break;

            case sf::Keyboard::Left:
                typeInputKey = TypeInPut::LEFT_KEY;
                break;

            case sf::Keyboard::Right:
                typeInputKey = TypeInPut::RIGHT_KEY;
                break;

            case sf::Keyboard::Space:
                typeInputKey = TypeInPut::SPACE;
                break;
            }
        }
      
    }
}


sf::Event EventGame::GetEvent()
{
    return m_Event;
}

