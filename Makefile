CC = gcc

INC = -Iinclude -Isrc

CFLAGS = -Wall -Wextra $(INC) -O2
LDFLAGS = -lglfw3 -lglew32 -lopengl32 -lgdi32

# Directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

# Files
TARGET = $(BUILD_DIR)/jumpercable.exe
SOURCES = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/**/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCES))

# Default target
all: $(BUILD_DIR) $(TARGET) mostlyclean

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Link object files
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(LDFLAGS)
	@echo "Build complete: $(TARGET)"

# Compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

# Remove intermediate object files
mostlyclean:
	@rm -rf $(BUILD_DIR)/*.o

# Run the application
run: $(TARGET)
	./$(TARGET)

# Rebuild from scratch
rebuild: clean all

# Shortcut for development
dev: rebuild run

# Shortcut for development testing
test: rebuild run

.PHONY: all clean run rebuild mostlyclean dev test