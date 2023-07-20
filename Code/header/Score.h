#pragma once
#include <string>
#include"TextGame.h"
#include"WindowGame.h"
class Score
{
public:
	Score();
	void AddLines(int lines);
	void AddPoints(int points);
	int Value() const;
	void Reset();
	void DrawScores(WindowGame* window);
	void SetString();
	std::string ToString() const;
private:
	int value = 0;
	TextGame textValue;
};

bool operator==(const Score& score1, const Score& score2);
bool operator>(const Score& score1, const Score& score2);
