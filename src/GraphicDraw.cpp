#include "GraphicAPI.h"

#include <iostream>
using namespace std;

namespace ALEI
{
	// Bresenham �㷨��ֱ�߶�
	void line(HDC hdc, int x1, int y1, int x2, int y2)
	{
		// ��ʼ��
		int x = x1;
		int y = y1;
		// ����ֵ
		int dx = abs(x1 - x2);
		int dy = abs(y1 - y2);
		// �ڶ������ڵ�һ�����ұߣ���x�������λΪ1������Ϊ-1��yͬ��
		int ux = x2 > x1 ? 1 : -1;
		int uy = y2 > y1 ? 1 : -1;


		int is_change = false;
		// б�ʾ���ֵ����1���򽻻�dy��dx
		if (dy > dx)
		{
			int temp = dx;
			dx = dy;
			dy = temp;
			is_change = true;
		}
		int e = 2 * dy - dx;
		for (int i = 0; i < dx; i++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
			// б�ʾ���ֵ����1������yΪ����
			if (is_change)
				y += uy;
			else
				x += ux;
			// �б�ʽ
			if (e >= 0)
			{
				if (is_change)
					x += ux;
				else
					y += uy;
				e -= 2 * dx;
			}
			e += 2 * dy;
		}
	}
	
	// ʹ����������Բ
	void circle(HDC hdc, int x, int y, int r, double r0, double r1)
	{
		int dx = 0, dy = r, f = 0;
		double x0 = r * cos(r0) + x, x1 = r * cos(r1) + x;
		while (dx <= dy)
		{
			// �˸��ԳƵ�
			// ��һ��������������
			if (r0 <= pi / 2 && (x + dx) <= x0)
			{
				if (r1 >= pi / 2)
					SetPixel(hdc, x + dx, y - dy, RGB(0, 0, 0));
				else if ((x + dx) >= x1)
					SetPixel(hdc, x + dx, y - dy, RGB(0, 0, 0));
			}
			// ������������������
			if (r1 >= 3 * pi / 2 && (x + dx) <= x1)
			{
				if (r0 <= 3 * pi / 2)
					SetPixel(hdc, x + dx, y + dy, RGB(0, 0, 0));
				else if ((x + dx) >= x0)
					SetPixel(hdc, x + dx, y + dy, RGB(0, 0, 0));
			}
			// �ڶ���������������
			if (r0 <= 3 * pi / 4 && (x - dx) <= x0)
			{
				if (r1 >= 3 * pi / 4)
					SetPixel(hdc, x - dx, y - dy, RGB(0, 0, 0));
				else if ((x-dx) >= x1)
					SetPixel(hdc, x - dx, y - dy, RGB(0, 0, 0));
			}
			// ������������������
			if (r1 >= 5 * pi / 4 && (x - dx) <= x1)
			{
				if (r0 <= 5 * pi / 4)
					SetPixel(hdc, x - dx, y + dy, RGB(0, 0, 0));
				else if ((x - dx) >= x0)
					SetPixel(hdc, x - dx, y + dy, RGB(0, 0, 0));
			}
			// ��һ��������������
			if (r0 <= pi / 4 && (x + dy) <= x0)
			{
				if (r1 >= pi / 4)
					SetPixel(hdc, x + dy, y - dx, RGB(0, 0, 0));
				else if ((x + dy) >= x1)
					SetPixel(hdc, x + dy, y - dx, RGB(0, 0, 0));
			}
			// ������������������
			if (r1 >= 7 * pi / 4 && (x + dy) <= x1)
			{
				if (r0 <= 7 * pi / 4)
					SetPixel(hdc, x + dy, y + dx, RGB(0, 0, 0));
				else if ((x + dy) >= x0)
					SetPixel(hdc, x + dy, y + dx, RGB(0, 0, 0));
			}
			// �ڶ���������������
			if (r0 <= pi && (x - dy) <= x0)
			{
				if (r1 >= pi)
					SetPixel(hdc, x - dy, y - dx, RGB(0, 0, 0));
				else if ((x - dy) >= x1)
					SetPixel(hdc, x - dy, y - dx, RGB(0, 0, 0));
			}
			// ������������������
			if (r1 >= pi && (x - dy) <= x1)
			{
				if (r0 <= pi)
					SetPixel(hdc, x - dy, y + dx, RGB(0, 0, 0));
				else if ((x - dy) >= x0)
					SetPixel(hdc, x - dy, y + dx, RGB(0, 0, 0));
			}

			if (f < 0)
				f = f + 2 * dx + 1, dx++;
			else
				f = f - 2 * dy + 1, dy--;
		}
	}
	
