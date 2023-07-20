#pragma once
#include <string>
#include<vector>
class Score;
 

class FileManager
{
public:
	//�� ������� ������� ��� ���������� ������ ��� ���� � ��������� 
	static bool ReadTextFromFile(const std::string& filename, std::vector<std::string>& content);

	//�� ������� ������� ��� ������ ������ ��� ���� � ��������� 
	static bool WriteTextInFile(const std::string& filename, const std::vector<std::string>& content);

	//�� ������� ������� ��� (����������  ������� � �������� ����� ) ��� ���� � ���������
	static bool ReadScoreTableFromFile(const std::string& filename, Score  scoreTable[], size_t size);

	//�� ������� ������� ��� (������  ������� � �������� ����� ) ��� ���� � ���������
	static bool WriteScoreTableInFile(const std::string& filename, const Score scoreTable[], size_t size);
};
