
#include "header//LoadPhoto.h"
#include "header//TetrisBoard.h"
#include "header//TetrisBoard.h"
#include "header//TextGame.h"
#include"header//MenuGame.h"
#include"header//MenuManager.h"



using namespace sf;
using namespace std;

class Game
{

private:
	MenuManager   menuGame;
	TextGame      textNameGame, textGameOver, TextScore;
	TetrisPiece   fallingFigure;
	TetrisPiece   nextPiece;
	FieldGame*	  fieldGame;
	vector<Point> good_point;
	GameWindow	  currentGameWindow;
	WindowGame    windowGame;

	Clock		  clock;
	float		  timer = 0;
	float         delay = 0.3;

	int   ColorFigure;
	int   TypeFigure;

	bool isRunning = true;
	bool  new_tetramino = true;
	bool  game_over = false;

	Texture       t_Cubik;
	Sprite        s_Cubik;
	LoadPhoto     background;
	EventGame     eventInputGame;
public:
	Game();
	~Game();
	bool IsRunning() const;

	void  CreateGame();
	void  DrawGame();
	void  DrawScores(TextGame& TextScores, int& scores);
	void  SetTextsGame();
	void  addScore(int lines);
	void  creatNextPiece(const TetrisPiece& next_piece);

	void HandleInput();
	void HandleInputGameScene();
	void DeleteGameObjects();
	void LoadBestScoresFromFile();
	MenuManager& GetMenu() { return menuGame; }
	WindowGame* GetWindow();
};

