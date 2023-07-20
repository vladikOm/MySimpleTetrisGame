#pragma once
#include <string>
#include<vector>
class Score;
 

class FileManager
{
public:
	//Ця функція потрібна для прочитання тексту для меню з рекордами 
	static bool ReadTextFromFile(const std::string& filename, std::vector<std::string>& content);

	//Ця функція потрібна для запису тексту для меню з рекордами 
	static bool WriteTextInFile(const std::string& filename, const std::vector<std::string>& content);

	//Ця функція потрібна для (прочитання  рекордів в бінарному режимі ) для меню з рекордами
	static bool ReadScoreTableFromFile(const std::string& filename, Score  scoreTable[], size_t size);

	//Ця функція потрібна для (запису  рекордів в бінарному режимі ) для меню з рекордами
	static bool WriteScoreTableInFile(const std::string& filename, const Score scoreTable[], size_t size);
};
