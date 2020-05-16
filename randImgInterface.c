// Libraries

#include <iostream>
#include <unistd.h>

#include "imgGenObj.c"


using namespace std;


// gens image named name
void genImg(string imgName) {

	if (imgName.substr(imgName.length()-4, imgName.length()) != ".png" ) {
		imgName += ".png";
		randImgGenObj img(imgName);
		cout << "Generated image " << imgName << "\n\n";
	
	}
	
	else {
		randImgGenObj img(imgName);
		cout << "Generated image " << imgName << "\n\n";
	}
	
	usleep(1000000);

}


// interface for generating single image
void genSingleImgInterface() {

	string imgName = "";
	

	cout << "\n\n";	
	cout << "Enter name of image:";

	cin >> imgName;
	cout << "\n\n";

	genImg(imgName);
	
	cout << "Complete\n\n";
		

}


// simple loop of generating and manually naming random images
void manualNaming(int numImgs) {

	for (int x = 0; x < numImgs; x ++) {
		genSingleImgInterface();	
	}

}


// takes base name and makes images named in format base + num + .png
void autoNaming(int numImgs) {

	string base = "";

	cout << "\n\n";
	cout << "Enter base name:";
	cin >> base;
	cout << "\n";
	
	if (base.substr(base.length()-4, base.length() ) == ".png") {
		base = base.substr(0, base.length()-4);
	}

	for (int x = 0; x < numImgs; x ++) {
		genImg(base + to_string(x));
	}


}


void multImgSelect(int selection, int numImgs) {

	switch (selection) {
	
		case 0: exit(2); break;
		case 1: cout << "\n\n"; break;
		case 2: manualNaming(numImgs); break;
		case 3: autoNaming(numImgs); break;
	
		default: cout << "Error, enter valid option:"; cin >> selection; multImgSelect(selection, numImgs); break;  
	
	}



}


void genXImagesInterface() {

	int numImgs = 0;
	int items = 4;
	int select = 0;

	string options[items] = { "Exit Program", "Go back to main interface", "Name images manually", "Number method"  };
	
	cout << "\n\n";
	cout << "Enter number of images to generate:";
	
	cin >> numImgs;
	cout << "\nWill generate " << to_string(numImgs) << " images.\n\n";

	cout << "Select naming method:\n\n";
	
	for (int x = 0; x < items; x ++) {
		cout << to_string(x) << ": " << options[x] << endl;
	}
	
	cout << "\nEnter Option:";
	cin >> select;
	
	multImgSelect(select, numImgs);
	
	


}



// selection switch for interface
void select(string selection) {

	switch (stoi(selection)) {
	
		case 0: exit(2); break;
		case 1: genSingleImgInterface(); break;
		case 2: genXImagesInterface(); break;
	
		default: cout << "Error, enter valid option:"; cin >> selection; select(selection); break;  
	
	}

}


// main interface
void interface() {

	int items = 3;
	string selection = "";


	string options[items] = { "Exit Program", "Gen single random image", "Gen x random images"  };


	while (true) {
	 
		cout << "Options:" << endl;
		
		for (int x = 0; x < items; x ++) {
		
			cout << to_string(x) << ": " << options[x] << endl;
		
		}	
		
		cout << "\nEnter Option: ";
		
		cin >> selection;

		select(selection);	

	}

}


int main() {


	interface();


	return 1;

}
