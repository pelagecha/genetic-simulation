# Compiler and flags
CXX := clang++
CXXFLAGS := -std=c++17 -Wall -DGL_SILENCE_DEPRECATION -I/opt/homebrew/opt/glfw/include

# Libraries and paths
LDFLAGS := -L/opt/homebrew/opt/glfw/lib -lglfw -framework OpenGL

# Target executable
TARGET := my_program

# Source files
SRCS := main.cpp

# Build the executable
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

# Clean up generated files
clean:
	rm -f $(TARGET)
