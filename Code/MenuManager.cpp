#include "header//MenuManager.h"
MenuManager::MenuManager()
{   }

void MenuManager::CreateMainMenu(GameWindow& currentWindow, bool& isRun)
{
	EventGame  eventInputMenu;
    MainMenuGame.SetImageMenu(background_MainMenu);
	MainMenuGame.setElementsMenu(MainMenuGame.sfTextMenu, MainMenuElements, 330, 80, true);
	MainMenuGame.alignMenu(2);
	MainMenuGame.menuWindow.SetUp(MainMenuGame.menuWindow.GetWindowSize(), "MainMenu");
	MainMenuGame.menuWindow.GetWindowGame().setFramerateLimit(100);
	eventInputMenu.SetWindowGame(&MainMenuGame.menuWindow);

	while (MainMenuGame.menuWindow.IsDone())
	{
		
			eventInputMenu.CheckEvent();

			switch (eventInputMenu.typeInputKey)
			{
			case TypeInPut::ESC_KEY:
				if (currentWindow != GameWindow::Menu)
				{
					MainMenuGame.menuWindow.Destroy();
				}
				break;

			case TypeInPut::DOWN_KEY:
				MainMenuGame.moveDown();
				break;

			case TypeInPut::UP_KEY:
				MainMenuGame.moveUp();
				break;

			case TypeInPut::ENTER_KEY:

				switch (MainMenuGame.MenuSelectedItem)
				{
				case 0: // Start
					MainMenuGame.menuWindow.Destroy();
					currentWindow = GameWindow::GameScene;
					break;

				case 1: // Options
					currentMenu = MenuType::OptionsMenu;
					MainMenuGame.menuWindow.Destroy();
					OptionsMenu.SetImageMenu(background_OptionsMenu);
					OptionsMenu.setElementsMenu(OptionsMenu.sfTextMenu, OptiosMenuElements, 330, 200, true);
					OptionsMenu.alignMenu(2);
					break;

				case 2: // Scores
					currentMenu = MenuType::BestScoresMenu;
					MainMenuGame.menuWindow.Destroy();
					ScoresMenuGame.SetImageMenu(background_ScoresMenu);
					ScoresMenuGame.setElementsMenu(ScoresMenuGame.sfTextMenu, bestScoresMenuContent, 250,50, false);
					ScoresMenuGame.alignMenu(2);

					break;

				case 3: // About

				currentMenu = MenuType::AboutGameMenu;
				MainMenuGame.menuWindow.Destroy();
				AboutGameMenu.SetImageMenu(background_AboutGameMenu);
					break;

				case 4: // Exit
					isRun = false;
					MainMenuGame.menuWindow.Destroy();
					break;
				}
		
				break;
		}
			eventInputMenu.typeInputKey = TypeInPut::WAIT_KEY;
	MainMenuGame.RenderMenu();
	}
	
}


void MenuManager::CreateScoresMenu()
{
	EventGame  eventInputMenu;
	ScoresMenuGame.menuWindow.SetUp(ScoresMenuGame.menuWindow.GetWindowSize(), "ScoresMenu");
	ScoresMenuGame.menuWindow.GetWindowGame().setFramerateLimit(60);
	eventInputMenu.SetWindowGame(&ScoresMenuGame.menuWindow);

	while (ScoresMenuGame.menuWindow.IsDone())
	{
		{
			eventInputMenu.CheckEvent();

			switch (eventInputMenu.typeInputKey)
			{
			case TypeInPut::ESC_KEY:
				currentMenu = MenuType::MainMenu;
				ScoresMenuGame.menuWindow.Destroy();
				break;
			}
		}
		ScoresMenuGame.RenderMenu();
	}
}

void MenuManager::CreateOptionsMenu()
{
	EventGame  eventInputMenu;
	OptionsMenu.menuWindow.SetUp(OptionsMenu.menuWindow.GetWindowSize(), "OptionsMenu");
	OptionsMenu.menuWindow.GetWindowGame().setFramerateLimit(60);
	eventInputMenu.SetWindowGame(&OptionsMenu.menuWindow);

	while (OptionsMenu.menuWindow.IsDone())
	{
		eventInputMenu.typeInputKey = TypeInPut::WAIT_KEY;
			eventInputMenu.CheckEvent();

			switch (eventInputMenu.typeInputKey)
			{
			case TypeInPut::ESC_KEY:
				currentMenu = MenuType::MainMenu;
				OptionsMenu.menuWindow.Destroy();
				break;

			case TypeInPut::DOWN_KEY:
				OptionsMenu.moveDown();
				break;

			case TypeInPut::UP_KEY:
				OptionsMenu.moveUp();
				break;

			case TypeInPut::ENTER_KEY:
				switch (OptionsMenu.MenuSelectedItem)
				{
				case 0:
					OptionsMenu.menuWindow.Destroy();
					ConfirmationMenu.SetImageMenu(background_ConfirmationMenu);
					ConfirmationMenu.setElementsMenu(ConfirmationMenu.sfTextMenu, ConfirmationMenuElements, 250, 200 , true);
					ConfirmationMenu.alignMenu(2);
					CreateConfirmationMenu();
				case 1:
					OptionsMenu.menuWindow.Destroy();
					currentMenu = MenuType::MainMenu;
					break;
				}
				break;
			}
		OptionsMenu.RenderMenu();
	}
}

