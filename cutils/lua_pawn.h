#pragma once
#include "lua.hpp"
#include "lua_obj.h"

class lua_pawn : public lua_obj {
public:
	lua_pawn(lua_State* L, int index);
	~lua_pawn();

	using lua_obj::get;
	using lua_obj::set;

	template <typename type>
	static int get(lua_State* L);
	template <typename type>
	static int set(lua_State* L);
};
