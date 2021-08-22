
//Eþref Burak KAYA 152120171103

#include <stdio.h>
#include "Poly.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
//------------------------------------------------- 
// Creates a polynomial from an expression.
// Returns a pointer to the first PolyNode in the list (head of the list)
// 
// Expression will be of the following sort:
// Ex1: 2.3x^4 + 5x^3 - 2.64x - 4
// Ex2: -4.555x^10 - 45.44
// Ex3: x^6 + 2x^4 - x^3 - 6.3x + 4.223 
// Ex4: 34
// Ex5: -x+1
// Ex6: -3x^4    +   4x
// Ex7: -2x  - 5
//

	PolyNode *CreatePoly(char *expr){

		PolyNode *p = new PolyNode();
		PolyNode *t = new PolyNode();
		t = NULL;
		//PolyNode* tail=NULL;
		int i = 0, j = 0, count = 0;
		char *temp;
		temp = expr;
		string newexpr = "";

		while (*temp != '\0') {

			if (*temp == ' ') {
				temp++;
				continue;
			}
			newexpr += *temp;
			temp++;
		}
		/*cout << "newexpr" << newexpr << endl;*/
		string tempexp = "";
		string tempcoef = "";
		int counter = 0, k = 0;
		double d1, d2;

		while (newexpr.length() > i) {
			tempexp = "";
			tempcoef = "";

			while (newexpr[j] != '\0') {
				if (newexpr[j] == 'x') {
					counter++;
				}
				j++;
			}

			if (counter == 0) {
				while (newexpr[i] != '\0') {
					tempcoef += newexpr[i];
					i++;
				}
				stringstream(tempcoef) >> d2;
				p->coef = d2;
				p->exp = 0;
			}
			if (newexpr[0] == 'x' && i == 0)
				p->coef = 1;

			if (newexpr[i] == '-' || newexpr[i] == '+') {

				if (newexpr[i] == '+' && newexpr[i + 1] == 'x') {
					p->coef = 1;
				}
				else if (newexpr[i] == '-' && newexpr[i + 1] == 'x') {
					p->coef = -1;
				}
				else if (newexpr[i] != 'x') {
					while (newexpr[i] != 'x' && newexpr[i] != '\0') {
						tempcoef += newexpr[i];
						if (newexpr.length() > i)
							i++;
					}
					stringstream(tempcoef) >> d1;
					p->coef = d1;
					if (newexpr[i] != 'x')
						p->exp = 0;

				}
				else {
					while (newexpr[i] != '\0') {
						tempcoef += newexpr[i];
						if (newexpr.length() > i)
							i++;
					}
					p->coef = stold(tempcoef);
					p->exp = 0;
				}

			}

			else {
				while (newexpr[i] != 'x' && newexpr[i] != '^' && counter != 0) {
					tempcoef += newexpr[i];
					if (newexpr.length() > i)
						i++;
				}

				if (newexpr[i] != 'x' && newexpr[i] != '^'&& counter != 0)
					p->coef = stold(tempcoef);
			}
			if (tempcoef != "")
				p->coef = stold(tempcoef);

			if (i > 0) {
				if (newexpr[i] == '^' && newexpr[i - 1] == 'x') {
					if (newexpr.length() > i)
						i++;
					while (newexpr[i] != '-' && newexpr[i] != '+' && newexpr[i] != '\0') {
						tempexp += newexpr[i];
						if (newexpr.length() > i)
							i++;
					}
					i--;
					p->exp = stold(tempexp);
				}

				else if (newexpr[i] == 'x' && newexpr[i + 1] != '^') {
					p->exp = 1;
				}
			}



			if (/*newexpr[i] != '\0'*/ newexpr.length() >= i && p->exp != NULL && p->exp >= 0) {
				t = AddNode(t, p->coef, p->exp);
				p->exp = NULL;
				p->coef = NULL;

			}
			if (newexpr[i] == '\0') {
				t = AddNode(t, p->coef, p->exp);
				p->exp = NULL;
				p->coef = NULL;
			}
			i++;
		}


		return t;
	} //end-CreatePoly
 //end-CreatePoly

/// -------------------------------------------------
/// Walk over the poly nodes & delete them
///
void DeletePoly(PolyNode* poly) {

	
		PolyNode *p = poly;
		while (p != NULL)
		{
			p = p->next;
			delete(poly);
			poly = p;
		}
		

	
} // end-DeletePoly

//-------------------------------------------------
// Adds a node (coefficient, exponent) to poly. If there already 
// is a node with the same exponent, then you simply add the coefficient
// to the existing coefficient. If not, you add a new node to polynomial
// Returns a pointer to the possibly new head of the polynomial.
//


