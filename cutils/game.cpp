#include "stdafx.h"
#include "address.h"
#include "game.h"
#include "lua_game.h"
#include "map"

std::vector<Address> gameAddr{
	Address::build<lua_game, int>("Rep", 0x7170, RW),
	Address::build<lua_game, int>("Core", 0x7174, RW),
	Address::build<lua_game, int>("Power", 0xA19C, RW),
	Address::build<lua_game, int>("MaxPower", 0xA1A0, RW),
	Address::build<lua_game, int>("Grid", 0xA2D0, RW),
};

void add_game_functions(lua_State* L) {
	if (!lua_istable(L, -1))
		luaL_error(L, "add_game_functions failed: parent table does not exist");

	if (VERBOSE)
		log(L, "Additional Game functions = {");

	Address::addLuaFunctions(L, gameAddr);

	if (VERBOSE)
		log(L, "}");
}
