#ifndef GLMANAGER_H
#define GLMANAGER_H

#include <Windows.h>
#include <GL/gl.h>
#include <gl\GLU.h>
#include"../OpenGL Tutorial1/LigthSpot.h" //Classe  que se encarga de calcular la luz
class GLRenderer
{
	public:
		GLRenderer(void);
		//Inicia la ventana de OpenGL
		int Inicializar(HDC _hdc, unsigned int _width, unsigned int _height);
		//Funcion para notificar a OpenGL que se cambio el tama�o de la ventana
		void Resize(unsigned int _width, unsigned int _height);
		//El Update
		void Update(float _deltaTime);
		//Todo lo de dibujar
		void Render(void);
	private:
		HDC m_hDC; //guarda referencia a la ventana
};

#endif