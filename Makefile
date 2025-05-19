# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

# Source files
SRCS = $(SRC_DIR)/main.cpp \
       $(SRC_DIR)/Logger.cpp \
       $(SRC_DIR)/Utils.cpp

# Output binary
TARGET = $(BUILD_DIR)/fuel_logger

# Object files
OBJS = $(SRCS:.cpp=.o)

# Build rules
all: $(TARGET)

$(TARGET): $(SRCS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) $(SRCS) -o $(TARGET)

clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET)

.PHONY: all clean
