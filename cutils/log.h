#pragma once
#include "lua.hpp"

int logf(lua_State* L, const char*, std::vector<int>);
int logf(lua_State* L, const char*, std::vector<unsigned int>);
int logf(lua_State* L, const char*, std::vector<bool>);
int logf(lua_State* L, const char*, std::vector<char>);
int logf(lua_State* L, const char*, std::vector<BYTE>);
int logf(lua_State* L, const char*, std::vector<const char*>);
int logf(lua_State* L, const char*, int);
int logf(lua_State* L, const char*, unsigned int);
int logf(lua_State* L, const char*, bool);
int logf(lua_State* L, const char*, char);
int logf(lua_State* L, const char*, BYTE);
int logf(lua_State* L, const char*, const char*);
int log(lua_State* L, const char*, std::vector<int>);
int log(lua_State* L, const char*, std::vector<unsigned int>);
int log(lua_State* L, const char*, std::vector<bool>);
int log(lua_State* L, const char*, std::vector<char>);
int log(lua_State* L, const char*, std::vector<BYTE>);
int log(lua_State* L, const char*, std::vector<const char*>);
int log(lua_State* L, const char*, int);
int log(lua_State* L, const char*, unsigned int);
int log(lua_State* L, const char*, bool);
int log(lua_State* L, const char*, char);
int log(lua_State* L, const char*, BYTE);
int log(lua_State* L, const char*, const char*);
int log(lua_State* L, const char*);
int log(lua_State* L, unsigned int);
int log(lua_State* L, int);
int log(lua_State* L, float);
int log(lua_State* L, bool);
