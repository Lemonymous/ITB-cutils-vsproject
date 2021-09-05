#include "stdafx.h"
#include "address.h"
#include "function.h"
#include "pawn.h"
#include "lua_pawn.h"
#include "map"

std::vector<Address> pawnAddr{
	Address::build<lua_pawn, int>("QueuedTargetX", 0x20, RW),
	Address::build<lua_pawn, int>("QueuedTargetY", 0x24, RW),
	Address::build<lua_pawn, int>("QueuedWeaponId", 0x28, R),
	Address::build<lua_pawn, int>("DefaultTeam", 0x40, RW),
	//Address::build<lua_pawn, int>("RepairSkill", 0x64, R),
	Address::build<lua_pawn, int>("Team", 0xAC, RW),
	Address::build<lua_pawn, int>("Health", 0x898, RW),
	Address::build<lua_pawn, int>("MaxHealth", 0x89C, RW),
	Address::build<lua_pawn, int>("MarkHealthLoss", 0x8A0, W),
	Address::build<lua_pawn, bool>("Fire", 0x8C0, RW),
	Address::build<lua_pawn, bool>("Frozen", 0x8C1, RW),
	Address::build<lua_pawn, bool>("Acid", 0x8C3, RW),
	Address::build<lua_pawn, bool>("Shield", 0x8C4, RW),
	Address::build<lua_pawn, bool>("Active", 0x904, RW),
	Address::build<lua_pawn, bool>("Pushable", 0x905, RW),
	Address::build<lua_pawn, bool>("Neutral", 0x964, RW),
	Address::build<lua_pawn, int>("BaseMaxHealth", 0x970, RW),
	Address::build<lua_pawn, int>("MoveSpeed", 0x974, RW),
	Address::build<lua_pawn, bool>("Massive", 0x97D, RW),
	Address::build<lua_pawn, bool>("MoveSpent", 0x97E, RW),
	Address::build<lua_pawn, int>("Id", 0x984, RW),
	Address::build<lua_pawn, int>("ImageOffset", 0x988, RW),
	Address::build<lua_pawn, const char*>("Class", 0x98C, RW),
	Address::build<lua_pawn, bool>("Mech", 0x9C4, RW),
	Address::build<lua_pawn, bool>("Invisible", 0x9E0, RW),
	Address::build<lua_pawn, int>("UndoX", 0xA1C, RW),
	Address::build<lua_pawn, int>("UndoY", 0xA20, RW),
	Address::build<lua_pawn, bool>("Corpse", 0xD98, RW),
	Address::build<lua_pawn, const char*>("SoundBase", 0xD9C, RW),
	Address::build<lua_pawn, int>("ImpactMaterial", 0xDB4, RW),
	Address::build<lua_pawn, const char*>("CustomAnim", 0xDB8, RW),
	Address::build<lua_pawn, bool>("SpaceColor", 0xDD0, RW),
	Address::build<lua_pawn, int>("DefaultFaction", 0xED4, RW),
	Address::build<lua_pawn, bool>("Powered", 0xED8, RW),
	Address::build<lua_pawn, bool>("MissionCritical", 0xEDA, RW),
	Address::build<lua_pawn, bool>("Minor", 0xEE8, RW),
	Address::build<lua_pawn, int>("Mutation", 0xF00, RW),
	Address::build<lua_pawn, bool>("Flying", 0x110C, RW),
	Address::build<lua_pawn, bool>("Teleporter", 0x110D, RW),
	Address::build<lua_pawn, int>("Leader", 0x1110, RW),
	Address::build<lua_pawn, bool>("Jumper", 0x1114, RW),
	Address::build<lua_pawn, int>("Owner", 0x1118, RW),
};

std::vector<Function> weaponAddr{
	Function::build("GetWeaponCount", lua_pawn::getWeaponCount),
	Function::build("GetWeapon", lua_pawn::getWeapon),
	Function::build("GetPoweredWeapon", lua_pawn::getPoweredWeapon),
};

void add_pawn_functions(lua_State* L) {
	if (!lua_istable(L, -1))
		luaL_error(L, "add_pawn_functions failed: parent table does not exist");

	if (VERBOSE)
		log(L, "Additional Pawn functions = {");

	Address::addLuaFunctions(L, pawnAddr);
	Function::addLuaFunctions(L, weaponAddr);

	if (VERBOSE)
		log(L, "}");
}
