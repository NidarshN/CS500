CXX = g++
FLAGS = -std=c++11

SOURCE = main.cpp trip.cpp
OBJECTS = $(SOURCE:.cpp=.o)
EXECUTABLE = trip_equalizer

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(FLAGS) -o $@ $(OBJECTS)

%.o: %.cpp
	$(CXX) $(FLAGS) -c $<

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
