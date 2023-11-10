
printf "Building in DEBUG MODE...\n\n"

printf "src/main.c\n"
gcc -c src/main.c -o objs/main.o

printf "build/ped_DEBUG\n"
gcc objs/*.o -o build/ped_DEBUG
