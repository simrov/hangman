APP_NAME = hangman
LIB_NAME = libhangman

CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -Isrc -MP -MMD
LDFLAGS =
LDLIBS = -lm
CC=gcc

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src

APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a

SRC_EXT = c

APP_SOURCES = $(shell find $(SRC_DIR)/$(APP_NAME) -name '*.$(SRC_EXT)')
APP_OBJECTS = $(APP_SOURCES:%.$(SRC_EXT)=$(OBJ_DIR)/%.o)

LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.$(SRC_EXT)')
LIB_OBJECTS = $(LIB_SOURCES:%.$(SRC_EXT)=$(OBJ_DIR)/%.o)

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d)

.PHONY: all
all: $(APP_PATH)

-include $(DEPS)

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/$(SRC_DIR)/$(APP_NAME)/%.o: $(SRC_DIR)/$(APP_NAME)/%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@ $(LDLIBS)

$(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/%.o: $(SRC_DIR)/$(LIB_NAME)/%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@ $(LDLIBS)

.PHONY: clean
clean:
	$(RM) $(APP_PATH) $(LIB_PATH) $(APP_PATH_TEST)
	find $(OBJ_DIR) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name '*.d' -exec $(RM) '{}' \;
