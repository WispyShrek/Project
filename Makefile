CC = gcc
CXX = g++
CXXFLAGS = -Wall -g
LD = g++
OUTDIR = out
OBJDIR = $(OUTDIR)/obj
BINDIR = $(OUTDIR)/bin
SRCFILES = $(filter-out testing.cpp, $(wildcard *.cpp))
TESTFILES = $(filter-out main.cpp, $(wildcard *.cpp))

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
	@if [! -d $(BINDIR) ]; then \
		mkdir -p $(BINDIR);\
	fi
	$(CXX) $(CXXFLAGS) -DENABLE_DOCTESTS -o $(BINDIR)/test $(TESTFILES)
	./$(BINDIR)/test

clean:
	rm -r $(OUTDIR)
