CC = gcc
CXX = g++
CXXFLAGS = -Wall -g
LD = g++
OUTDIR = out
OBJDIR = $(OUTDIR)/obj
BINDIR = $(OUTDIR)/bin
SRCFILES = $(wildcard *.cpp)
TESTS_SRC = tests.cpp

all:
	make $(BINDIR)/program

$(BINDIR)/program: $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCFILES))
	@if [ ! -d $(BINDIR) ]; then \
		mkdir -p $(BINDIR); \
	fi
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/program $^

$(OBJDIR)/%.o: %.cpp
	@if [ ! -d $(OBJDIR) ]; then \
		mkdir -p $(OBJDIR); \
	fi
	$(CXX) -c $(CXXFLAGS) -o $@ $<

run: $(BINDIR)/program $(SRCFILES)
	./$(BINDIR)/program

test:
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/run_tests $(TESTS_SRC) $(filter-out $(OBJDIR)/main.o $(OBJDIR)/tests.o, $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCFILES)))
	./$(BINDIR)/run_tests

clean:
	rm -r $(OUTDIR)
