# #!make -f
# # This Makefile can handle any set of cpp and hpp files.
# # To use it, you should put all your cpp and hpp files in the SOURCE_PATH folder.

# CXX=clang++-9
# CXXVERSION=c++2a
# SOURCE_PATH=sources
# OBJECT_PATH=objects
# CXXFLAGS=-std=$(CXXVERSION) -Werror -Wsign-conversion -I$(SOURCE_PATH)
# TIDY_FLAGS=-extra-arg=-std=$(CXXVERSION) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=*
# VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

# SOURCES=$(wildcard $(SOURCE_PATH)/*.cpp)
# HEADERS=$(wildcard $(SOURCE_PATH)/*.hpp)
# OBJECTS=$(subst sources/,objects/,$(subst .cpp,.o,$(SOURCES)))

# all: test

# test: test.cpp Game.cpp Game.hpp Leauge.cpp Leauge.hpp Schedule.cpp Schedule.hpp Score.cpp Score.hpp Team.cpp Team.hpp
# 	$(CXX) $(CXXFLAGS) Game.cpp Leauge.cpp Schedule.cpp Score.cpp Team.cpp test.cpp -o test
# 	./test

# tidy:
# 	clang-tidy Game.cpp Game.hpp Leauge.cpp Leauge.hpp Schedule.cpp Schedule.hpp Score.cpp Score.hpp Team.cpp Team.hpp $(HEADERS) $(TIDY_FLAGS) --

# valgrind: test
# 	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

# clean:
# 	rm test

#!make -f
# This Makefile can handle any set of cpp and hpp files.
# To use it, you should put all your cpp and hpp files in the SOURCE_PATH folder.

CXX=clang++-9
CXXVERSION=c++2a
SOURCE_PATH=sources
OBJECT_PATH=objects
CXXFLAGS=-std=$(CXXVERSION) -Werror -Wsign-conversion -I$(SOURCE_PATH)
TIDY_FLAGS=-extra-arg=-std=$(CXXVERSION) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=*
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

SOURCES=$(wildcard $(SOURCE_PATH)/*.cpp)
HEADERS=$(wildcard $(SOURCE_PATH)/*.hpp)
OBJECTS=$(subst sources/,objects/,$(subst .cpp,.o,$(SOURCES)))

run: test

test: TestRunner.o StudentTest1.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

$(OBJECT_PATH)/%.o: $(SOURCE_PATH)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

# Orel Zamler
StudentTest1.cpp: 
	curl https://raw.githubusercontent.com/orelz890/Ex6_cpp_ballGame_a/main/test.cpp > $@

my_test: test.cpp TestRunner.cpp doctest.h sources/Game.cpp sources/my_iterator.cpp sources/Leauge.cpp sources/Schedule.cpp sources/Score.cpp sources/Team.cpp sources/Game.hpp sources/my_iterator.hpp sources/Leauge.hpp sources/Schedule.hpp sources/Score.hpp sources/Team.hpp
	$(CXX) test.cpp TestRunner.cpp sources/Game.cpp sources/my_iterator.cpp sources/Leauge.cpp sources/Schedule.cpp sources/Score.cpp sources/Team.cpp -o my_test

tidy:
	clang-tidy $(SOURCES) $(HEADERS) $(TIDY_FLAGS) --

valgrind: test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

clean:
	rm -f $(OBJECTS) *.o test
	rm -f StudentTest*.cpp