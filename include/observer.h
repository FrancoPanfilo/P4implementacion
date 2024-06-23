#ifndef OBSERVER_NOTIFICACION_H
#define OBSERVER_NOTIFICACION_H

#include "./Datatypes/DTNotificacion.h"
class ObserverNotificacion
{

public:
	// ObserverNotificacion() = 0;
	// ObserverNotificacion(ObserverNotificacion &&) = default;
	// ObserverNotificacion(const ObserverNotificacion &) = default;
	// ObserverNotificacion &operator=(ObserverNotificacion &&) = default;
	// ObserverNotificacion &operator=(const ObserverNotificacion &) = default;
	virtual ~ObserverNotificacion() {};

	virtual void notificar(DTNotificacion) = 0;

private:
};

#endif // !OBSERVER_NOTIFICACION_H
