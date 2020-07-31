//
// modified & integrated by Giovanni Abbiendi
// from code by Arun Luthra:
// UserCode/luthra/MuonTrackSelector/src/MuonTrackSelector.cc
//
#ifndef MCTruth_MuonTrackProducer_h
#define MCTruth_MuonTrackProducer_h

#include "DataFormats/CSCRecHit/interface/CSCSegmentCollection.h"
#include "DataFormats/DTRecHit/interface/DTRecSegment4DCollection.h"
#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/MuonReco/interface/MuonFwd.h"
#include "DataFormats/TrackerCommon/interface/TrackerTopology.h"
#include "Geometry/Records/interface/TrackerTopologyRcd.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/stream/EDProducer.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include <memory>

class MuonTrackProducer : public edm::stream::EDProducer<> {
public:
  explicit MuonTrackProducer(const edm::ParameterSet &);
  ~MuonTrackProducer() override;

private:
  void produce(edm::Event &, const edm::EventSetup &) override;

  edm::EDGetTokenT<reco::MuonCollection> muonsToken;
  edm::EDGetTokenT<DTRecSegment4DCollection> inputDTRecSegment4DToken_;
  edm::EDGetTokenT<CSCSegmentCollection> inputCSCSegmentToken_;
  edm::ESGetToken<TrackerTopology, TrackerTopologyRcd> ttopoToken_;

  std::vector<std::string> selectionTags;
  std::string trackType;
  bool ignoreMissingMuonCollection;
};

#endif
