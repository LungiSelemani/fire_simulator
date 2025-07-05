CC = gcc
CFLAGS = -Wall -Wextra -fopenmp -Iinclude
SRC_DIR = src
OBJ_DIR = obj
BIN = fire_simulator

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: $(BIN)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
    @mkdir -p $(OBJ_DIR)
    $(CC) $(CFLAGS) -c $< -o $@

$(BIN): $(OBJ)
    $(CC) $(CFLAGS) $(OBJ) -o $@

clean:
    rm -rf $(OBJ_DIR) $(BIN)

run: $(BIN)
    ./$(BIN)