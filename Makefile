APP_NAME = graphs
LIB_NAME = libgraphs
TEST_NAME = tests

CC = gcc
CFLAGS = -Wall -Werror -I src
LIBS =
DEPSFLAGS = -MMD
TESTFLAGS = -I thirdparty

BIN_DIR = ./bin
SRC_DIR = ./src
OBJ_DIR = ./obj
TEST_DIR = ./test

APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a
TEST_PATH = $(BIN_DIR)/$(TEST_NAME)

APP_SRC = $(wildcard $(SRC_DIR)/$(APP_NAME)/*.c)
APP_OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(APP_SRC))

LIB_SRC =  $(wildcard $(SRC_DIR)/$(LIB_NAME)/*.c)
LIB_OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(LIB_SRC))

TEST_SRC = $(wildcard $(TEST_DIR)/*.c)
TEST_OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(TEST_SRC))

DEPS = $(APP_OBJ:.o=.d) $(LIB_OBJ:.o=.d) $(TEST_OBJ:.o=.d)

.PHONY: all test clean
all: $(APP_PATH)

-include $(DEPS)

# BUILD
$(APP_PATH): $(APP_OBJ) $(LIB_PATH) 
	$(CC) $(CFLAGS) -o $@ $^ -lncursesw

$(LIB_PATH): $(LIB_OBJ)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(DEPSFLAGS) -c -o $@ $< -lncursesw

$(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/%.o: $(SRC_DIR)/$(LIB_NAME)/%.c
	$(CC) $(CFLAGS) $(DEPSFLAGS) -c -o $@ $<

# TEST
test: $(LIB_PATH) $(TEST_PATH)
	$(TEST_PATH)

$(TEST_PATH): $(TEST_OBJ) $(LIB_PATH)
	$(CC) $(TESTFLAGS) $(CFLAGS) $(DEPSFLAGS) -o $@ $^

$(OBJ_DIR)/test/main.o: test/main.c
	$(CC) $(TESTFLAGS) $(CFLAGS) $(DEPSFLAGS) -c -o $@ $<

$(OBJ_DIR)/test/tests.o: test/tests.c
	$(CC) $(TESTFLAGS) $(CFLAGS) $(DEPSFLAGS) -c -o $@ $<

# RUN
run: all
	$(APP_PATH)

# CLEAN
clean:
	$(RM) $(APP_PATH) $(TEST_PATH) $(OBJ_DIR)/*/*/*.[aod] $(OBJ_DIR)/test/*.[aod]