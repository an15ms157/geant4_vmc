//------------------------------------------------
// The Virtual Monte Carlo examples
// Copyright (C) 2007 - 2014 Ivana Hrivnacova
// All rights reserved.
//
// For the licensing terms see geant4_vmc/LICENSE.
// Contact: root-vmc@cern.ch
//-------------------------------------------------

/// \file A01/set_g3_vis.C
/// \brief Macro for setting G3 visualization for Example A01

#include "TVirtualMC.h"

void set_g3_vis()
{
/// Macro for setting G3 visualization for Example A01

  if ( TString(gMC->GetName()) == "TGeant3TGeo" ) {
    // Set drawing options
    TGeoVolume* vol;
    vol = gGeoManager->GetVolume("ABSO");
    if (vol) vol->SetLineColor(kMagenta);
    vol = gGeoManager->GetVolume("GAPX");
    if (vol) vol->SetLineColor(kYellow);
    gMC->SetCollectTracks(kTRUE);
  }
}
