// $Id: example03LinkDef.h,v 1.1 2003/03/17 14:56:51 brun Exp $

#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
 
#pragma link C++ class  Ex03MCApplication+;
#pragma link C++ class  Ex03MCStack+;
#pragma link C++ class  Ex03DetectorConstruction+;
#pragma link C++ class  Ex03DetectorConstructionOld+;
#pragma link C++ class  Ex03CalorHit+;
#pragma link C++ class  Ex03CalorimeterSD+;
#pragma link C++ class  Ex03PrimaryGenerator+;
#pragma link C++ class  Ex02RootManager+;

#pragma link C++ enum   FileMode;

#endif





