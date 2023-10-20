# Nombre del archivo fuente y del archivo ejecutable.
SRC_FILE = gauss.cc
TARGET = gauss

# Opciones de compilación y optimización.
CFLAGS = -Wall -fopenmp


# Compilar el programa sin optimizaciones.
no_opt: $(SRC_FILE)
	g++ $(CFLAGS) -O0 $< -o $(TARGET)

# Compilar el programa con optimización estándar.
Est: $(SRC_FILE)
	g++ $(CFLAGS) -O1 $< -o $@

# Compilar el programa con optimización alta.
opt: $(SRC_FILE)
	g++ $(CFLAGS) -O3 $< -o $(TARGET)

#Lanzar el programa 
run: gauss
	./$(TARGET) 1000

# Eliminar el archivo ejecutable.
clean:
	rm $(TARGET)
