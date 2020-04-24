#include <stdio.h>
#include <math.h>

float fun(float,float);
float Pmedio(float,float,float);
float Eulmod(float,float,float);
float Meheun(float,float,float);

void main(){
	float h=(2.0-0.0)/10;
	float t,K1,K2;
	float wmedio,weuler,w_heun;
	t=0;
	wmedio=0.5;
	weuler=0.5;
	w_heun=0.5;
	printf("| P. medio | Euler M. |   Heun   | \n");
	for (int i=0;i<10;i++){
		wmedio+= Pmedio(h,t,wmedio);
		weuler+= Eulmod(h,t,weuler);
		w_heun+= Meheun(h,t,w_heun);
		t+=h;
		printf("| %f | %f | %f | \n",wmedio,weuler,w_heun);
     }
}

float Pmedio(float h, float t, float w){
	float K1,K2;
	K1=h*fun(t,w);
	K2=h*fun(t+(h/2),w+(K1/2));
	return K2;
}

float Eulmod(float h, float t, float w){
	float res;
	res=(h/2)*(fun(t,w)+fun(t+h,w+h*fun(t,w)));
	return res;
}

float Meheun(float h, float t, float w){
	float res;
	res=(h/4)*(fun(t,w)+3*fun(t+2*h/3,w+2*h/3*fun(t,w)));
	return res;
}

float fun(float t,float y){
	float res;
	res=y-pow(t,2)+1;
	return res;
}
