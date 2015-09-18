/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/
//Version: 001

#include "LUtil.h"
#include "Polygon.h"
#include "Aircraft.h"
#include "Item.h"
#include "Shot.h"
#include "Game.h"
#include <iostream>
#include <cstdlib>

Game *game;


bool* keyStates[256];// = new bool[256]; // Create an array of boolean values of length 256 (0-255)
bool* keySpecialStates[256];// = new bool[256]; // Create an array of boolean values of length 256 (0-255)

// Key Handling
void initKeys(){
    //std::fill_n(keyStates, 256, NULL);
    //std::fill_n(keySpecialStates, 256, NULL);
}
void keyPressed(unsigned char key, int x, int y){
    if(key == 'p'){
        game->pauseOrContinue();
    }

    if(keyStates[key] != NULL){
        *keyStates[key] = true;
    }
}
void keyUp(unsigned char key, int x, int y){
    if(keyStates[key] != NULL){
        *keyStates[key] = false;
    }
}
void keyOperations(void){
}

void keySpecial(int key, int x, int y){
    if(keySpecialStates[key] != NULL){
        *keySpecialStates[key] = true;
    }
}
void keySpecialUp(int key, int x, int y){
    if(keySpecialStates[key] != NULL){
        *keySpecialStates[key] = false;
    }
}

void keySpecialOperations(){
    //if(keySpecialStates[GLUT_KEY_UP]){}
    //if(keySpecialStates[GLUT_KEY_LEFT]){}
    //if(keySpecialStates[GLUT_KEY_RIGHT]){}
}

bool initGL(){
    glClearColor(0.0, 0.0, 0.0, 0.0); // é a função que determina a cor utilizada para limpar a janela. Parametros: (red, green, blue, alpha).
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); // Função utilizada antes de qualquer operação com matrizes para inicializar sistema de coordenadas
    glOrtho(XMIN, XMAX, YMIN, YMAX, -1.0, 1.0); // de4fine a janela de projeção que se deseja trabalhar. Os parâmetros são os seguintes glOrtho(Xmin, Xmax, Ymin, Ymax, Zmin, Zmax).

    //Check for error
    GLenum error = glGetError();
    if(error != GL_NO_ERROR){
        std::cout << "Error initializing OpenGL! " << gluErrorString(error) << "\n";
        return false;
    }

    return true;
}

void update(){

    if(!game->isPaused()){
        game->iterate();
    }

}

void render(){
    glClear(GL_COLOR_BUFFER_BIT); // Limpa a janela de visualização com a cor de fundo     especificada
    glMatrixMode(GL_MODELVIEW); // especifica qual matriz será utilizada

    game->draw();

    glFlush(); //Executa os andos OpenGL ao invés de aguardar outros comandos adicionais OpenGL
}

// Dot Interception
bool isInterceptingSegments(Dot A1, Dot A2, Dot B1, Dot B2){
    float SA1, SA2, SB1, SB2;

    SA1 = A1.whichSide(B1, B2);
    SA2 = A2.whichSide(B1, B2);

    SB1 = B1.whichSide(A1, A2);
    SB2 = B2.whichSide(A1, A2);

    if(((SB2 <= 0 && SB1 >= 0) || (SB1 <= 0 && SB2 >= 0)) && ((SA2 <= 0 && SA1 >= 0) || (SA1 <= 0 && SA2 >= 0)))
        return true;
    return false;
}

void initGame(){
	game = new Game();

	Aircraft* p = game->getPlayer();

	keySpecialStates[GLUT_KEY_UP] = p->getCommandAddress(BOOST_COMMAND);
	keySpecialStates[GLUT_KEY_LEFT] = p->getCommandAddress(TURN_LEFT);
	keySpecialStates[GLUT_KEY_RIGHT] = p->getCommandAddress(TURN_RIGHT);
	keyStates[' '] = p->getCommandAddress(SHOOT);
}

void clearGame(){
    delete game;
}
