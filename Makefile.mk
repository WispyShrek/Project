CC = gcc
CXX = g++
CXXFLAGS = -Wall -g
LD = g++
OUTDIR = out
OBJDIR = $(OUTDIR)/obj
BINDIR = $(OUTDIR)/bin

# Source files for the main application (all .cpp except tests.cpp)
APP_SRC = $(filter-out tests.cpp, $(wildcard *.cpp))
APP_OBJS = $(patsubst %.cpp,$(OBJDIR)/%.o,$(APP_SRC))

# Source files for the tests (all .cpp except main.cpp)
TEST_SRC = $(filter-out main.cpp, $(wildcard *.cpp))
TEST_OBJS = $(patsubst %.cpp,$(OBJDIR)/%.o,$(TEST_SRC))

all:
	make program

# Target to build the main application executable
program: $(APP_OBJS)
	@if [ ! -d $(BINDIR) ]; then \
		mkdir -p $(BINDIR); \
	fi
	$(LD) $(CXXFLAGS) -o $(BINDIR)/program $^

# Generic rule to compile any .cpp file into an object file
$(OBJDIR)/%.o: %.cpp
	@if [ ! -d $(OBJDIR) ]; then \
		mkdir -p $(OBJDIR); \
	fi
	$(CXX) -c $(CXXFLAGS) -o $@ $<

# Target to run the main application
run: program
	./$(BINDIR)/program

# Target to build and run the test executable
test: $(TEST_OBJS)
	@if [ ! -d $(BINDIR) ]; then \
		mkdir -p $(BINDIR); \
	fi
	$(LD) $(CXXFLAGS) -o $(BINDIR)/run_tests $^
	./$(BINDIR)/run_tests

clean:
	rm -r $(OUTDIR)
