all: dijkstra_parallel dijkstra_serial

dijkstra_parallel: src/dijkstra_omp.c #run parallel
	gcc -g -o MAIN_PARALLEL src/dijkstra_omp.c -fopenmp

dijkstra_serial: src/serial.c #run serial
	gcc -g -o MAIN_SERIAL src/serial.c -fopenmp
