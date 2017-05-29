#include "LigthSpot.h"


/*Este pedazo de codigo es para parametrizar  un vector posicion con la velocidad asignada como Constante*/
void LigthSpot::Update(float _deltatime)
{

}

void LigthSpot::Move(float _deltatime)
{

	// Definir si es positivo o negativa la velocidad               
	for (int i = 0; i < V2_ChekcPoints.size(); i++)
	{
		if (B_ChekcPoints[i] != true) //Falso
		{
			//No hacer nada
		}
		else
		{
			//Es verdadero
			//Ver hacia donde debemos de ir  si izquierda o derecha
			CheckDir(V2_ChekcPoints[i], V2_ChekcPoints[1 + i]); //Asi simpre nos aseguramos que es el siguiente al numero
			//mover la luz
			//        
			Position.x += (0.05f*dir.x)*_deltatime;
			Position.y += (0.05f*dir.y)*_deltatime;

		}
	}
}

bool LigthSpot::CheckDir(glm::vec2 A, glm::vec2 B)
{
	/*
	Dado el punto A  en el spacio de R2 dada la Base canonica de : A.x*i(1,0) , A.y*j(0,1) y el mismo caso para el Vector B
    Definir la direcion  el cual debe de tomar el vector Velocidad
	*/

	glm::vec2 _Dir(B - A); //El vector resultante de la resta de  vec2( B.x - A.x , B.y-A.y)
	//Ver si el valor de  _Dir en sus componentes es 0 
	if(_Dir.x==0||_Dir.y==0) //Caso 1
	{
		//Entonces sabemos que  es el mismo punto
		return true; //--> Si retornamos true es por que son iguales y pues podriamos hacer nada o  hacer algo.(De algo servira)
	}
	else
	{
		//Sabemos que no es la misma posicion y por ende debemos de movernos hacia algun lado
		//Para la variable en X
		if(_Dir.x > 0)
		{
			//Entonces sabemos que es un valor positivo y por ende debemos de avanzar hacia el lado positivo de la base
			dir.x = 1;
		}
		else
		{
			//Solo queda asumir qe es negativo ... 
			dir.x = -1;
		}
		//Para la variable en Y
		if(_Dir.y>0)
		{
			//Sabemos que es una magnitud positiva y por ende la direccion tambien
			dir.y = 1;
		}
		else
		{
			//solo queda asumir que es una magnitud negativa y por ende la direccion tambien
			dir.y = -1;
		}

	}

	return false;
}

LigthSpot::LigthSpot(std::vector<glm::vec2> _Positions) //Constructor el cual  se encargara de setear los puntos
{
	// Asignamos un vector de posiciones

	// Debemos de igualar el vector de bools al de posiciones
	for (int i = 0;i<(_Positions.size()+1);i++)//A;adimos 1 por que la condicion es  i< algo  y como comienza del index 0 los aggreglos y vectores
	{
		B_ChekcPoints.push_back(bool(false));//Algo extra;o pero... veremos si funciona -->> 
	}
}


LigthSpot::~LigthSpot()
{
}
