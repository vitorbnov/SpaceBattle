/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/
//Version: 001

#include "LUtil.h"
#include "Polygon.h"
#include "Aircraft.h"
#include "Game.h"



void runMainLoop( int val );
/*
Pre Condition:
 -Initialized freeGLUT
Post Condition:
 -Calls the main loop functions and sets itself to be called back in 1000 / SCREEN_FPS milliseconds
Side Effects:
 -Sets glutTimerFunc
*/

int main(int argc, char* args[]){

    glutInit(&argc, args); // Inicializa a biblioteca GLUT e negocia uma seção com o gerenciador de janelas.
    glutInitContextVersion( 2, 1 ); //Create OpenGL 2.1 context
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // avisa a GLUT que tipo de modo de exibição deve ser usado quando a janela é criada
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT); // tamanho da janela
    glutInitWindowPosition(100, 100); // posição inicial no canto superior esquerdo na tela
    glutCreateWindow("SpaceBattle"); // comando da biblioteca GLUT que cria a janela.

	//Do post window/context creation initialization
	if( !initGL() ){
		std::cout << "Unable to initialize graphics library!\n";
		return 1;
	}

	initKeys();

    glutDisplayFunc(render); // estabelece a função “display" como a função callback de exibição. Isto significa que a GLUT chama a função sempre que a janela precisar ser redesenhada.

    glutKeyboardFunc(keyPressed); // Te ll GLUT to use the method "keyPressed" for key presses
    glutKeyboardUpFunc(keyUp);  // Tell GLUT to use the method "keyUp" for key up events


    glutSpecialFunc(keySpecial); // Tell GLUT to use the method "keySpecial" for special key presses
    glutSpecialUpFunc(keySpecialUp); // Tell GLUT to use the method "keySpecialUp" for special up key events
	//Set main loop
	glutTimerFunc( 1000 / SCREEN_FPS, runMainLoop, 0 );

    //Init the game
	initGame();

	//Start GLUT main loop
    glutMainLoop(); // é a função que faz com que comece a execução

    clearGame();

    return 0;
}

void runMainLoop(int val){
    // Input
    keyOperations();
    keySpecialOperations();

    // Game logic
    update();

    //
    render();

    //Run frame one more time
    glutTimerFunc( 1000 / SCREEN_FPS, runMainLoop, val );
}
