# Subject
- Llamar a la función repetidamente lee el archivo línea a línea hasta el final
- La función devuelve la línea que acaba de leer
- Se debe comportar adecuadamente cuando lee de un archivo y cuando lee de stdin
- La línea leida acaba con el caracter \n excepto cuando devuelves la última línea
- las funciones de ayuda van en get_next_line_utils.c
- Debe compilar con -D BUFFER_SIZE=xx. b

# Lo que yo se (ahora)
- No puedes tratar al file descriptor como si fuera un array normal
- 

# Librerias incluidas y por qué
- unistd.h: 
	bp


- stdlib.h
- stddef.h
- fcntl.h
- stdio.h

# Lo que hago paso a paso
1. Un main simple de prueba, donde abro un archivo
	
