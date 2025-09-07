COMPILER = g++
RMDIR = rm -rdf
RM = rm -f

DEP_FLAGS = -M -MT $@ -MT $(BIN_PATH)/$(*F).o -MP -MF $@

# SE FOR WINDOWS
ifeq ($(OS),Windows_NT)
	INC_PATHS = -I$(INC_PATH)
	LINK_PATH =
	FLAGS = -std=c++11 -Wall -pedantic -Wextra -Wno-unused-parameter -Werror=init-self
	RMDIR = rd /s /q
	RM = del /q
	SDL_PATHS = C:/SDL2
	INC_PATHS += $(addprefix -I,$(SDL_PATHS)/include)
	LINK_PATH = $(addprefix -L,$(SDL_PATHS)/lib)
	LIBS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
	EXEC := $(EXEC).exe
# SE FOR MAC OU LINUX
else
	UNAME_S := $(shell uname -s)
	FLAGS = -std=c++11 -Wall -pedantic -Wextra -Wno-unused-parameter -Werror=init-self

	# SE FOR MAC (COM CAMINHO CORRIGIDO)
	ifeq ($(UNAME_S), Darwin)
		INC_PATHS = -Iinclude -I/opt/homebrew/include
		LINK_PATH = -L/opt/homebrew/lib
		LIBS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
	# SE FOR LINUX
	else
		INC_PATHS = -Iinclude -I/usr/include/SDL2
		LINK_PATH =
		LIBS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm
	endif
endif


DFLAGS = -ggdb -O0 -DDEBUG
RFLAGS = -O3 -mtune=native

INC_PATH = include
SRC_PATH = src
BIN_PATH = bin
DEP_PATH = dep

CPP_FILES = $(wildcard $(SRC_PATH)/*.cpp)
INC_FILES = $(wildcard $(SRC_PATH)/*.hpp)
FILE_NAMES = $(sort $(notdir $(CPP_FILES:.cpp=)) $(notdir $(INC_FILES:.h=)))
DEP_FILES = $(addprefix $(DEP_PATH)/,$(addsuffix .d,$(FILE_NAMES)))
OBJ_FILES = $(addprefix $(BIN_PATH)/,$(notdir $(CPP_FILES:.cpp=.o)))

EXEC = JOGO

.PRECIOUS: $(DEP_FILES)
.PHONY: all release debug clean folders help

all: $(EXEC)

$(EXEC): $(OBJ_FILES)
	$(COMPILER) -o $@ $^ $(LINK_PATH) $(LIBS) $(FLAGS)

$(BIN_PATH)/%.o: $(DEP_PATH)/%.d | folders
	$(COMPILER) $(INC_PATHS) $(addprefix $(SRC_PATH)/,$(notdir $(<:.d=.cpp))) -c $(FLAGS) -o $@

$(DEP_PATH)/%.d: $(SRC_PATH)/%.cpp | folders
	$(COMPILER) $(INC_PATHS) $< $(DEP_FLAGS) $(FLAGS)

clean:
	$(RMDIR) $(DEP_PATH)
	$(RMDIR) $(BIN_PATH)
	$(RM) $(EXEC)

release: FLAGS += $(RFLAGS)
release: $(EXEC)

debug: FLAGS += $(DFLAGS)
debug: $(EXEC)

folders:
ifeq ($(OS), Windows_NT)
	@if NOT exist $(DEP_PATH) (mkdir $(DEP_PATH))
	@if NOT exist $(BIN_PATH) (mkdir $(BIN_PATH))
else
	@mkdir -p $(DEP_PATH)
	@mkdir -p $(BIN_PATH)
endif

help:
	@echo "Comandos:"
	@echo "  make          - Compila o projeto em modo release."
	@echo "  make release  - Compila o projeto em modo release."
	@echo "  make debug    - Compila o projeto em modo debug."
	@echo "  make clean    - Remove os arquivos gerados pela compilação."