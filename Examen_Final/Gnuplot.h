#ifndef GPLOT_H
#define GPLO_H

void gplot(){
    FILE *p = popen("gnuplot","w");	// popen() permite trabajar en gnuplot, w para modo write,
    					// *p es nuestro puntero de archivo
  					// El comando fprintf(p,"..."); permite escribir comandos en gnuplot
    fprintf(p,"reset \n");		// Borramos cualquier configuración previa que pudiera tener gnuplot
    fprintf(p,"set title 'Gráfica Cohetes' \n");		// Se define el título del gráfico
    fprintf(p,"set xlabel 'x' \n");	// Se define el título del eje x
    fprintf(p,"set ylabel 'tiempo' \n");	// Se define el título del eje y
//    fprintf(p,"set yrange [-5:15] \n");		// Rango en x para la gráfica a generar
//    fprintf(p,"set xrange [-5:5] \n");		// Rango en y para la gráfica a generar
    fprintf(p,"set grid\n");			// Cuadrícula para observar mejor los datos
    fprintf(p,"set term png \n");		// Defnimos la terminal como png, para crear un gráfico de los datos
    fprintf(p,"set key bottom right \n");	// Cambiamos la posición de key
    fprintf(p,"set output 'biseccion.png' \n"); // La imagen obtenida se guarda con el nombre biseccion.png
    fprintf(p,"'min_cuadrados' with xyerrorbars \n");	// Se plotea simultáneamente la línea que mejor
    		
    pclose(p);				// Se cierra gnuplot
}