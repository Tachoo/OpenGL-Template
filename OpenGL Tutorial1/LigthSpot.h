#pragma once
#include "glm\glm\glm.hpp"
#include <vector>
class LigthSpot
{
private:
	// Dir
	glm::vec2 dir;  /*Si Dir es -1  significa que puede ir  hacia abajo o hacia la izquierda*/
	// El vector velocidad
	glm::vec2 V2_Velocity;

	//Update ChildFunc
	//Funcion secundaria cual se encarga de un aspecto en especifico
	void Move(float _deltatime); // Mover el objeto
	bool CheckDir(glm::vec2 A, glm::vec2 B);// Definir que direccion es la que debe de  tomar
public:
	//Posicion en 2 dimenciones
	glm::vec2 Position;

	//Vector de posiciones a que seguir
	std::vector<glm::vec2> V2_ChekcPoints;
	//Vector de Booleanos
	std::vector<bool> B_ChekcPoints;
	
	/**/
	//Funcion principal  donde llama diferentes funciones
	void Update(float _deltatime);


	LigthSpot(std::vector<glm::vec2> _Positions);
	~LigthSpot();
};

