
WX_CONFIG := wx-config
WX_CXXFLAGS := $(shell $(WX_CONFIG) --cxxflags)
WX_LIBS := $(shell $(WX_CONFIG) --libs)

APPLICATION := calc
TESTS := simple_calculator_test
TESTS_OBJECTS := $(addsuffix .o,TESTS)
APPLICATION_OBJECTS := app.o calc_ui.o simple_calculator.o
OBJECTS := $(APPLICATION_OBJECTS) catch_amalgamated.o

all: $(APPLICATION) $(TESTS)

$(APPLICATION): $(APPLICATION_OBJECTS)
	$(CXX) -o $@ $(APPLICATION_OBJECTS) $(LDFLAGS) $(WX_LIBS) $(LIBS)

$(OBJECTS): %.o: %.cpp %.hpp
	$(CXX) -c -o $@ $(WX_CXXFLAGS) $(CXXFLAGS) $<

$(TESTS_OBJECTS): %.o: %.cpp
	$(CXX) -c -o $@ $(WX_CXXFLAGS) $(CXXFLAGS) $<

# missing dependency issue
simple_calculator_test: simple_calculator_test.o simple_calculator.o catch_amalgamated.o
	$(CXX) -o $@ $(LDFLAGS) $^ -lpthread



.PHONY: clean
clean:
	find . -name '*~' -o -name '*.o' -o -name $(APPLICATION) -o -name $(TESTS) | xargs rm
