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
	Address::build<lua_pawn, int>("Health", 0x8A4, RW),
	Address::build<lua_pawn, int>("MaxHealth", 0x8A8, RW),
	Address::build<lua_pawn, int>("MarkHealthLoss", 0x8AC, W),
	Address::build<lua_pawn, bool>("Fire", 0x8CC, RW),
	Address::build<lua_pawn, bool>("Frozen", 0x8CD, RW),
	Address::build<lua_pawn, bool>("Acid", 0x8CF, RW),
	Address::build<lua_pawn, bool>("Shield", 0x8D0, RW),
	Address::build<lua_pawn, bool>("Active", 0x918, RW),
	Address::build<lua_pawn, bool>("Pushable", 0x91A, RW),
	Address::build<lua_pawn, bool>("Neutral", 0x978, RW),
	Address::build<lua_pawn, int>("BaseMaxHealth", 0x984, RW),
	Address::build<lua_pawn, int>("MoveSpeed", 0x98C, RW),
	Address::build<lua_pawn, bool>("Massive", 0x999, RW),
	Address::build<lua_pawn, bool>("MoveSpent", 0x99A, RW),
	Address::build<lua_pawn, int>("Id", 0x9A0, RW),
	Address::build<lua_pawn, int>("ImageOffset", 0x9A4, RW),
	Address::build<lua_pawn, const char*>("Class", 0x9A8, RW),
	Address::build<lua_pawn, bool>("Mech", 0x9E0, RW),
	Address::build<lua_pawn, bool>("Invisible", 0x9FC, RW),
	Address::build<lua_pawn, int>("UndoX", 0xA38, RW),
	Address::build<lua_pawn, int>("UndoY", 0xA3C, RW),
	Address::build<lua_pawn, bool>("Corpse", 0xF78, RW),
	Address::build<lua_pawn, const char*>("SoundBase", 0xF7C, RW),
	Address::build<lua_pawn, int>("ImpactMaterial", 0xF94, RW),
	Address::build<lua_pawn, const char*>("CustomAnim", 0xF98, RW),
	Address::build<lua_pawn, bool>("SpaceColor", 0xFB0, RW),
	Address::build<lua_pawn, int>("DefaultFaction", 0x10B4, RW),
	Address::build<lua_pawn, bool>("Powered", 0x10B8, RW),
	Address::build<lua_pawn, bool>("MissionCritical", 0x10BA, RW),
	Address::build<lua_pawn, bool>("Minor", 0x10C8, RW),
	Address::build<lua_pawn, int>("Mutation", 0x10E0, RW),
	Address::build<lua_pawn, bool>("Flying", 0x130C, RW),
	Address::build<lua_pawn, bool>("Teleporter", 0x130D, RW),
	Address::build<lua_pawn, int>("Leader", 0x1310, RW),
	Address::build<lua_pawn, bool>("Jumper", 0x1314, RW),
	Address::build<lua_pawn, int>("Owner", 0x1318, RW),
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
