# Lo que dice el subject
## Sin servidor gráfico de ningún tipo
## Al menos dos particiones cifradas, usando LVM
## Diferencias entre aptitude y apt
## SElinux y AppArmor
## El ssh Se conecta por el puerto 4242
# No ssh como root
## Con el firewall UFW, cierra todos los puertos menos 4242
## Hostname de la máquina = ranavarr42
## Política de contraseñas fuerte
- Contraseña expira cada 30 dias
- El número de dias permitido antes de modificar una contraseña es 2
- El usuario recibe un aviso 7 dias antes de que esta expire
- contraseña de 10 caracteres, una mayuscula, una minuscula y un número, sin que se repita
el mismo caracter 3 veces.
- No puede contener el nombre del usuario
- La conntraseña debe tener al menos 7 caracteres que no sean parte de la antigua contraseña ( no se aplica a root)
# para sudo 
- máximo 3 intentos de autenticación
- mensaje de contraseña incorrecta
- cada comando ejecutado debe guardarse(input y output) en /var/log/sudo
- Modo TTY activado
- Los directorios utilizables por sudo debene estar restringidos
## Instalar y configurar sudo con reglas estrictas
## Dos usuarios, root y rafa
## el usuario, debe pertenecer a los grupos user42 y sudo
## monitoring.sh
- Escrito en Bash
- Ningún error visible
- Se muestra en todos los terminales cada 10 min
- Arquitectura  Version de kernel
- Número de núcleos físicos
- Ram disponible y porcentaje de uso
- Memoria disponible y uso en %
- Porcentaje de uso de núcleos
- Fecha y hora último reinicio
- LVM activo o no
- Número de conexiones activas
- Número de usuarios del servidor
- IPv4 y Mac
- Número de comandos ejecutados con sudo

