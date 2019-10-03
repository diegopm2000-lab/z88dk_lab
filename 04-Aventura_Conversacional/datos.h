typedef struct {
    int id;
    char descripcion[255];
    int direcciones[4];
        // 0 - Norte
        // 1 - Este
        // 2 - Sur
        // 3 - Oeste
} THabitacion;

typedef struct {
	char nombre[35];
	int localizacion;
	int peso;
} TObjeto;