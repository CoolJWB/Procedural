#pragma once

#include <array>
#include <vector>
#include <cassert>

constexpr float cabs(const float x)
{
	return x < 0 ? -x : x;
}

struct Biome
{
	const char* name;

	float
		elevationMin, elevationMax,
		temperatureMin, temperatureMax,
		humidityMin, humidityMax;

	float
		elevationLength,
		temperatureLength,
		humidityLength;

	std::array<std::array<uint, 8>, 4> surface;
	std::array<std::array<uint, 8>, 4> layers;
	std::array<std::array<uint, 8>, 2> liquids;

	constexpr Biome
	(
		const char* name,
		float elevationMin, float elevationMax,
		float temperatureMin, float temperatureMax,
		float humidityMin, float humidityMax,
		std::array<std::array<uint, 8>, 4> surface,
		std::array<std::array<uint, 8>, 4> layers,
		std::array<std::array<uint, 8>, 2> liquids
	) :
		name(name),
		elevationMin(elevationMin), elevationMax(elevationMax),
		temperatureMin(temperatureMin), temperatureMax(temperatureMax),
		humidityMin(humidityMin), humidityMax(humidityMax),
		elevationLength(cabs(elevationMax - elevationMin)),
		temperatureLength(cabs(temperatureMax - temperatureMin)),
		humidityLength(cabs(humidityMax - humidityMin)),
		surface(surface),
		layers(layers),
		liquids(liquids)
	{
		// Empty
	}
};

// Grayscale
constexpr std::array<uint, 8> PALETTE_GRAY =
{
	0x111, 0x222, 
	0x444, 0x666, 
	0x888, 0xaaa, 
	0xccc, 0xeee
};

// Grass
constexpr std::array<uint, 8> PALETTE_GRASS =
{
	0x030, 0x030, 0x030, 0x030, 0x030, 0x030, 0x030, 0x030
	//0x340, 0x680, 0x650, 0xee0, 0xee0, 0xab0, 0x570, 0x590
};
constexpr std::array<uint, 8> PALETTE_GRASS_SNOW =
{
	0xbc8, 0xbc8, 0xbc8, 0xbc8, 0xbc8, 0xbc8, 0xbc8, 0xbc8
	//0x332, 0x8a6, 0xbc8, 0xeee, 0x9a7, 0x895, 0x673, 0x995
};
constexpr std::array<uint, 8> PALETTE_GRASS_DARK =
{
	0x020, 0x020, 0x020, 0x020, 0x020, 0x020, 0x020, 0x020
	//0x330, 0x570, 0x440, 0x430, 0x550, 0x340, 0x330, 0x220
};

// Dirt
constexpr std::array<uint, 8> PALETTE_DIRT =
{
	0x321, 0x321, 0x321, 0x321, 0x321, 0x321, 0x321, 0x321
};
constexpr std::array<uint, 8> PALETTE_DIRT_MUD =
{
	0x210, 0x210, 0x210, 0x210, 0x210, 0x210, 0x210, 0x210
};
constexpr std::array<uint, 8> PALETTE_DIRT_PODZOL =
{
	0x321, 0x210, 0x432, 0x321, 0x321, 0x210, 0x321, 0x321
};
constexpr std::array<uint, 8> PALETTE_DIRT_STONE =
{
	0x321, 0x444, 0x321, 0x321, 0x332, 0x321, 0x321, 0x321
};

// Sand
constexpr std::array<uint, 8> PALETTE_SAND =
{
	0xec4, 0xec4, 0xec4, 0xec4, 0xec4, 0xec4, 0xec4, 0xec4
	//0xec4, 0xb93, 0x641, 0xa72, 0xca4, 0x852, 0xa73, 0x751
};

