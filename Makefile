CXX = g++
CXXFLAGS = -std=c++14 -Wall -Iinclude
LDFLAGS = -lgmpxx -lgmp
LDFLAGSTEST = -lgtest -lgtest_main -pthread $(LDFLAGS)

SRCDIR = src
TESTDIR = tests
BINDIR = bin

SRCFILES = $(wildcard $(SRCDIR)/*.cpp)
TESTFILES = $(wildcard $(TESTDIR)/*.cpp)
OBJFILES = $(SRCFILES:$(SRCDIR)/%.cpp=$(BINDIR)/%.o)
TESTOBJFILES = $(TESTFILES:$(TESTDIR)/%.cpp=$(BINDIR)/%.o)

all: squares_counter test

squares_counter: $(OBJFILES)
	$(CXX) $(CXXFLAGS) $^ -o $(BINDIR)/$@ $(LDFLAGS)

test: $(filter-out $(BINDIR)/main.o, $(OBJFILES)) $(TESTOBJFILES)
	$(CXX) $(CXXFLAGS) $^ -o $(BINDIR)/$@ $(LDFLAGSTEST)
	./$(BINDIR)/$@

$(BINDIR)/%.o: $(SRCDIR)/%.cpp | $(BINDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BINDIR)/%.o: $(TESTDIR)/%.cpp | $(BINDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BINDIR):
	mkdir -p $(BINDIR)

clean:
	rm -rf $(BINDIR)
