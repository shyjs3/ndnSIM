/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/**
 * Copyright (c) 2011-2015  Regents of the University of California.
 *
 * This file is part of ndnSIM. See AUTHORS for complete list of ndnSIM authors and
 * contributors.
 *
 * ndnSIM is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * ndnSIM is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * ndnSIM, e.g., in COPYING.md file.  If not, see <http://www.gnu.org/licenses/>.
 **/

// ndn-congestion-topo-plugin.cpp

#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/ndnSIM-module.h"

namespace ns3 {

/**
 * This scenario simulates a grid topology (using topology reader module)
 *
 *   /------\                                                    /------\
 *   | Src1 |<--+                                            +-->| Dst1 |
 *   \------/    \                                          /    \------/
 *                \                                        /
 *                 +-->/------\   "bottleneck"  /------\<-+
 *                     | Rtr1 |<===============>| Rtr2 |
 *                 +-->\------/                 \------/<-+
 *                /                                        \
 *   /------\    /                                          \    /------\
 *   | Src2 |<--+                                            +-->| Dst2 |
 *   \------/                                                    \------/
 *
 * To run scenario and see what is happening, use the following command:
 *
 *     NS_LOG=ndn.Consumer:ndn.Producer ./waf --run=ndn-congestion-topo-plugin
 */

