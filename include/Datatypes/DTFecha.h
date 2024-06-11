class DTFecha
{
private:
    int anio;
    int mes;
    int dia;
public:
    DTFecha(int dia, int mes, int anio); 
    ~DTFecha();   
    int getDia() const;
    int getMes() const;
    int getAnio() const;
};