// File: Iobserver.h

#ifndef _IOBSERVER_H
#define _IOBSERVER_H

#include "./Datatypes/DTNotificacion.h"

#include <string>

using namespace std;

class Iobserver
{
public:
    virtual void notificar(DTNotificacion notificacion) = 0;
};

#endif //_IOBSERVER_H