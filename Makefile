CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude -g 
LDFLAGS = -lgtest -lgtest_main -pthread
SRCDIR = src
INCDIR = include
TESTDIR = test
BUILDDIR = build
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
HEADERS = $(wildcard $(INCDIR)/*.h)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))
TEST_SOURCES = $(wildcard $(TESTDIR)/*_test.cpp)
TEST_OBJECTS = $(patsubst $(TESTDIR)/%.cpp,$(BUILDDIR)/%.o,$(TEST_SOURCES))
TARGET = card_game
TEST_TARGET = card_game_tests

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS)
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(OBJECTS) $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(OBJECTS) $(TEST_OBJECTS) $(LDFLAGS)

$(BUILDDIR)/%_test.o: $(TESTDIR)/%_test.cpp $(HEADERS)
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILDDIR) $(TARGET) $(TEST_TARGET)
