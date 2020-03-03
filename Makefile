dijkstra_parallel: # run parallel
	gcc -g -Wall -o MAIN_PARALLEL dijkstra_omp.c -fopenmp

dijkstra_serial: # run serial
	gcc serial.c -o MAIN_SERIAL
