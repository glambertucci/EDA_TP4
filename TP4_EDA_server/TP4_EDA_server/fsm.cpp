#include "fsm.h"

void fsm::run(int ev, void* userData)
{
	((data_t *)userData)->last_ev = ((data_t *)userData)->ev;
	((data_t *)userData)->ev = ev;
	tabla[estado][ev].action(userData);
	estado = tabla[estado][ev].proximoEstado;
}
fsm::fsm()
{
	estado = INIT;
}

