LIBRARY_NAME = libmx.a

SOURCE_DIR = src
OBJECT_DIR = obj
INCLUDE_DIR = inc

SOURCE_FILES = $(wildcard $(SOURCE_DIR)/*.c)
OBJECT_FILES = $(patsubst $(SOURCE_DIR)/%.c,$(OBJECT_DIR)/%.o,$(SOURCE_FILES))

INCLUDE_FILES = $(wildcard $(INCLUDE_DIR)/*.h)

CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -g

AR = ar
AFLAGS = rcs

MKDIR = mkdir -p
RM = rm -rf

.PHONY: all uninstall clean reinstall

all: $(LIBRARY_NAME)

$(LIBRARY_NAME): $(OBJECT_FILES)
	$(AR) $(AFLAGS) $@ $^

$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.c $(INCLUDE_FILES) | $(OBJECT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE_DIR)

$(OBJECT_DIR):
	$(MKDIR) $@

clean:
	$(RM) $(OBJECT_DIR)

uninstall: clean
	$(RM) $(LIBRARY_NAME)

reinstall: uninstall all