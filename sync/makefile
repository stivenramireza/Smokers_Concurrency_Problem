SRCDIR   := src
BUILDDIR := build
INCLUDE  := include
BINDIR   := bin
LDFLAGS  := -pthread
CXXFLAGS := -pedantic-errors -Wall -Wextra -std=c++11 -I include

all: dirs $(BINDIR)/CreateSemSmokers $(BINDIR)/DeleteSemSmokers $(BINDIR)/Smoker $(BINDIR)/Agent

VPATH := src include build

$(BINDIR)/CreateSemSmokers: CreateSemSmokers.o names.o sync.o isync.o
	$(CXX) -o $@ $(LDFLAGS) $^

$(BUILDDIR)/CreateSemSmokers.o: CreateSemSmokers.cpp names.h sync.h isync.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(BINDIR)/DeleteSemSmokers: DeleteSemSmokers.o names.o sync.o isync.o
	$(CXX) -o $@ $(LDFLAGS) $^

$(BINDIR)/Agent: Agent.o names.o sync.o isync.o
	$(CXX) -o $@ $(LDFLAGS) $^

$(BINDIR)/Smoker: Smoker.o sync.o isync.o
	$(CXX) -o $@ $(LDFLAGS) $^

$(BUILDDIR)/names.o: names.cpp names.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(BUILDDIR)/sync.o: sync.cpp sync.h isync.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(BUILDDIR)/isync.o: isync.cpp isync.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(BUILDDIR)/DeleteSemSmokers.o: DeleteSemSmokers.cpp names.h sync.h isync.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(BUILDDIR)/Smoker.o: Smoker.cpp sync.h isync.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(BUILDDIR)/Agent.o: Agent.cpp names.h sync.h isync.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

.PHONY: clean

clean:
	rm -f $(SRCDIR)/*.cpp~ $(INCLUDE)/*.h~ makefile~
	rm -f -R $(BUILDDIR)
	rm -f -R $(BINDIR)

.PHONY: dirs
dirs:
	@test -d build || mkdir build
	@test -d bin || mkdir bin
