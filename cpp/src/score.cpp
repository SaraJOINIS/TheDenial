#include <string>
#include <iostream>
#include <chrono>
#include "Score.h"

/// @brief Adds points to the score.
/// @param amount The amount of points to add.
void Score::addPoints(int amount) {
    points += amount;
    streak++;
    lastActionTime = std::chrono::system_clock::now();
}

/// @brief Removes points from the score.
/// @param amount The amount of points to remove.
void Score::deletePoints(int amount) {
    points = std::max(0, points - amount);
    streak = 0; // Reset streak on point loss
    lastActionTime = std::chrono::system_clock::now();
}

/// @brief Displays the current score details.
void Score::display() const {
    std::cout << "Player: " << playerName << ", Points: " << points
                << ", Streak: " << streak << std::endl;
}

/// @brief Get player's name.
/// @return Player's name as a string.
std::string Score::getPlayerName() const { return playerName; }

/// @brief Get current points.
/// @return The player's points.
int Score::getPoints() const { return points; }

/// @brief Get current streak.
/// @return The player's streak.
int Score::getStreak() const { return streak; }

/// @brief Get last action time.
/// @return Last action time as a chrono time_point.
std::chrono::system_clock::time_point Score::getLastActionTime() const { return lastActionTime; }
