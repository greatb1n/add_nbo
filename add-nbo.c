#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <netinet/in.h>


uint32_t readandchange(char* filename){

    FILE* f;
    FILE* f1;
    uint32_t a;
    uint32_t change;
    int size;

    f = fopen(filename, "rb");
    f1 = fopen(filename, "rb");

    if(f1 == NULL || f == NULL){
        printf("unable to open file");
        exit(0);
    }

    fseek(f, 0, SEEK_END); 
    size = ftell(f);
    if(size != 4){
        printf("Invalid file size. Need to be 4byte.\n");
        printf("Your size is :%d", size);
        exit(0);
    }

    fread(&a, sizeof(uint32_t), 1, f1);
    change = ntohl(a);
    fclose(f);
    fclose(f1);
    return change;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("You must have two arguments");
        exit(0);
    }
    uint32_t first = readandchange(argv[1]);
    uint32_t second = readandchange(argv[2]);
    uint32_t result = first + second;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", first, first, second, second, result, result);
    return 0;
}