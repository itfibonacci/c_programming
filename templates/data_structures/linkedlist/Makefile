CC := clang
CFLAGS := -g -Wall -Wextra -Iinclude

SRC_DIR := src
BUILD_DIR := bin

SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))

TARGET := $(BUILD_DIR)/linkedlist

TEST_DIR := tests
TEST_FILES := $(wildcard $(TEST_DIR)/*.c)
TEST_SRC_FILES := $(filter-out src/main.c, $(SRC_FILES))
TEST_TARGET := $(BUILD_DIR)/test_runner

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c include/*.h
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(TEST_TARGET): $(TEST_DIR)/test_runner.c $(TEST_SRC_FILES) $(TEST_FILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: tests
tests: $(TEST_TARGET)

# Rule to run the tests
test: tests
	./bin/test_runner

.PHONY: clean
clean:
	rm $(BUILD_DIR)/*.o $(TARGET) $(TEST_TARGET)
