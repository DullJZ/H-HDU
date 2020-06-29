#include<iostream>
#include<stdio.h>
#include<string.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#define MAXELEM 100

int main()
{
	typedef struct coord {
		double x1;
		double y1;
		double x2;
		double y2;
	}coord;

	coord Line[MAXELEM];
	coord Rectangle[MAXELEM];
	coord Ellipse[MAXELEM];
	coord Word[MAXELEM];
	static int temp_l = 0;//�ֱ�Ϊ ֱ��/����/��Բ/���� ����Ŀ
	static int temp_r = 0;
	static int temp_e = 0;
	static int temp_w = 0;
	initgraph(980, 756);//��ʼ��ͼ��


	setcolor(GREEN);
	for (int i = 54, k = 0; i < 756; i += 30, k++)
	{
		if (k % 5 == 0)
			i += 24;
		rectangle(10, i, 210, i + 30);
	}
	/*���߲���*/
	setlinestyle(PS_DASH);
	line(220, 0, 220, 756);
	line(0, 60, 980, 60);
	setlinestyle(PS_SOLID);
	/*���ֲ���*/
	outtextxy(84, 24, "ѡ�����");
	outtextxy(512, 24, "��ͼ����");
	outtextxy(102, 83, "ֱ��");
	outtextxy(102, 257, "����");
	outtextxy(102, 431, "��Բ");
	outtextxy(102, 605, "����");
	outtextxy(12, 113, "����ֱ��");
	outtextxy(12, 143, "ɾ��ֱ��");
	outtextxy(12, 173, "�ı��С");
	outtextxy(12, 203, "�ƶ�ֱ��");
	outtextxy(12, 292, "���þ���");
	outtextxy(12, 322, "ɾ������");
	outtextxy(12, 352, "�ı��С");
	outtextxy(12, 382, "�ƶ�����");
	outtextxy(12, 461, "������Բ");
	outtextxy(12, 491, "ɾ����Բ");
	outtextxy(12, 521, "�ı��С");
	outtextxy(12, 551, "�ƶ���Բ");
	outtextxy(12, 640, "��������");
	outtextxy(12, 670, "ɾ������");
	outtextxy(12, 700, "�ı��С");
	outtextxy(12, 730, "�ƶ�����");


	/*LINE: 74-709 ���ܲ���*/


	MOUSEMSG m;											// ���������Ϣ
	while (true)
	{
	Flag_ChoiceAgain:
		double START_X, START_Y, END_X, END_Y;

		m = GetMouseMsg();
		/*��ͼ�����������ѡ����*/
		if (m.uMsg == WM_LBUTTONDOWN)
		{

			/*��ͼ��ѡ��ֱ����صĲ���*/
			/*LINE: 88-281 ֱ�߲���*/

			if (10 <= m.x && m.x <= 210 && 108 <= m.y && m.y <= 228)
			{
				/*1:����ֱ��*/
				if (m.y <= 138)
				{
				Flag_LineAgain:
					while (true)
					{
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)		//�����������ȡ���
						{
							START_X = m.x;
							START_Y = m.y;
							Line[temp_l].x1 = m.x;
							Line[temp_l].y1 = m.y;
							while (START_X >= 220 && START_Y >= 60)//ȷ���������ͼ����
							{
								m = GetMouseMsg();
								if (m.uMsg == WM_LBUTTONUP)//������𣬻�ȡ�յ�
								{
									END_X = m.x;
									END_Y = m.y;
									Line[temp_l].x2 = m.x;
									Line[temp_l].y2 = m.y;
									if (END_X >= 220 && END_Y >= 60)//ȷ���յ�����ͼ����
									{
										setcolor(RED);
										line(START_X, START_Y, END_X, END_Y);
										temp_l++;				//ֱ�ߵ�������һ
										goto Flag_LineAgain;	//�ظ�����
									}
								}
								else if (m.uMsg == WM_RBUTTONUP)
								{
									goto Flag_ChoiceAgain;
								}

							}
						}
						else if (m.uMsg == WM_RBUTTONDOWN)//�����Ҽ��ص�����ѡ������
							goto Flag_ChoiceAgain;
					}
				}
				/*2:ɾ��ֱ��*/
				else if (m.y <= 168)
				{
				Flag_DeleteAgain:
					while (true)
					{
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)		//���������ɾ���߶�
						{
							int i;
							for (i = 0; i < temp_l; i++)	//����ֱ�����飬Ѱ�ҷ���������ֱ��
							{
								if (m.x >= 220 && m.y >= 60)//��������Ϊ��ͼ����
									if (fabs((Line[i].y2 - Line[i].y1) / (Line[i].x2 - Line[i].x1) - (Line[i].y2 - m.y) / (Line[i].x2 - m.x)) <= 0.1)//ֻҪ��һ��ֱ���ϣ���ѡ��
									{
										setcolor(BLACK);
										line(Line[i].x1, Line[i].y1, Line[i].x2, Line[i].y2);
										for (int k = i; k < temp_l - 1; k++)//���Դ洢�����Ժ���ֱ����Ҫ��ǰ��һλ
										{
											Line[k].x1 = Line[k + 1].x1;
											Line[k].y1 = Line[k + 1].y1;
											Line[k].x2 = Line[k + 1].x2;
											Line[k].y2 = Line[k + 1].y2;
										}
										temp_l--;

										goto Flag_DeleteAgain;//�ظ�ɾ��
									}
							}
						}
						else if (m.uMsg == WM_RBUTTONDOWN)//�����Ҽ�,�ص�����ѡ�����
						{

							goto Flag_ChoiceAgain;
						}
					}
				}
				/*3:�ı�ֱ�ߴ�С*/
				else if (m.y <= 198)
				{
				Flag_ChoiceLineAgain:
					while (true)
					{
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)		//�������,ѡ���߶�
						{
							int i;
							for (i = 0; i < temp_l; i++)
							{
								if (m.x >= 220 && m.y >= 60)		//��������Ϊ��ͼ����
									if (fabs((Line[i].y2 - Line[i].y1) / (Line[i].x2 - Line[i].x1) - (Line[i].y2 - m.y) / (Line[i].x2 - m.x)) <= 0.1)//ֻҪ��һ��ֱ���ϣ���ѡ��
									{
										double k = (Line[i].y2 - Line[i].y1) / (Line[i].x2 - Line[i].x1);//����б��
									again:
										char ch;
										ch = getch();
										if (ch == 'w')					//����w����
										{
											setcolor(BLACK);
											line(Line[i].x1, Line[i].y1, Line[i].x2, Line[i].y2);
											Line[i].x1 -= 50;
											Line[i].y1 -= 50 * k;
											Line[i].x2 += 50;
											Line[i].y2 += 50 * k;
											setcolor(RED);
											line(Line[i].x1, Line[i].y1, Line[i].x2, Line[i].y2);
											goto again;
										}
										if (ch == 's')			//����s��С
										{
											setcolor(BLACK);
											line(Line[i].x1, Line[i].y1, Line[i].x2, Line[i].y2);
											Line[i].x1 += 50;
											Line[i].y1 += 50 * k;
											Line[i].x2 -= 50;
											Line[i].y2 -= 50 * k;
											setcolor(RED);
											line(Line[i].x1, Line[i].y1, Line[i].x2, Line[i].y2);
											goto again;
										}
										goto Flag_ChoiceLineAgain;
									}
							}
						}
						else if (m.uMsg == WM_RBUTTONDOWN)//�����Ҽ������¹���ѡ��
						{

							goto Flag_ChoiceAgain;
						}

					}
				}
				/*4:�ƶ�ֱ��*/
				else if (m.y <= 228)
				{
				Flag_MoveAgain:
					while (true)
					{
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)		//���������ѡ���߶�
						{
							int i;
							for (i = 0; i < temp_l; i++)		//ɸѡ�߶�
							{
								if (m.x >= 220 && m.y >= 60)//��������ƶ�����Ϊ��ͼ����
									if (fabs((Line[i].y2 - Line[i].y1) / (Line[i].x2 - Line[i].x1) - (Line[i].y2 - m.y) / (Line[i].x2 - m.x)) <= 0.1)//ֻҪ��һ��ֱ���ϣ���ѡ��
									{
										double START_X, START_Y, END_X, END_Y;
										START_X = m.x;
										START_Y = m.y;
										setcolor(BLACK);
										line(Line[i].x1, Line[i].y1, Line[i].x2, Line[i].y2);
										while (START_X >= 220 && START_Y >= 60)
										{
											m = GetMouseMsg();
											if (m.uMsg == WM_LBUTTONUP)//������𣬻�ȡ�յ�
											{
												END_X = m.x;
												END_Y = m.y;
												if (END_X >= 220 && END_Y >= 60)
												{
													setcolor(RED);
													double D_x = END_X - START_X;
													double D_y = END_Y - START_Y;
													Line[i].x1 += D_x;
													Line[i].x2 += D_x;
													Line[i].y1 += D_y;
													Line[i].y2 += D_y;
													line(Line[i].x1, Line[i].y1, Line[i].x2, Line[i].y2);
													goto Flag_MoveAgain;//�ظ�ѡ���߶��ƶ�
												}
											}
											else if (m.uMsg == WM_RBUTTONUP)
											{

												goto Flag_ChoiceAgain;
											}
										}
										goto Flag_MoveAgain;//����ѡ���߶��ƶ�
									}
							}
						}
						else if (m.uMsg == WM_RBUTTONDOWN)//�����Ҽ�,�ص�����ѡ�����
						{

							goto Flag_ChoiceAgain;
						}
					}
				}
			}

			/*��ͼ��ѡ�������صĲ���*/
			/*LINE: 286-498 ���β���*/

			if (10 <= m.x && m.x <= 210 && 282 <= m.y && m.y <= 402)
			{
				/*1:���þ���*/
				if (m.y <= 312)
				{
				Flag_RectangleAgain:
					while (true)
					{
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)		//�����������ȡ�������϶���
						{
							START_X = m.x;
							START_Y = m.y;
							Rectangle[temp_r].x1 = m.x;
							Rectangle[temp_r].y1 = m.y;
							while (START_X >= 220 && START_Y >= 60)//ȷ���������ͼ����
							{
								m = GetMouseMsg();
								if (m.uMsg == WM_LBUTTONUP)//������𣬻�ȡ�������¶���
								{
									END_X = m.x;
									END_Y = m.y;
									Rectangle[temp_r].x2 = m.x;
									Rectangle[temp_r].y2 = m.y;
									if (END_X >= 220 && END_Y >= 60)//ȷ���յ�����ͼ����
									{
										setcolor(RED);
										rectangle(START_X, START_Y, END_X, END_Y);
										temp_r++;				//���ε�������һ
										goto Flag_RectangleAgain;	//�ظ�������
									}
								}
								else if (m.uMsg == WM_RBUTTONUP)
								{

									goto Flag_ChoiceAgain;
								}

							}
						}
						else if (m.uMsg == WM_RBUTTONDOWN)//�����Ҽ��ص�����ѡ������
							goto Flag_ChoiceAgain;
					}
				}
				/*2:ɾ������*/
				else if (m.y <= 342)
				{
				Flag_DeleteRectangleAgain:
					while (true)
					{
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)		//���������ɾ������
						{
							int i;
							for (i = 0; i < temp_r; i++)	//�����������飬Ѱ�ҷ��������ľ���
							{
								if (m.x >= 220 && m.y >= 60)//��������Ϊ��ͼ����
								{
									bool a = (fabs(m.x - Rectangle[i].x1) < 5);
									bool b = (fabs(m.x - Rectangle[i].x2) < 5);
									bool c = (fabs(m.y - Rectangle[i].y1) < 5);
									bool d = (fabs(m.y - Rectangle[i].y2) < 5);
									if((a||b)&&(c||d))//���������һ���㼴ѡ��
									{
										setcolor(BLACK);
										rectangle(Rectangle[i].x1, Rectangle[i].y1, Rectangle[i].x2, Rectangle[i].y2);
										for (int k = i; k < temp_r - 1; k++)//���Դ洢�����Ժ���������Ҫ��ǰ��һλ
										{
											Rectangle[k].x1 = Rectangle[k + 1].x1;
											Rectangle[k].y1 = Rectangle[k + 1].y1;
											Rectangle[k].x2 = Rectangle[k + 1].x2;
											Rectangle[k].y2 = Rectangle[k + 1].y2;
										}
										temp_r--;

										goto Flag_DeleteRectangleAgain;//�ظ�ɾ��
									}
								}
							}
						}
						else if (m.uMsg == WM_RBUTTONDOWN)//�����Ҽ�,�ص�����ѡ�����
						{

							goto Flag_ChoiceAgain;
						}
					}
				}
				/*3:�ı���δ�С*/
				else if (m.y <= 372)
				{
					Flag_ChoiceRectangleAgain:
					while (true)
					{
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)		//�������,ѡ�о���
						{
							int i;
							for (i = 0; i < temp_r; i++)
							{
								if (m.x >= 220 && m.y >= 60)		//��������Ϊ��ͼ����
								{
									bool a = (fabs(m.x - Rectangle[i].x1) < 5);
									bool b = (fabs(m.x - Rectangle[i].x2) < 5);
									bool c = (fabs(m.y - Rectangle[i].y1) < 5);
									bool d = (fabs(m.y - Rectangle[i].y2) < 5);
									if ((a || b) && (c || d))//���������һ���㼴ѡ��
									{
										double k = (Rectangle[i].y2 - Rectangle[i].y1) / (Rectangle[i].x2 - Rectangle[i].x1);//�����
										Again:
										char ch;
										ch = getch();
										if (ch == 'w')					//����w����
										{
											setcolor(BLACK);
											rectangle(Rectangle[i].x1, Rectangle[i].y1, Rectangle[i].x2, Rectangle[i].y2);
											Rectangle[i].x1 -= 50;
											Rectangle[i].y1 -= 50 * k;
											Rectangle[i].x2 += 50;
											Rectangle[i].y2 += 50 * k;
											setcolor(RED);
											rectangle(Rectangle[i].x1, Rectangle[i].y1, Rectangle[i].x2, Rectangle[i].y2);
											goto Again;
										}
										if (ch == 's')			//����s��С
										{
											setcolor(BLACK);
											rectangle(Rectangle[i].x1, Rectangle[i].y1, Rectangle[i].x2, Rectangle[i].y2);
											Rectangle[i].x1 += 50;
											Rectangle[i].y1 += 50 * k;
											Rectangle[i].x2 -= 50;
											Rectangle[i].y2 -= 50 * k;
											setcolor(RED);
											rectangle(Rectangle[i].x1, Rectangle[i].y1, Rectangle[i].x2, Rectangle[i].y2);
											goto Again;
										}
										goto Flag_ChoiceRectangleAgain;
									}
								}
							}
						}
						else if (m.uMsg == WM_RBUTTONDOWN)//�����Ҽ������¹���ѡ��
						{

							goto Flag_ChoiceAgain;
						}

					}
				}
				/*4:�ƶ�����*/
				else if (m.y <= 402)
				{
				Flag_MoveRectangleAgain:
					while (true)
					{
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)		//���������ѡ���߶�
						{
							int i;
							for (i = 0; i < temp_r; i++)		//ɸѡ�߶�
							{
								if (m.x >= 220 && m.y >= 60)//��������ƶ�����Ϊ��ͼ����
								{
									bool a = (fabs(m.x - Rectangle[i].x1) < 5);
									bool b = (fabs(m.x - Rectangle[i].x2) < 5);
									bool c = (fabs(m.y - Rectangle[i].y1) < 5);
									bool d = (fabs(m.y - Rectangle[i].y2) < 5);
									if ((a || b) && (c || d))//���������һ���㼴ѡ��
									{
										double START_X, START_Y, END_X, END_Y;
										START_X = m.x;
										START_Y = m.y;
										setcolor(BLACK);
										rectangle(Rectangle[i].x1, Rectangle[i].y1, Rectangle[i].x2, Rectangle[i].y2);
										while (START_X >= 220 && START_Y >= 60)
										{
											m = GetMouseMsg();
											if (m.uMsg == WM_LBUTTONUP)//������𣬻�ȡ�յ�
											{
												END_X = m.x;
												END_Y = m.y;
												if (END_X >= 220 && END_Y >= 60)
												{
													setcolor(RED);
													double D_x = END_X - START_X;
													double D_y = END_Y - START_Y;
													Rectangle[i].x1 += D_x;
													Rectangle[i].x2 += D_x;
													Rectangle[i].y1 += D_y;
													Rectangle[i].y2 += D_y;
													rectangle(Rectangle[i].x1, Rectangle[i].y1, Rectangle[i].x2, Rectangle[i].y2);
													goto Flag_MoveRectangleAgain;//�ظ�ѡ���߶��ƶ�
												}
											}
											else if (m.uMsg == WM_RBUTTONUP)
											{

												goto Flag_ChoiceAgain;
											}
										}
										goto Flag_MoveAgain;//����ѡ���߶��ƶ�
									}
								}

							}
						}
						else if (m.uMsg == WM_RBUTTONDOWN)//�����Ҽ�,�ص�����ѡ�����
						{

							goto Flag_ChoiceAgain;
						}
					}
				}
			}

			/*��ͼ��ѡ����Բ��صĲ���*/
			/*LINE: 503-715 ��Բ����*/
			if (10 <= m.x && m.x <= 210 && 456 <= m.y && m.y <= 576)
			{
				/*1:������Բ*/
				if (m.y <= 486)
				{
				Flag_EllipseAgain:
					while (true)
					{
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)		//�����������ȡ���
						{
							START_X = m.x;
							START_Y = m.y;
							Ellipse[temp_e].x1 = m.x;
							Ellipse[temp_e].y1 = m.y;
							while (START_X >= 220 && START_Y >= 60)//ȷ���������ͼ����
							{
								m = GetMouseMsg();
								if (m.uMsg == WM_LBUTTONUP)//������𣬻�ȡ�յ�
								{
									END_X = m.x;
									END_Y = m.y;
									Ellipse[temp_e].x2 = m.x;
									Ellipse[temp_e].y2 = m.y;
									if (END_X >= 220 && END_Y >= 60)//ȷ���յ�����ͼ����
									{
										setcolor(RED);
										ellipse((START_X*0.5+END_X*0.5),START_Y,0, 0, (END_X*0.5-START_X*0.5), (END_Y-START_Y));
										temp_e++;		//ֱ�ߵ�������һ
										goto Flag_EllipseAgain;	//�ظ�����
									}
								}
								else if (m.uMsg == WM_RBUTTONUP)
								{

									goto Flag_ChoiceAgain;
								}

							}
						}
						else if (m.uMsg == WM_RBUTTONDOWN)//�����Ҽ��ص�����ѡ������
							goto Flag_ChoiceAgain;
					}
				}
				/*2:ɾ����Բ*/
				else if (m.y <= 516)
				{
				Flag_DeleteEAgain:
					while (true)
					{
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)		//���������ɾ����Բ
						{
							int i;
							for (i = 0; i < temp_e; i++)	//������Բ���飬Ѱ�ҷ���������ֱ��
							{
								if (m.x >= 220 && m.y >= 60)//��������Ϊ��ͼ����
								{
									bool a = (fabs(m.x - Ellipse[i].x1) < 5);
									bool b = (fabs(m.x - Ellipse[i].x2) < 5);
									bool c = (fabs(m.y - Ellipse[i].y1) < 5);
									bool d = (fabs(m.y - Ellipse[i].y2) < 5);
									if((a||b)&&(c||d))//�����Բ������һ���㼴ѡ��
									{
										setcolor(BLACK);

										ellipse((Ellipse[i].x1*0.5+ Ellipse[i].x2*0.5),Ellipse[i].y1,0,0, (Ellipse[i].x2*0.5-Ellipse[i].x1*0.5), (Ellipse[i].y2-Ellipse[i].y1));
										for (int k = i; k < temp_e - 1; k++)//���Դ洢�����Ժ���ֱ����Ҫ��ǰ��һλ
										{
											Ellipse[k].x1 = Ellipse[k + 1].x1;
											Ellipse[k].y1 = Ellipse[k + 1].y1;
											Ellipse[k].x2 = Ellipse[k + 1].x2;
											Ellipse[k].y2 = Ellipse[k + 1].y2;
										}
										temp_e--;

										goto Flag_DeleteEAgain;//�ظ�ɾ��
									}
								}
							}
						}
						else if (m.uMsg == WM_RBUTTONDOWN)//�����Ҽ�,�ص�����ѡ�����
						{

							goto Flag_ChoiceAgain;
						}
					}
				}
				/*3:�ı���Բ��С*/
				else if (m.y <= 546)
				{
				Flag_ChoiceEAgain:
					while (true)
					{
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)		//�������,ѡ����Բ
						{
							int i;
							for (i = 0; i < temp_e; i++)
							{
								if (m.x >= 220 && m.y >= 60)		//��������Ϊ��ͼ����
								{
									bool a = (fabs(m.x - Ellipse[i].x1) < 5);
									bool b = (fabs(m.x - Ellipse[i].x2) < 5);
									bool c = (fabs(m.y - Ellipse[i].y1) < 5);
									bool d = (fabs(m.y - Ellipse[i].y2) < 5);
									if((a||b)&&(c||d))//�����Բ������һ���㼴ѡ��
									{
										double k = (Ellipse[i].y2 - Ellipse[i].y1) / (Ellipse[i].x2 - Ellipse[i].x1);//�����
									_Eagain:
										char ch;
										ch = getch();
										if (ch == 'w')					//����w����
										{
											setcolor(BLACK);
											ellipse((Ellipse[i].x1*0.5+ Ellipse[i].x2*0.5),Ellipse[i].y1,0,0, (Ellipse[i].x2*0.5-Ellipse[i].x1*0.5), (Ellipse[i].y2-Ellipse[i].y1));
											Ellipse[i].x1 -= 50;
											Ellipse[i].y1 -= 50 * k;
											Ellipse[i].x2 += 50;
											Ellipse[i].y2 += 50 * k;
											setcolor(RED);
											ellipse((Ellipse[i].x1*0.5+ Ellipse[i].x2*0.5),Ellipse[i].y1,0,0, (Ellipse[i].x2*0.5-Ellipse[i].x1*0.5), (Ellipse[i].y2-Ellipse[i].y1));
											goto _Eagain;
										}
										if (ch == 's')			//����s��С
										{
											setcolor(BLACK);
											ellipse((Ellipse[i].x1*0.5+ Ellipse[i].x2*0.5),Ellipse[i].y1,0,0, (Ellipse[i].x2*0.5-Ellipse[i].x1*0.5), (Ellipse[i].y2-Ellipse[i].y1));
											Ellipse[i].x1 += 50;
											Ellipse[i].y1 += 50 * k;
											Ellipse[i].x2 -= 50;
											Ellipse[i].y2 -= 50 * k;
											setcolor(RED);
											ellipse((Ellipse[i].x1*0.5+ Ellipse[i].x2*0.5),Ellipse[i].y1,0,0, (Ellipse[i].x2*0.5-Ellipse[i].x1*0.5), (Ellipse[i].y2-Ellipse[i].y1));
											goto _Eagain;
										}
										goto Flag_ChoiceEAgain;
									}
								}

							}
						}
						else if (m.uMsg == WM_RBUTTONDOWN)//�����Ҽ������¹���ѡ��
						{

							goto Flag_ChoiceAgain;
						}

					}
				}
				/*4:�ƶ���Բ*/
				else if (m.y <= 576)
				{
				Flag_MoveEAgain:
					while (true)
					{
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)		//���������ѡ����Բ
						{
							int i;
							for (i = 0; i < temp_e; i++)		//ɸѡ��Բ
							{
								if (m.x >= 220 && m.y >= 60)//��������ƶ�����Ϊ��ͼ����
								{
									bool a = (fabs(m.x - Ellipse[i].x1) < 5);
									bool b = (fabs(m.x - Ellipse[i].x2) < 5);
									bool c = (fabs(m.y - Ellipse[i].y1) < 5);
									bool d = (fabs(m.y - Ellipse[i].y2) < 5);
									if((a||b)&&(c||d))//�����Բ������һ���㼴ѡ��
									{
										double START_X, START_Y, END_X, END_Y;
										START_X = m.x;
										START_Y = m.y;
										setcolor(BLACK);
										ellipse((Ellipse[i].x1*0.5+ Ellipse[i].x2*0.5),Ellipse[i].y1,0,0, (Ellipse[i].x2*0.5-Ellipse[i].x1*0.5), (Ellipse[i].y2-Ellipse[i].y1));
										while (START_X >= 220 && START_Y >= 60)
										{
											m = GetMouseMsg();
											if (m.uMsg == WM_LBUTTONUP)//������𣬻�ȡ�յ�
											{
												END_X = m.x;
												END_Y = m.y;
												if (END_X >= 220 && END_Y >= 60)
												{
													setcolor(RED);
													double D_x = END_X - START_X;
													double D_y = END_Y - START_Y;
													Ellipse[i].x1 += D_x;
													Ellipse[i].x2 += D_x;
													Ellipse[i].y1 += D_y;
													Ellipse[i].y2 += D_y;
													ellipse((Ellipse[i].x1*0.5+ Ellipse[i].x2*0.5),Ellipse[i].y1,0,0, (Ellipse[i].x2*0.5-Ellipse[i].x1*0.5), (Ellipse[i].y2-Ellipse[i].y1));
													goto Flag_MoveEAgain;//�ظ�ѡ����Բ�ƶ�
												}
											}
											else if (m.uMsg == WM_RBUTTONUP)
											{

												goto Flag_ChoiceAgain;
											}
										}
										goto Flag_MoveEAgain;//����ѡ����Բ�ƶ�
									}
								}
							}
						}
						else if (m.uMsg == WM_RBUTTONDOWN)//�����Ҽ�,�ص�����ѡ�����
						{

							goto Flag_ChoiceAgain;
						}
					}
				}
			}

			//������
			if (10 <= m.x && m.x <= 210 && 635 <= m.y && m.y <= 745)
            {
                char ch;
                if(m.y<665)
                {
                    Flag_WordAgain:
                    while(true)
                    {
                        m = GetMouseMsg();
                        if (m.uMsg == WM_LBUTTONDOWN)
                        {
                            START_X = m.x;
							START_Y = m.y;
							Word[temp_w].x1 = m.x;
							Word[temp_w].y1 = m.y;
							while (START_X >= 220 && START_Y >= 60)
                            {
                                m = GetMouseMsg();
								if (m.uMsg == WM_LBUTTONUP)
                                {


                                    if (START_X >= 220 && START_Y >= 60)
                                        {
                                moveto(START_X,START_Y);

                                setcolor(RED);
                                ch = getch();
                                xyprintf(START_X,START_Y,&ch);
                                temp_w++;
                                goto Flag_WordAgain;
                                        }
                                }


                        else if (m.uMsg == WM_RBUTTONUP)
                        {
                            goto Flag_ChoiceAgain;
                        }
                            }
                        }
                    else if (m.uMsg == WM_RBUTTONDOWN)//�����Ҽ��ص�����ѡ������
							goto Flag_ChoiceAgain;
                }
            }


            else if (m.y <= 695)
				{
				Flag_DeleteWordAgain:
					while (true)
					{
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							int i;
							for (i = 0; i < temp_w; i++)
							{
								if (m.x >= 220 && m.y >= 60)//��������Ϊ��ͼ����
								{
									bool a = (fabs(m.x - Word[i].x1) < 5);
									bool b = (fabs(m.x - Word[i].x2) < 5);
									if((a||b))
									{
										setcolor(BLACK);
                                        xyprintf(Word[i].x1,Word[i].y1,&ch);
										for (int k = i; k < temp_w - 1; k++)
										{
											Word[k].x1 = Word[k + 1].x1;
											Word[k].y1 = Word[k + 1].y1;
										}
										temp_w--;
										goto Flag_DeleteWordAgain;//�ظ�ɾ��
									}
								}
							}
						}

                    }
                }


