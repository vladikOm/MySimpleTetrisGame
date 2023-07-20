#include "header//Game.h"
#include "header//Random.h"
void DrawCoordinatesTetramino(TetrisPiece& piece);


void Game::HandleInput()
{
	switch (currentGameWindow)
	{
	case GameWindow::Menu: 
		menuGame.HandleInputMenu(currentGameWindow, isRunning);
	break;

	case GameWindow::GameScene:
		CreateGame();
	break;
	}

}


void Game::LoadBestScoresFromFile()
{
	if (!FileManager::ReadTextFromFile(menuGame.bestScoresMenuFilename, menuGame.bestScoresMenuContent))
	{
		cout << "Error ReadFromFille\n";
	}

	if (!FileManager::ReadScoreTableFromFile(menuGame.bestScoresFilename ,menuGame.bestScoresTable, menuGame.BEST_SCORES_COUNT))
	{
		cout << "Error ReadFromFilleTable\n";
	}

	SetTextsGame();
}

bool Game::IsRunning() const
{
	return isRunning;
}

Game::Game() : fieldGame(new FieldGame()), currentGameWindow(GameWindow::Menu)
{
    LoadBestScoresFromFile();
	menuGame.SetScoresOnBestScoresMenu();
}

Game::~Game()
{
	delete fieldGame;
}

void Game::creatNextPiece(const TetrisPiece& next_piece)
{
	this->ColorFigure = Random::GenerateInt(0, 7);
	this->TypeFigure = Random::GenerateInt(0, 6);
	this->nextPiece = TetrisPiece(t_Cubik, ColorFigure, 72, 315, TypeFigure);
}




void Game::CreateGame()
{
	windowGame.SetUp(windowGame.GetWindowSize(), "TETRIS");
	windowGame.GetWindowGame().setFramerateLimit(60);
	eventInputGame.SetWindowGame(GetWindow());

	while (windowGame.IsDone())
	{
		if (new_tetramino && !game_over)
		{
			fallingFigure = TetrisPiece(t_Cubik, ColorFigure, fieldGame->getPositionField_X() + correctionX_Piece * sizeImage, fieldGame->getPositionField_Y(), TypeFigure);
			creatNextPiece(fallingFigure);
			new_tetramino = false;
			
			
			if (fieldGame->IsGameOver(fallingFigure))
		    {
			menuGame.CheckScoreBeating();
			FileManager::WriteScoreTableInFile(menuGame.bestScoresFilename, menuGame.bestScoresTable, 5);
			game_over = true;
			new_tetramino = false;
			return;
		    }
		}

		if (!fieldGame->GoDown(fallingFigure, timer, delay, clock, *this->fieldGame) && !game_over)
		{
			new_tetramino = true;
			//fieldGame->ShowBoardBusy(fieldGame->get_is_FieldSprite());
		}

		HandleInputGameScene();
        fieldGame->CheckField(fallingFigure, good_point);
		fieldGame->SearchAndDelLines(menuGame.playerScore);
		DrawGame();
	}
}


void Game::DrawGame()
{
	windowGame.Draw(background.getSprite());
	fieldGame->drawField(GetWindow());
	nextPiece.drawTetramino(windowGame, nextPiece);
	fallingFigure.drawTetramino(windowGame, fallingFigure);
	menuGame.playerScore.DrawScores(GetWindow());
    textNameGame.PrintText(GetWindow());

	if (game_over)
	{
		textGameOver.PrintText(GetWindow());
	}
	windowGame.EndDraw();
}

WindowGame* Game::GetWindow()
{
	return &windowGame;
}
 
void Game::HandleInputGameScene()
{
	eventInputGame.typeInputKey = TypeInPut::WAIT_KEY;
	eventInputGame.CheckEvent();

	switch (eventInputGame.typeInputKey)
	{
	case TypeInPut::CLOSE:
		currentGameWindow = GameWindow::Menu;
		return;

	case TypeInPut::WAIT_KEY:     delay = 0.3f;
		break;

	case TypeInPut::DOWN_KEY:     delay = 0.05f;
		break;

	case TypeInPut::SPACE:		  fallingFigure.makeRotation();
		break;

	case TypeInPut::LEFT_KEY:	  fallingFigure.moveLeft();
		break;

	case TypeInPut::RIGHT_KEY:	  fallingFigure.moveRight();
		break;

	case TypeInPut::ESC_KEY:	  windowGame.Destroy();
		
		currentGameWindow = GameWindow::Menu; 
		DeleteGameObjects();
		break;
	}
}

void Game::DeleteGameObjects()
{
	isRunning = true;
	game_over = false;
	new_tetramino = true;
	menuGame.playerScore.Reset();
	delete fieldGame;
	fieldGame = new FieldGame();
	fallingFigure = TetrisPiece();
	nextPiece = TetrisPiece(); 
}

void Game::SetTextsGame()
{
	t_Cubik.loadFromFile("C://Users//wladu//OneDrive//Робочий стіл//TetrisMyGame//TetrisMyGame//Resource//Images//tiles.png");
	background.setNamePath("C://Users//wladu//OneDrive//Робочий стіл//TetrisMyGame//TetrisMyGame//Resource//Images//BlackBackground3.jpg");
	background.getSprite().setPosition(0, 0);

	textNameGame.SetString(" Tetris Game ");
	textNameGame.SetTextPosition(200, 0);
	textNameGame.SetSize(60);
	textNameGame.SetColor(sf::Color::Green, sf::Color::Black);

	textGameOver.SetString("GAME\n OVER");
	textGameOver.SetTextPosition(255 + widthField / 4, 70 + heightField * sizeImage / 2 - 50);
	textGameOver.SetSize(60);
	textGameOver.SetColor(sf::Color::Red, sf::Color::Black);
}
