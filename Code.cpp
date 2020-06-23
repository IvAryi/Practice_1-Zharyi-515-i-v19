/*
* @file    Practice_1_TP.cpp
* @author  Жарый И.И., гр. 515-и
* @date    10 june 2020
* @brief   актика 1-й курс
* @variant 19
*
*
* Завершение с кодом 2 - неверный ввод
* Завершение с кодом 3 - прямая и отрезок параллельны или совпадают
*/


#include <stdio.h>
#include <stdlib.h>


//float tangens_vsemy_head(int, int, int, int);
//float paddiom_Skins(float, int ,int);

int main()
{
	float La, Lb; //Line coef_s
	float xA, yA, xB, yB;//Segment's dots coord_s
	float Sa, Sb;//Segment's line coef_s
	float mesto_vstrechi_izmenit_nizzya_blt;//Inrsect abscissa
	printf("Hello, my dear!\nToday we are going to explore whether the line and segment intersect!\n Firstly, just input the coefficients 'a' and 'b' in line y=ax+b.\na: ");
	scanf_s("%f", &La);
	printf("b: ");
	scanf_s("%f",&Lb);
	printf("Well done!\nSecondly, input the abscissas and ordinates of segment's end's dots A and B\nAbscissa A:");
	scanf_s("%f", &xA);
	printf("Ordinate A:");
	scanf_s("%f", &yA);
	printf("Abscissa B:");
	scanf_s("%f", &xB);
	printf("Ordinate B:");
	scanf_s("%f", &yB);
	//защита от ...
	if (xA > xB)
	{
		float fixA = xA, fixAy = yA;
		xA = xB; yA = yB;
		xB = fixA; yB = fixAy;
		printf("swap!");
	}
	if (xA == xB && yA == yB) {
		printf("Dots have simillar coordinates.");
		exit(2);
	}

	printf("\nOkay. \nSo, we are loocking for line\ny=%f*x+%f\nAnd segment AB, where\nA(%f;%f)\t B(%f;%f)", La, Lb, xA, yA, xB, yB);
	Sa = (yB - yA) / (xB - xA);//tangens_vsemy_head
	printf("\n\nLine y=a1*x+b1, which contains dots A and B had a1=%f ",Sa);
	Sb = yA - Sa * xA;//Coef b
	printf("\nLine y=a1*x+b1, which contains dots A and B had b1=%f ", Sb);
	//защита от  ...
	if(La==Sa){
		if (Lb == Sb) {
			printf("\nYour line contains dots A and B");
			exit(3);
		}
		else {
			printf("\nYour line colinear to segment AB");
			exit(3);
		}
	}
	mesto_vstrechi_izmenit_nizzya_blt = (Sb - Lb) / (La - Sa);
	printf("\n\nOur lines intersect when x=%f\n", mesto_vstrechi_izmenit_nizzya_blt);
	printf("Intersection point's ordinate =%f\n", mesto_vstrechi_izmenit_nizzya_blt*Sa+Sb);
	if (mesto_vstrechi_izmenit_nizzya_blt>xA&&mesto_vstrechi_izmenit_nizzya_blt<xB) {
		printf("Intersection point is in segment! Great!");
	}
	else {
		printf("Intersection point isn't in segment!");
	}
