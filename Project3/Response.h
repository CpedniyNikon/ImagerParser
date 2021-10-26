#pragma once
#define CURL_STATICLIB
#include "curl/curl.h"
#include <string>


class Response {
public:
	Response(std::string path);
	std::string get_str_response();
private:
	static size_t getResponsetoString(void* contents, size_t size, size_t nmemb, void* userp);
	CURL* curl;
	CURLcode response;
	std::string str_response;
};
