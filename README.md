# Campeonato de Fórmula 1

## Contexto
Hoy en día la Fórmula 1 se ha vuelto un depprte muy popular, por lo que cada vez más personas lo ven y disfrutan. Aunque se encuentra la información de todo lo sucedido en internet, este programa sirve para poder calcular el estado de los campeonatos después de cada carrera para su fácil uso. Cada carrera tiene su "standing" donde se le suma puntos a cada piloto dependiendo del lugar en el que quedó. También dice el "standing" tomando en cuenta todas las carreras. 

## Funcionalidad
El programa permite crear nuevos pilotos, equipos, carreras, standings y campeonatos. Es importante mencionar que como todos los datos son conocidos, solo hay dos contructores, el parametrizado (con todos los datos) y el vacío según sea el caso. Después calcula los lugares de los pilotos y equipos con la información proporcionada. 
Va a constar de un menu donde se va a poder consultar información sobre pilotos, equipos y el campeoneato. 

Se va a proporcionar una lista con los datos del 2022, para que el usuario pueda agregar cada carrera conforme pase el tiempo. Para no complicar mucho el programa por el momento no hay opción de agregar más pilotos o que sean personalizados. 

Se corre en consola y compila con g++

## Tipo de objetos
Como hay muchos tipos de objetos, quiero especificar como va a funcionar cada tipo de objeto, y su relación con los demás, ya que están muy unidos uno al otro. 

1. Persona: Este es el molde para cualquier persona del programa. Va a tener nombre, años activos, nacionalidad y escudería. 
2. Piloto: Esta clase hereda de persona, donde ademas se le agrega puntos. 
3. Team principal: Tambíen hereda de persona, y se le agregra las wins con ese equipo. 
4. Standings: Una lista de pilotos y una lista de equipos, con integers de sus respectivos tamaños. 
5. Equipo: Consta de los dos pilotos, el team principal, con puntos totales (de los dos pilotos) y el nombre del equipo (para comparaciones).
6. Carrera: Esta clase tiene vueltas, país, nombre del circuito, número de carrera, longitud del circuito y objeto standings de dicha carrera. 
7. Campeonato: Hereda de standings, y además consta de una lista de las carreras de dicha temporada, el tamaño de la lista de carreras. 
