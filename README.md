# Proyecto de Juego de Naves - Informe Trabajo Final CComp1

Este es el informe del trabajo final realizado para el curso CComp1. El proyecto consiste en el desarrollo de un juego de naves con similitudes al clásico juego "Asteroids". A continuación, se proporcionará una breve introducción, se listarán los integrantes del equipo y se describirá el proyecto en detalle.

## Introducción
El objetivo de este proyecto fue crear un juego de naves algo desafiante, inspirado en el popular juego "Asteroids". Se implementaron varias clases y se utilizaron diferentes recursos para crear una experiencia de juego emocionante. A lo largo de este informe, se detallarán los elementos clave del juego y las dificultades encontradas durante su desarrollo.

## Integrantes del Equipo
- Renato Oscar Corrales Peña

## Descripción del Proyecto
El juego de naves se desarrolló utilizando el lenguaje de programación C++ y consta de las siguientes clases y objetos:

- **Asteroides**: Representa los asteroides en el juego. Se encarga de su generación en la parte supeior de la ventana y su movimiento.
- **Cometa**: Representa los cometas en el juego que en general son lo mismo que los asteroides. Se encarga de su generación y movimiento en diagonal hacia la izquierda.
- **Disparo**: Representa las balas que nacen desde la nave teniendo en cuenta su angulo, tienen colision con los cometas y asteroides al chocar ambos objetos se eliminan. 
- **Fondo**: Clase que controla el fondo de pantalla del juego de manera de que cambie a lo largo de la partida.
- **Personaje**: Representa la nave del jugador y se encarga de su movimiento.
- **Pantalla de Inicio**: Clase encargada de mostrar la pantalla de inicio del juego con interaccioon con el mouse.
- **Objeto (Clase abstracta)**: Clase base para los asteroides y cometas. Define los métodos y atributos comunes a ambos.
## Ejecucion del proyecto
Al momento de iniciar la ejecucion del codigo se mostrara la siguiente ventana:
![Pantalla de inicio](pruebas/"WhatsApp Image 2023-06-25 at 21.06.48.jpeg")

Durante el desarrollo del proyecto, se enfrentaron las siguientes complicaciones:

1. **Abandono del grupo**: Los integrantes abandonó el grupo, lo que generó la redistribución de tareas y un ajuste en la planificación del proyecto.
2. **Problemas de zsh y errores de segmentación**: Se presentaron problemas relacionados con el acceso no autorizado a la memoria durante la ejecución del programa. Se investigó y solucionó estos errores para garantizar un funcionamiento adecuado del juego.
3. **Error en la clase FondoAleatorio**: Se identificó un error en la generación de fondos aleatorios, donde solo se mostraba un fondo estático en lugar de cambiar cada 30 segundos. La solución implementada fue generar un número aleatorio (0, 1 o 2) para seleccionar el fondo correspondiente y cambiarlo cada 30 segundos.
4. **Uso de herramientas de compilación**: Durante el desarrollo del proyecto, se hizo uso de herramientas de compilación para facilitar el proceso de construcción y gestión del código fuente pero a veces podian causar confusion.

En resumen, el proyecto consistió en la creación de un juego de naves inspirado en "Asteroids". A pesar de las dificultades encontradas, se logró desarrollar el juego en su totalidad, implementando las clases mencionadas anteriormente y solucionando los problemas técnicos
