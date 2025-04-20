#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MEMORY_SIZE 30000
#define COPY_BUFFER_SIZE 256

void parse_and_execute(const char *code);
int match_command(const char *code, int index);
void print_nearby_cells(unsigned char *memory, int pointer);

int main(int argc, char *argv[]) {
    char code[100000] = {0}; 
    srand(time(NULL));
    if (argc == 2) {

        FILE *file = fopen(argv[1], "r");
        if (file == NULL) {
            fprintf(stderr, "Could not open file: %s\n", argv[1]);
            return 1;
        }

        size_t read_size = fread(code, 1, sizeof(code) - 1, file);
        code[read_size] = '\0';
        fclose(file);
    } else {

        printf("Enter your code (Ctrl+D to end input):\n");
        size_t read_size = fread(code, 1, sizeof(code) - 1, stdin);
        code[read_size] = '\0';
    }

    parse_and_execute(code);
    return 0;
}

void parse_and_execute(const char *code) {
    unsigned char memory[MEMORY_SIZE] = {0};
    int pointer = 0;
    int code_len = strlen(code);
    int i = 0;
    int bracket_stack[1000];
    int bracket_top = -1;
    unsigned char copy_buffer[COPY_BUFFER_SIZE];
    int copy_mode = 0;

    while (i < code_len) {
        if (code[i] == '1' && i + 1 < code_len && code[i + 1] == '0' && 
            (i + 2 >= code_len || (code[i + 2] != '1' && code[i + 2] != '0'))) {
            memory[pointer]++;
            i += 2;
        }
        else if (code[i] == '0' && i + 1 < code_len && code[i + 1] == '1' && 
                (i + 2 >= code_len || (code[i + 2] != '1' && code[i + 2] != '0'))) {
            memory[pointer]--;
            i += 2;
        }
        else if (code[i] == '0' && i + 2 < code_len && code[i + 1] == '1' && code[i + 2] == '1' &&
                (i + 3 >= code_len || (code[i + 3] != '1' && code[i + 3] != '0'))) {
            pointer = (pointer + 1) % MEMORY_SIZE;
            i += 3;
        }
        else if (code[i] == '1' && i + 2 < code_len && code[i + 1] == '0' && code[i + 2] == '1' &&
                (i + 3 >= code_len || (code[i + 3] != '1' && code[i + 3] != '0'))) {
            pointer = (pointer - 1 + MEMORY_SIZE) % MEMORY_SIZE;
            i += 3;
        }
        else if (code[i] == '1' && i + 3 < code_len && code[i + 1] == '1' && code[i + 2] == '0' && code[i + 3] == '1' &&
                (i + 4 >= code_len || (code[i + 4] != '1' && code[i + 4] != '0'))) {
            putchar(memory[pointer]);
            fflush(stdout);
            i += 4;
        }
        else if (code[i] == '1' && i + 3 < code_len && code[i + 1] == '1' && code[i + 2] == '1' && code[i + 3] == '1' &&
                (i + 4 >= code_len || (code[i + 4] != '1' && code[i + 4] != '0'))) {
            memory[pointer] = getchar();
            i += 4;
        }
        else if (code[i] == '1' && i + 4 < code_len && code[i + 1] == '0' && code[i + 2] == '1' && 
                code[i + 3] == '1' && code[i + 4] == '1' &&
                (i + 5 >= code_len || (code[i + 5] != '1' && code[i + 5] != '0'))) {
            if (memory[pointer] == 0) {
                int nest_level = 1;
                i += 5;
                while (nest_level > 0 && i < code_len) {
                 if (i + 4 < code_len && code[i] == '0' && code[i+1] == '1' && 
                code[i+2] == '0' && code[i+3] == '0' && code[i+4] == '0') {
                 nest_level--;
                if (nest_level == 0) {
                i += 5;
                break;
                    }
                i += 5;
                 } else if (i + 4 < code_len && code[i] == '1' && code[i+1] == '0' && 
                code[i+2] == '1' && code[i+3] == '1' && code[i+4] == '1') {
                nest_level++;
                i += 5;
                    } else {
                        i++;
                    }
                }
            } else {
                i += 5;
            }
        }
        else if (code[i] == '0' && i + 4 < code_len && code[i + 1] == '1' && code[i + 2] == '0' && 
                code[i + 3] == '0' && code[i + 4] == '0' &&
                (i + 5 >= code_len || (code[i + 5] != '1' && code[i + 5] != '0'))) {
            if (memory[pointer] != 0) {
                int nest_level = 1;
                i -= 1;  
                while (nest_level > 0 && i >= 0) {
                    if (i >= 4 && code[i-4] == '1' && code[i-3] == '0' && 
                        code[i-2] == '1' && code[i-1] == '1' && code[i] == '1') {
                        nest_level--;
            if (nest_level == 0) {
                    i -= 4;
                    break;
                 }
                i -= 5;
            } else if (i >= 4 && code[i-4] == '0' && code[i-3] == '1' && 
                 code[i-2] == '0' && code[i-1] == '0' && code[i] == '0') {
                nest_level++;
             i -= 5;
             } else {
                i--;
             }
            }
            } else {
                i += 5;
            }
        }
        else if (code[i] == '0' && i + 3 < code_len && code[i + 1] == '1' && code[i + 2] == '0' && code[i + 3] == '1' &&
                (i + 4 >= code_len || (code[i + 4] != '1' && code[i + 4] != '0'))) {
            printf("%d", memory[pointer]);
            fflush(stdout);
            i += 4;
        }
        else if (code[i] == '0' && i + 6 < code_len && code[i + 1] == '1' && code[i + 2] == '1' && 
                code[i + 3] == '1' && code[i + 4] == '0' && code[i + 5] == '0' && code[i + 6] == '1' &&
                (i + 7 >= code_len || (code[i + 7] != '1' && code[i + 7] != '0'))) {
            if (copy_mode == 0) {

                copy_buffer[0] = memory[pointer];
                copy_mode = 1;
            } else {

                memory[pointer] = copy_buffer[0];
                copy_mode = 0;
            }
            i += 7;
        }
        else if (code[i] == '1' && i + 24 < code_len && 
                strncmp(&code[i], "1010101011010101110101010", 25) == 0 &&
                (i + 25 >= code_len || (code[i + 25] != '1' && code[i + 25] != '0'))) {
            int num;
            if (scanf("%d", &num) == 1) {
                memory[pointer] = (unsigned char)(num & 0xFF);
            }
            i += 25;
        }
        else if (code[i] == '1' && i + 6 < code_len && code[i + 1] == '1' && code[i + 2] == '1' && 
                code[i + 3] == '1' && code[i + 4] == '1' && code[i + 5] == '0' && code[i + 6] == '0' &&
                (i + 7 >= code_len || (code[i + 7] != '1' && code[i + 7] != '0'))) {
            print_nearby_cells(memory, pointer);
            i += 7;
        }
        else if (code[i] == '1' && i + 7 < code_len && code[i + 1] == '1' && code[i + 2] == '0' && 
                code[i + 3] == '0' && code[i + 4] == '1' && code[i + 5] == '0' && code[i + 6] == '1' && code[i + 7] == '0' &&
                (i + 8 >= code_len || (code[i + 8] != '1' && code[i + 8] != '0'))) {

            printf("Cell %d toggled (Value: %d, Char: '%c')\n", pointer, memory[pointer], memory[pointer]);
            i += 8;
        }
        else if (code[i] == '*') {
            int count = 0;
            while (i < code_len && code[i] == '*') {
                count++;
                i++;
            }

            if (count - 1 < MEMORY_SIZE) {
                memory[pointer] += memory[count - 1];
            }
        }

        else if (code[i] == '-') {
            memory[pointer] = rand() % 256;
            i++;
        }
        else {

            i++;
        }
    }
}
void print_nearby_cells(unsigned char *memory, int pointer) {
    printf("Memory around cell %d: [", pointer);
    for (int i = -2; i <= 2; i++) {
        int idx = (pointer + i + MEMORY_SIZE) % MEMORY_SIZE;
        printf("%d", memory[idx]);
        if (i < 2) printf(", ");
    }
    printf("]\n");
}