CXX = g++
CXXFLAGS = -Wall -g -lncurses -lpanel -pthread
LD = g++

OUTDIR = out
OBJDIR = $(OUTDIR)/obj
BINDIR = $(OUTDIR)/bin

SRCFILES = $(filter-out testing.cpp, $(wildcard *.cpp))
TESTFILES = $(filter-out main.cpp, $(wildcard *.cpp))

OBJS = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCFILES))

.PHONY: all run test clean

all:
	make $(BINDIR)/program

# Use an order-only prerequisite to create directories before building
$(BINDIR)/program: $(OBJS) | $(BINDIR)
	$(LD) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) -c $(CXXFLAGS) -o $@ $<

# Create directories if they don't exist
$(BINDIR) $(OBJDIR):
	mkdir -p $@

run: $(BINDIR)/program
	./$(BINDIR)/program

test:
	mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -DENABLE_DOCTESTS -o $(BINDIR)/test $(TESTFILES)
	./$(BINDIR)/test

clean:
	rm -rf $(OUTDIR)
