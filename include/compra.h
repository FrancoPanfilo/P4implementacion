//include



class Compra{
public: 
    Compra() = default;
    Compra(DTFecha, int);
    ~Compra() = default;
private:    
    DTFecha fechaCompra;
    int montoFinal;   
};
