#include "header//FileManager.h"
#include "header//Score.h"
#include <fstream>
#include <iostream>
#include "header//MenuManager.h"
bool FileManager::ReadTextFromFile(const std::string& filename, std::vector<std::string>& content)
{
	// Відкриття файлу для читання:
	std::ifstream fileStream(filename);

	if (!fileStream.is_open())
	{
		std::cout << "File isn't open\n";
		return false;
	}

	// Очищення попереднього вмісту:
	content.clear();

	// Зчитування нового вмісту з файлу:
	std::string textLine;
	while (std::getline(fileStream, textLine))
	{
		content.push_back(textLine);
	}

	// Закриття файлу:
	fileStream.close();

	return true;
}

bool FileManager::WriteTextInFile(const std::string& filename, const std::vector<std::string>& content)
{
	// Відкриття файлу для запису:
	std::ofstream fileStream(filename);
	if (!fileStream.is_open())
	{
		return false;
	}
	// Запис вмісту в файл:
	for (const std::string& line : content)
	{
		fileStream << line << endl; // Записуємо рядок у файл, додаючи символ нового рядка
	}
	// Закриття файлу:
	fileStream.close();

	return true;
}


bool FileManager::ReadScoreTableFromFile(const std::string& filename, Score scoreTable[], size_t size)
{
	// Open file (in binary mode):
	std::ifstream fileStream(filename, std::ios::binary);

	// There might be no files or the file might be inaccessible. In this case score table is already
	// set by hardcoded values.
	if (!fileStream.is_open())
	{
		return true;
	}

	for (size_t i = 0; i < size; i++)
	{
		int score;

		//// File can have more or less, than 'size' numbers.
		if (!fileStream.read(reinterpret_cast<char*>(&score), sizeof(int)))
		{
			return false;
		}

		scoreTable[i].AddPoints(score);
	
	}
	fileStream.close();

	return true;
}

bool FileManager::WriteScoreTableInFile(const std::string& filename, const Score scoreTable[], size_t size)
{
    // Відкриття файлу:
    std::ofstream fileStream(filename, std::ios::binary);

    if (!fileStream.is_open())
    {
        return false;
    }

    for (size_t i = 0; i < size; i++)
    {
        int score = scoreTable[i].Value();
        fileStream.write(reinterpret_cast<const char*>(&score), sizeof(int));
    }

    fileStream.close();

    return true;
}