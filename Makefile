CC := gcc
STANDARD := -std=c99
COMPILER_FLAGS := -Wall -Wextra
LINKER_FLAGS := -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
#---------------------------
SRC_DIR := ./src
OBJS_DIR := ./objs
BUILD_DIR := ./build
#---------------------------
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJS_DIR)/%.o)
#---------------------------
INCLUDE_DIR := -I.
LIBRARY_DIR := -L.
#---------------------------
OUTPUT_EXE := pong
#---------------------------
.PHONY: compile_run compile run clean_build clean all all_no_run 
#---------------------------
compile_run: $(BUILD_DIR)/$(OUTPUT_EXE) run

$(BUILD_DIR)/$(OUTPUT_EXE): $(OBJ_FILES)
	@$(CC) $(STANDARD) $(COMPILER_FLAGS) $^ -o $@ $(INCLUDE_DIR) $(LIBRARY_DIR) $(LINKER_FLAGS)

# Compile source files into object files
$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(STANDARD) $(COMPILER_FLAGS) -c $< -o $@ $(INCLUDE_DIR) $(LIBRARY_DIR) $(LINKER_FLAGS)

clean_build:
ifneq ("$(wildcard $(BUILD_DIR)/$(OUTPUT_EXE))", "")
	@rm $(BUILD_DIR)/$(OUTPUT_EXE)
	@echo "[ Make:CLEAN BUILD ] $(OUTPUT_EXE) removed."
endif

run:
	@echo -e "[ Make:RUN ] ...\n"
	@$(BUILD_DIR)/$(OUTPUT_EXE)
	@echo -e "\n[ Make:RUN ] complete."

compile: $(OBJ_FILES)
	@$(CC) $(STANDARD) $(COMPILER_FLAGS) $^ -o $(BUILD_DIR)/$(OUTPUT_EXE) $(INCLUDE_DIR) $(LIBRARY_DIR) $(LINKER_FLAGS)
	@echo "[ Make:COMPILE ] complete."

clean: clean_build
ifneq ("$(wildcard $(OBJS_DIR)/*.o)", "")
	@rm $(OBJS_DIR)/*.o
	@echo "[ Make:CLEAN ] Objects removed."
	@echo "[ Make:CLEAN ] complete."
endif

all: clean compile run
all_no_run: clean compile

