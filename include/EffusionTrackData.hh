//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
// $Id: $
//
// --------------------------------------------------------------------
// GEANT 4 class header file
//
// Class Description:
//    Extends G4Track properties with information needed for the
//    channeling biasing operator.
//
// ------------------ EffusionTrackData ------------------
//
// Author: M.Verderi (LLR), E. Bagli (INFN) April 2016
//
// --------------------------------------------------------------------

#ifndef EffusionTrackData_hh
#define EffusionTrackData_hh

class EffusionProcess;
#include "G4VAuxiliaryTrackInformation.hh"

class EffusionTrackData : public G4VAuxiliaryTrackInformation {
    friend class EffusionProcess;
    
public:
    EffusionTrackData();
    ~EffusionTrackData();
    
    void Print() const;
    
private:
    const EffusionProcess* fEffusionProcess;
    
public:
    
public:
    void SetTimeSticked(G4double aDouble) {
        fTimeSticked = aDouble;
        fTotalTimeSticked += fTimeSticked;
    };
    G4double GetTimeSticked() {return fTimeSticked;};
    
    void SetTotalTimeSticked(G4double aDouble) {fTotalTimeSticked = aDouble;};
    G4double GetTotalTimeSticked() {return fTotalTimeSticked;};
    
private:
    // ----------
    // Sticking Time
    // ----------
    G4double fTimeSticked;
    G4double fTotalTimeSticked;

};

#endif
