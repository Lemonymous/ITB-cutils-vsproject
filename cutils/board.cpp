#include "stdafx.h"
#include "address.h"
#include "board.h"
#include "lua_board.h"
#include "map"

std::vector<Address> boardAddr {
	Address::build<lua_board, bool>("Gameboard", 0x28C8, R),
	Address::build<lua_board, int>("HighlightedX", 0x2C30, R),
	Address::build<lua_board, int>("HighlightedY", 0x2C34, R),
};

std::vector<Address> tileAddr {
	Address::build<lua_tile, unsigned char>("RubbleType", 0x6C, RW),
	Address::build<lua_tile, int>("Health", 0x74, RW),
	Address::build<lua_tile, int>("MaxHealth", 0x78, RW),
	Address::build<lua_tile, int>("LostHealth", 0x80, RW),
	Address::build<lua_tile, bool>("Highlighted", 0x26EC, R),
	Address::build<lua_tile, const char*>("TerrainIcon", 0x2680, R),
	Address::build<lua_tile, int>("UniqueBuilding", 0x26D4, R),
	Address::build<lua_tile, int>("UniqueBuildingObject", 0x2790, R),
	Address::build<lua_tile, const char*>("UniqueBuildingName", 0x2798, R),
	Address::build<lua_tile, bool>("Frozen", 0x2A9D, RW),
	Address::build<lua_tile, bool>("Shield", 0x2AA0, RW),
	Address::build<lua_tile, int>("Terrain", 0x2ADC, RW),
	Address::build<lua_tile, unsigned char>("FireType", 0x2AE8, RW),
	Address::build<lua_tile, bool>("Acid", 0x2AED, RW),
	Address::build<lua_tile, const char*>("ItemName", 0x2AF0, R),
	Address::build<lua_tile, bool>("Smoke", 0x2B21, RW),
	Address::build<lua_tile, int>("GridLoss", 0x2B5C, W),
};

void add_board_functions(lua_State* L) {
	if (!lua_istable(L, -1))
		luaL_error(L, "add_board_functions failed: parent table does not exist");

	if (VERBOSE)
		log(L, "Additional Board functions = {");

	Address::addLuaFunctions(L, boardAddr);
	Address::addLuaFunctions(L, tileAddr);

	if (VERBOSE)
		log(L, "}");
}
