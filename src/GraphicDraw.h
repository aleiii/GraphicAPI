//#pragma once
//#ifdef GRAPHICDRAW_H
//#define GRAPHICDRAW_H

#include <iostream>
#include "GraphicAPI.h"
using namespace std;
namespace ALEI
{
	// Bresenham �㷨��ֱ�߶�
	void line(HDC hdc, int x1, int y1, int x2, int y2);
	// ʹ����������Բ
	void circle(HDC hdc, int x, int y, int r, double r0, double r1);
	// ʹ���е��㷨����Բ
	void ellipse(HDC hdc, int x0, int y0, int a, int b);
	// ����ͨ���ڵ��ʾ����ɫ�����ˮ�㷨
	void Flood_Fill_4(HDC hdc, int x, int y, COLORREF old_color, COLORREF new_color);
	// ��Ӱ������㷨
	void Shadow_Fill(HDC hdc);
	// ������
	void Draw_Name(HDC hdc);
	
}

//#endif