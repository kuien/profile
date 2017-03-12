# Options
ARCH = $(shell uname -s)

ifeq "$(ARCH)" "Darwin"
    LDFLAGS += -coverage
else
    LDFLAGS += -lgcov
endif


# GCC
CXX = g++
CC = gcc

GCOVFLAGS = -fprofile-arcs -ftest-coverage
CFLAGS += -O2 -g3 -Wall -g -ggdb $(GCOVFLAGS)
CPPFLAGS += $(CFLAGS) -std=c++11

# modify frequently
PROGRAM = sum
TEST_APP = sum_test
SRC_OBJS = run.o
TEST_OBJS = sum_test.o
TEST_SRC = $(TEST_OBJS:.o=.cpp)

all: $(SRC_OBJS)
	$(CXX) -o $(PROGRAM) $(LDFLAGS) $(SRC_OBJS)


# Google TEST
gtest_filter ?= *
GTEST_DIR = ../googletest/googletest

INCLUDES =
$(TEST_OBJS) gtest_main.o gtest-all.o : INCLUDES += -I$(GTEST_DIR)/ -I$(GTEST_DIR)/src -I$(GTEST_DIR)/include

gtest-all.o :
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o :
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $(GTEST_DIR)/src/gtest_main.cc

AR = ar
gtest_main.a : gtest_main.o gtest-all.o
	$(AR) -rv $@ $^

%.o: %.cpp
	#$(CXX) $(CPPFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@
	$(CXX) $(CPPFLAGS) $(INCLUDES) -c $< -o $@

lint:
	cppcheck -v --enable=warning *.cpp

format:
	clang-format -style="{BasedOnStyle: Google, IndentWidth: 4}" -i *.cpp

tags:
	-ctags -R --c++-kinds=+p --fields=+ialS --extra=+q
	-cscope -Rbq
	-gtags -i

# Keep gtest_main.a at end, otherwise linker will report undefined symbol error.
$(TEST_APP): $(TEST_OBJS) gtest_main.a
	$(CXX) $^ -o $(TEST_APP) $(LDFLAGS)

test: $(TEST_APP)
	./$(TEST_APP) --gtest_filter=$(gtest_filter)

coverage: test
	@echo
	@echo "==- coverage -=="
	@gcov $(TEST_SRC) | grep -A 1 ".*.cpp"

# it requires DA file
genhtml:
	lcov --capture --directory . --output-file $(PROGRAM).info --test-name $(TEST_APP) --no-external
	genhtml -o $(PROGRAM)HTML $(PROGRAM).info
	open $(PROGRAM)HTML/index.html

clean:
	rm -f *.o *.BAK *.d *.a *.gcov *.gcda *.gcno
	rm -f $(PROGRAM) $(TEST_APP)
