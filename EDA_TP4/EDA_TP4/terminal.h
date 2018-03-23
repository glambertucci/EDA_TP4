#pragma once

void print_terminal(int id, const char * msg);
//recibe un identificador de donde se imprime, y que imprimir USA UN ENUM
enum{EVENT_IN,LAST_EVENT,ACTION, STATE};