#ifndef FUNCTION_H
#define FUNCTION_H

#pragma once
#include "lua.hpp"
#include "lua_function.h"

struct Function {
	std::string id = "";
	lua_CFunction func;

	void addLuaFunction(lua_State*);
	static void addLuaFunctions(lua_State*, std::vector<Function>);

	static Function build(std::string, lua_CFunction);
};

#endif
