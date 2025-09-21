import math
from turtle import *

# Funções da curva do coração
def hearta(k):
    return 15 * math.sin(k) ** 3

def heartb(k):
    return 12 * math.cos(k) - 5 * \
           math.cos(2 * k) - 2 * \
           math.cos(3 * k) - \
           math.cos(4 * k)

# Configurações da tela
speed(0)
bgcolor("black")
color("#f73487")
penup()

# Começa o desenho no primeiro ponto
x = hearta(0) * 20
y = heartb(0) * 20
goto(x, y)
pendown()

# Desenha o coração todo
for i in range(1, 6000):
    x = hearta(i) * 20
    y = heartb(i) * 20
    goto(x, y)

# Agora escreve o texto no centro
penup()
goto(0, -30)  # Ajuste fino da posição do texto
color("white")
write("Dayane Minha Princesa", align="center", font=("Arial", 20, "bold"))

hideturtle()
done()
