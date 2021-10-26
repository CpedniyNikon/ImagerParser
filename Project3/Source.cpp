#include <iostream>
#include "curl/curl.h"
#include "Response.h"
#include <fstream>
int main() {
	setlocale(0, "");
	Response resp("https://www.adme.ru/tvorchestvo-fotografy/70-luchshih-resursov-s-besplatnymi-fotografiyami-975760/");
	std::ofstream fout("SiteCode.txt");
	fout << resp.get_str_response() << "\n\n";
	fout.close();
	std::ifstream fin("SiteCode.txt");
	std::string str;
	while (fin >> str) {
		std::string path;
		int j = str.find("png\"");
		int k = str.find("jpeg\"");
		int l = str.find("jpg\"");
		if (str.find("http") != std::string::npos && j != std::string::npos && j - str.find("http") <= 100) {
			for (int i = str.find("http"); i < j + 3; i++) {
				path.push_back(str[i]);
			}
			std::cout << path << std::endl;
			path.resize(0);
		}
		if ((str.find("http") != std::string::npos) && k != std::string::npos && k - str.find("http") <= 100) {
			for (int i = str.find("http"); i < k + 4; i++) {
				path.push_back(str[i]);
			}
			std::cout << path << std::endl;
			path.resize(0);
		}
		if ((str.find("http") != std::string::npos) && l != std::string::npos && l - str.find("http") <= 100) {
			for (int i = str.find("http"); i < l + 3; i++) {
				path.push_back(str[i]);
			}
			std::cout << path << std::endl;
			path.resize(0);
		}
	}
	fin.close();
	return 0;
}