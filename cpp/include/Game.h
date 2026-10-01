#pragma once
#include "Score.h"
#include <vector>

class Game {
private:
    static Game* instance;
    std::vector<Score*> scores; // Stores a list of scores

    Game() {} // Private constructor for Singleton

public:
    static Game* getInstance();

    void addScore(Score* score);
    void showScores() const;
    void showScoresByPlayerName(std::string playerName);
    ~Game(); // Destructor to clean up memory
};
