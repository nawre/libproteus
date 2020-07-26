#include "tests.h"
#include "tests_assert.h"

#include "proteus/Ocean.h"

#define OCEAN_DATA_FILE_1 "./test_data/ocean/f1.csv"
#define OCEAN_DATA_FILE_2 "./test_data/ocean/f1.csv"

int test_Ocean_run()
{
	// TODO: Need a more complete test. This just sanity checks that we read the data,
	//       and that some of the weather items were filled in correctly (sea surface temperature and salinity).

	if (0 != proteus_Ocean_init(OCEAN_DATA_FILE_1, OCEAN_DATA_FILE_2))
	{
		return 1;
	}

	proteus_GeoPos p;
	proteus_OceanData od;


	p.lat = 55.0;
	p.lon = -100.0;
	IS_FALSE(proteus_Ocean_get(&p, &od));

	p.lat = -80.0;
	p.lon = 50.0;
	IS_FALSE(proteus_Ocean_get(&p, &od));

	p.lat = 40.0;
	p.lon = -60.0;
	IS_TRUE(proteus_Ocean_get(&p, &od));
	EQUALS_FLT(28.003f, od.surfaceTemp);
	EQUALS_FLT(35.396f, od.salinity);
	EQUALS_FLT(0.0, od.ice);

	p.lat = -65.2;
	p.lon = 70.4;
	IS_TRUE(proteus_Ocean_get(&p, &od));
	EQUALS_FLT(-1.814f, od.surfaceTemp);
	EQUALS_FLT(33.737f, od.salinity);
	EQUALS_FLT(100.0, od.ice);


	return 0;
}
