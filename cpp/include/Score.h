#pragma once
#include <iostream>
#include <string>
#include <chrono>

class Score {
private:
    int points;
    int streak;
    std::chrono::system_clock::time_point lastActionTime;
    std::string playerName;

public:
    /// @brief Constructor initializes score attributes.
    /// @param playerName Name of the player
    Score(const std::string& playerName) : points(0), streak(0), lastActionTime(std::chrono::system_clock::now()), playerName(playerName) {}
    
    void addPoints(int amount);
    void deletePoints(int amount);
    void display() const;

    std::string getPlayerName() const;
    int getPoints() const;
    int getStreak() const;
    std::chrono::system_clock::time_point getLastActionTime() const;
};
