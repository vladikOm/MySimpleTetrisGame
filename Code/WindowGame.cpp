#include"header//WindowGame.h"

WindowGame::WindowGame()   //Constructor Class WindowGame
{

	//При створені об'єкту класу в нас встановлюються налаштування 
	m_isFullScreen = false;      // Повноекранний режим вимкнений
	m_isDone = false;            //Відкрите вікно 
	//Викликається метод для встановлення розмірів вікна
	SetSizeWindow(m_windowSize, widthWindow, hightWindow);
}

void WindowGame::SetSizeWindow(sf::Vector2u& size, const  unsigned int& x, const unsigned int& y)
{
	m_windowSize.x = x;
	m_windowSize.y = y;
}
// функція для встановлення 
void WindowGame::SetUp(const  sf::Vector2u& size, const  std::string& title)
{
	m_Title = title;      //Назва вікна гри
	 //Розміри Вікна
	m_windowSize = size;
	//Встановити фукнкціонал вікна 
	Create();

}
WindowGame ::~WindowGame()
{
	Destroy();   //Метод для закриття вікна
}
void WindowGame::Create()   //Реалізація методу для функціоналу вікна 
{
	//sf::Style::Fullscreen : sf::Style::Default
	auto style = sf::Style::Close;    // Встановлення стилю вікна розгорнуте(повний екран),або за замовчуванням

	m_window.create(sf::VideoMode(m_windowSize.x, m_windowSize.y), m_Title, style);//Створюємо вікно з заданими параметрами
}
void WindowGame::Destroy()
{
	m_window.close();     //Це функція з класу Window(SFML) вона закриває вікно
}
void WindowGame::BeginDraw() //Метод який задає початковий фон
{
	m_window.clear();
}
void WindowGame::EndDraw()//Метод який малює наше вікно
{
	m_window.display();
}
bool WindowGame::IsDone()//Метод повертає для члена класу,cкажіть, відкрите вікно чи ні.
{
	return m_window.isOpen();//Ця функція повертає інформацію про те, чи існує вікно.
}
bool WindowGame::IsFullScreen()
{
	return m_isFullScreen;
}
void WindowGame::Draw(sf::Drawable& d)//Передаємо силку на вікно що вивести в вікні 
{
	m_window.draw(d);
}


sf::RenderWindow& WindowGame::GetWindowGame() //Вказівник на вікно 
{//Тобто нам в майбутньому щоб получити доступ до вікна це потрібно буде написати *GetWindowGame()
 //Таким чином ми запишемо в нашому вікні дані
	return  m_window;
}




sf::Vector2u WindowGame::GetWindowSize()
{
	return m_windowSize;
}
//sf::RenderWindow& WindowGame::GetWindowGame()
//{
//	return  m_window;
//}
//Даний метод є вказівником на клас Vector2u  і оскільки вказівник зберігає посилання то ми повернемо його і
//таким чином будемо звертатись до закритого члена класу, тому якщо ми розіменуємо то ми отримаємо,
// що лежить за нашою адресою

