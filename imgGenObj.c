// Libraries

#include <iostream>
#include <fstream>


#include <curl/curl.h>
#include <curl/easy.h>

#include <string>

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>  


using namespace std;


class randImgGenObj {
	public:
	
	// global vars ************************************************************************************************************************************************************
	
	string imgName;
	
	
	
	
	
	// gen methods ************************************************************************************************************************************************************
			
	char* strToChrArr(string base) {

		char* output = new char[base.length()];
		
		for(int x = 0; x < base.length(); x ++) {
		
			output[x] = base.at(x);
		
		}
		return output;

	}




	// gens rand url
	char* genRandUrlString() { 

		srand (time(NULL));

		// letters for rand generation
		string allLetters = "qwertyuioplkjhgfdsazxcvbnm";
		// base url
		char* base = strToChrArr("http://prnt.sc/");
		
		base[15] = to_string( rand() % 9 ).at(0);
		base[16] = to_string( rand() % 9 ).at(0);
		
		for (int x = 0; x < 4; x ++) {
		
			base[17+x] = allLetters.at(rand() % 26);
			
		}


		return base;
	}


	static size_t writer(void *ptr, size_t size, size_t count, void *stream) {
		((string*)stream)->append((char*)ptr, 0, size*count);
		return size*count;
	}



	// takes string url, returns html content of url
	string getHtmlFromUrl(char* URL) {


		// convert string to char*
		
		
		CURL* curl;
		string output;

		CURLcode res;

		curl = curl_easy_init();
		
		
		// sets curl options and gets html	
		if(curl) {
			curl_easy_setopt(curl, CURLOPT_URL, URL);
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &output);
			curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
			curl_easy_setopt(curl, CURLOPT_USERAGENT, "Firefox/1.0");
			
			res = curl_easy_perform(curl);
			curl_easy_cleanup(curl);
		}	
		else {
		
			return "error";
		
		}
		
		
		return output;

	}


	void getImg(string URL) {

		CURL* curl;
		CURLcode res;
		
		
		char* url = strToChrArr(URL);
		char* name = strToChrArr(imgName);
		
		
		curl = curl_easy_init();
		
		FILE *fp = nullptr;
		
		
		// sets curl options and gets img	
		if(curl) {
		
			fp = fopen(name,"wb");
		
			curl_easy_setopt(curl, CURLOPT_URL, url);
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
			curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
			curl_easy_setopt(curl, CURLOPT_USERAGENT, "Firefox/1.0");
			
			res = curl_easy_perform(curl);
			fclose(fp);
			curl_easy_cleanup(curl);
		}	
		


	}






	string getLink() {

		string html = getHtmlFromUrl(genRandUrlString());
		string link = "https://i.imgur.com/";


		
		int index = html.find(link);
		
		while (index == -1) {
		
			html = getHtmlFromUrl(genRandUrlString());
			index = html.find(link);

		
		}
		
		
		
		for (int x = 0; x < 7; x ++) {
		
			link += html.at(index+20+x);
		
		}
		link += ".png";
		
		return link;

	}

	
	// constructors


	randImgGenObj() {	
		imgName = "default.png";
		getImg( getLink() );
	}


	randImgGenObj(string name) {	
		imgName = name;
		getImg( getLink() );
	}



};	


