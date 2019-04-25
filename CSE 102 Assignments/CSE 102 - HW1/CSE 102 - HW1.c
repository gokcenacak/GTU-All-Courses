/*171044079.c	*/
/*Gökçe Nur Erer*/
/*								DESCRIPTION									 */
/*171044079.c contains the function implementations for HW1 in course CSE102 */
/*Which calculates the area of the largest circle and the largest square in a*/
/*given rectangle by user and also calculates the area of the smallest circle*/
/*and the smallest square that surrounds a given rectangle by user.		 	 */

#include <stdio.h>
#include <math.h>
#define PI 3.14

/*This function calculates the area of a circle with a given radius */

double circle_area(double radius){

 	double circle_area=PI*(pow(radius,2));
	
	return circle_area;
}

/*This function calculates the area of a square by using a given side*/

double calc_area_of_square(int side){
	
	double square_area=pow(side,2);
	
	return square_area;
}

/*This function calculates the hypotenuse by given 2 sides from pythagorian theorem.*/

double calc_hypotenuse(int side1, int side2){
	
	double hypotenuse = sqrt(pow(side1,2)+pow(side2,2));

	return hypotenuse;
}

/*This function calculates the radius of the smallest circle that surrounds*/
/*the given rectangle by the user, the radius is equal to the half of the hypotenuse*/

double calc_radius_of_smallest_circle(int side1, int side2)
{
	double radius=calc_hypotenuse(side1,side2)/2;
	
	return radius;
}

/*This function calculates the radius of the largest circle that fits the given*/
/*rectangle by the user, the radius is equal to the half of the short side     */

double calc_radius_of_largest_circle(int side1, int side2)
{
	double radius=side2/2.0;
	return radius;
}

/*This function calculates the area of the smallest circle that surrounds the*/
/*given rectangle by the user, using the radius of the smallest circle that  */
/*surrounds the given rectangle by the user									 */

double calc_area_of_smallest_circle(int side1, int side2){
	
	double radius_of_smallest_circle=calc_radius_of_smallest_circle(side1,side2);
	double area_of_smallest_circle=circle_area(radius_of_smallest_circle);
	
	return area_of_smallest_circle;
}

/*This function calculates the area of the largest circle that fits in the	*/
/*given rectangle by the user, using the radius of the largest circle that  */
/*fits the given rectangle by the user									 	*/

double calc_area_of_largest_circle(int side1, int side2){

	double radius_of_largest_circle=calc_radius_of_largest_circle(side1,side2);
	double area_of_largest_circle=circle_area(radius_of_largest_circle);
	
	return area_of_largest_circle;
}

/*This function calculates the area of the smallest square that surrounds the*/
/*given rectangle by the user, using the long side of the rectangle that is given*/	
								 
double calc_area_of_smallest_square(int side1, int side2){
	double area_of_smallest_square=calc_area_of_square(side1);
	
	return area_of_smallest_square;
}

/*This function calculates the area of the largest square that fits in the*/
/*given rectangle by the user, using the short side of the rectangle that is given*/
			
double calc_area_of_largest_square(int side1, int side2){
	
	double area_of_largest_square=calc_area_of_square(side2);
	
	return area_of_largest_square;
}

/*This function gets the largest circle, largest square, smallest circle and*/
/*smallest square values and displays them to screen						*/

void display_results(double largest_circle, double largest_square, double smallest_circle, double smallest_square){
	printf("The area of the largest circle that fits inside a rectangle: %3.2f\n",largest_circle);
	printf("The area of the largest square that fits inside a rectangle: %3.2f\n",largest_square);
	printf("The area of the smallest circle that surrounds the same rectangle: %3.2f\n",smallest_circle);
	printf("The area of the smallest square that surrounds the same rectangle: %3.2f\n",smallest_square);
	
}

int main(){

/*side1 is the long side, side2 is the short side, temp is used for swapping.*/
	int side1, side2,temp; 

	printf("Please enter the first side of the rectangle:");
	scanf("%d",&side1);
	printf("Please enter the second side of the rectangle:");
	scanf("%d",&side2);

/*A side length cannot be negative or 0 in here it is tested.*/
/*Also, since I have taken side1 as longer and side2 as shorter*/
/*the second if block helps me swap the values if side2 is bigger than side1*/

	if(side1>0&&side2>0){
		if(side2>side1){	
			temp=side1;
			side1=side2;
			side2=temp;
		}

		display_results(calc_area_of_largest_circle(side1,side2), calc_area_of_largest_square(side1,side2), calc_area_of_smallest_circle(side1,side2), calc_area_of_smallest_square(side1,side2));
	}
	else 
		printf("Please enter a valid side values.");

return 0;
}
