track = box(pos=vector(0,-.05,0), size=vector(2.0,0.05,0.10), color=color.white)
cart = box(pos=vector(-.95,0,0), size=vector(0.1,0.04,0.06), color=color.orange)
mcart = 0.80
vcart = vector(0.5, 0, 0)
print('cart velocity =', vcart)
deltat = 0.01
t = 0
while t < 4.0:
    print('the time is now', t)
    rate(100)
    cart.pos = cart.pos + vcart*deltat
    t = t + deltat
print('after the loop')