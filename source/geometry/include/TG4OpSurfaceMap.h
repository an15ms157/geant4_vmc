// $Id: TG4OpSurfaceMap.h,v 1.1 2005/05/17 14:55:13 brun Exp $
/// \ingroup geometry
//
/// \typedef TG4OpSurfaceMap
/// \brief The map between optical surfaces names and their objects.
///
/// Author: I. Hrivnacova

#ifndef TG4_OP_SURFACE_MAP_H
#define TG4_OP_SURFACE_MAP_H

#include <G4OpticalSurface.hh>

typedef std::map<G4String, G4OpticalSurface*>  TG4OpSurfaceMap;

#endif