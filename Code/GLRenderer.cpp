#include "GLRenderer.h"

float PosicionLuz[] = { 0.5,0.5,0.0,1.0 };
GLRenderer::GLRenderer(void)//Creo que este es el contructor
{
	//Instancia de la ventana
	m_hDC = NULL;
	// lista de puntos
	std::vector<glm::vec2> Puntos;
	// Punto Inicial
	Puntos.push_back(glm::vec2(0.75,0.75) );
	Puntos.push_back(glm::vec2(0.75,0.0) );
	//Primera instancia
	Puntos.push_back(glm::vec2(-0.5,0.0));
	Puntos.push_back(glm::vec2(-0.5,-0.5));
	//
	Puntos.push_back(glm::vec2(0.0, -0.5));
	//punto Final
	Puntos.push_back(glm::vec2(0.0, 0.75));
	//
	LigthSpot L_Luz(Puntos);
}

int GLRenderer::Inicializar(HDC _hdc, unsigned int _width, unsigned int _height)
{
	//almacenamos la referencia a la ventana
	m_hDC = _hdc;
	//Indicamos el tamaño de la ventana inicial
	Resize(_width, _height);
	//Color del fondo
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glMatrixMode(GL_PROJECTION);    //cargamos la matriz de proyeccion
	glLoadIdentity();   //movemos al origen la matriz de proyeccion

						//calculamos la relacion del aspecto de la ventana
	//gluPerspective(52.0f, (GLfloat)_width / (GLfloat)_height, 1.0f, 1000.0f);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);

	float LuzAmbiente [] = {0.2,0.2,0.2,1.0};
    float LuzDifusa [] = {0.8,0.8,0.8,1.0};
    float LuzEspecular [] = {1.0,1.0,1.0,1.0};
    //
	glLightfv(GL_LIGHT0,GL_AMBIENT,LuzAmbiente);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,LuzDifusa);
	glLightfv(GL_LIGHT0,GL_SPECULAR, LuzEspecular);
	//position inicial
	
	glLightfv(GL_LIGHT0, GL_POSITION, PosicionLuz);

	glMatrixMode(GL_MODELVIEW); //cargmos la matrix del modelo
	glLoadIdentity();   //movemos al origen la matriz de modelado

  return 0;
}

void GLRenderer::Resize(unsigned int _width, unsigned int _height)
{  
	//No puede tener un ancho de 0 la ventana //Seguridad
	if(0 == _width)
	{
		_width = 1;
	}
	//Igual la altura
	if(0 == _height)
	{
		_height = 1;
	}

	//Indicamos las dimensiones a OpenGL
	glViewport(0, 0, (GLsizei)_width, (GLsizei)_height);
}

void GLRenderer::Update(float _deltaTime)
{

	//inicial
	/**/
	  //between = from + (to - from) * factor;
		PosicionLuz[0] +=   /*velocidad*/(0.05 * _deltaTime);
		PosicionLuz[1] +=   /*velocidad*/(0.05 * _deltaTime);
	   /**/
		glLightfv(GL_LIGHT0, GL_POSITION, PosicionLuz);
}

void GLRenderer::Render()
{
	//Limpiamos pantalla
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();   //nos posisionamos en el centro

	float rojo[] = { 1.0,0.0,0.0,1.0 };
	float verde[] = { 0.0,1.0,0.0,1.0 };
	float azul[] = { 0.0,0.0,1.0,1.0 };
	float blanco[] = { 1.0,1.0,1.0,1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, azul);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, verde);
	glMaterialfv(GL_FRONT, GL_SPECULAR, blanco);
	glMaterialf(GL_FRONT, GL_SHININESS, 60.0);

	glBegin(GL_QUADS);
	const float incremento = 0.01;
	for ( int i=-90; i < 90; i++)
	{
		for (int j = -90; j < 90; j++)
		{
			glVertex3f(j*incremento,i*incremento,-0.2);
			glVertex3f((j+1)*incremento,i*incremento,-0.2);
			glVertex3f((j+1)*incremento,(i+1)*incremento,-0.2);
			glVertex3f(j*incremento,(i+1)*incremento,-0.2);
		}
	}
	glEnd();
	//Mostramos todo lo dibujado //BACK Buffer
	SwapBuffers(m_hDC);
}