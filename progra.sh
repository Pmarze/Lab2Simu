#!/bin/bash
echo "Ingrese el nombre de su archivo :D"
read nombre_archivo								##Nos permite ingresar un dato desde consola y lo asigna a la variable
Extension="${nombre_archivo##*.}"						##Elimina todos los caracteres antes del último punto
Nombre="${nombre_archivo%.*}"							##Elimina todos los caracteres después del último punto

if [ -z $Nombre ]; then								##Si no ingresamos un nombre,aunque este tenga extensión
	exit									# va a terminar el programa sin retornar algún valor

elif [ "$Nombre" = "$Extension" ]; then						##Si las variables son iguales implica que no hay puntos 
	exit									# por lo tanto tampoco va a tener extension y termina el programa

fi
										##si cumple ambas condiciones ahora verificamos que
if [ $Extension = "c" ]; then							# la extensión sea .c, ponemos "c"  sin el punto porque no es necesario,

	touch $nombre_archivo							##Si cumple con todas las condiciones entonces creamos el archivo
	echo "/*" >> $nombre_archivo
	echo "Autor: $USER"  >> $nombre_archivo					##Añade una línea con el nombre de usuario
										##Con el siguiente comando obtenemos solo el número de versión de GCC
	echo "Compilador: $(gcc --version|head -n1 |cut -d" " -f4 )" >> $nombre_archivo
	echo "Compilado: gcc $nombre_archivo -o $Nombre" >> $nombre_archivo	##Comentario de como compilar nuestro archivo en terminal
	echo "Fecha: $(date)" >> $nombre_archivo					##Se añade la fecha al archivo
	echo "Ingrese las librerias a utilizar"
	read librerias								##Comando para ingresar datos desde la terminal
	echo "librerias: stdio, $librerias" >> $nombre_archivo			##Añadimos las librerias  al archivo
	echo "Ingrese el resumen de su archivo"
	read resumen
	echo "Resumen: $resumen" >> $nombre_archivo				##Añadimos el resumen al archivo
	echo "Especifique  las entradas de su programa"	
	read entradas
	echo "Entrada:  $entradas" >> $nombre_archivo				##Añadimos las entradas al archivo
	echo "Especifique las salidas de su programa"
	read salidas
	echo "Salida: $salidas" >> $nombre_archivo				##Añadimos las salidas al archivo
	echo */ >> $nombre_archivo
	echo "" >> $nombre_archivo						##Espacio en blanco para separar encabezado del programa
	echo "#include <stdio.h>" >> $nombre_archivo 				##Añadimos la libreria stdio a nuestro programa
	echo "*/" >> $nombre_archivo
else
	exit
fi
