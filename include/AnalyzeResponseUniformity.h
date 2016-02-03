//
//  AnalyzeResponseUniformity.h
//  
//
//  Created by Brian L Dorney on 28/01/16.
//
//

#ifndef ____AnalyzeResponseUniformity__
#define ____AnalyzeResponseUniformity__

//C++ Includes
#include <iterator>
#include <stdio.h>
#include <string>
#include <map>
#include <memory>
#include <vector>

//Framework Includes
//#include "DetectorMPGD.h"
#include "TimingUtilityFunctions.h"
#include "TimingUtilityTypes.h"
#include "UniformityUtilityTypes.h"

//ROOT Includes
#include "TDirectory.h"
#include "TF1.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TROOT.h"
#include "TSpectrum.h"

namespace Uniformity {
    class AnalyzeResponseUniformity {
        
    public:
        //Constructors
        //------------------------------------------------------------------------------------------------------------------------------------------
        //Default
        AnalyzeResponseUniformity();
        
        //Declare the detector and the requested granularity
        //AnalyzeResponseUniformity(int iNSlices, Uniformity::DetectorMPGD inputDet);
        
        //Set the detector and anlysis parameters at construction
        AnalyzeResponseUniformity(Uniformity::AnalysisSetupUniformity inputSetup, Uniformity::DetectorMPGD inputDet);
        
        //Actions - Methods that Do Something
        //------------------------------------------------------------------------------------------------------------------------------------------
        //Filling*****************
        //Loops over all stored clusters in detMPGD and Book histograms for the full detector
        void fillHistos();
        
        //Fitting*****************
        //Loops over all slices in detMPGD and fits Booked histograms for the full detector
        void fitHistos();
        
        //Storing*****************
        //Stores booked histograms (for those histograms that are non-null)
        void storeHistos(std::string strOutputROOTFileName, std::string strOption);
        
        //Stores booked fits (for those fits that are non-null)
        void storeFits(std::string strOutputROOTFileName, std::string strOption);
        
        //Stores TObjects created in createResponseMap() in the requested output file
        //Placeholder
        //void storeResponseMap(std::string strOutputROOTFileName, std::string strOption);
        
        //Visualizing*************
        //Displays the results of the analysis in a user friendly manner
        //Placeholder
        //void createResponseMap();
        
        //Getters - Methods that Get (i.e. Return) Something
        //------------------------------------------------------------------------------------------------------------------------------------------
        Uniformity::DetectorMPGD getDetector(){ return detMPGD; };
        
        //Printers - Methods that Print Something
        //------------------------------------------------------------------------------------------------------------------------------------------
        
        //Setters - Methods that Set Something
        //------------------------------------------------------------------------------------------------------------------------------------------
        //Sets the Analysis Setup
        void setAnalysisParameters(Uniformity::AnalysisSetupUniformity inputSetup){ aSetup = inputSetup; return; };
        
        //Sets the Detector
        void setDetector(Uniformity::DetectorMPGD inputDet){ detMPGD = inputDet; return; };
        
    private:
        //Actions - Methods that Do Something
        //------------------------------------------------------------------------------------------------------------------------------------------
        
        //Getters - Methods that Get (i.e. Return) Something
        //------------------------------------------------------------------------------------------------------------------------------------------
        //Returns a fit whose parameters match those defined in the AnalysisSetupUniformity
        //TF1 getFit(int iEta, int iPhi, int iSlice, Uniformity::AnalysisSetupUniformity & setupFit);
        TF1 getFit(int iEta, int iPhi, int iSlice, Timing::HistoSetup & setupHisto);
        
        //Returns a histogram whose parmeters match those defined in the input HistoSetup object
        TH1F getHistogram(int iEta, int iPhi, Timing::HistoSetup &setupHisto);
        
        //Data Members
        //------------------------------------------------------------------------------------------------------------------------------------------
        std::string analysisName;
        
        //Holds Setup Parameters for the
        //Timing::HistoSetup hSetupClust_ADC, hSetupClust_Multi, hSetupClust_Pos, hSetupClust_Size, hSetupClust_Time;
        
        Uniformity::AnalysisSetupUniformity aSetup;
        
        Uniformity::DetectorMPGD detMPGD; //Link to header file in AnalyzeResponseUniformity.cpp
        
    }; //End class AnalyzeResponseUniformity
} //End namespace Uniformity


#endif /* defined(____AnalyzeResponseUniformity__) */