 //C27P3

int
main(int argc, char* argv[])
{
  CommandLine cmd;
  cmd.Parse(argc, argv);

  AnnotatedTopologyReader topologyReader("", 25);
  topologyReader.SetFileName("src/ndnSIM/examples/topologies/C3P9.txt");
  topologyReader.Read();

  // Install NDN stack on all nodes
  ndn::StackHelper ndnHelper;
  // ndnHelper.SetOldContentStore("ns3::ndn::cs::Lru", "MaxSize", "10000");
  ndnHelper.InstallAll();



  // Choosing forwarding strategy
  ndn::StrategyChoiceHelper::InstallAll("/", "/localhost/nfd/strategy/best-route");

  // Installing global routing interface on all nodes
  ndn::GlobalRoutingHelper ndnGlobalRoutingHelper;
  ndnGlobalRoutingHelper.InstallAll();

  // Getting containers for the consumer/producer
  Ptr<Node> consumer1 = Names::Find<Node>("Doc1");
  Ptr<Node> consumer2 = Names::Find<Node>("Doc2");
  Ptr<Node> consumer3 = Names::Find<Node>("Doc3");
  Ptr<Node> consumer4 = Names::Find<Node>("Doc4");
  Ptr<Node> consumer5 = Names::Find<Node>("Doc5");
  Ptr<Node> consumer6 = Names::Find<Node>("Doc6");
  Ptr<Node> consumer7 = Names::Find<Node>("Doc7");
  Ptr<Node> consumer8 = Names::Find<Node>("Doc8");
  Ptr<Node> consumer9 = Names::Find<Node>("Doc9");
  Ptr<Node> consumer10 = Names::Find<Node>("Doc10");
  Ptr<Node> consumer11 = Names::Find<Node>("Doc11");
  Ptr<Node> consumer12  Names::Find<Node>("Doc12");
  Ptr<Node> consumer13 = Names::Find<Node>("Doc13");
  Ptr<Node> consumer14 = Names::Find<Node>("Doc14");
  Ptr<Node> consumer15  Names::Find<Node>("Doc15");
  Ptr<Node> consumer16 = Names::Find<Node>("Doc16");
  Ptr<Node> consumer17 = Names::Find<Node>("Doc17");
  Ptr<Node> consumer18  Names::Find<Node>("Doc18");
  Ptr<Node> consumer19 = Names::Find<Node>("Doc19");
  Ptr<Node> consumer20 = Names::Find<Node>("Doc20");
  Ptr<Node> consumer21  Names::Find<Node>("Doc21");
  Ptr<Node> consumer22 = Names::Find<Node>("Doc22");
  Ptr<Node> consumer23 = Names::Find<Node>("Doc23");
  Ptr<Node> consumer24  Names::Find<Node>("Doc24");
  Ptr<Node> consumer25 = Names::Find<Node>("Doc25");
  Ptr<Node> consumer26 = Names::Find<Node>("Doc26");
  Ptr<Node> consumer27  Names::Find<Node>("Doc27");

  Ptr<Node> producer1 = Names::Find<Node>("Dev1Pat1");
  Ptr<Node> producer2 = Names::Find<Node>("Dev2Pat1");
  Ptr<Node> producer3 = Names::Find<Node>("Dev3Pat1");
  Ptr<Node> producer4 = Names::Find<Node>("Dev1Pat2");
  Ptr<Node> producer5 = Names::Find<Node>("Dev2Pat2");
  Ptr<Node> producer6 = Names::Find<Node>("Dev3Pat2");
  Ptr<Node> producer7 = Names::Find<Node>("Dev1Pat3");
  Ptr<Node> producer8 = Names::Find<Node>("Dev2Pat3");
  Ptr<Node> producer9 = Names::Find<Node>("Dev3Pat3");


  ndn::AppHelper consumerHelper("ns3::ndn::ConsumerHealth");
  consumerHelper.SetAttribute("Frequency", StringValue("5")); // 5 interests a second
  consumerHelper.SetAttribute("Randomize", StringValue("exponential"));

  // on the first consumer node install a Consumer application
  // that will express interests in /dst1 namespace
  consumerHelper.SetAttribute("Seed", StringValue("3"));
  consumerHelper.SetPrefix("/Pat1");
  consumerHelper.Install(consumer1);
  
  consumerHelper.SetAttribute("Seed", StringValue("7"));
  consumerHelper.SetPrefix("/Pat2");
  consumerHelper.Install(consumer2);


  consumerHelper.SetAttribute("Seed", StringValue("5"));
  consumerHelper.SetPrefix("/Pat3");
  consumerHelper.Install(consumer3);

  consumerHelper.SetAttribute("Seed", StringValue("3"));
  consumerHelper.SetPrefix("/Pat1");
  consumerHelper.Install(consumer4);
  
  consumerHelper.SetAttribute("Seed", StringValue("7"));
  consumerHelper.SetPrefix("/Pat2");
  consumerHelper.Install(consumer5);


  consumerHelper.SetAttribute("Seed", StringValue("5"));
  consumerHelper.SetPrefix("/Pat3");
  consumerHelper.Install(consumer6);

  consumerHelper.SetAttribute("Seed", StringValue("3"));
  consumerHelper.SetPrefix("/Pat1");
  consumerHelper.Install(consumer7);
  
  consumerHelper.SetAttribute("Seed", StringValue("7"));
  consumerHelper.SetPrefix("/Pat2");
  consumerHelper.Install(consumer8);

  consumerHelper.SetAttribute("Seed", StringValue("5"));
  consumerHelper.SetPrefix("/Pat3");
  consumerHelper.Install(consumer9);

  consumerHelper.SetAttribute("Seed", StringValue("3"));
  consumerHelper.SetPrefix("/Pat1");
  consumerHelper.Install(consumer10);
  
  consumerHelper.SetAttribute("Seed", StringValue("7"));
  consumerHelper.SetPrefix("/Pat2");
  consumerHelper.Install(consumer11);

  consumerHelper.SetAttribute("Seed", StringValue("5"));
  consumerHelper.SetPrefix("/Pat3");
  consumerHelper.Install(consumer12);

  consumerHelper.SetAttribute("Seed", StringValue("3"));
  consumerHelper.SetPrefix("/Pat1");
  consumerHelper.Install(consumer13);
  
  consumerHelper.SetAttribute("Seed", StringValue("7"));
  consumerHelper.SetPrefix("/Pat2");
  consumerHelper.Install(consumer14);

  consumerHelper.SetAttribute("Seed", StringValue("5"));
  consumerHelper.SetPrefix("/Pat3");
  consumerHelper.Install(consumer15);

  consumerHelper.SetAttribute("Seed", StringValue("3"));
  consumerHelper.SetPrefix("/Pat1");
  consumerHelper.Install(consumer16);
  
  consumerHelper.SetAttribute("Seed", StringValue("7"));
  consumerHelper.SetPrefix("/Pat2");
  consumerHelper.Install(consumer17);

  consumerHelper.SetAttribute("Seed", StringValue("5"));
  consumerHelper.SetPrefix("/Pat3");
  consumerHelper.Install(consumer18);

  consumerHelper.SetAttribute("Seed", StringValue("3"));
  consumerHelper.SetPrefix("/Pat1");
  consumerHelper.Install(consumer19);
  
  consumerHelper.SetAttribute("Seed", StringValue("7"));
  consumerHelper.SetPrefix("/Pat2");
  consumerHelper.Install(consumer20);

  consumerHelper.SetAttribute("Seed", StringValue("5"));
  consumerHelper.SetPrefix("/Pat3");
  consumerHelper.Install(consumer21);

  consumerHelper.SetAttribute("Seed", StringValue("3"));
  consumerHelper.SetPrefix("/Pat1");
  consumerHelper.Install(consumer22);
  
  consumerHelper.SetAttribute("Seed", StringValue("7"));
  consumerHelper.SetPrefix("/Pat2");
  consumerHelper.Install(consumer23);

  consumerHelper.SetAttribute("Seed", StringValue("5"));
  consumerHelper.SetPrefix("/Pat3");
  consumerHelper.Install(consumer24);

  consumerHelper.SetAttribute("Seed", StringValue("3"));
  consumerHelper.SetPrefix("/Pat1");
  consumerHelper.Install(consumer25);
  
  consumerHelper.SetAttribute("Seed", StringValue("7"));
  consumerHelper.SetPrefix("/Pat2");
  consumerHelper.Install(consumer26);

  consumerHelper.SetAttribute("Seed", StringValue("5"));
  consumerHelper.SetPrefix("/Pat3");
  consumerHelper.Install(consumer27);


  ndn::AppHelper producerHelper("ns3::ndn::HealthProducer");
  producerHelper.SetAttribute("PayloadSize", StringValue("1018"));

  // Register /dst1 prefix with global routing controller and
  // install producer that will satisfy Interests in /dst1 namespace
  ndnGlobalRoutingHelper.AddOrigins("/Pat1", producer1);
  producerHelper.SetPrefix("/Pat1");
  producerHelper.SetAttribute("DataType", StringValue("2"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("1"));
  producerHelper.Install(producer1);

  ndnGlobalRoutingHelper.AddOrigins("/Pat1", producer2);
  producerHelper.SetPrefix("/Pat1");
  producerHelper.SetAttribute("DataType", StringValue("2"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("3"));
  producerHelper.Install(producer2);

  ndnGlobalRoutingHelper.AddOrigins("/Pat1", producer3);
  producerHelper.SetPrefix("/Pat1");
  producerHelper.SetAttribute("DataType", StringValue("4"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("2"));
  producerHelper.Install(producer3);

  ndnGlobalRoutingHelper.AddOrigins("/Pat2", producer4);
  producerHelper.SetPrefix("/Pat2");
  producerHelper.SetAttribute("DataType", StringValue("2"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("1"));
  producerHelper.Install(producer4);

  ndnGlobalRoutingHelper.AddOrigins("/Pat2", producer5);
  producerHelper.SetPrefix("/Pat2");
  producerHelper.SetAttribute("DataType", StringValue("2"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("5"));
  producerHelper.Install(producer5);

  ndnGlobalRoutingHelper.AddOrigins("/Pat2", producer6);
  producerHelper.SetPrefix("/Pat2");
  producerHelper.SetAttribute("DataType", StringValue("4"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("2"));
  producerHelper.Install(producer6);

  ndnGlobalRoutingHelper.AddOrigins("/Pat3", producer7);
  producerHelper.SetPrefix("/Pat3");
  producerHelper.SetAttribute("DataType", StringValue("2"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("4"));
  producerHelper.Install(producer7);

  ndnGlobalRoutingHelper.AddOrigins("/Pat3", producer8);
  producerHelper.SetPrefix("/Pat3");
  producerHelper.SetAttribute("DataType", StringValue("2"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("5"));
  producerHelper.Install(producer8);

  ndnGlobalRoutingHelper.AddOrigins("/Pat3", producer9);
  producerHelper.SetPrefix("/Pat3");
  producerHelper.SetAttribute("DataType", StringValue("4"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("3"));
  producerHelper.Install(producer9);


  // Calculate and install FIBs
  ndn::GlobalRoutingHelper::CalculateRoutes();

  Simulator::Stop(Seconds(50.0));

  ndn::AppDelayTracer::InstallAll("app-delays.txt");
  Simulator::Run();
  Simulator::Destroy();

  return 0;
}

} // namespace ns3

int
main(int argc, char* argv[])
{
  return ns3::main(argc, argv);
}
