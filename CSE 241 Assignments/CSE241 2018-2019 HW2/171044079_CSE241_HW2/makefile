171044079_CSE241_HW2: triangle.o rectangle.o circle.o composedShape.o 171044079_main.o
		    g++ -std=c++11 composedShape.o 171044079_main.o triangle.o rectangle.o circle.o -o 171044079_CSE241_HW2
triangle.o: triangle.cpp
		g++ -c -std=c++11 triangle.cpp
rectangle.o: rectangle.cpp
		g++ -c -std=c++11 rectangle.cpp
circle.o: circle.cpp
		g++ -c -std=c++11 circle.cpp
composedShape.o: composedShape.cpp 
		g++ -c -std=c++11 composedShape.cpp 
171044079_main.o: 171044079_main.cpp
		g++ -c -std=c++11 171044079_main.cpp 
clean:
	rm *.o 171044079_CSE241_HW2
