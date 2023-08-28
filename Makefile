#options = -DDO_TEST

CXX_FLAGS = -D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat=2 -Winline -Wnon-virtual-dtor -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-overflow=2 -Wsuggest-override -Wswitch-default -Wswitch-enum -Wundef -Wunreachable-code -Wunused -Wvariadic-macros -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -fno-omit-frame-pointer -Wlarger-than=8192 -pie -fPIE -Werror=vla -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr

TARGET=main.out

main.out: main.o solution_equation.o test.o input_roots.o print_roots.o
	g++ $(CXX_FLAGS) main.o solution_equation.o test.o input_roots.o print_roots.o -o main.out

main.o: main.cpp Makefile
	g++ $(CXX_FLAGS) $(options) -c main.cpp -o main.o
functions.o: solution_equation.cpp
	g++ $(CXX_FLAGS) -c solution_equation.cpp -o solution_equation.o
test.o: test.cpp
	g++ $(CXX_FLAGS) -c test.cpp -o test.o
input_roots.o: input_roots.cpp
	g++ $(CXX_FLAGS) -c input_roots.cpp -o input_roots.o
print_roots.o: print_roots.cpp
	g++ $(CXX_FLAGS) -c print_roots.cpp -o print_roots.o

.PHONY: doxygen
doxygen:
	@doxygen

all: main.out doxygen

