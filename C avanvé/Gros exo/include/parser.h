#ifndef PARSER_H
#define PARSER_H



#include"class.h"


int parse_student(char* line, Class* promo);
int parse_course_line( char *line, Class *promo);
int parse_grade_line(const char *line, Class *promo);
int load_class(const char* filepath,Class *promo);
#endif