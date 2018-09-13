TITLE   	= game
CXX      	= g++
STANDARD 	= -std=c++17
DEBUG    	= -g
INCLUDE  	= -I./include
WFLAGS   	= -Wall -Wextra -O2
CXXFLAGS 	= $(WFLAGS) $(STANDARD) $(INCLUDE) $(DEBUG)
LDFLAGS 	= -lm
SFML_FLAGS      = -ltgui -lsfml-graphics -lsfml-window -lsfml-system
BIN		= build
MAIN		= main.cpp
MAINOBJ 	= $(BIN)/$(MAIN:.cpp=.o)
SRC 		= $(wildcard game/*.cpp)
HEAD 		= $(patsubst game/%.cpp, game/%.hpp, $(SRC))
HEADONLY 	= $(wildcard game/*.hpp)
OBJ 		= $(patsubst game/%.cpp, $(BIN)/%.o, $(SRC))
TARGET 		= $(BIN)/$(TITLE)



.PHONY: clean zip beauty

all: $(BIN) $(TARGET)

$(TARGET): $(OBJ) $(MAINOBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS) $(SFML_FLAGS)

$(MAINOBJ): $(MAIN) $(HEADONLY)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BIN)/%.o: game/%.cpp game/%.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BIN):
	@test ! -d $@ && mkdir $@

clean:
	rm -rf $(BIN)
	rm -f ~*
	rm -f game/*~

zip:
	zip -r $(TITLE).zip ./

beauty:
	clang-format -i -style=Chromium $(SRC) $(HEAD)
