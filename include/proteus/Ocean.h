#ifndef _proteus_Ocean_h_
#define _proteus_Ocean_h_

#include <stdbool.h>

#include "proteus/GeoPos.h"
#include "proteus/GeoVec.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


/**
 * A structure containing various ocean condition parameters
 */
typedef struct
{
	proteus_GeoVec current; // Ocean surface current, using metres/second for magnitude

	float surfaceTemp; // Sea surface temperature, in degrees Celsius
	float salinity; // Sea surface salinity, probably using PSS-78 values
	float ice; // Sea ice concentration, in percent
} proteus_OceanData;

/**
 * Initializes the ocean data processing system.
 *
 * Assumes two forecast points, 12 hours apart (used for temporal interpolation).
 *
 * Parameters
 * 	f1File [in]: the path to the file with the first forecast point data
 * 	f2File [in]: the path to the file with the second forecast point data
 *
 * Returns
 * 	0, on success
 * 	any other value, on failure
 */
int proteus_Ocean_init(const char* f1File, const char* f2File);

/**
 * Provides ocean information, if available, at the given geographical position.
 *
 * Parameters
 * 	pos [in]: the geographical position to be queried
 * 	od [out]: the ocean data structure to be populated
 *
 * Returns
 * 	true, if ocean data is available and valid at the provided position
 * 	false, if ocean data is not available or not valid at the provided position
 */
bool proteus_Ocean_get(const proteus_GeoPos* pos, proteus_OceanData* od);


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _proteus_Ocean_h_