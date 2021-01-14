COMPILER = g++
EXECUTABLE_NAME = pong.exe
FLAGS = -DGLEW_STATIC
INCLUDE_PATH = -I../include/ -Iinclude/
LIBPATH = -L../lib/
LIBRARIES = -static-libstdc++ -static-libgcc -lglfw3 -lglew32 -lgdi32 -lopengl32

main: main.cpp paddle.o entity.o ball.o shader.o player.o bounding-box.o stb_image.o score.o src/vertex.h
	${COMPILER} -o ${EXECUTABLE_NAME} main.cpp *.o ${INCLUDE_PATH} ${FLAGS} ${LIBPATH} ${LIBRARIES}

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

player.o: src/player/player.hpp src/player/player.cpp
	${COMPILER} -c src/player/player.cpp ${INCLUDE_PATH} ${FLAGS}

score.o: src/score/score.hpp src/score/score.cpp
	${COMPILER} -c src/score/score.cpp ${INCLUDE_PATH} ${FLAGS}

stb_image.o: src/stb_image.cpp include/stb_image.h
	${COMPILER} -c src/stb_image.cpp ${INCLUDE_PATH}

clean:
	del *.o
