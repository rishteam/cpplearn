CXX=g++
FLAG=-std=c++14
CFLAGS =
INCLUDE=-I.
LIBS=

EXE = main
SOURCES = intpair.cpp judge.cpp

OBJS = $(addsuffix .o, $(basename $(notdir $(SOURCES))))

%.o:%.cpp
	$(CXX) $(FLAG) $(INCLUDE) $(LIBS) $(CFLAGS) -c -o $@ $<

all: $(EXE)
	@echo Build complete for $(EXE)

$(EXE): $(OBJS)
	$(CXX) $(FLAG) -o $@ $^ $(INCLUDE) $(LIBS) $(CFLAGS)

test: test.sh test.in $(EXE)
	@echo Testing...
	@./test.sh "$(EXE)"

.PHONY: clean
clean:
	rm -f $(OBJS) p.out