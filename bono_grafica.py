import numpy as np
import matplotlib.pyplot as plt

datos = np.loadtxt('bono.txt')
t = datos[:,0]
x = datos[:,1]
y = datos[:,2]
vx = datos[:,3]
vy = datos[:,4]

plt.figure()
plt.plot(t,vx,label = 'x')
plt.plot(t,vy,label = 'y')
plt.legend()
plt.xlabel('Tiempo')
plt.ylabel('Velocidad')
plt.savefig('VelocidadBono.png')

plt.figure()
plt.plot(t,x,label = 'x')
plt.plot(t,y,label = 'y')
plt.legend()
plt.xlabel('Tiempo')
plt.ylabel('Posicion')
plt.savefig('PosicionBono.png')

plt.figure()
plt.plot(x,vx,label = 'x')
plt.plot(y,vy,label = 'y')
plt.legend()
plt.xlabel('Distancia')
plt.ylabel('Velocidad')
plt.savefig('FaseBono.png')

plt.figure()
plt.plot(x,y)
plt.xlabel('x')
plt.ylabel('y')
plt.savefig('xvsy_bono.png')
