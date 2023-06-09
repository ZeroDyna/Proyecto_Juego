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
- 
## Ejecucion del proyecto
Al momento de iniciar la ejecucion del codigo se mostrara la siguiente ventana:

![Pantalla de inicio](https://github.com/ZeroDyna/Proyecto_Juego/blob/main/pruebas/WhatsApp%20Image%202023-06-25%20at%2021.06.48.jpeg)

Siendo la pantalla de inicio definida en los archvios pantalla_inicio.hpp y pantalla_inicio.cpp en el cual lo mas destacable es 

    void PantallaInicio::manejarEventos() {
    sf::Event evento;
    while (ventana_.pollEvent(evento)) {
        if (evento.type == sf::Event::Closed) {
            ventana_.close();
        } else if (evento.type == sf::Event::MouseButtonPressed && evento.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i posicionMouse = sf::Mouse::getPosition(ventana_);
            if (textoInicio_.getGlobalBounds().contains(sf::Vector2f(posicionMouse))) {
                iniciarJuegoSeleccionado_ = true;
            } else if (textoSalir_.getGlobalBounds().contains(sf::Vector2f(posicionMouse))) {
                salirSeleccionado_ = true;
            }
        }
    }
    }
Permite que a traves del click del mouse se selccione una de las 2 opciones disponibles.

Al seleccionar la opcion iniciar juego les dara el siguiente resultado:

![Pantalla de inicio](https://github.com/ZeroDyna/Proyecto_Juego/blob/main/pruebas/WhatsApp%20Image%202023-06-25%20at%2021.06.53.jpeg)

 

| Objeto                          | Imagen                          |
| ------------------------------ | ------------------------------- |
| En esta se encuentra la clase Personaje que usa un sprite de una nave de una serie de televisión  | ![GUTS wing](https://github.com/ZeroDyna/Proyecto_Juego/blob/main/juego/img/wing.png) |
| También se puede observar el fondo  | ![Cielo](https://github.com/ZeroDyna/Proyecto_Juego/blob/main/juego/img/cielo.png) |
| También se observa el objeto asteroide que es simplemente un círculo de color tierra | ![Asteroide](https://thumbs.dreamstime.com/b/radio-de-un-icono-del-c%C3%ADrculo-en-el-estilo-ne%C3%B3n-uno-la-figura-geom%C3%A9trica-colecci%C3%B3n-se-puede-utilizar-para-ui-ux-126541800.jpg) |


En la clase Personaje lo mas destacable es la funcion mover:

        void Personaje::mover(sf::RenderWindow& ventana) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        sprite.move(0, -velocidad);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        sprite.move(0, velocidad);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        sprite.move(-velocidad, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        sprite.move(velocidad, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        girar(-5);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        girar(5);
    }
    }
Que permite de que el objeto Personaje pueda moverse libremente, ademas de que tambien permiten la rotacion del objeto.

Para los objetos de la clase asteroide lo mas interesanre es la funcion actualizar que seria la siguiente:

        void Asteroide::actualizar(float deltaTime) {
    sf::Vector2f posicion = forma.getPosition();
    posicion += velocidad * deltaTime;

    // Si el asteroide sale de la pantalla, reiniciar su posición en la parte superior
    if (posicion.y > ventana->getSize().y) {
        // Generar una posición aleatoria en el eje X dentro de la ventana
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> disX(0.0f, static_cast<float>(ventana->getSize().x));
        float posX = disX(gen);

        // Reiniciar la posición en la parte superior de la ventana
        posicion.x = posX;
        posicion.y = -forma.getRadius();
    }

    forma.setPosition(posicion);
    }

Lo que hace la funcion actualizar es acutaliza la posicion del objeto agregando la velocidad del objeto multiplicado por "delta time" , ademas de que tambein ayuda al reposicionamiento de los objetos de asteroide en la parte superior de la ventana al salirse de esta a traves de generar un umero aleatorio. 

A continuacion en la siguiente imagen se puede observar los objetos de la clase disparo en diferentes situaciones

![Pantalla de inicio](https://github.com/ZeroDyna/Proyecto_Juego/blob/main/pruebas/WhatsApp%20Image%202023-06-25%20at%2021.06.54.jpeg)

![Pantalla de inicio](https://github.com/ZeroDyna/Proyecto_Juego/blob/main/pruebas/WhatsApp%20Image%202023-06-25%20at%2021.06.54%20(1).jpeg)

![Pantalla de inicio](https://github.com/ZeroDyna/Proyecto_Juego/blob/main/pruebas/WhatsApp%20Image%202023-06-25%20at%2021.06.54%20(2).jpeg)

¿Qué es lo mas destacable de la clase disparo?

Pues es el calculo de la direccion del disparo que se alinea con el angulo en el que se encuentra el objeto personajee que se hace cconvirtiendo el angulo en radianes una vez hecho esto se usa el cos y el sin para calcular el componente X y la direccion Y , las cuales se van a guardar en un vector2f indicando este ultimo en que direccion se mueve. 



Durante el desarrollo del proyecto, se enfrentaron las siguientes complicaciones:

1. **Abandono del grupo**: Los integrantes abandonó el grupo, lo que generó la redistribución de tareas y un ajuste en la planificación del proyecto.
2. **Problemas de zsh y errores de segmentación**: Se presentaron problemas relacionados con el acceso no autorizado a la memoria durante la ejecución del programa. Se investigó y solucionó estos errores para garantizar un funcionamiento adecuado del juego.
3. **Error en la clase FondoAleatorio**: Se identificó un error en la generación de fondos aleatorios, donde solo se mostraba un fondo estático en lugar de cambiar cada 30 segundos. La solución implementada fue generar un número aleatorio (0, 1 o 2) para seleccionar el fondo correspondiente y cambiarlo cada 30 segundos.
4. **Uso de herramientas de compilación**: Durante el desarrollo del proyecto, se hizo uso de herramientas de compilación para facilitar el proceso de construcción y gestión del código fuente pero a veces podian causar confusion.

En resumen, el proyecto consistió en la creación de un juego de naves inspirado en "Asteroids". A pesar de las dificultades encontradas, se logró desarrollar el juego en su totalidad, implementando las clases mencionadas anteriormente y solucionando los problemas técnicos
