#include"header//WindowGame.h"

WindowGame::WindowGame()   //Constructor Class WindowGame
{

	//��� ������� ��'���� ����� � ��� �������������� ������������ 
	m_isFullScreen = false;      // ������������� ����� ���������
	m_isDone = false;            //³������ ���� 
	//����������� ����� ��� ������������ ������ ����
	SetSizeWindow(m_windowSize, widthWindow, hightWindow);
}

void WindowGame::SetSizeWindow(sf::Vector2u& size, const  unsigned int& x, const unsigned int& y)
{
	m_windowSize.x = x;
	m_windowSize.y = y;
}
// ������� ��� ������������ 
void WindowGame::SetUp(const  sf::Vector2u& size, const  std::string& title)
{
	m_Title = title;      //����� ���� ���
	 //������ ³���
	m_windowSize = size;
	//���������� ����������� ���� 
	Create();

}
WindowGame ::~WindowGame()
{
	Destroy();   //����� ��� �������� ����
}
void WindowGame::Create()   //��������� ������ ��� ����������� ���� 
{
	//sf::Style::Fullscreen : sf::Style::Default
	auto style = sf::Style::Close;    // ������������ ����� ���� ����������(������ �����),��� �� �������������

	m_window.create(sf::VideoMode(m_windowSize.x, m_windowSize.y), m_Title, style);//��������� ���� � �������� �����������
}
void WindowGame::Destroy()
{
	m_window.close();     //�� ������� � ����� Window(SFML) ���� ������� ����
}
void WindowGame::BeginDraw() //����� ���� ���� ���������� ���
{
	m_window.clear();
}
void WindowGame::EndDraw()//����� ���� ����� ���� ����
{
	m_window.display();
}
bool WindowGame::IsDone()//����� ������� ��� ����� �����,c�����, ������� ���� �� �.
{
	return m_window.isOpen();//�� ������� ������� ���������� ��� ��, �� ���� ����.
}
bool WindowGame::IsFullScreen()
{
	return m_isFullScreen;
}
void WindowGame::Draw(sf::Drawable& d)//�������� ����� �� ���� �� ������� � ��� 
{
	m_window.draw(d);
}


sf::RenderWindow& WindowGame::GetWindowGame() //�������� �� ���� 
{//����� ��� � ����������� ��� �������� ������ �� ���� �� ������� ���� �������� *GetWindowGame()
 //����� ����� �� �������� � ������ ��� ���
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
//����� ����� � ���������� �� ���� Vector2u  � ������� �������� ������ ��������� �� �� ��������� ���� �
//����� ����� ������ ���������� �� ��������� ����� �����, ���� ���� �� ��������� �� �� ��������,
// �� ������ �� ����� �������

