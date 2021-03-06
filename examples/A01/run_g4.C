//------------------------------------------------
// The Virtual Monte Carlo examples
// Copyright (C) 2007 - 2014 Ivana Hrivnacova
// All rights reserved.
//
// For the licensing terms see geant4_vmc/LICENSE.
// Contact: root-vmc@cern.ch
//-------------------------------------------------

/// \ingroup A01
/// \file A01/run_g4.C
/// \brief Macro for running Example A01 with Geant4.

#include "set_g4_vis.C"

void run_g4(const TString& configMacro = "g4Config.C")
{
/// Macro function for running Example A01 with Geant4 from
/// Root interactive session
/// Note that since Root 6 the libraries have to be loaded first
/// via load_g4.C.
/// \param configMacro configuration macro name, default \ref E03/g4Config.C

  // MC application
  A01MCApplication* appl
    =  new A01MCApplication("ExampleA01", "The exampleA01 MC application");
  appl->GetPrimaryGenerator()->SetRandomize(false);
  appl->SetWriteStack(true);
  appl->SetWriteHits(true);
  // Activate use of local magnetic field (available only with Geant4);
  // requires to run with g4[tgeo]Config2.C
  // appl->SetUseLocalMagField(true);

  appl->InitMC(configMacro);

  // visualization setting
  set_g4_vis();

  // Enter in Geant4 interactive session
  //((TGeant4*)gMC)->StartGeantUI();

  TStopwatch timer;
  timer.Start();
  appl->RunMC(5);
  timer.Stop();
  timer.Print();

  delete appl;
}
