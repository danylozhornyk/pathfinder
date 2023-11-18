CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

OBJECT_DIR = obj
SOURCE_DIR = src
LIBMIX_DIR = libmx
LIBRARY_NAME = $(LIBMIX_DIR)/libmx.a
LIBRARY = $(LIBRARY_NAME)
PATHFINDER = pathfinder

MKDIR = mkdir -p
RM = rm -rf

SOURCE_FILES = $(wildcard $(SOURCE_DIR)/*.c)
OBJECT_FILES = $(patsubst $(SOURCE_DIR)/%.c, $(OBJECT_DIR)/%.o, $(SOURCE_FILES))

.PHONY: all uninstall clean reinstall

all: $(LIBRARY) $(PATHFINDER)

$(PATHFINDER): $(OBJECT_FILES)
	$(CC) $(CFLAGS) -o $@ $^ -L $(LIBMIX_DIR) -lmx

$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.c | $(OBJECT_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJECT_DIR):
	$(MKDIR) $@

$(LIBRARY):
	$(MAKE) -C $(LIBMIX_DIR)

clean:
	# Remove object files
	$(RM) $(OBJECT_FILES)
	# Remove the object directory and its contents
	$(RM) $(OBJECT_DIR)

uninstall:
	# Call uninstall target in the libmx directory
	$(MAKE) -C $(LIBMIX_DIR) $@
	# Clean up object files and the object directory
	$(MAKE) clean
	# Remove the pathfinder binary
	$(RM) $(PATHFINDER)

reinstall: uninstall all