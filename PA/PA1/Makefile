# Define compiler
CXX=g++
# Compiler flags
CXXFLAGS=-Wall -Wextra -std=c++17
# Source files
SRC=src/pa1.cpp
# Output executable
OUT=bin/pa1.out

# Default target
all: $(OUT)

# Run tests target
test: $(OUT)
	@./$(OUT) -z 9 -s 27 -a s
	@./$(OUT) -z 9 -s 27 -a i
	@./$(OUT) -z 9 -s 27 -a q
	@./$(OUT) -z 9 -s 27 -a q3
	@./$(OUT) -z 9 -s 27 -a qi
	@./$(OUT) -z 9 -s 27 -a q3i
	@./$(OUT) -z 9 -s 27 -a h
	@./$(OUT) -z 9 -s 27 -a rs
	@./$(OUT) -z 81 -s 17 -a s
	@./$(OUT) -z 81 -s 17 -a i
	@./$(OUT) -z 81 -s 17 -a q
	@./$(OUT) -z 81 -s 17 -a q3
	@./$(OUT) -z 81 -s 17 -a qi
	@./$(OUT) -z 81 -s 17 -a q3i
	@./$(OUT) -z 81 -s 17 -a h
	@./$(OUT) -z 81 -s 17 -a rs
	@./$(OUT) -z 448 -s 15 -a s
	@./$(OUT) -z 448 -s 15 -a i
	@./$(OUT) -z 448 -s 15 -a q
	@./$(OUT) -z 448 -s 15 -a q3
	@./$(OUT) -z 448 -s 15 -a qi
	@./$(OUT) -z 448 -s 15 -a q3i
	@./$(OUT) -z 448 -s 15 -a h
	@./$(OUT) -z 448 -s 15 -a rs
	@./$(OUT) -z 4803 -s 34 -a s
	@./$(OUT) -z 4803 -s 34 -a i
	@./$(OUT) -z 4803 -s 34 -a q
	@./$(OUT) -z 4803 -s 34 -a q3
	@./$(OUT) -z 4803 -s 34 -a qi
	@./$(OUT) -z 4803 -s 34 -a q3i
	@./$(OUT) -z 4803 -s 34 -a h
	@./$(OUT) -z 4803 -s 34 -a rs
	@./$(OUT) -z 19097 -s 25 -a s
	@./$(OUT) -z 19097 -s 25 -a i
	@./$(OUT) -z 19097 -s 25 -a q
	@./$(OUT) -z 19097 -s 25 -a q3
	@./$(OUT) -z 19097 -s 25 -a qi
	@./$(OUT) -z 19097 -s 25 -a q3i
	@./$(OUT) -z 19097 -s 25 -a h
	@./$(OUT) -z 19097 -s 25 -a rs

# Rule to create the executable
$(OUT): $(SRC)
	@mkdir -p bin  # Ensure the bin directory exists
	$(CXX) $(CXXFLAGS) $< -o $@

# Clean rule to delete the compiled files
clean:
	rm -rf bin/*
