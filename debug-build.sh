
INCFLAGS=-Iexternal

printf "Building in DEBUG MODE...\n\n"

printf "src/main.c\n"
gcc -c src/main.c -o objs/main.o $INCFLAGS

printf "src/linux_window.c\n"
gcc -c src/linux_window.c -o objs/linux_window.o $INCFLAGS

printf "external/glad/glad.c\n"
gcc -c external/glad/glad.c -o objs/glad.o $INCFLAGS

printf "build/ped_DEBUG\n"
gcc objs/*.o -o build/ped_DEBUG -lX11 -ldl
