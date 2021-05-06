#include "stdafx.h"
#include "lua_tile.h"
#include "lua_board.h"

const size_t BOARD_TILES_ROW = 0x4C;
const size_t BOARD_TILES_COLUMN = 0xC;
const size_t TILE_OBJ_SIZE = 0x285C;

/*
	Creates an object with the address of a tile
	on the board; which can be used to easily
	manipulate its associated memory values.
	Tile can be specified with a Point userdata,
	or with x and y integer coordinate values.
*/
lua_tile::lua_tile(lua_State* L, int index) {
	lua_board board = lua_board(L);

	if (lua_isuserdata(L, index)) {
		lua_getfield(L, index, "y");
		lua_getfield(L, index, "x");
		lua_replace(L, index);
		lua_insert(L, index + 1);
	}

	this->L = L;
	this->userdata = board.getUserdata();
	this->x = luaL_checkinteger(L, index);
	this->y = luaL_checkinteger(L, index + 1);
	// userdata can remain as the board userdata

	size_t tiles_row = *(size_t*)(board.getAddr() + BOARD_TILES_ROW);
	size_t tiles_column = *(size_t*)(tiles_row + BOARD_TILES_COLUMN * x);
	addr = tiles_column + TILE_OBJ_SIZE * y;
}

lua_tile::~lua_tile() {}

template <typename type>
int lua_tile::get(lua_State* L) {
	return lua_tile(L, 1).get<type>();
}
template <typename type>
int lua_tile::set(lua_State* L) {
	return lua_tile(L, 1).set<type>(3);
}

template int lua_tile::get<int>(lua_State* L);
template int lua_tile::get<unsigned int>(lua_State* L);
template int lua_tile::get<unsigned char>(lua_State* L);
template int lua_tile::get<double>(lua_State* L);
template int lua_tile::get<const char*>(lua_State* L);
template int lua_tile::get<bool>(lua_State* L);

template int lua_tile::set<int>(lua_State* L);
template int lua_tile::set<unsigned int>(lua_State* L);
template int lua_tile::set<unsigned char>(lua_State* L);
template int lua_tile::set<double>(lua_State* L);
template int lua_tile::set<const char*>(lua_State* L);
template int lua_tile::set<bool>(lua_State* L);
