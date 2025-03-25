
## root password = r00T
## username = ranavarr
## ranavarr password = tH3W0rd ahora: B0D4C1us80
## Encryption passphrase = Holdyourcol0ur
## Al menos dos particiones cifradas, usando LVM
## editar crontab con `crontab -e`

## Diferencias entre aptitude y apt

- apt: Advanced Packaging Tool. Controla instalación de software. 
es de bajo nivel y acepta .deb y .rpm
- aptitude: es un gestor de alto nivel con interfaz en ncurses que añade
funciones y autatiza ciertas tareas.	
## SElinux y AppArmor
### SElinux
- Orientado a proteger todo el sistema
- Hecho por la NSA??
- Es un set de modificaciones del kernel.
- Control de acceso obligatorio
- Contro de acceso basado en roles
esto es, que solo ciertos usuarios, que controlan la org. tienen acceso
al sistema.  - Integrado en Mainline Linux
### Apparmor
- Orientado a progeger el sistema de ficheros.
- Más fácil de configurara.



#El ssh Se conecta por el puerto 4242
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


contraseña root = 8igu8 
contraseña host name = 5ddu8 
encription passphrase = esto es una frase

- El puerto 22 esta abierto? debería cerrarlo???


                  _      _      _
               __(.)< __(.)> __(.)=
               \___)  \___)  \___)   hjw


# First of all
# particiones
5.	guided - Use entire disk	and set up encrypted LVM
6.	Separate /home, /var and /tmp partitions (importante para el bonus)
7.	sda encryption password = sdancript
8.	Ajustar tamaño de la partición (he puesto 15GB)
9.	Crear logical volume srv
11.	#doubt. What size?
12.	ext4 journaling system
13.	mount to /srv
14.	Crear logical volume var-log
15.	#doubt. What size?
16.	ext4 journaling system
17.	mount to /var/log
18.	"configure logical volume manager"
19.	avoid scanning for extra installation media.
20.	select default debian mirror
21.	Leave proxy settings blank
22.	Do not participate
23.	Ensure to install GRUB loader
24.	select to install SSH Server and Standard system utilitites
25.	reboot
# SSH setup
26.	check service status. systemctl status ssh
27.	at /etc/ssh/sshd_config, change Port 22 to Port 4343 (porque el 42 no va)
28.	Same file, PermitRootLogin to no
29. restart SSH with systemctl restart ssh
# port forwarding
In virtual machine settings
1.	Network
2.	Advanced
3.	Port Forwarding
4.	Create New rule named SSH
5.	find avalilable host port
6.	guest port = 4242
7.	Logout of the vm `logout`
# firewall	
on host terminal
1.	`ssh ranavarr@localhost -p nosepuerto` 
2.	switch to root `su -`
3.	install ufw
4.	block all incoming requests `ufw default deny incoming`
5.	`ufw default allow outgoing` allow all outgoing requests
6.	`ufw allow 4242`
# sudo 
1.	instalar sudo
2.	`visudo` para configurar sudo
3.	add: `Defaults secure_path="/usr/local/sbin:/usr/sbin:/usr/bin:/sbin:/bin"
4.	add: `Defaults requiretty`
5.	add: `Defaults badpass_message="YOU GOT IT WRONG"`
5.	add: `Defaults logfile="/var/log/sudo/sudo.log"`
5.	add: `Defaults log_input`
5.	add: `Defaults log_output`
5.	add: `Defaults iolog_dir=/var/log/sudo`
5.	add: `Defaults passwd_tries=3`
# groups
1.	`groupadd user42`
2.	`usermod -a -G user42,sudo ranavarr` 
3.	`cat /etc/group` verify changes
# Password policy
1.	`vim pa

