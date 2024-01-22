#pragma once

#include <array>

// Grass
constexpr uint PALETTE_GRASS_LIGHT[8] =
{
	0x340, 0x680, 0x650, 0xee0, 0xee0, 0xab0, 0x570, 0x590
};
constexpr uint PALETTE_GRASS_SNOW[8] =
{
	0x332, 0x8a6, 0xbc8, 0xeee, 0x9a7, 0x895, 0x673, 0x995
};
constexpr uint PALETTE_GRASS_DARK[8] =
{
	0x330, 0x570, 0x440, 0x430, 0x550, 0x340, 0x330, 0x220
};

// Dirt
constexpr uint PALETTE_DIRT[8] =
{
	0x321, 0x321, 0x321, 0x321, 0x321, 0x321, 0x321, 0x321
};
constexpr uint PALETTE_DIRT_MUD[8] =
{
	0x210, 0x210, 0x210, 0x210, 0x210, 0x210, 0x210, 0x210
};
constexpr uint PALETTE_DIRT_PODZOL[8] =
{
	0x321, 0x210, 0x432, 0x321, 0x321, 0x210, 0x321, 0x321
};
constexpr uint PALETTE_DIRT_STONE[8] =
{
	0x321, 0x444, 0x321, 0x321, 0x332, 0x321, 0x321, 0x321
};

// Sand
constexpr uint PALETTE_SAND[8] =
{
	0xec4, 0xb93, 0x641, 0xa72, 0xca4, 0x852, 0xa73, 0x751
};

// Stone
constexpr uint PALETTE_STONE[8] =
{
	0x554, 0x444, 0x666, 0x665, 0x332, 0x443, 0x555, 0x333
};
constexpr uint PALETTE_STONE_SNOW[8] =
{
	0xaa9, 0x777, 0xccc, 0xbbb, 0x665, 0x887, 0xaaa, 0x999
};


// Tundra
constexpr std::array<uint, 8> PALETTE_TUNDRA_FALL =
{
	0xD40,0xD40,0xD40,0xD40,0xD40,0xD40,0xD40,0xD40
	// 0x850, 0x268, 0x557, 0xCB0, 0x844, 0x268, 0x566, 0x743
};

struct Biome
{

};