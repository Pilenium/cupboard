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
cout << endl;
}
Cupboard(){
	cout << "Do you want to create your own cupboard? |Yes or no (y,n)|" << endl;
}
Cupboard(int sizel, int sizew, int sizeh){
	this->sizel = sizel;
	this->sizew = sizew;
	this->sizeh = sizeh;
	cout << "__________________________" << endl << "Sizes of example cupboard: " << endl;
	cout << "|Lenght = " << sizel << "|" << endl;
	cout << "|Width = " << sizew << "  |" << endl;
	cout << "|Height = " << sizeh << "|" << endl << "__________________________" << endl;
}
void setCupboardsizes(){
	cout << "Enter sizes of your cupboard:" << endl;
	cout << "Enter length: "; cin >> sizel;
	cout << "Enter width: ";  cin >> sizew;
	cout << "Enter height: "; cin >> sizeh;
	space = sizel*sizew*sizeh;
}
void clothes(){
int amountclothes = 0;
bclothes = false;
int sw = sizew;
int clsizelmax = 44, clsizewmax = 1, clsizehmax = 89;
	while ((sizel > clsizelmax) && (sw > clsizewmax) && (sizeh > clsizehmax)){
		amountclothes = amountclothes + 1;
		sw = sw -2;
		bclothes = true;
	}
	if (bclothes == false){
		cout << endl << " You can't put clothes on the hanger in your cupboard " << endl;
	}
	else if (bclothes == true){
		cout << endl <<"Amount of clothes on the hanger in your cupboard: " << amountclothes << endl;
		
	}
}
float space;
void changevolume(){
	float cvoluser, cvolclothes, cvolsafe, cvolcompare;
	cvoluser = sizel*sizew*sizeh;
	cvolclothes = 45*sizew*90;
	cvolsafe = 36*45*52;
	if (bclothes == true){
		cvolcompare = 100-((cvoluser-cvolclothes)/cvoluser*100);
		cout << endl << "Your cupboard will be smaller on " << cvolcompare << "% if you have only clothes" << endl;
		space = cvoluser-cvolclothes;
} 
	if (bsafe == true){
		cvolcompare = 100-((cvoluser-cvolsafe)/cvoluser*100);
		cout << endl << "Your cupboard will be smaller on " << cvolcompare << "% if you have only safe" << endl;
		space = cvoluser-cvolsafe;
}
	if ((bsafe == true)&&(bclothes == true)){
		cvolcompare = 100-((cvoluser-cvolclothes-cvolsafe)/cvoluser*100);
		cout << endl << "Your cupboard will be smaller on " << cvolcompare << "% if you have safe and clothes" << endl;
		space = cvoluser-cvolclothes-cvolsafe;
}
}
void volume(){
	float voluser, volexample, volcompare;
	voluser = sizel*sizew*sizeh;
	volexample = 200*70*200;
	if(volexample < voluser){
		volcompare = 100-((volexample/voluser)*100);
		cout << endl << "Example cupboard is smaller than yours on " << volcompare << " %" << endl;
}
	else if (voluser < volexample){
		volcompare = 100-((voluser/volexample)*100);
		cout << endl << "Example cupboard is bigger than yours on " << volcompare << " %" << endl;
}
	else if (voluser == volexample) cout << endl << "Volumes are equal" << endl;
}
void getCupboardvolume(){
	cout << endl << "Volume of your cupboard in cubic meters: " << (space/1000000) << endl;
	
}
void csafe(){
	cout << endl << "Do you want to shove a safe in the cupboard? |Yes or no(y,n)|" << endl;
	bsafe = false;
	string ans;
	cin >> ans;
	while ((ans != "y") && (ans != "n")){
	cout << "Error enter again ";
	cin >> ans;
}
	if (ans == "y"){
		if ((sizel > 36) && (sizew > 45) && (sizeh > 52)) bsafe = true;
			else cout << endl << "You can't put safe in your cupboard" << endl;
	}
}
~Cupboard(){
	amountcup++;
	cout << endl << "Destruct, there was " << amountcup << " cupboard" << endl << endl;
}
};
int Cupboard::amountcup;
int main(int argc, char* argv[]){
	Cupboard (200, 70, 200);
	Cupboard obj1;
	obj1.create();
	obj1.setCupboardsizes();
	obj1.getCupboardvolume();
	obj1.volume();
	obj1.clothes();
	obj1.csafe();
	obj1.changevolume();
	obj1.getCupboardvolume();
	return 0;
}
