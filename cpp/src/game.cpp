#include "Game.h"
#include <iostream>

Game* Game::instance = nullptr;

Game* Game::getInstance() {
    if (!instance)
        instance = new Game();
    return instance;
}

void Game::addScore(Score* score) {
    scores.push_back(score);
    std::cout << "Added score for " << score->getPlayerName() << std::endl;
}

void Game::showScores() const {
    std::cout << "Current Scores:" << std::endl;
    for (const auto& score : scores) {
        std::cout << score->getPlayerName() << " - " << score->getPoints() << " points" << std::endl;
    }
}

void Game::showScoresByPlayerName(std::string playerName) {
    for (const auto& score : scores) {
        if (score->getPlayerName() == playerName){
            std::cout << score->getPlayerName() << " - " << score->getPoints() << " points" << std::endl;
        }
    }
}

// Destructor to free allocated memory
Game::~Game() {
    for (auto score : scores) {
        delete score;
    }
    scores.clear();
}
