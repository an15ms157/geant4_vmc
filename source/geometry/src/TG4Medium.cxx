// $Id: TG4Medium.cxx,v 1.2 2006/12/15 09:30:29 brun Exp $
// Category: geometry
//
// Class TG4Medium
// -------------------------
// See the class description in the header file.
//
// Author: I. Hrivnacova

#include "TG4Medium.h"
#include "TG4Limits.h"
#include "TG4Globals.h"

#include <G4LogicalVolume.hh>
#include <G4Material.hh>
#include <G4UserLimits.hh>

const G4String TG4Medium::fgkUndefinedName = "UndefinedMediumName";

//_____________________________________________________________________________
TG4Medium::TG4Medium(G4int id) 
  : fID(id),
    fName(fgkUndefinedName),
    fMaterial(0),
    fLimits(0)
{
/// Standard constructor from given id
}

//_____________________________________________________________________________
TG4Medium::~TG4Medium() 
{
/// Destructor
}

//_____________________________________________________________________________
void TG4Medium::Print() const
{
/// Print medium characteristics

  G4cout << "ID = " << fID
         << "  name = "<< fName
         << "  limits = " << fLimits;
 
  TG4Limits* limits =  dynamic_cast<TG4Limits*> (fLimits);
  if (limits) limits->Print();
}         

//_____________________________________________________________________________
void TG4Medium::SetName(const G4String& name)
{
/// Set the given name;
/// give a warning if medium name has been already defined

  if ( fName != fgkUndefinedName &&  fName != name ) {
    TG4Globals::Warning(
      "TG4Medium", "SetName", 
      "Reseting name " + TString(fName) + " to " + TString(name));
  }  
  fName = name;
}  

//_____________________________________________________________________________
void TG4Medium::SetMaterial(G4Material* material)
{
/// Set the given material;
/// give a warning if medium material has been already defined

  if ( fMaterial && fMaterial != material ) {
    G4cout << fMaterial->GetName() << " " << material->GetName() << G4cout;
    TG4Globals::Warning(
      "TG4Medium", "SetMaterial",
      "Reseting material " + TString(fMaterial->GetName()) + 
      " to " + TString(material->GetName()));
  }  
  fMaterial = material;
}  

//_____________________________________________________________________________
void TG4Medium::SetLimits(G4UserLimits* limits)
{
/// Set the given limits;

  // if ( fLimits && fLimits != limits ) {
  //  TG4Globals::Warning(
  //    "TG4Medium", "SetLimits", "Reseting medium limits");
  //}  
  fLimits = limits;
}  