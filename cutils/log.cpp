#include "stdafx.h"
#include "log.h"
#include "options.h"
#include "lua_helpers.h"

template <typename type2>
int push_tostring(lua_State* L, type2 n) {
	lua_getglobal(L, "tostring");
	lua_push<type2>(L, n);
	lua_call(L, 1, 1);
	return 1;
}

// LOG BASE
template <typename type>
int _log(lua_State* L, const char* log_func, const char* s, type n) {
	lua_getglobal(L, log_func);
	lua_pushstring(L, s);
	push_tostring<type>(L, n);
	lua_call(L, 2, 0);

	return 0;
}

template <typename type>
int _log(lua_State* L, const char* log_func, const char* s, std::vector<type> v) {
	lua_getglobal(L, log_func);
	lua_pushstring(L, s);

	for (type n : v)
		push_tostring<type>(L, n);

	lua_call(L, 1 + v.size(), 0);

	return 0;
}

// simple LOG
template <typename type>
int log(lua_State* L, type n) {
	lua_getglobal(L, "LOG");
	lua_push<type>(L, n);
	lua_call(L, 1, 0);

	return 0;
}

// simple LOGD
template <typename type>
int logd(lua_State* L, type n) {
	lua_getglobal(L, "LOGD");
	lua_push<type>(L, n);
	lua_call(L, 1, 0);

	return 0;
}

// LOG
template <typename type>
int log(lua_State* L, const char* s, type n) {
	return _log<type>(L, "LOG", s, n);
}

template <typename type>
int log(lua_State* L, const char* s, std::vector<type> v) {
	return _log<type>(L, "LOG", s, v);
}

// LOGF
template <typename type>
int logf(lua_State* L, const char* s, type n) {
	return _log<type>(L, "LOGF", s, n);
}

template <typename type>
int logf(lua_State* L, const char* s, std::vector<type> v) {
	return _log<type>(L, "LOGF", s, v);
}

// LOGD
template <typename type>
int logd(lua_State* L, const char* s, type n) {
	return _log<type>(L, "LOGD", s, n);
}

template <typename type>
int logd(lua_State* L, const char* s, std::vector<type> v) {
	return _log<type>(L, "LOGD", s, v);
}

// LOGDF
template <typename type>
int logdf(lua_State* L, const char* s, type n) {
	return _log<type>(L, "LOGDF", s, n);
}

template <typename type>
int logdf(lua_State* L, const char* s, std::vector<type> v) {
	return _log<type>(L, "LOGDF", s, v);
}

int log(lua_State* L, const char* s) {
	return log<const char*>(L, s);
}
int log(lua_State* L, int n) {
	return log<int>(L, n);
}
int log(lua_State* L, unsigned int n) {
	return log<unsigned int>(L, n);
}
int log(lua_State* L, bool b) {
	return log<bool>(L, b);
}
int log(lua_State* L, float f) {
	return log<float>(L, f);
}

int logd(lua_State* L, const char* s) {
	return logd<const char*>(L, s);
}
int logd(lua_State* L, int n) {
	return logd<int>(L, n);
}
int logd(lua_State* L, unsigned int n) {
	return logd<unsigned int>(L, n);
}
int logd(lua_State* L, bool b) {
	return logd<bool>(L, b);
}
int logd(lua_State* L, float f) {
	return logd<float>(L, f);
}

int logf(lua_State* L, const char* s, int n) {
	return logf<int>(L, s, n);
}
int logf(lua_State* L, const char* s, unsigned int n) {
	return logf<unsigned int>(L, s, n);
}
int logf(lua_State* L, const char* s, bool b) {
	return logf<bool>(L, s, b);
}
int logf(lua_State* L, const char* s, char b) {
	return logf<bool>(L, s, b);
}
int logf(lua_State* L, const char* s, BYTE b) {
	return logf<BYTE>(L, s, b);
}
int logf(lua_State* L, const char* s, const char* c) {
	return logf<const char*>(L, s, c);
}
int logf(lua_State* L, const char* s, std::vector<int> v) {
	return logf<int>(L, s, v);
}
int logf(lua_State* L, const char* s, std::vector<unsigned int> v) {
	return logf<unsigned int>(L, s, v);
}
int logf(lua_State* L, const char* s, std::vector<bool> v) {
	return logf<bool>(L, s, v);
}
int logf(lua_State* L, const char* s, std::vector<char> v) {
	return logf<char>(L, s, v);
}
int logf(lua_State* L, const char* s, std::vector<BYTE> v) {
	return logf<BYTE>(L, s, v);
}
int logf(lua_State* L, const char* s, std::vector<const char*> v) {
	return logf<const char*>(L, s, v);
}

