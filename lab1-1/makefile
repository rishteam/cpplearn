CXX=g++
FLAG=-std=c++14
CFLAGS =
INCLUDE=-I.
LIBS=

EXE = main
SOURCES = point.cpp judge.cpp

OBJS = $(addsuffix .o, $(basename $(notdir $(SOURCES))))

%.o:%.cpp
	$(CXX) $(FLAG) $(INCLUDE) $(LIBS) $(CFLAGS) -c -o $@ $<

all: $(EXE)
	@echo Build complete for $(EXE)

$(EXE): $(OBJS)
	$(CXX) $(FLAG) -o $@ $^ $(INCLUDE) $(LIBS) $(CFLAGS)

TESTS=test_set.in test_c.in test_add.in test_ae.in
TEST_OUTS=$(addsuffix .out, $(basename $(notdir $(TESTS))))
test: $(EXE) $(TESTS)
	@echo Testing...
	@./test.sh "$(EXE)"
	@echo All tests passed

.PHONY: clean
clean:
	rm -f $(OBJS) $(TEST_OUTS)