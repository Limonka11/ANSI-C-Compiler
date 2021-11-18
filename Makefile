CPPFLAGS += -std=c++11 -W -Wall -g
CPPFLAGS += -I include -I include/ast -I include/lexer -I include/parser -I include/codegen

# ============================ Main Rules ======================================

bin/c_compiler: obj/lexer/lexer.yy.o obj/parser/parser.tab.o obj/main.o $(addprefix obj/codegen/, $(addsuffix .o, $(basename $(notdir $(wildcard src/codegen/*.cpp)))))| bin-dir
	@g++ -o $@ $^ $(CPPFLAGS)

# ========================== Lexer Rules =======================================

src/lexer/lexer.yy.cpp: src/lexer/lexer.flex | include/parser/parser.tab.hpp
	@flex -o src/lexer/lexer.yy.cpp src/lexer/lexer.flex

obj/lexer/lexer.yy.o: src/lexer/lexer.yy.cpp | lexer-obj-dir
	@g++ -c -o $@ $< $(CPPFLAGS) -w

# ========================== Parser Rules ======================================

src/parser/parser.tab.cpp include/parser/parser.tab.hpp: src/parser/parser.y
	@bison -v -d $< -o src/parser/parser.tab.cpp
	@cp src/parser/parser.tab.hpp include/parser/parser.tab.hpp
	@rm -f src/parser/parser.tab.hpp

obj/parser/parser.tab.o: src/parser/parser.tab.cpp | parser-obj-dir
	@g++ -c -o $@ $< $(CPPFLAGS) -w

# ========================== CPP Rules =========================================

obj/%.o: src/%.cpp | obj-dir
	@g++ -c -o $@ $< $(CPPFLAGS)

obj/lexer/%.o: src/lexer/%.cpp | lexer-obj-dir
	@g++ -c -o $@ $< $(CPPFLAGS)

obj/parser/%.o: src/parser/%.cpp | parser-obj-dir
	@g++ -c -o $@ $< $(CPPFLAGS)

obj/codegen/%.o: src/codegen/%.cpp | codegen-obj-dir
	@g++ -c -o $@ $< $(CPPFLAGS)

# =============================== Folder Rules =================================

bin-dir:
	@mkdir -p bin/

obj-dir:
	@mkdir -p obj/

lexer-obj-dir: obj-dir
	@mkdir -p obj/lexer/

parser-obj-dir: obj-dir
	@mkdir -p obj/parser/

codegen-obj-dir: obj-dir
	@mkdir -p obj/codegen

clean:
	@rm -rf bin/ obj/
	@rm -f include/parser/*.tab.hpp src/lexer/*.yy.cpp src/parser/*.output src/parser/*.tab.cpp
	@rm -rf test/working/