//����
            else if (m.y <= 725)
				{
				Flag_ChoiceWAgain:
					while (true)
					{
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							int i;
							for (i = 0; i < temp_w; i++)
							{
								if (m.x >= 220 && m.y >= 60)
								{
									bool a = (fabs(m.x - Word[i].x1) < 5);
									bool b = (fabs(m.y - Word[i].y1) < 5);
									if(a||b)//
									{
									    _Wagain:
										char s;
										s = getch();
										if (s == 'w')					//����w����
										{
											setcolor(BLACK);
											xyprintf(Word[i].x1,Word[i].y1,&ch);
											LOGFONTA f;
											getfont(&f);
											f.lfHeight+=4;
											setfont(f.lfHeight, 0,"����");
											setcolor(RED);
											xyprintf(Word[i].x1,Word[i].y1,&ch);
											goto _Wagain;
										}
										if (s == 's')					//����w����
										{
											setcolor(BLACK);
											xyprintf(Word[i].x1,Word[i].y1,&ch);
											LOGFONTA f;
											getfont(&f);
											f.lfHeight-=4;
											setfont(f.lfHeight, 0,"����");
											setcolor(RED);
											xyprintf(Word[i].x1,Word[i].y1,&ch);
											goto _Wagain;
										}
										goto Flag_ChoiceWAgain;
									}
								}

							}
						}
						else if (m.uMsg == WM_RBUTTONDOWN)//�����Ҽ������¹���ѡ��
						{

							goto Flag_ChoiceAgain;
						}

					}
				}
				//�ƶ�
            else if (m.y <= 745)
				{
				Flag_MoveWAgain:
					while (true)
					{
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)		//�������
						{
							int i;
							for (i = 0; i < temp_w; i++)		//ɸѡ
							{
								if (m.x >= 220 && m.y >= 60)//��������ƶ�����Ϊ��ͼ����
								{
									bool a = (fabs(m.x - Word[i].x1) < 5);
									bool b = (fabs(m.y - Word[i].y1) < 5);
									if((a||b))//��
									{
										double START_X, START_Y;
										START_X = m.x;
										START_Y = m.y;
										setcolor(BLACK);
										xyprintf(Word[i].x1,Word[i].y1,&ch);
										while (START_X >= 220 && START_Y >= 60)
										{
											m = GetMouseMsg();
											if (m.uMsg == WM_LBUTTONUP)//������𣬻�ȡ�յ�
											{
												END_X = m.x;
												END_Y = m.y;
												if (END_X >= 220 && END_Y >= 60)
												{
													setcolor(RED);
													double D_x = END_X - START_X;
													double D_y = END_Y - START_Y;
													Word[i].x1 += D_x;
													Word[i].y1 += D_y;

													xyprintf(Word[i].x1,Word[i].y1,&ch);
													goto Flag_MoveWAgain;//�ظ�ѡ����Բ�ƶ�
												}
											}
											else if (m.uMsg == WM_RBUTTONUP)
											{

												goto Flag_ChoiceAgain;
											}
										}
										goto Flag_MoveWAgain;//����ѡ����Բ�ƶ�
									}
								}
							}
						}
						else if (m.uMsg == WM_RBUTTONDOWN)//�����Ҽ�,�ص�����ѡ�����
						{

							goto Flag_ChoiceAgain;
						}
					}
				}



            }//������
		}

		}

	getch();
	closegraph();

	return 0;
}
