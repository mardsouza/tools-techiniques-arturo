// CSC Latin America 2026 - Main Analysis Program
#include "Particle.hpp"
#include "EventProcessor.hpp"
#include "TrackReconstructor.hpp"

#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <ROOT/RDataFrame.hxx>

#include <iostream>
#include <chrono>

using namespace csc2026;

void runSimpleAnalysis() {
    std::cout << "=== CSC 2026 Simple Analysis ===" << std::endl;
    
    // Create some test particles
    Particle electron(10.0, 20.0, 30.0, 0.000511);  // electron
    Particle muon(-15.0, 25.0, -40.0, 0.1057);      // muon
    
    std::cout << "Electron pT: " << electron.pt() << " GeV" << std::endl;
    std::cout << "Electron energy: " << electron.energy() << " GeV" << std::endl;
    std::cout << "Muon pT: " << muon.pt() << " GeV" << std::endl;
    
    // Combine particles
    Particle combined = electron + muon;
    std::cout << "Combined mass: " << combined.mass() << " GeV" << std::endl;
}

void runEventProcessing(int nEvents = 1000) {
    std::cout << "\n=== Event Processing ===" << std::endl;
    
    auto events = generateSampleEvents(nEvents, 50);
    EventProcessor processor;
    
    auto start = std::chrono::high_resolution_clock::now();
    processor.processEvents(events);
    auto end = std::chrono::high_resolution_clock::now();
    
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    std::cout << "Processed " << nEvents << " events" << std::endl;
    std::cout << "Total tracks: " << processor.totalTracksProcessed() << std::endl;
    std::cout << "Total energy: " << processor.totalEnergy() << " GeV" << std::endl;
    std::cout << "Time: " << duration.count() << " ms" << std::endl;
}

void runTrackReconstruction() {
    std::cout << "\n=== Track Reconstruction ===" << std::endl;
    
    TrackReconstructor reco(200);
    
    // Add some test hits
    for (int i = 0; i < 25; ++i) {
        Hit hit{
            static_cast<double>(i) * 0.5,
            static_cast<double>(i) * 0.3 + (i % 5) * 0.1,
            static_cast<double>(i) * 10.0,
            1.0
        };
        reco.addHit(hit);
    }
    
    auto tracks = reco.reconstruct();
    std::cout << "Reconstructed " << tracks.size() << " tracks" << std::endl;
    
    for (size_t i = 0; i < tracks.size(); ++i) {
        std::cout << "  Track " << i << ": " 
                  << tracks[i].hits.size() << " hits, "
                  << "pT=" << tracks[i].pt << ", "
                  << "chi2=" << tracks[i].chi2() << std::endl;
    }
}

int main(int argc, char* argv[]) {
    std::cout << "CSC Latin America 2026 - HEP Analysis Framework" << std::endl;
    std::cout << "================================================" << std::endl;
    
    runSimpleAnalysis();
    runEventProcessing();
    runTrackReconstruction();
    
    std::cout << "\nAnalysis complete!" << std::endl;
    return 0;
}
