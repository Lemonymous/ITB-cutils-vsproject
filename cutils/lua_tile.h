#ifndef LUA_TILE_H
#define LUA_TILE_H

#pragma once
#include "lua.hpp"
#include "lua_obj.h"

extern const size_t BOARD_TILES_ROW;
extern const size_t BOARD_TILES_COLUMN;
extern const size_t TILE_OBJ_SIZE;

// forward declaration
class lua_board;

class lua_tile : public lua_obj {
public:
	int x;
	int y;

	lua_tile(lua_State* L, int index);
	~lua_tile();

	using lua_obj::get;
	using lua_obj::set;

	template <typename type>
	static int get(lua_State* L);
	template <typename type>
	static int set(lua_State* L);
};

#endif
