/*
 * test1.cpp
 *
 *  Created on: Jul 4, 2015
 *      Author: cch
 */

#include <GL/glut.h>

//绘制场景
void RenderScene()
{
	//用当前清除颜色清除窗口
	glClear(GL_COLOR_BUFFER_BIT);

	//选择当前绘图颜色
	glColor3f(1.0f, 0.0f, 0.0f);

	//当前颜色画矩形， 左上角， 右下角
	glRectf(-25.0f, 25.0f, 25.0f, -25.0f);

	//刷新绘图
	glFlush();
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
	if (w <= h)
		//参数： x轴最小最大，y轴，z轴
		glOrtho(-100.0, 100.0, -100 / aspectRatio, 100.0/aspectRatio, 1.0, -1.0);
	else
		glOrtho(-100.0 * aspectRatio , 100.0 * aspectRatio, -100, 100.0, 1.0, -1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char **argv)
{
	//初始化GLUT函数库
	glutInit(&argc, argv);
	//设置窗口现实模式，单缓冲，RGB模式
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	//创建窗口
	glutCreateWindow("Simple");
	//显示回调函数，需要重新绘制时调用
	glutDisplayFunc(RenderScene);
	//设置窗口大小改变时回调函数
	glutReshapeFunc(ChangeSize);
	//初始化渲染
	SetupRC();
	//开始消息循环
	glutMainLoop();
	return 0;
}


