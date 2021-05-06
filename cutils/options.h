#pragma once
#include "lua.hpp"

extern const char* NAME;
extern bool VERBOSE;
extern bool HEX;
extern bool DEBUG_MODE;
extern bool GET_FUNCS;
extern bool SET_FUNCS;

std::string getAddrFormat();

class Options {
public:
	static int get(lua_State* L, const char* name, int default_value);
	static bool get(lua_State* L, const char* name, bool default_value);
	static const char* get(lua_State* L, const char* name, const char* default_value);
};
