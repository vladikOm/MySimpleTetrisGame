#pragma once
#include "MenuGame.h"
#include "Score.h"
#include "FileManager.h"
#include "TextGame.h"

enum class MainMenuItem
{
    PLAY_GAME,      
    OPTION_GAME,    
    ABOUT_GAME,     
    SCORES,
    EXIT_GAME,      
    WAIT            
};

enum class MenuType
{
    MainMenu,
    OptionsMenu,
    BestScoresMenu,
    ConfirmationMenu,
    AboutGameMenu
};

class MenuManager
{
public:
    MenuManager();
    ~MenuManager() = default;

    void HandleInputMenu(GameWindow& currentWindow, bool& isRun);
    void RenderMenu();
    void CreateMainMenu(GameWindow& currentWindow, bool& isRun);
    void CreateScoresMenu();
    void CreateOptionsMenu();
    void CreateConfirmationMenu();
    void CreateAboutGameMenu();

    void CheckScoreBeating();
    void SetScoresOnBestScoresMenu();
    void ReadScoresDataFromFiles();
    void LoadBestScoresFromFile();

    
    MenuType currentMenu = MenuType::MainMenu;

    GameMenu MainMenuGame;
    GameMenu OptionsMenu;
    GameMenu ConfirmationMenu;
    GameMenu ScoresMenuGame;
    GameMenu AboutGameMenu;

  
    static const size_t BEST_SCORES_COUNT = 5;
    Score bestScoresTable[BEST_SCORES_COUNT];  
    Score playerScore;                        
    std::vector<std::string> bestScoresMenuContent;

    std::string bestScoresMenuFilename = "C://Users//wladu//OneDrive//Робочий стіл//TetrisMyGame//TetrisMyGame//Resource//Files//BestScores.txt";
    std::string bestScoresFilename     = "C://Users//wladu//OneDrive//Робочий стіл//TetrisMyGame//TetrisMyGame//Resource//Data//BestScores.bin";

private:

       std::vector<std::string> MainMenuElements   { "Start Game", "Options", "Scores", "About Game", "Exit" };
       std::vector<std::string> OptiosMenuElements { "Delete_Scores", "Back to main menu" }; 
       std::vector<std::string> ConfirmationMenuElements {"\tYES","\tNO" }; 

       std::string background_MainMenu         = "C://Users//wladu//OneDrive//Робочий стіл//TetrisMyGame//TetrisMyGame//Resource//Images//BlackBackground2.jpg";
       std::string background_ScoresMenu       = "C://Users//wladu//OneDrive//Робочий стіл//TetrisMyGame//TetrisMyGame//Resource//Images//BestScores.png";
       std::string background_ConfirmationMenu = "C://Users//wladu//OneDrive//Робочий стіл//TetrisMyGame//TetrisMyGame//Resource//Images//ConfirmationMenu.png";
       std::string background_OptionsMenu      = "C://Users//wladu//OneDrive//Робочий стіл//TetrisMyGame//TetrisMyGame//Resource//Images//OptionsMenu.png";
       std::string background_AboutGameMenu    = "C://Users//wladu//OneDrive//Робочий стіл//TetrisMyGame//TetrisMyGame//Resource//Images//AboutGameMenu.png";

};
