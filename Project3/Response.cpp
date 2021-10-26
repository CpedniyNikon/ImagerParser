#define CURL_STATICLIB
#include "curl/curl.h"
#include "Response.h"
#include <string>
#ifdef _DEBUG
#pragma comment(lib, "curl/libcurl_a_debug.lib")
#else
#pragma comment(lib, "curl/libcurl_a.lib")
#endif // _DEBUG

#pragma comment (lib, "Normaliz.lib")
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Wldap32.lib")
#pragma comment (lib, "Crypt32.lib")
#pragma comment (lib, "advapi32.lib")
Response::Response(std::string path)
{
	curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, path.data());
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, getResponsetoString);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &str_response);
	response = curl_easy_perform(curl);
	curl_easy_cleanup(curl);
}

size_t Response::getResponsetoString(void* contents, size_t size, size_t nmemb, void* userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

std::string Response::get_str_response()
{
	return str_response;
}
