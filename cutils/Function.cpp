#include "stdafx.h"
#include "function.h"

Function Function::build(std::string id, lua_CFunction func) {
	return Function{ id, func };
}

void Function::addLuaFunction(lua_State* L) {
	if (!lua_istable(L, -1))
		luaL_error(L, "addLuaFunction failed: parent table does not exist");

	lua_pushstring(L, id.c_str());
	lua_pushcfunction(L, func);
	lua_rawset(L, -3);
}

void Function::addLuaFunctions(lua_State* L, std::vector<Function> functions) {
	if (!lua_istable(L, -1))
		luaL_error(L, "addLuaFunctions failed: parent table does not exist");

	for (auto function : functions) {

		if (VERBOSE)
			log(L, ("[-]: " + function.id).c_str());

		function.addLuaFunction(L);
	}
}
