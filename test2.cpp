/*
 * test1.cpp
 *
 *  Created on: Jul 4, 2015
 *      Author: cch
 */

#include <GL/glut.h>

GLfloat x = 0.0f;
GLfloat y = 0.0f;
GLfloat rsize = 25;

GLfloat xstep = 1.0f;
GLfloat ystep = 1.0f;

GLfloat windowWidth;
GLfloat windowHeight;

//绘制场景
void RenderScene()
{
	//用当前清除颜色清除窗口
	glClear(GL_COLOR_BUFFER_BIT);

	//选择当前绘图颜色
	glColor3f(1.0f, 0.0f, 0.0f);

	//当前颜色画矩形， 左上角， 右下角
	glRectf(x, y, x + rsize, y - rsize);

	//刷新绘图
	glutSwapBuffers();
}

void TimerFunction(int value)
{
	// Reverse direction when you reach left or right edge
	if(x > windowWidth-rsize || x < -windowWidth)
		xstep = -xstep;

	// Reverse direction when you reach top or bottom edge
	if(y > windowHeight || y < -windowHeight + rsize)
		ystep = -ystep;

	// Actually move the square
	x += xstep;
	y += ystep;

	// Check bounds. This is in case the window is made
	// smaller while the rectangle is bouncing and the
	// rectangle suddenly finds itself outside the new
	// clipping volume
	if(x > (windowWidth-rsize + xstep))
		x = windowWidth-rsize-1;
	else if(x < -(windowWidth + xstep))
		x = -windowWidth -1;

	if(y > (windowHeight + ystep))
		y = windowHeight-1;
	else if(y < -(windowHeight - rsize + ystep))
		y = -windowHeight + rsize - 1;



	// Redraw the scene with new coordinates
	glutPostRedisplay();
	glutTimerFunc(33,TimerFunction, 1);
}

// 设置渲染状态
void SetupRC()
{
	//设置一种颜色用于清理窗口，RGBA
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

//窗口改变时回调函数
void ChangeSize(GLsizei w, GLsizei h)
{
	GLfloat aspectRatio;

	//防止0除
	if (h == 0) h = 1;
	//设置当前视口大小
	glViewport(0, 0, w, h);

	//重置坐标系统
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//建立裁剪区域
	aspectRatio = (GLfloat)w / (GLfloat)h;
	if (w <= h){
		windowWidth = 100;
		windowHeight = 100 / aspectRatio;
		//参数： x轴最小最大，y轴，z轴
		glOrtho(-100.0, 100.0, windowHeight, -windowHeight, 1.0, -1.0);
	}
	else{
		windowWidth = 100 / aspectRatio;
		windowHeight = 100;
		glOrtho(-windowWidth, windowWidth, -100, 100.0, 1.0, -1.0);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char **argv)
{
	//初始化GLUT函数库
	glutInit(&argc, argv);
	//设置窗口现实模式，双缓冲，RGB模式
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	//设置窗口大小
	glutInitWindowSize(800, 600);
	//创建窗口
	glutCreateWindow("Simple");
	//显示回调函数，需要重新绘制时调用
	glutDisplayFunc(RenderScene);
	//设置窗口大小改变时回调函数
	glutReshapeFunc(ChangeSize);
	//timer回调
	glutTimerFunc(33,TimerFunction, 1);
	//初始化渲染
	SetupRC();
	//开始消息循环
	glutMainLoop();
	return 0;
}


