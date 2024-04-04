#include<iostream>
#include<string>
using namespace std;
// define strings into numbers for sorting purpose
enum Color{Red = 0, White = 1, Green = 2};

void swap(Color& a, Color& b){
	Color temp = a;
	a = b;
	b = temp;
}
// sorting function
void bubbleSortColor(Color* color, int n){
	for (int i =0; i< n; i++){
		for (int j=0; j < n - 1 - i; j++){
			if(color[j] > color[j+1]){
				swap(color[j],color[j+1]);
			}
		}
	}
}
// convert array Color containing numbers into containing strings
string numberToColor(Color color){
	switch(color){
		case 0:
			return "Red" ;
		case 1:
			return "White";
		case 2:
			return "Green";
		default:
			return "Invalid color";
}
}
int main() {
	Color color[] = {Green,Red,Green,Red,Red,White,Red,Green,White};
	int n = sizeof(color) / sizeof(color[0]);
	bubbleSortColor (color, n);
	for(int i = 0; i <n; i++){
		cout << numberToColor(color[i]) << " ";
	}
	cout << endl;
	return 0;
}
