#define NE -1

struct Usuario{
    char user[15];
    char pass[9];
    int saldoTotal;
};

struct Categoria
{
    int id;
    char nombre[30];
    int saldo;
};

struct Fecha
{
    int day;
    int month;
    int year;
};


struct Gasto
{
    int cat1;
    int cat2;
    int cat3;
    int cat4; 
    int cat5;
    int idcat;
    int idGast;
    char descripcion[400];
    int monto;
    int estado;
    Fecha fecha;
    
};



