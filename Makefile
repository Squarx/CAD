CXX= g++
CXXFLAGS=  -Wall -Werror -Wextra  -std=c++17 -g -fPIC
GTESTFLAGS = -lgtest -pthread -lstdc++
EXECUTABLE=cad
LDFLAGS=  -shared

ALL_FILES= $(shell find . -name '*.cc' -o -name '*.h')
ALL_FILES_CC= $(shell find . -name '*.cc')
ALL_SOURCES = $(shell find . -mindepth 2 -name '*.cc')
MAIN_SOURCES = $(shell find . -maxdepth 1 -name '*.cc')
OBJECTS= $(patsubst %.cc, %.o, $(ALL_SOURCES))
LIBRARY=libcad.so
LIBNAME=cad
VGRND= CK_FORK=no valgrind --vgdb=no\
				--leak-check=full --show-leak-kinds=all\
				--trace-children=yes --track-origins=yes\
				-v --verbose -q --quiet -s

build: clean
	$(CXX) $(CXXFLAGS) $(ALL_FILES_CC)  -o $(EXECUTABLE)
	./$(EXECUTABLE)

build_dynamic: clean library
	export LD_LIBRARY_PATH=${PWD} && \
	$(CXX) -L. $(MAIN_SOURCES) -l$(LIBNAME) -o $(EXECUTABLE) && \
	./$(EXECUTABLE)

style:
	clang-format --style=Google -i $(ALL_FILES)

check_valgrind: clean
	$(CXX) -g $(CXXFLAGS) $(ALL_FILES_CC) -o $(EXECUTABLE)
	$(VGRND) ./$(EXECUTABLE)


clean:
	rm -rf $(EXECUTABLE)  $(OBJECTS) *.o *.so

library: clean $(OBJECTS)
	$(CXX) -shared  $(OBJECTS) -o $(LIBRARY)