int log(lua_State* L, const char* s, int n) {
	return log<int>(L, s, n);
}
int log(lua_State* L, const char* s, unsigned int n) {
	return log<unsigned int>(L, s, n);
}
int log(lua_State* L, const char* s, bool b) {
	return log<bool>(L, s, b);
}
int log(lua_State* L, const char* s, char b) {
	return log<char>(L, s, b);
}
int log(lua_State* L, const char* s, BYTE b) {
	return log<BYTE>(L, s, b);
}
int log(lua_State* L, const char* s, const char* c) {
	return log<const char*>(L, s, c);
}
int log(lua_State* L, const char* s, std::vector<int> v) {
	return log<int>(L, s, v);
}
int log(lua_State* L, const char* s, std::vector<unsigned int> v) {
	return log<unsigned int>(L, s, v);
}
int log(lua_State* L, const char* s, std::vector<bool> v) {
	return log<bool>(L, s, v);
}
int log(lua_State* L, const char* s, std::vector<char> v) {
	return log<char>(L, s, v);
}
int log(lua_State* L, const char* s, std::vector<BYTE> v) {
	return log<BYTE>(L, s, v);
}
int log(lua_State* L, const char* s, std::vector<const char*> v) {
	return log<const char*>(L, s, v);
}

int logd(lua_State* L, const char* s, int n) {
	return logd<int>(L, s, n);
}
int logd(lua_State* L, const char* s, unsigned int n) {
	return logd<unsigned int>(L, s, n);
}
int logd(lua_State* L, const char* s, bool b) {
	return logd<bool>(L, s, b);
}
int logd(lua_State* L, const char* s, char b) {
	return logd<char>(L, s, b);
}
int logd(lua_State* L, const char* s, BYTE b) {
	return logd<BYTE>(L, s, b);
}
int logd(lua_State* L, const char* s, const char* c) {
	return logd<const char*>(L, s, c);
}
int logd(lua_State* L, const char* s, std::vector<int> v) {
	return logd<int>(L, s, v);
}
int logd(lua_State* L, const char* s, std::vector<unsigned int> v) {
	return logd<unsigned int>(L, s, v);
}
int logd(lua_State* L, const char* s, std::vector<bool> v) {
	return logd<bool>(L, s, v);
}
int logd(lua_State* L, const char* s, std::vector<char> v) {
	return logd<char>(L, s, v);
}
int logd(lua_State* L, const char* s, std::vector<BYTE> v) {
	return logd<BYTE>(L, s, v);
}
int logd(lua_State* L, const char* s, std::vector<const char*> v) {
	return logd<const char*>(L, s, v);
}

int logdf(lua_State* L, const char* s, int n) {
	return logdf<int>(L, s, n);
}
int logdf(lua_State* L, const char* s, unsigned int n) {
	return logdf<unsigned int>(L, s, n);
}
int logdf(lua_State* L, const char* s, bool b) {
	return logdf<bool>(L, s, b);
}
int logdf(lua_State* L, const char* s, char b) {
	return logdf<bool>(L, s, b);
}
int logdf(lua_State* L, const char* s, BYTE b) {
	return logdf<BYTE>(L, s, b);
}
int logdf(lua_State* L, const char* s, const char* c) {
	return logdf<const char*>(L, s, c);
}
int logdf(lua_State* L, const char* s, std::vector<int> v) {
	return logdf<int>(L, s, v);
}
int logdf(lua_State* L, const char* s, std::vector<unsigned int> v) {
	return logdf<unsigned int>(L, s, v);
}
int logdf(lua_State* L, const char* s, std::vector<bool> v) {
	return logdf<bool>(L, s, v);
}
int logdf(lua_State* L, const char* s, std::vector<char> v) {
	return logdf<char>(L, s, v);
}
int logdf(lua_State* L, const char* s, std::vector<BYTE> v) {
	return logdf<BYTE>(L, s, v);
}
int logdf(lua_State* L, const char* s, std::vector<const char*> v) {
	return logdf<const char*>(L, s, v);
}
