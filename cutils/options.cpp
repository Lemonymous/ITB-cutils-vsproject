#include "stdafx.h"
#include "options.h"

const char* NAME;
bool VERBOSE;
bool HEX;
bool DEBUG_MODE;
bool GET_FUNCS;
bool SET_FUNCS;

std::string getAddrFormat() {
	if (HEX)
		return std::string("0x%X");
	else
		return std::string("%s");
}

int Options::get(lua_State* L, const char* name, int default_value) {
	int result = default_value;
	lua_getfield(L, 1, name);

	if (!lua_isnil(L, -1))
		result = lua_tointeger(L, -1);

	lua_pop(L, 1);
	return result;
}
bool Options::get(lua_State* L, const char* name, bool default_value) {
	bool result = default_value;
	lua_getfield(L, 1, name);

	if (!lua_isnil(L, -1))
		result = lua_toboolean(L, -1);

	lua_pop(L, 1);
	return result;
}
const char* Options::get(lua_State* L, const char* name, const char* default_value) {
	const char* result = default_value;
	lua_getfield(L, 1, name);

	if (!lua_isnil(L, -1))
		result = lua_tostring(L, -1);

	lua_pop(L, 1);
	return result;
}
