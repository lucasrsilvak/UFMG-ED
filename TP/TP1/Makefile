CC=gcc
CFLAGS=-Wall -g
BIN=./bin
SRC=./src
INCLUDE=./include

# Default target
all: $(BIN)/main.out test_sequential

# Compiling the main program
$(BIN)/main.out: $(SRC)/main.c
	@mkdir -p $(BIN)
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ $^ -lm

# Running sequential tests from 10 to 5000
.PHONY: test_sequential
test_sequential:
	@echo "Running sequential tests..."
	@for n in $$(seq 0 50 10000); do \
		$(BIN)/main.out insertion $$n; \
	done

# Cleaning up binaries
.PHONY: clean
clean:
	@echo "Cleaning up..."
	@rm -rf $(BIN)/*