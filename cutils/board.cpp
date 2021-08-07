#include "stdafx.h"
#include "address.h"
#include "board.h"
#include "lua_board.h"
#include "map"

std::vector<Address> boardAddr {
	Address::build<lua_board, bool>("Gameboard", 0x28C8, R),
	Address::build<lua_board, int>("HighlightedX", 0x28D0, R),
	Address::build<lua_board, int>("HighlightedY", 0x28D4, R),
};

std::vector<Address> tileAddr {
	Address::build<lua_tile, unsigned char>("RubbleType", 0x6C, RW),
	Address::build<lua_tile, int>("Health", 0x74, RW),
	Address::build<lua_tile, int>("MaxHealth", 0x78, RW),
	Address::build<lua_tile, int>("LostHealth", 0x80, RW),
	Address::build<lua_tile, bool>("Highlighted", 0x2400, R),
	Address::build<lua_tile, const char*>("TerrainIcon", 0x2394, R),
	Address::build<lua_tile, int>("UniqueBuilding", 0x23E8, R),
	Address::build<lua_tile, int>("UniqueBuildingObject", 0x24A4, R),
	Address::build<lua_tile, const char*>("UniqueBuildingName", 0x24AC, R),
	Address::build<lua_tile, bool>("Frozen", 0x27A1, RW),
	Address::build<lua_tile, bool>("Shield", 0x27A4, RW),
	Address::build<lua_tile, int>("Terrain", 0x27E0, RW),
	Address::build<lua_tile, unsigned char>("FireType", 0x27EC, RW),
	Address::build<lua_tile, bool>("Acid", 0x27F1, RW),
	Address::build<lua_tile, const char*>("ItemName", 0x27F4, R),
	Address::build<lua_tile, bool>("Smoke", 0x280D, RW),
	Address::build<lua_tile, int>("GridLoss", 0x2848, W),
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
