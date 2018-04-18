Bono: VelocidadBono.png
VelocidadBono.png: bono.txt bono_grafica.py
	python bono_grafica.py
bono.txt: bono.cpp
	c++ bono.cpp
	./a.out > bono.txt
	rm a.out

Tarea: phase.png
phase.png: tray.txt SG_graph.py
	python SG_graph.py
tray.txt: SG_gravity.cpp
	c++ SG_gravity.cpp
	./a.out > tray.txt
	rm a.out
