#ifndef OBSERVER_NOTIFICACION_H
#define OBSERVER_NOTIFICACION_H

<<<<<<<< Updated upstream:include/IObserver.h
#ifndef _IOBSERVER_H
#define _IOBSERVER_H

#include "./Datatypes/DTNotificacion.h"

#include <string>

using namespace std;

class IObserver
{
========
#include "datatypes.h"
class ObserverNotificacion {
>>>>>>>> Stashed changes:include/ObserverNotificacion.h
public:
	ObserverNotificacion();
	// ObserverNotificacion(ObserverNotificacion &&) = default;
	// ObserverNotificacion(const ObserverNotificacion &) = default;
	// ObserverNotificacion &operator=(ObserverNotificacion &&) = default;
	// ObserverNotificacion &operator=(const ObserverNotificacion &) = default;
	~ObserverNotificacion();

	virtual void notificar(DTNotificacion) = 0;

private:
	
};

#endif // !OBSERVER_NOTIFICACION_H
