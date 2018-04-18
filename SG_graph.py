import numpy as np
import matplotlib.pyplot as plt

datos = np.loadtxt('tray.txt')
t = datos[:,0]
x = datos[:,1]
v = datos[:,2]

plt.figure()
plt.plot(t,x)
plt.xlabel('Tiempo')
plt.ylabel('Posicion')
plt.savefig('pos.png')

plt.figure()
plt.plot(t,v)
plt.ylabel('Velocidad')
plt.xlabel('Tiempo')
plt.savefig('vel.png')

plt.figure()
plt.plot(x,v)
plt.ylabel('Velocidad')
plt.xlabel('Posicion')
plt.savefig('phase.png')
