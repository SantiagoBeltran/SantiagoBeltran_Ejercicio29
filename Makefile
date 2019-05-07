onda.png: intento.dat
	python graficador.py

intento.dat : a.out
	./a.out

a.out: SantiagoBeltran_Ejercicio29.cpp
	g++ SantiagoBeltran_Ejercicio29.cpp
    
clean:
	rm -rf *.out *.dat *.png
