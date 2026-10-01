#include "Game.h"
#include "Protagonist.h"
#include "Student.h"
#include "GoodBehaviourState.h"
#include "BadBehaviourState.h"

int main() {
    Game* game = Game::getInstance();
    Score score1 = Score("Matthieu");
    Score score2 = Score("Sara");
    Score score3 = Score("Matthieu");
    Score score4 = Score("Matthieu");
    Score score5 = Score("Pierre");
    Score score6 = Score("Pierre");

    score1.addPoints(5);
    score2.addPoints(13);
    score3.addPoints(10);
    score4.addPoints(7);
    score5.addPoints(15);
    score6.addPoints(1);

    printf("Add Matthieu, Sara and Pierre scores ----------------------------------\n");
    game->addScore(&score1);
    game->addScore(&score2);
    game->addScore(&score3);
    game->addScore(&score4);
    game->addScore(&score5);
    game->addScore(&score6);
    printf("Add Matthieu, Sara and Pierre scores ----------------------------------\n");
    
    printf("Showing score for player Matthieu ----------------------------------\n");
    game->showScoresByPlayerName("Matthieu");
    printf("Showing score for player Matthieu ----------------------------------\n");

    printf("Showing score for player Sara ----------------------------------\n");
    game->showScoresByPlayerName("Sara");
    printf("Showing score for player Sara ----------------------------------\n");

    printf("Showing all scores ----------------------------------\n");
    game->showScores();
    printf("Showing all scores ----------------------------------\n");
    
    Student student("John");
    Protagonist protagonist("Teacher");

    printf("Initializing state for student John ------\n");
    student.initState();
    
    return 0;
}
