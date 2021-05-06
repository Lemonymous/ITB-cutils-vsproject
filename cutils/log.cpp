#include "stdafx.h"
#include "log.h"
#include "options.h"

int push_tostring(lua_State* L, int n) {
	lua_getglobal(L, "tostring");
	lua_pushnumber(L, n);
	lua_call(L, 1, 1);
	return 1;
}

int push_tostring(lua_State* L, unsigned int n) {
	lua_getglobal(L, "tostring");
	lua_pushnumber(L, n);
	lua_call(L, 1, 1);
	return 1;
}

int push_tostring(lua_State* L, bool b) {
	lua_getglobal(L, "tostring");
	lua_pushboolean(L, b);
	lua_call(L, 1, 1);
	return 1;
}

int push_tostring(lua_State* L, const char* s) {
	lua_getglobal(L, "tostring");
	lua_pushstring(L, s);
	lua_call(L, 1, 1);
	return 1;
}

// LOGF
template <typename type>
int logf(lua_State* L, const char* s, type n) {
	lua_getglobal(L, "LOGF");
	lua_pushstring(L, s);
	push_tostring(L, n);
	lua_call(L, 2, 0);

	return 0;
}

template <typename type>
int logf(lua_State* L, const char* s, std::vector<type> v) {
	lua_getglobal(L, "LOGF");
	lua_pushstring(L, s);

	//for (size_t i = 0; i < v.size(); i++)
		//push_tostring(L, v[i]);
	//for (auto i = v.begin(); i != v.end(); i++)
		//push_tostring(L, *i);
	for (type n : v)
		push_tostring(L, n);

	lua_call(L, 1 + v.size(), 0);

	return 0;
}

/*template <>
int logf(lua_State* L, const char* s, std::vector<const char*> v) {
	lua_getglobal(L, "LOGF");
	lua_pushstring(L, s);

	//for (size_t i = 0; i < v.size(); i++)
		//push_tostring(L, v[i]);
	//for (auto i = v.begin(); i != v.end(); i++)
		//push_tostring(L, *i);
	for (const char* & n : v)
		push_tostring(L, n);

	lua_call(L, 1 + v.size(), 0);

	return 0;
}*/

// LOG
template <typename type>
int log(lua_State* L, const char* s, type n) {
	lua_getglobal(L, "LOG");
	lua_pushstring(L, s);
	push_tostring(L, n);
	lua_call(L, 2, 0);

	return 0;
}

template <typename type>
int log(lua_State* L, const char* s, std::vector<type> v) {
	lua_getglobal(L, "LOG");
	lua_pushstring(L, s);

	//for (size_t i = 0; i < v.size(); i++)
		//push_tostring(L, v[i]);
	//for (auto i = v.begin(); i != v.end(); i++)
		//push_tostring(L, *i);
	for (type n : v)
		push_tostring(L, n);

	lua_call(L, 1 + v.size(), 0);

	return 0;
}
/*template <>
int log(lua_State* L, const char* s, std::vector<const char*> v) {
	lua_getglobal(L, "LOG");
	lua_pushstring(L, s);

	for (size_t i = 0; i < v.size(); i++)
		push_tostring(L, v[i]);
	//for (auto i = v.begin(); i < v.end(); i++)
		//push_tostring(L, *i);
	//for (const char* & n : v)
		//push_tostring(L, n);

	lua_call(L, 1 + v.size(), 0);

	return 0;
}*/

// simple LOG
int log(lua_State* L, const char* s) {
	lua_getglobal(L, "LOG");
	lua_pushstring(L, s);
	lua_call(L, 1, 0);

	return 0;
}

int log(lua_State* L, int n) {
	lua_getglobal(L, "LOG");
	lua_pushnumber(L, n);
	lua_call(L, 1, 0);

	return 0;
}

int log(lua_State* L, bool b) {
	lua_getglobal(L, "LOG");
	lua_pushboolean(L, b);
	lua_call(L, 1, 0);

	return 0;
}

int log(lua_State* L, char b) {
	lua_getglobal(L, "LOG");
	lua_pushinteger(L, b);
	lua_call(L, 1, 0);

	return 0;
}

int log(lua_State* L, BYTE b) {
	lua_getglobal(L, "LOG");
	lua_pushinteger(L, b);
	lua_call(L, 1, 0);

	return 0;
}

int log(lua_State* L, unsigned int n) {
	return log(L, (int)n);
}
int log(lua_State* L, float n) {
	return log(L, (int)n);
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