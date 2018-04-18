phase.png: tray.txt SG_graph.py
	python SG_graph.py
tray.txt: SG_gravity.cpp
	c++ SG_gravity.cpp
	./a.out > tray.txt
	rm a.out
