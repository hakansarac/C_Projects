#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct instruction_s{ int step, index; };

char * get_word(char *s, int n);

void get_sentence(char **lines, struct instruction_s *instructions, int n_instructions, char *sentence);

const int MAX_BOOK_LINES = 10000;
const int MAX_LINE_LEN = 200;
const int MAX_INS = 20;

int main(int argc, char **argv){

	int i, j;

	char *path_book = argv[1];
	char *path_ins = argv[2];

	FILE *r = fopen(path_book, "r");

	char **lines = (char **)malloc(sizeof(char *) * MAX_BOOK_LINES);
    for(i = 0; i < MAX_BOOK_LINES; i++) lines[i] = (char *)malloc(sizeof(char) * MAX_LINE_LEN);

	for(i = 0; !feof(r); i++) fgets(lines[i], MAX_LINE_LEN, r);

    fclose(r);

    int number_of_book_lines = i - 1;

    int dif = 'z' - 'Z';

    for(i = 0; i < number_of_book_lines; i++){
        char *new_line = (char *)malloc(sizeof(char) * MAX_LINE_LEN);
        for(j = 0; j < MAX_LINE_LEN; j++) new_line[j] = '\0';
        int line_counter = 0;
        int is_space = 0;
        for(j = 0; lines[i][j] == ' '; j++);
        for(; lines[i][j] != 10; j++){
            if(lines[i][j] == ' '){
                if(is_space) continue;
                else is_space = 1;
            }
            if( !ispunct(lines[i][j]) ){
                new_line[line_counter] = lines[i][j] < 'a' && lines[i][j] >= 'A' ? lines[i][j] + dif : lines[i][j];
                line_counter++;
                if(lines[i][j] != ' ') is_space = 0;
            }
        }
        new_line[line_counter - 1] = '\0';
        lines[i] = (char *)realloc(lines[i], sizeof(char) * line_counter);
        strcpy(lines[i], new_line);
        free(new_line);
    }

    r = fopen(path_ins, "r");

    struct instruction_s *instructions = (struct instruction_s *)malloc(sizeof(struct instruction_s) * MAX_INS);
    for(i = 0; !feof(r); i++){
        int step, index;
        fscanf(r, "%d %d", &step, &index);
        instructions[i].step = step;
        instructions[i].index = index;
    }
    
    fclose(r);
    
    int number_of_instructions = i - 1;

    char *secret = (char *)malloc(sizeof(char) * MAX_LINE_LEN);
    strcpy(secret, "");
    get_sentence(lines, instructions, number_of_instructions, secret);
    printf("%s\n", secret);
    free(secret);
    free(instructions);
    for(i = 0; i < MAX_BOOK_LINES; i++) free(lines[i]);
    free(lines);

    return 0;
}

char * get_word(char *s, int n){

    int i;
    int curr_word = 0;

    char *word = (char *)malloc(sizeof(char) * MAX_LINE_LEN);
    for(i = 0; i < MAX_LINE_LEN; i++) word[i] = '\0';
    int word_counter = 0;

    for(i = 0; s[i] != '\0'; i++){
        if(s[i] == ' '){
            if(n - 1 == curr_word) break;
            curr_word += 1;
        }
        else if(n - 1 == curr_word){
            word[word_counter] = s[i];
            word_counter += 1;
        }
    }

    return word;

}

void get_sentence(char **lines, struct instruction_s *instructions, int n_instructions, char *sentence){
    int i;
    int counter = 0;

    for(i = 0; i < n_instructions; i++){
        counter += instructions[i].step;
        char *temp = get_word(lines[counter - 1], instructions[i].index);
        
        strcat(sentence, temp);
        if( i != n_instructions - 1 ) strcat(sentence, " ");
        free(temp);
    }
}