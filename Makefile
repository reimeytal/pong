COMPILER = g++
EXECUTABLE_NAME = pong.exe
FLAGS = -DGLEW_STATIC
INCLUDE_PATH = -I../include/ -Iinclude/
LIBPATH = -L../lib/
LIBRARIES = -lglfw3 -lglew32 -lgdi32 -lopengl32

main: main.cpp paddle.o entity.o ball.o shader.o bounding-box.o src/vertex.h
	${COMPILER} -o ${EXECUTABLE_NAME} main.cpp *.o -static-libstdc++ ${INCLUDE_PATH} ${FLAGS} ${LIBPATH} ${LIBRARIES}

paddle.o: src/vertex.h src/paddle/paddle.cpp src/paddle/paddle.hpp entity.o
	${COMPILER} -c src/paddle/paddle.cpp ${INCLUDE_PATH} ${FLAGS}

ball.o: src/vertex.h src/ball/ball.cpp src/ball/ball.hpp entity.o
	${COMPILER} -c src/ball/ball.cpp ${INCLUDE_PATH} ${FLAGS}

entity.o: src/entity/entity.hpp src/entity/entity.cpp bounding-box.o
	${COMPILER} -c src/entity/entity.cpp ${INCLUDE_PATH} ${FLAGS}

shader.o: src/shader/shader.hpp src/shader/shader.cpp
	${COMPILER} -c src/shader/shader.cpp ${INCLUDE_PATH} ${FLAGS}

bounding-box.o: src/bounding-box/bounding-box.hpp src/bounding-box/bounding-box.cpp
	${COMPILER} -c src/bounding-box/bounding-box.cpp ${INCLUDE_PATH} ${FLAGS}

clean:
	del *.o
