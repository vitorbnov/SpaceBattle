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


bool* keyStates = new bool[256]; // Create an array of boolean values of length 256 (0-255)
bool* keySpecialStates = new bool[256]; // Create an array of boolean values of length 256 (0-255)

// Key Handling
void initKeys(){
    std::fill_n(keyStates, 256, false);
    std::fill_n(keySpecialStates, 256, false);
}
void keyPressed(unsigned char key, int x, int y){
    keyStates[key] = true;
}
void keyUp(unsigned char key, int x, int y){
    keyStates[key] = false;
}
void keyOperations(void){
    if(keyStates['a']){
        //Bla
    }
}

void keySpecial(int key, int x, int y){
    keySpecialStates[key] = true;
}
void keySpecialUp(int key, int x, int y){
    keySpecialStates[key] = false;
}

void keySpecialOperations(){
    if(keySpecialStates[GLUT_KEY_UP]){
        // HANDLE HERE
    }
    if(keySpecialStates[GLUT_KEY_LEFT]){
        //aircraft->turnLeft();
    }
    if(keySpecialStates[GLUT_KEY_RIGHT]){
        //aircraft->turnRight();
    }
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
    Dot pos;

    game->iterate(keySpecialStates[GLUT_KEY_UP], keySpecialStates[GLUT_KEY_LEFT], keySpecialStates[GLUT_KEY_RIGHT], keyStates[' ']);

}

void render(){
    glClear(GL_COLOR_BUFFER_BIT); // Limpa a janela de visualização com a cor de fundo     especificada
    glMatrixMode(GL_MODELVIEW); // especifica qual matriz será utilizada

    game->draw();

    glFlush(); //Executa os andos OpenGL ao invés de aguardar outros comandos adicionais OpenGL
}

void initGame(){
	game = new Game();
}

void clearGame(){
    delete game;
}
