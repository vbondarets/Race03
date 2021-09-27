SRC_DIR := src
OBJ_DIR := obj

EXE := way_home
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

DEBUG=#-O0 -g -fsanitize=address
CC=clang
CPPFLAGS=-Iinc -MMD -MP
CFLAGS=-std=c11 -Wall -Wextra -Werror -Wpedantic $(DEBUG)
LDFLAGS=$(DEBUG)

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

uninstall: clean
	@$(RM) -v $(EXE)
clean:
	@$(RM) -rv $(OBJ_DIR)

-include $(OBJ:.o=.d)

reinstall: uninstall all


