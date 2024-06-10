// File: dtFecha.cpp

#include "../include/dtFecha.h"

// Constructor

DTFecha::DTFecha(int dia, int mes, int anio)
    : dia(dia), mes(mes), anio(anio) {}

// Destructor

DTFecha::~DTFecha() {}

// Getters

int DTFecha::getDia() {
    return this->dia;
}

int DTFecha::getMes() {
    return this->mes;
}

int DTFecha::getAnio() {
    return this->anio;
}

// Setters

void DTFecha::setDia(int dia) {
    this->dia = dia;
}

void DTFecha::setMes(int mes) {
    this->mes = mes;
}

void DTFecha::setAnio(int anio) {
    this->anio = anio;
}
