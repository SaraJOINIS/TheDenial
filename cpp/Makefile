CC = g++
CFLAGS = -Wall -Wextra -std=c++17 -Iinclude -Iinclude/characters -Iinclude/states
LIBS =
LIB_DIR = lib

SRC_DIR = src
BIN_DIR = bin

SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/Game.cpp $(SRC_DIR)/Score.cpp \
	$(SRC_DIR)/characters/Protagonist.cpp $(SRC_DIR)/characters/Student.cpp \
	$(SRC_DIR)/states/BadBehaviourState.cpp $(SRC_DIR)/states/GoodBehaviourState.cpp $(SRC_DIR)/states/TargettedState.cpp

EXEC = $(BIN_DIR)/main.exe

all: clean build

build: $(BIN_DIR) $(EXEC)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)  # Use "if not exist $(BIN_DIR) mkdir $(BIN_DIR)" on Windows

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC) $(LIBS)

clean:
	del /Q $(BIN_DIR)\*.exe 2>nul || exit 0
