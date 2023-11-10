
printf "Building in RELEASE MODE...\n\n"

printf "src/main.c\n"
gcc -c -O3 src/main.c -o objs/main.o

# TODO: more optimization options

printf "build/ped\n"
gcc objs/*.o -o build/ped