// Stone
constexpr std::array<uint, 8> PALETTE_STONE =
{
	0x554, 0x554, 0x554, 0x554, 0x554, 0x554, 0x554, 0x554
	//0x554, 0x444, 0x666, 0x665, 0x332, 0x443, 0x555, 0x333
};
constexpr std::array<uint, 8> PALETTE_STONE_SNOW =
{
	0xaa9, 0xaa9, 0xaa9, 0xaa9, 0x777, 0x777, 0x777, 0x777
	//0xaa9, 0x777, 0xccc, 0xbbb, 0x665, 0x887, 0xaaa, 0x999
};

// Snow
constexpr std::array<uint, 8> PALETTE_SNOW =
{
	0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff
	//0xfff, 0xeee, 0x556, 0x889, 0x334, 0x9ab, 0xabb, 0x666
};

// Water
constexpr std::array<uint, 8> PALETTE_WATER =
{
	0x024, 0x024, 0x024, 0x024, 0x024, 0x024, 0x024, 0x024
};
constexpr std::array<uint, 8> PALETTE_WATER_ICE =
{
	0x9df, 0x9df, 0x9df, 0x9df, 0x9df, 0x9df, 0x9df, 0x9df
	//0xfff, 0xeff, 0x39c, 0xcef, 0x9df, 0x013, 0x024, 0x59c
};

constexpr Biome BIOME_FOREST
(
	"FOREST",

	// Elevation (min/max)
	0.0f, 0.2f,
	
	// Temperature (min/max)
	0.2f, 0.4f,

	// Humidity (min/max)
	-0.6f, 0.6f,

	// Surface
	{
		PALETTE_GRASS,
		PALETTE_GRASS,
		PALETTE_GRASS,
		PALETTE_GRASS
	},

	// Layers
	{
		PALETTE_DIRT,
		PALETTE_DIRT,
		PALETTE_STONE,
		PALETTE_STONE
	},

	// Liquids
	{
		PALETTE_WATER,
		PALETTE_WATER
	}
);
constexpr Biome BIOME_SAVANNA
(
	"SAVANNA",

	// Elevation (min/max)
	0.0f, 0.2f,

	// Temperature (min/max)
	0.2, 0.5,

	// Humidity (min/max)
	0.4, 1.0,

	// Surface
	{
		PALETTE_GRASS_DARK,
		PALETTE_GRASS_DARK,
		PALETTE_GRASS_DARK,
		PALETTE_GRASS_DARK
	},

	// Layers
	{
		PALETTE_DIRT,
		PALETTE_DIRT,
		PALETTE_STONE,
		PALETTE_STONE
	},

	// Liquids
	{
		PALETTE_WATER,
		PALETTE_WATER
	}
);
constexpr Biome BIOME_DESERT
(
	"DESERT",

	// Elevation (min/max)
	0.0f, 0.2f,

	// Temperature (min/max)
	-0.3, 1.0,

	// Humidity (min/max)
	-1.0, -0.4,

	// Surface
	{
		PALETTE_SAND,
		PALETTE_SAND,
		PALETTE_SAND,
		PALETTE_SAND
	},

	// Layers
	{
		PALETTE_DIRT,
		PALETTE_DIRT,
		PALETTE_STONE,
		PALETTE_STONE
	},

	// Liquids
	{
		PALETTE_WATER,
		PALETTE_WATER
	}
);
constexpr Biome BIOME_TUNDRA
(
	"TUNDRA",

	// Elevation (min/max)
	0.0f, 0.2f,

	// Temperature (min/max)
	-1.0, -0.3,

	// Humidity (min/max)
	-1.0, -0.4,

	// Surface
	{
		PALETTE_GRASS_SNOW,
		PALETTE_GRASS_SNOW,
		PALETTE_GRASS_SNOW,
		PALETTE_GRASS_SNOW
	},

	// Layers
	{
		PALETTE_DIRT,
		PALETTE_DIRT,
		PALETTE_STONE,
		PALETTE_STONE
	},

	// Liquids
	{
		PALETTE_WATER_ICE,
		PALETTE_WATER_ICE
	}
);
constexpr Biome BIOME_MOUNTAIN
(
	"MOUNTAIN",

	// Elevation (min/max)
	0.2f, 1.0f,

	// Temperature (min/max)
	-1.0, 1.0,

	// Humidity (min/max)
	-1.0, 1.0,

	// Surface
	{
		PALETTE_STONE,
		PALETTE_STONE,
		PALETTE_STONE,
		PALETTE_STONE
	},

	// Layers
	{
		PALETTE_STONE,
		PALETTE_STONE,
		PALETTE_STONE,
		PALETTE_STONE
	},

	// Liquids
	{
		PALETTE_WATER,
		PALETTE_WATER
	}
);
constexpr Biome BIOME_MOUNTAIN_SNOW
(
	"MOUNTAIN_SNOW",

	// Elevation (min/max)
	0.8f, 1.0f,

	// Temperature (min/max)
	-1.0, -0.2,

	// Humidity (min/max)
	-1.0, 1.0,

	// Surface
	{
		PALETTE_STONE_SNOW,
		PALETTE_STONE_SNOW,
		PALETTE_STONE_SNOW,
		PALETTE_STONE_SNOW
	},

	// Layers
	{
		PALETTE_STONE,
		PALETTE_STONE,
		PALETTE_STONE,
		PALETTE_STONE
	},

	// Liquids
	{
		PALETTE_WATER_ICE,
		PALETTE_WATER_ICE
	}
);
constexpr Biome BIOME_OCEAN
(
	"OCEAN",

	// Elevation (min/max)
	-1.0f, 0.0f,

	// Temperature (min/max)
	0.0, 1.0,

	// Humidity (min/max)
	-1.0, 1.0,

	// Surface
	{
		PALETTE_WATER,
		PALETTE_WATER,
		PALETTE_WATER,
		PALETTE_WATER
	},

	// Layers
	{
		PALETTE_DIRT,
		PALETTE_DIRT,
		PALETTE_STONE,
		PALETTE_STONE
	},

	// Liquids
	{
		PALETTE_WATER,
		PALETTE_WATER
	}
);
constexpr Biome BIOME_OCEAN_ICE
(
	"OCEAN_ICE",

	// Elevation (min/max)
	-1.0f, 0.0f,

	// Temperature (min/max)
	-1.0, 0.0,

	// Humidity (min/max)
	-1.0, 1.0,

	// Surface
	{
		PALETTE_WATER_ICE,
		PALETTE_WATER_ICE,
		PALETTE_WATER_ICE,
		PALETTE_WATER_ICE
	},

	// Layers
	{
		PALETTE_DIRT,
		PALETTE_DIRT,
		PALETTE_STONE,
		PALETTE_STONE
	},

	// Liquids
	{
		PALETTE_WATER_ICE,
		PALETTE_WATER_ICE
	}
);

