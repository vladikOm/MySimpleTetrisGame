#include "header//Game.h"
#include"header//Tools.h"
#include"header//MenuManager.h"
#include <fstream>
using namespace Tools;

int main()
{
    Tools::SetTools();
    Game g;
    while (g.IsRunning() )
    {
        g.HandleInput();

    }


    return 0;
}
	 
	

