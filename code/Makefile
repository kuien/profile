CXX = G++
CPPFLAGS = -O2 -g3 -std=c++11 -Wall -g -ggdb
PROGRAM = test
OBJS = fclose.o

all: $(OBJS)
	$(CXX) -o $(PROGRAM) $(OBJS)

%.o: %.cpp
	$(CXX) -c $(CPPFLAGS) $< -o $@

lint:
	cppcheck -v --enable=warning *.cpp

format:
	clang-format -style="{BasedOnStyle: Google, IndentWidth: 4}" -i *.cpp

tags:
	-ctags -R --c++-kinds=+p --fields=+ialS --extra=+q
	-cscope -Rbq
	-gtags -i

clean:
	rm -f *.o
	rm -f $(PROGRAM)