constexpr std::array<Biome, 8> biomes =
{
	BIOME_FOREST,
	BIOME_SAVANNA,
	BIOME_DESERT,
	BIOME_TUNDRA,
	BIOME_MOUNTAIN,
	BIOME_MOUNTAIN_SNOW,
	BIOME_OCEAN,
	BIOME_OCEAN_ICE
};

Biome BiomeFunction(const float elevation, const float temperature, const float humidity)
{
	int bestIndex = 0; // TODO: use -1, should never find invalid biome
	float bestLength = FLT_MAX;  // Initialize with maximum possible float value

	for (int index = 0; index < biomes.size(); index++)
	{
		const Biome& biome = biomes[index];

		// Check if all parameters are within their respective ranges
		if (elevation >= biome.elevationMin && elevation <= biome.elevationMax &&
			temperature >= biome.temperatureMin && temperature <= biome.temperatureMax &&
			humidity >= biome.humidityMin && humidity <= biome.humidityMax)
		{
			float currentLength = biome.elevationLength + biome.temperatureLength + biome.humidityLength;

			// Update bestIndex if this biome is a closer match
			if (currentLength < bestLength)
			{
				bestIndex = index;
				bestLength = currentLength;
			}
		}
	}

	assert(bestIndex > -1);
	return biomes[bestIndex];
}