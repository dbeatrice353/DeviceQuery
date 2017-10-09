
CC  = nvcc
INC = ./include
LIB = ./lib/x64
lib = OpenCL

dq.exe: src/main.c inc/DeviceQuery.o
	$(CC) src/main.c inc/DeviceQuery.o -o dq.exe -L $(LIB) -l $(lib)

inc/DeviceQuery.o: inc/DeviceQuery.c inc/DeviceQuery.h
	$(CC) -c inc/DeviceQuery.c -o inc/DeviceQuery.o -L $(LIB) -l $(lib)
