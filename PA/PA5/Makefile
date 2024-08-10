EXEC = pa5.out

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INC_DIR = include

CXX = g++
CXXFLAGS = -I$(INC_DIR) -Wall -Wextra -g -std=c++11

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(BIN_DIR)/$(EXEC)

$(BIN_DIR)/$(EXEC): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJECTS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/$(EXEC)

.PHONY: all clean
