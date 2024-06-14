#ifndef OBSERVER_NOTIFICACION_H
#define OBSERVER_NOTIFICACION_H

#include "./Datatypes/DTNotificacion.h"
class ObserverNotificacion
{

public:
	ObserverNotificacion();
	// ObserverNotificacion(ObserverNotificacion &&) = default;
	// ObserverNotificacion(const ObserverNotificacion &) = default;
	// ObserverNotificacion &operator=(ObserverNotificacion &&) = default;
	// ObserverNotificacion &operator=(const ObserverNotificacion &) = default;
	~ObserverNotificacion();

	virtual void notificar(DTNotificacion);

private:
};

#endif // !OBSERVER_NOTIFICACION_H
