//////////////////////////////////////////////////////////////////////////////
// Video Texture: This program shows that OpenCV images can be used as
// texture in OpenGL. It can be used as first step in development of
// an Augmented Reality application
//
// Copyright (C) 2009  Arsalan Malik (arsalank2@hotmail.com)
//                                                                            
// This program is free software: you can redistribute it and/or modify       
// it under the terms of the GNU General Public License as published by       
// the Free Software Foundation, either version 3 of the License, or          
// (at your option) any later version.                                        
//                                                                            
// This program is distributed in the hope that it will be useful,            
// but WITHOUT ANY WARRANTY; without even the implied warranty of             
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              
// GNU General Public License for more details.                               
//                                                                            
// You should have received a copy of the GNU General Public License          
// along with this program.  If not, see <http://www.gnu.org/licenses/>.      
//                                                                            
//////////////////////////////////////////////////////////////////////////////


#include <cv.h>
#include <highgui.h>

#include <stdio.h>
#include <string.h>
#include <GL/glut.h>

#define VIEWPORT_WIDTH              640
#define VIEWPORT_HEIGHT             480
#define KEY_ESCAPE                  27


CvCapture* g_Capture;
GLint g_hWindow;

GLvoid InitGL();
GLvoid OnDisplay();
GLvoid OnReshape(GLint w, GLint h);
GLvoid OnKeyPress (unsigned char key, GLint x, GLint y);
GLvoid OnIdle();

int main(int argc, char* argv[])
{

	// Create GLUT Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(VIEWPORT_WIDTH, VIEWPORT_HEIGHT);

	g_hWindow = glutCreateWindow("Video Texture");

	// Create OpenCV camera capture
	// If multiple cameras are installed, please choose correct index
	g_Capture = cvCaptureFromAVI(argv[1]);
	assert(g_Capture);

	// Initialize OpenGL
	InitGL();

	glutMainLoop();

	return 0;
}

GLvoid InitGL()
{  

	glClearColor (0.0, 0.0, 0.0, 0.0);

	glutDisplayFunc(OnDisplay);
	glutReshapeFunc(OnReshape);
	glutKeyboardFunc(OnKeyPress);
	glutIdleFunc(OnIdle);

}

GLvoid OnDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);

	// Set Projection Matrix
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, VIEWPORT_WIDTH, VIEWPORT_HEIGHT, 0);

	// Switch to Model View Matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Draw a textured quad
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(VIEWPORT_WIDTH, 0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(VIEWPORT_WIDTH, VIEWPORT_HEIGHT);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, VIEWPORT_HEIGHT);
	glEnd();

	glFlush();
	glutSwapBuffers();

}


GLvoid OnReshape(GLint w, GLint h)
{
	glViewport(0, 0, w, h);
}

GLvoid OnKeyPress(unsigned char key, int x, int y)
{
	switch (key) {
	  case KEY_ESCAPE:
		  cvReleaseCapture(&g_Capture);
		  glutDestroyWindow(g_hWindow);
		  exit(0);
		  break;
	}
	glutPostRedisplay();
}


GLvoid OnIdle()
{
  std::cout << "ICI " << std::endl;
	// Capture next frame
	IplImage *image = cvQueryFrame(g_Capture);
  std::cout << "ICI 1" << std::endl;

	// Convert to RGB
	cvCvtColor(image, image, CV_BGR2RGB);
 std::cout << "ICI 2" << std::endl;

	// Create Texture
	gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, image->width, image->height, GL_RGB, GL_UNSIGNED_BYTE, image->imageData);
 std::cout << "ICI 3" << std::endl;

	// Update View port
	glutPostRedisplay();
}

