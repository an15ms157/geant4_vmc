#!/bin/sh 
# $Id: test_suite.sh,v 1.3 2005/10/13 08:42:29 brun Exp $
#
# Test all VMC examples and regenerate output files
#
# by I. Hrivnacova, IPN Orsay

CURDIR=`pwd`

for EXAMPLE in E01
do
  cd $CURDIR/$EXAMPLE

  # run G3 + native geometry
  echo "... Running example $EXAMPLE with G3" 
  root.exe -q "run_g3.C" >& g3.out
  root.exe -q "test_g3.C" >& g3_test.out

  # run G3 + TGeo geometry
  echo "... Running example $EXAMPLE with G3 + TGeo" 
  root.exe -q "run_g3.C(\"g3tgeoConfig.C\")" >& g3tgeo.out
  root.exe -q "test_g3.C(\"g3tgeoConfig.C\")" >& g3tgeo_test.out
  
  # run G4
  echo "... Running example $EXAMPLE with G4" 
  root.exe -q "run_g4.C"  >& g4.out
  root.exe -q "test_g4.C"  >& g4_test.out
done
  
for EXAMPLE in E02 E06
do
  cd $CURDIR/$EXAMPLE

  # run G3 + native geometry
  echo "... Running example $EXAMPLE with G3" 
  root.exe -q "run_g3.C" >& g3.out

  # run G3 + TGeo geometry
  echo "... Running example $EXAMPLE with G3 + TGeo" 
  root.exe -q "run_g3.C(\"g3tgeoConfig.C\")" >& g3tgeo.out
  
  # run G4
  echo "... Running example $EXAMPLE with G4" 
  root.exe -q "run_g4.C"  >& g4.out
done
  
for EXAMPLE in E03
do
  for TEST in test1 test2
  do
    cd $CURDIR/$EXAMPLE

    # run G3 + native geometry
    echo "... Running example $EXAMPLE $TEST with G3" 
    root.exe -q "run_g3.C(\"g3Config.C\", \"$TEST.C\")" >& g3_$TEST.out

    # run G3 + TGeo geometry
    echo "... Running example $EXAMPLE $TEST with G3 + TGeo" 
    root.exe -q "run_g3.C(\"g3tgeoConfig.C\", \"$TEST.C\")" >& g3tgeo_$TEST.out
  
    # run G4
    echo "... Running example $EXAMPLE $TEST with G4" 
    root.exe -q "run_g4.C(\"g4Config.C\", \"$TEST.C\")"  >& g4_$TEST.out

    # run G4 + user physics list
    echo "... Running example $EXAMPLE $TEST with G4 with user physics list" 
    root.exe -q "run_g4.C(\"g4Config2.C\", \"$TEST.C\")"  >& g4pl_$TEST.out
  done  
done
  
cd $CURDIR
