# Campeonato de Fórmula 1

## Contexto
Hoy en día la Fórmula 1 se ha vuelto un depprte muy popular, por lo que cada vez más personas lo ven y disfrutan. Aunque se encuentra la información de todo lo sucedido en internet, este programa sirve para poder calcular el estado de los campeonatos después de cada carrera para su fácil uso. Cada carrera tiene su "standing" donde se le suma puntos a cada piloto dependiendo del lugar en el que quedó. También dice el "standing" tomando en cuenta todas las carreras. 

## Funcionalidad
El programa permite crear nuevos pilotos, equipos, carreras y standings. Es importante mencionar que como todos los datos son conocidos, solo hay dos contructores, el parametrizado y el vacío. Después calcula los lugares de los pilotos y equipos con la información proporcionada. 
Va a constar de un menu donde se va a poder agregar cada tipo de objeto, y recopilar información de los standings. 

Se corre en consola y compila con g++

## Tipo de objetos
Como hay muchos tipos de objetos, quiero especificar como va a funcionar cada tipo de objeto, y su relación con los demás, ya que están muy unidos uno al otro. 

1. Persona: Este es el molde para cualquier persona del programa. Va a tener nombre, años activos, nacionalidad, escudería y cualquier otra variable que sea útil. 
2. Piloto: Esta clase hereda de persona, donde ademas se le agrega puntos, y cualquier otra variable que sea útil. 
3. Team principal: Tambíen hereda de persona, una variable distinta y cualquier otra variable que sea útil. 
4. Standings: Una lista de pilotos y una lista de equipos dependiendo de qué tan bien les fue en carrera/campeonato. 
5. Equipo: Consta de los dos pilotos, el team principal, con puntos totales (de los dos pilotos) y cualquier otra variable que sea útil.
6. Carrera: Esta clase tiene vueltas, país, nombre del circuito, número de carrera, longitud del circuito y objeto standings de dicha carrera. 

Standings, equipos y carrera tienen de variables los objetos antes mencionados, por lo que se puede volver complicado de modelar, pero con variables claras se debe de poder modelar sin problema. 
