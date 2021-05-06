#ifndef ADDRESS_H
#define ADDRESS_H

#pragma once
#include "lua.hpp"
#include "lua_function.h"

enum Access { R, W, RW };

struct Address {
	std::string id = "";
	size_t delta = 0x0;
	Access access = RW;
	LuaFunction get;
	LuaFunction set;

	void addLuaFunction(lua_State*, size_t, LuaFunction*);
	static void addLuaFunctions(lua_State*, std::vector<Address>);

	template <class obj, typename type>
	static Address build(std::string, size_t, Access);
};

#endif
