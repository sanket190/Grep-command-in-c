#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED


// all functions defination
void init();
int ischar(char var);
void insert_line(int line_no,char *filename);
char *read_line();
struct text* Newnode(int line_no,char *filename);
void line_Numbering(char *filename);
int count_line();
char *strcasestr(const char *str, const char *pattern);
void Case_insensitive_search(char *text);
void Case_sensitive_search(char *text);
void whole_word_search(char *text);
int  count_occurance_match_world_in_line(char *search,int line_no);
int count_occurance_match_world_in_file(char *text);
void print_line_no_of_match(char *text);
void Display_lines_not_match_word(char *text);
void Display_the_line_start_with_word(char *text);
void Display_the_line_End_with_word(char *text);
void Display_filename(char *text,char *filename);
void print_n_line_after_line(char *line,int n);
void print_n_line_before_line(char *line,int n);
void print_n_line_before_and_after_line(char *line,int n);

#endif // FILE_H_INCLUDED