PolyNode* AddNode(PolyNode *head, double coef, int exp) {
	int flag = 0, t;
	double t2;
	PolyNode *temp = new PolyNode();
	
	temp = head;
	
	if (head == NULL)
	{
		head = new PolyNode();
		head->coef = coef;
		head->exp = exp;
		temp = head;
	}
	else
	{
		while (temp->next != NULL)
		{
		
			if (temp->exp == exp)
			{
				temp->coef += coef;
					flag = 1;
					////REMOVE///REMOVE//////REMOVE/////////////
					if (temp->coef == 0)
					{

						PolyNode *q = NULL;
						PolyNode *p = head;

						while (p != NULL && p->coef != 0)
						{
							q = p;
							p = p->next;
						}
						if (q == NULL) head = p->next;
						else q->next = p->next;


					}
		    }

			temp = temp->next;
			
		}
		if (temp->next == NULL && temp->exp == exp)
		{
			temp->coef += coef;
			flag = 1;
			////REMOVE///REMOVE//////REMOVE/////////////
			if (temp->coef == 0)
			{

				PolyNode *q = NULL;
				PolyNode *p = head;

				while (p != NULL && p->coef != 0)
				{
					q = p;
					p = p->next;
				}
				if (q == NULL) head = p->next;
				else q->next = p->next;


			}


			//////////////REMOVE REMOVE REMOVE REMOVE
		}
		



		if (flag != 1)
		{
			temp->next = new PolyNode();
			temp = temp->next;
			temp->coef = coef;
			temp->exp = exp;
			temp->next = NULL;
		}
	

	}
	
	PolyNode *ptr = new PolyNode();
	PolyNode *cpt = new PolyNode();
	ptr = head;
	
	while (ptr != NULL) {
		cpt = ptr->next;
		while (cpt != NULL) {
			if (ptr->exp < cpt->exp) {
				t = ptr->exp;
				ptr->exp = cpt->exp;
				cpt->exp = t;

				t2 = ptr->coef;
				ptr->coef = cpt->coef;
				cpt->coef = t2;
				
			}
			cpt = cpt->next;
		}
		ptr = ptr->next;
	}



	return head;
}

//-------------------------------------------------
// Adds two polynomials and returns a new polynomial that contains the result
// Computes: poly3 = poly1 + poly2 and returns poly3
//
PolyNode *Add(PolyNode *poly1, PolyNode *poly2) {
	// Fill this in

	PolyNode *p3=new PolyNode();
	while (poly1 != NULL)
	{
		p3 = AddNode(p3, poly1->coef, poly1->exp);
		poly1 = poly1->next;
	}
	while (poly2 != NULL)
	{
		p3 = AddNode(p3, poly2->coef, poly2->exp);
		poly2 = poly2->next;
	}
	
	return p3;
} //end-Add

//-------------------------------------------------
// Subtracts poly2 from poly1 and returns the resulting polynomial
// Computes: poly3 = poly1 - poly2 and returns poly3
//
PolyNode *Subtract(PolyNode *poly1, PolyNode *poly2) {
	PolyNode *p3 = new PolyNode();
	while (poly1 != NULL)
	{
		p3 = AddNode(p3, poly1->coef, poly1->exp);
		poly1 = poly1->next;
	}
	while (poly2 != NULL)
	{
		p3 = AddNode(p3, (-1)*poly2->coef, poly2->exp);
		poly2 = poly2->next;
	}

	return p3;
} //end-Substract

//-------------------------------------------------
// Multiplies poly1 and poly2 and returns the resulting polynomial
// Computes: poly3 = poly1 * poly2 and returns poly3
//
PolyNode *Multiply(PolyNode *poly1, PolyNode *poly2) {
	PolyNode *p3 = new PolyNode();
	PolyNode *te = new PolyNode();
	te = poly2;
	while (poly1 != NULL)
	{
		while (poly2 != NULL)
		{
			p3 = AddNode(p3, poly1->coef*poly2->coef, poly1->exp + poly2->exp);

			poly2 = poly2->next;
			
		}
		poly1=poly1->next;
		poly2 = te;
	}
	return p3;
	
} //end-Multiply

//-------------------------------------------------
// Evaluates the polynomial at a particular "x" value and returns the result
//
double Evaluate(PolyNode *poly, double x) {
	double tem=0.0;
	double tem2 = x;
	while (poly != NULL)
	{
		x = tem2;
		x=pow(x, poly->exp);
		x *= poly->coef;

		tem = tem + x;
		poly = poly->next;
	}
	return tem;
} //end-Evaluate

//-------------------------------------------------
// Computes the derivative of the polynomial and returns it
// Ex: poly(x) = 3x^4 - 2x + 1-->Derivative(poly) = 12x^3 - 2
//
PolyNode *Derivative(PolyNode *poly) {
	PolyNode* der = new PolyNode();
	while (poly != NULL) {

		if (poly->exp != 0) {
			poly->coef = poly->coef*poly->exp;
			poly->exp = poly->exp - 1;
			der= AddNode(der, poly->coef, poly->exp);
		}
		poly = poly->next;
	}

	return der;
} //end-Derivative

//-------------------------------------------------
// Plots the polynomial in the range [x1, x2].
// -39<=x1<x2<=39
// -12<=y<=12
// On the middle of the screen you gotta have x & y axis plotted
// During evaluation, if "y" value does not fit on the screen,
// then just skip it. Otherwise put a '*' char depicting the curve
//
void Plot(PolyNode *poly, int x1, int x2) {
	int y, x,counter=0,counter2=0;
	int i = 0;

	for (y = 12; y > -12; y--) {
		for (x = -39; x < 39; x++) {

			if (x > x1&&x < x2) {
				if (round(Evaluate(poly, x)) == y) {

					cout << "*";

				}
				else {
					cout << " ";
				}
			}
			if (y == 0) {
				for ( ; i < 80; i++) {
					if (counter % 5 == 0) {
						cout << "+";
						counter++;
					}
					else {
						cout << "-";
						counter++;
					}
				}
			}
			if (x == 0) {
				if (counter2 % 5 == 0) {
					cout << "+";
					counter2++;
				}
				else {
					cout << "|";
					counter2++;
				}
			}

		}
		cout << endl;
	}
} //end-Plot
