# Nombre del archivo fuente y del archivo ejecutable.
SRC_FILE = gauss.cc
TARGET = gauss

# Opciones de compilación y optimización.
CFLAGS = -Wall -fopenmp


# Compilar el programa sin optimizaciones.
OptB: $(SRC_FILE)
	g++ $(CFLAGS) -O0 $< -o $(TARGET)

# Compilar el programa con optimización estándar.
Est: $(SRC_FILE)
	g++ $(CFLAGS) -O1 $< -o $@

# Compilar el programa con optimización alta.
OptA: $(SRC_FILE)
	g++ $(CFLAGS) -O3 $< -o $(TARGET)

#Lanzar el programa 
Run: gauss
	./$(TARGET) 1000

# Eliminar el archivo ejecutable.
clean:
	rm $(TARGET)
