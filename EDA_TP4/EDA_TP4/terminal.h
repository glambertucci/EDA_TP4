#pragma once

void print_terminal(int id, const char * msg);
//recibe un identificador de donde se imprime, y que imprimir USA UN ENUM

void print_menu(void);

void init_color(void);
void print_no_key();
enum{EVENT_IN,LAST_EVENT,ACTION, STATE};