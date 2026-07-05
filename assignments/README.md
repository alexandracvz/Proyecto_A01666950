# Proyecto A01666950

## Clase Personaje

Este proyecto implementa una clase **Personaje** que representa una unidad de combate. La clase cuenta con atributos para la vida, salud, ataque y nivel, además de métodos para calcular ataques, recibir daño y mostrar el estado del personaje.

## Diagrama UML
```mermaid
classDiagram

class Personaje{
    - int vida
    - int salud
    - int ataque
    - int nivel

    + Personaje()
    + Personaje(int vida, int ataque, int nivel)

    + getVida() int
    + getSalud() int
    + getAtaque() int
    + getNivel() int

    + setVida(int vida) void
    + setSalud(int salud) void
    + setAtaque(int ataque) void
    + setNivel(int nivel) void

    + porcentajeSalud() int
    + imprimeBarra() void
    + calculaAtaque(Personaje& objetivo) int
    + recibeAtaque(int ptosAtaque) void
    + atacar(Personaje& objetivo) void
    + imprimir() void
}
```


