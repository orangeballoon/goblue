track = box(pos=vector(0,-.05,0), size=vector(2.0,0.05,0.10), color=color.white)
cart = box(pos=vector(-1.0,0,0), size=vector(.1,.04,.06), color=color.orange)
mcart = 0.80
vcart = vector(0.5, 0, 0)
print('cart velocity =', vcart)
deltat = 0.01
t = 0
while t < 0.2:
  print('the time is now', t)
  t = t + deltat
  print('after the loop')
  t = t + deltat
  cart.pos = cart.pos + vcart*deltat