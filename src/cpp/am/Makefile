# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -g

# Source files (automatically detect all .cpp files, except main.cpp)
SOURCES = $(filter-out main.cpp, $(wildcard *.cpp))

# Object files
OBJECTS = $(addprefix build/,$(notdir $(SOURCES:.cpp=.o)))

# Build directory
BUILD_DIR = build

# Executable name
EXECUTABLE = build/main

# Compile
all: $(BUILD_DIR) $(EXECUTABLE) $(BUILD_DIR)/main.o

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(EXECUTABLE): $(OBJECTS) $(BUILD_DIR)/main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the executable
run: $(EXECUTABLE)
	./$(EXECUTABLE)

# Clean up object files and executable
clean:
	rm -rf $(BUILD_DIR)

### Tests
# Path to the test directory
TEST_DIR = test

# Linking with gtest
LDFLAGS = -lgtest -lgtest_main -pthread

# Test executable name
TEST_EXECUTABLE = $(TEST_DIR)/$(BUILD_DIR)/run_tests

# Object files for the tests
TEST_SOURCES = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJECTS = $(addprefix $(TEST_DIR)/$(BUILD_DIR)/,$(notdir $(TEST_SOURCES:.cpp=.o)))

# Compile tests
tests: $(BUILD_DIR) $(OBJECTS) $(TEST_DIR)/$(BUILD_DIR) $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TEST_EXECUTABLE) $(TEST_OBJECTS) $(OBJECTS) $(LDFLAGS)

$(TEST_DIR)/$(BUILD_DIR):
	mkdir -p $(TEST_DIR)/$(BUILD_DIR)

$(TEST_DIR)/$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run tests
run_tests: tests
	./$(TEST_EXECUTABLE)

# Clean up test object files and executable
clean_tests:
	rm -rf $(TEST_DIR)/$(BUILD_DIR) $(TEST_EXECUTABLE)
