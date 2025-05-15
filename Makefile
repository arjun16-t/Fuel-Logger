# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Directories
SRCDIR = src
BUILDDIR = build

# Detect OS and set executable extension
ifeq ($(OS),Windows_NT)
    EXE_EXT = .exe
else
    EXE_EXT =
endif

TARGET = $(BUILDDIR)/FuelLogger$(EXE_EXT)

# Source and object files
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))

# Default target
all: $(TARGET)

# Link object files into the final executable
$(TARGET): $(OBJECTS)
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile each .cpp file to .o file in build/
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(BUILDDIR)

# Run the app
run: all
	./$(TARGET)