void MenuManager::CreateConfirmationMenu()
{
		EventGame  eventInputMenu;
		ConfirmationMenu.menuWindow.SetUp(ConfirmationMenu.menuWindow.GetWindowSize(), "ConfirmationMenu");
		ConfirmationMenu.menuWindow.GetWindowGame().setFramerateLimit(60);
		eventInputMenu.SetWindowGame(&ConfirmationMenu.menuWindow);

		while (ConfirmationMenu.menuWindow.IsDone())
		{
			eventInputMenu.typeInputKey = TypeInPut::WAIT_KEY;
			eventInputMenu.CheckEvent();

			switch (eventInputMenu.typeInputKey)
			{

			case TypeInPut::DOWN_KEY:
				ConfirmationMenu.moveDown();
				break;

			case TypeInPut::UP_KEY:
				ConfirmationMenu.moveUp();
				break;

			case TypeInPut::ENTER_KEY:
				switch (ConfirmationMenu.MenuSelectedItem)
				{
				case 0:
					ConfirmationMenu.menuWindow.Destroy();
					currentMenu = MenuType::OptionsMenu;

					for (size_t i = 0; i < BEST_SCORES_COUNT; i++)
					{
						bestScoresTable[i].Reset();
					}

					SetScoresOnBestScoresMenu();
					FileManager::WriteScoreTableInFile(bestScoresFilename, bestScoresTable, BEST_SCORES_COUNT);
					break;
				case 1:
					ConfirmationMenu.menuWindow.Destroy();
					currentMenu = MenuType::OptionsMenu;
					break;
				}
				break;
			}
			ConfirmationMenu.RenderMenu();
		}
}

void MenuManager::CreateAboutGameMenu()
{
		EventGame  eventInputMenu;
		AboutGameMenu.menuWindow.SetUp(AboutGameMenu.menuWindow.GetWindowSize(), "AboutGame");
		AboutGameMenu.menuWindow.GetWindowGame().setFramerateLimit(60);
		eventInputMenu.SetWindowGame(&AboutGameMenu.menuWindow);

		while (AboutGameMenu.menuWindow.IsDone())
		{
			eventInputMenu.typeInputKey = TypeInPut::WAIT_KEY;
			eventInputMenu.CheckEvent();

			switch (eventInputMenu.typeInputKey)
			{
			case TypeInPut::ESC_KEY:
				AboutGameMenu.menuWindow.Destroy();
				currentMenu = MenuType::MainMenu;
				break;

			}
			AboutGameMenu.RenderMenu();
		}

	 

}

void MenuManager::HandleInputMenu(GameWindow& currentWindow, bool& isRun)
{
		switch (currentMenu)
		{
		case MenuType::MainMenu:
			 
			CreateMainMenu(currentWindow, isRun);
			break;
		case MenuType::OptionsMenu:
			CreateOptionsMenu();
			break;

		case MenuType::BestScoresMenu:
			CreateScoresMenu();
			break;

		case MenuType::ConfirmationMenu:
			CreateConfirmationMenu();
			break;

		case MenuType::AboutGameMenu:
			CreateAboutGameMenu();
			break;
		//default:
		}
}

void MenuManager::CheckScoreBeating()
{
	for (size_t i = 0; i < BEST_SCORES_COUNT; i++)
	{
		if (playerScore > bestScoresTable[i])
		{
			for (size_t j = BEST_SCORES_COUNT - 1; j > i; j--)
			{
				bestScoresTable[j] = bestScoresTable[j - 1];
			}

			bestScoresTable[i] = playerScore;
			SetScoresOnBestScoresMenu(); 
			return;
		}
	}

}

void MenuManager::SetScoresOnBestScoresMenu()
{
	for (size_t i = 0; i < BEST_SCORES_COUNT; i++)
	{	
		std::string scoreString = bestScoresTable[i].ToString();
		size_t scorePosition = bestScoresMenuContent[i].find(std::to_string(i + 1) + ".");
		bestScoresMenuContent[i].erase(scorePosition+3, scoreString.length());
		bestScoresMenuContent[i].insert(scorePosition+3, scoreString);
	} 
}
	 
