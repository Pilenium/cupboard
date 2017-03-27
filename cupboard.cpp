#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
class Cupboard
{
private:
	int sizel, sizew, sizeh;
	static int amountcup;
public:
bool bclothes, bsafe;
void create(){
	string ans;
	cin >> ans;
	while ((ans != "y") && (ans != "n")){
	cout << "Error enter again ";
	cin >> ans;
}
	if (ans == "n"){
		cout << "goodbye" << endl;
		exit(0);
	}
}
Cupboard(){
	cout << "Do you want to create your own cupboard? |Yes or no (y,n)|" << endl;
}
Cupboard(int sizel, int sizew, int sizeh){
	this->sizel = sizel;
	this->sizew = sizew;
	this->sizeh = sizeh;
	cout << "Example sizes of cupboard: " << endl;
	cout << "Lenght = " << sizel << endl;
	cout << "Width = " << sizew << endl;
	cout << "Height = " << sizeh << endl;
}
void setCupboardsizes(){
	cout << "Enter sizes of your cupboard:" << endl;
	cout << "Enter length: "; cin >> sizel;
	cout << "Enter width: ";  cin >> sizew;
	cout << "Enter height: "; cin >> sizeh;
}
void getCupboardsizes(){
	cout << "Sizes of your cupboard" << endl << "Length: " << sizel << endl << "Width: "<< sizew << endl << "Height: " << sizeh << endl;
}
void clothes(){
int amountclothes = 0;
bclothes = false;
int sw = sizew;
	while ((sizel > 44) && (sw > 1) && (sizeh > 89)){
		amountclothes = amountclothes + 1;
		sw = sw -2;
		bclothes = true;
	}
	if (bclothes == false){
		cout << " You can't put clothes on the hanger in your cupboard " << endl;
	}
	else if (bclothes == true){
		cout << "Amount of clothes on the hanger in your cupboard: " << amountclothes << endl;
	}
}
void changevolume(){
	float svol1, svol2, svol3, svol4;
	svol1 = sizel*sizew*sizeh;
	svol2 = 45*sizew*90;
	svol3 = 36*45*52;
	if (bclothes == true){
		svol4 = 100-((svol1-svol2)/svol1*100);
		cout << "your cupboard will be smaller on " << svol4 << "% if you have only clothes" << endl;
} 
	if (bsafe == true){
		svol4 = 100-((svol1-svol3)/svol1*100);
		cout << "your cupboard will be smaller on " << svol4 << "% if you have only safe" << endl;
}
	if ((bsafe == true)&&(bclothes == true)){
		svol4 = 100-((svol1-svol2-svol3)/svol1*100);
		cout << "your cupboard will be smaller on " << svol4 << "% if you have safe and clothes" << endl;
}
}
void volume(){
	float vol1, vol2, vol3;
	vol1 = sizel*sizew*sizeh;
	vol2 = 200*70*200;
	if(vol2 < vol1){
		vol3 = 100-((vol2/vol1)*100);
		cout << "standard cupboard is smaller than yours on " << vol3 << " %" << endl;
}
	else if (vol1 < vol2){
		vol3 = 100-((vol1/vol2)*100);
		cout << "Standard cupboard is bigger than yours on " << vol3 << " %" << endl;
}
	else if (vol1 == vol2) cout << "Volumes are equal" << endl;
}
void csafe(){
	cout << "Do you have safe in your cupboard? |Yes or no(y,n)|" << endl;
	bsafe = false;
	string ans;
	cin >> ans;
	while ((ans != "y") && (ans != "n")){
	cout << "Error enter again ";
	cin >> ans;
}
	if (ans == "y"){
		if ((sizel > 36) && (sizew > 45) && (sizeh > 52)) bsafe = true;
	}
}
~Cupboard(){
	amountcup++;
	cout << "Destruct, there was " << amountcup << " cupboard" << endl << endl;
}
};
int Cupboard::amountcup;
int main(int argc, char* argv[]){
	Cupboard (200, 70, 200);
	Cupboard obj1;
	obj1.create();
	obj1.setCupboardsizes();
	obj1.volume();
	obj1.clothes();
	obj1.csafe();
	obj1.changevolume();
	obj1.getCupboardsizes();
	return 0;
}
// 45 - lenght, 90 height, 5 width()clothes
// 200 - height, 200 - lenght, width - 70() cupboard
