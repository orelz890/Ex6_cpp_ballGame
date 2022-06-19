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

run: my_test
	./my_test

test: TestRunner.o my_test $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

$(OBJECT_PATH)/%.o: $(SOURCE_PATH)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

my_test: test.cpp TestRunner.cpp doctest.h sources/Game.cpp sources/my_iterator.cpp sources/Leauge.cpp sources/Schedule.cpp sources/Score.cpp sources/Team.cpp sources/Game.hpp sources/my_iterator.hpp sources/Leauge.hpp sources/Schedule.hpp sources/Score.hpp sources/Team.hpp
	$(CXX) test.cpp TestRunner.cpp sources/Game.cpp sources/my_iterator.cpp sources/Leauge.cpp sources/Schedule.cpp sources/Score.cpp sources/Team.cpp -o my_test

# tidy:
# 	clang-tidy $(SOURCES) $(HEADERS) $(TIDY_FLAGS) --

# valgrind: test
# 	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

clean:
	rm -f $(OBJECTS) *.o test my_test
	rm -f StudentTest*.cpp