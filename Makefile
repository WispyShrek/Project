CC = gcc
CXX = g++
CXXFLAGS = -Wall -g -pthread
LDFLAGS = -lncurses -lpanel
LD = g++

OUTDIR = out
OBJDIR = $(OUTDIR)/obj
BINDIR = $(OUTDIR)/bin

SRCFILES = $(filter-out testing.cpp, $(wildcard *.cpp))
TESTFILES = $(filter-out main.cpp, $(wildcard *.cpp))

all: $(BINDIR)/program

$(BINDIR)/program: $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCFILES))
	@mkdir -p $(BINDIR)
	$(LD) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

run: $(BINDIR)/program
	./$(BINDIR)/program

test: $(TESTFILES)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -DENABLE_DOCTESTS -o $(BINDIR)/test $(TESTFILES) $(LDFLAGS)
	./$(BINDIR)/test

clean:
	rm -rf $(OUTDIR)