	// ʹ���е��㷨����Բ
	void ellipse(HDC hdc, int x0, int y0, int a, int b)
	{
	
		double a1 = a * a, b1 = b * b;
		double a2 = 2 * a1, b2 = 2 * b1;
		int x = 0, y = b;	
		double d = b1 + a1 * (-b + 0.25);
		//double c = sqrt(a * a - b * b);
		//double R0 = b1 / (a - c * sin(r0)), R1 = b1 / (a - c * sin(r1));
		//double rx0 = R0 * cos(r0) + x, rx1 = R1 * cos(r1) + x;

		// �ĸ��ԳƵ�
		SetPixel(hdc, x0 + x, y0 + y, RGB(0, 0, 0));
		SetPixel(hdc, x0 - x, y0 + y, RGB(0, 0, 0));
		SetPixel(hdc, x0 + x, y0 - y, RGB(0, 0, 0));
		SetPixel(hdc, x0 - x, y0 - y, RGB(0, 0, 0));

		while (b1 * (x + 1) < a1 * (y - 0.5)) 
		{
			if (d < 0)
				d += b1 * (2 * x + 3);
			else
				d = d+ b1 * (2 * x + 3) + a1 * (-2 * y + 2), y--;
			x++;

			SetPixel(hdc, x0 + x, y0 - y, RGB(0, 0, 0));
			SetPixel(hdc, x0 + x, y0 + y, RGB(0, 0, 0));
			SetPixel(hdc, x0 - x, y0 - y, RGB(0, 0, 0));
			SetPixel(hdc, x0 - x, y0 + y, RGB(0, 0, 0));
		}
		d = b1 * (x + 0.5) * (x + 0.5) + a1 * (y - 1) * (y - 1) - a1 * b1;
	
		while (y >= 0)
		{
			if (d < 0)
				d = d + b1 * (2 * x + 2) + a1 * (-2 * y + 3), x++;
			else
				d += a1 * (-2 * y + 3);
			y--;
			SetPixel(hdc, x0 + x, y0 + y, RGB(0, 0, 0));
			SetPixel(hdc, x0 - x, y0 + y, RGB(0, 0, 0));
			SetPixel(hdc, x0 + x, y0 - y, RGB(0, 0, 0));
			SetPixel(hdc, x0 - x, y0 - y, RGB(0, 0, 0));
		}
	}
	
	// ����ͨ���ڵ��ʾ����ɫ�����ˮ�㷨
	void Flood_Fill_4(HDC hdc, int x, int y, COLORREF old_color, COLORREF new_color)
	{
		// ������ʹ�ø�����ɫ������� 
		if ((GetPixel(hdc, x, y) != RGB(0, 0, 0)) & (GetPixel(hdc, x, y) != new_color)) 
		{
			SetPixel(hdc, x, y, new_color);
	
			Flood_Fill_4(hdc, x, y + 1, old_color, new_color);
			Flood_Fill_4(hdc, x, y - 1, old_color, new_color);
			Flood_Fill_4(hdc, x - 1, y, old_color, new_color);
			Flood_Fill_4(hdc, x + 1, y, old_color, new_color);
		}
	}
	
	bool IsIn(int c, int a, int b)
	{
		return ((c >= a && c < b) || (c >= b && c < a));
	}


	//��Ӱ������㷨
	void Shadow_Fill(HDC hdc)
	{
		int vertex[2][4];
		int distance[4];
		float cross[2][4];
		int k = 1;
		int dis_max = 0;
		int dis_min = 1000000;
		int dis;
		BOOL paint = true;

		/*vertex[0][0] = 100;//Ԥ�ø���������
		vertex[1][0] = 100;
		vertex[0][1] = 200;
		vertex[1][1] = 100;
		vertex[0][2] = 200;
		vertex[1][2] = 200;
		vertex[0][3] = 100;
		vertex[1][3] = 200;*/

		vertex[0][0] = 500;//Ԥ�ø���������
		vertex[1][0] = 400;
		vertex[0][1] = 600;
		vertex[1][1] = 400;
		vertex[0][2] = 500;
		vertex[1][2] = 700;
		vertex[0][3] = 600;
		vertex[1][3] = 700;

		// ������߽ؾ�
		for (int i = 0; i < 4; i++)
			distance[i] = vertex[1][i] - vertex[0][i] * k;

		// ����ؾ�����ֵ����Сֵ
		for (int i = 0; i < 4; i++) 
		{
			if (distance[i] > dis_max)
				dis_max = distance[i];
			else if (distance[i] < dis_min)
				dis_min = distance[i];
		}

		dis = dis_min + 3;

		while (dis <= dis_max) {
			// ����Ӱ����ߵĽ���
			int t = 0;
			for (int i = 0; i < 4; i++) 
			{
				int j = (i + 1) % 4;
				if (!IsIn(dis, distance[i], distance[j]))
					continue;
				if ((vertex[1][j] - vertex[1][i]) - k * (vertex[0][j] - vertex[0][i]) == 0)
					break;
				
				cross[0][t] = (vertex[1][j] * vertex[0][i] - vertex[1][i] * vertex[0][j]
					+ dis * (vertex[0][j] - vertex[0][i])) /
					((vertex[1][j] - vertex[1][i]) - k * (vertex[0][j] - vertex[0][i]));

				cross[1][t] = k * cross[0][t] + dis;
				t++;
			}
			line(hdc, cross[0][0], cross[1][0], cross[0][1], cross[1][1]);//����Ӱ��
			// line(hdc, cross[0][2], cross[1][2], cross[0][3], cross[1][3]);
			dis += 3;
		}
	}
	
}