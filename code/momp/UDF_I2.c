#include <udf.h> 
DEFINE_PROFILE(xvel, t, position) 
{ 
	face_t f; 
	float x[ND_ND]; 
	float vel,vel_aver,vel_max,y1,y2,y,ycent; 
	/*********** Modyfikacja **********/ 
	y1= <Y współrzędna dolnej ściany> ; 
	y2= <Y współrzędna górnej ściany> ; 
	vel_aver= <średnia wartość X-wej składowej prędkości> ; 
	/***********************************/ 
	vel_max=1.5*vel_aver; 
	ycent = 0.5*(y1+y2); 
	begin_f_loop(f,t) 
	{ 
		F_CENTROID(x,f,t); 
		y=x[1]; 
		vel = vel_max*( 1.0 - SQR((y-ycent)/(y1-ycent)) ); 

		F_PROFILE(f,t,position)=vel; 
	} 
	end_f_loop(f,t) 
}