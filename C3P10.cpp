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

 //C3P10

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

  Ptr<Node> producer1 = Names::Find<Node>("Dev1Pat1");
  Ptr<Node> producer2 = Names::Find<Node>("Dev2Pat1");
  Ptr<Node> producer3 = Names::Find<Node>("Dev3Pat1");
  Ptr<Node> producer4 = Names::Find<Node>("Dev1Pat2");
  Ptr<Node> producer5 = Names::Find<Node>("Dev2Pat2");
  Ptr<Node> producer6 = Names::Find<Node>("Dev3Pat2");
  Ptr<Node> producer7 = Names::Find<Node>("Dev1Pat3");
  Ptr<Node> producer8 = Names::Find<Node>("Dev2Pat3");
  Ptr<Node> producer9 = Names::Find<Node>("Dev3Pat3");
  Ptr<Node> producer10 = Names::Find<Node>("Dev1Pat4");
  Ptr<Node> producer11 = Names::Find<Node>("Dev2Pat4");
  Ptr<Node> producer12 = Names::Find<Node>("Dev3Pat4");
  Ptr<Node> producer13 = Names::Find<Node>("Dev1Pat5");
  Ptr<Node> producer14 = Names::Find<Node>("Dev2Pat5");
  Ptr<Node> producer15 = Names::Find<Node>("Dev3Pat5");
  Ptr<Node> producer16 = Names::Find<Node>("Dev1Pat6");
  Ptr<Node> producer17 = Names::Find<Node>("Dev2Pat6");
  Ptr<Node> producer18 = Names::Find<Node>("Dev3Pat6");
  Ptr<Node> producer19 = Names::Find<Node>("Dev1Pat7");
  Ptr<Node> producer20 = Names::Find<Node>("Dev2Pat7");
  Ptr<Node> producer21 = Names::Find<Node>("Dev3Pat7");
  Ptr<Node> producer22 = Names::Find<Node>("Dev1Pat8");
  Ptr<Node> producer23 = Names::Find<Node>("Dev2Pat8");
  Ptr<Node> producer24 = Names::Find<Node>("Dev3Pat8");
  Ptr<Node> producer25 = Names::Find<Node>("Dev1Pat9");
  Ptr<Node> producer26 = Names::Find<Node>("Dev2Pat9");
  Ptr<Node> producer27 = Names::Find<Node>("Dev3Pat9");
  Ptr<Node> producer25 = Names::Find<Node>("Dev1Pat10");
  Ptr<Node> producer26 = Names::Find<Node>("Dev2Pat10");
  Ptr<Node> producer27 = Names::Find<Node>("Dev3Pat10");
  
  ndn::AppHelper consumerHelper("ns3::ndn::ConsumerHealth");
  consumerHelper.SetAttribute("Frequency", StringValue("5")); // 5 interests a second
  consumerHelper.SetAttribute("Randomize", StringValue("exponential"));

  // on the first consumer node install a Consumer application
  // that will express interests in /dst1 namespace
  consumerHelper.SetAttribute("Seed", StringValue("3"));
  consumerHelper.SetPrefix("/Pat1_2");
  consumerHelper.Install(consumer1);
  
  consumerHelper.SetAttribute("Seed", StringValue("7"));
  consumerHelper.SetPrefix("/Pat3_4");
  consumerHelper.Install(consumer2);


  consumerHelper.SetAttribute("Seed", StringValue("5"));
  consumerHelper.SetPrefix("/Pat5_6");
  consumerHelper.Install(consumer3);


  ndn::AppHelper producerHelper("ns3::ndn::HealthProducer");
  producerHelper.SetAttribute("PayloadSize", StringValue("1018"));

  // Register /dst1 prefix with global routing controller and
  // install producer that will satisfy Interests in /dst1 namespace
  ndnGlobalRoutingHelper.AddOrigins("/Pat1_2", producer1);
  producerHelper.SetPrefix("/Pat1_2");
  producerHelper.SetAttribute("DataType", StringValue("2"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("1"));
  producerHelper.Install(producer1);

  ndnGlobalRoutingHelper.AddOrigins("/Pat1_2", producer2);
  producerHelper.SetPrefix("/Pat1_2");
  producerHelper.SetAttribute("DataType", StringValue("2"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("3"));
  producerHelper.Install(producer2);

  ndnGlobalRoutingHelper.AddOrigins("/Pat1_2", producer3);
  producerHelper.SetPrefix("/Pat1_2");
  producerHelper.SetAttribute("DataType", StringValue("4"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("2"));
  producerHelper.Install(producer3);

  ndnGlobalRoutingHelper.AddOrigins("/Pat1_2", producer4);
  producerHelper.SetPrefix("/Pat1_2");
  producerHelper.SetAttribute("DataType", StringValue("2"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("1"));
  producerHelper.Install(producer4);

  ndnGlobalRoutingHelper.AddOrigins("/Pat1_2", producer5);
  producerHelper.SetPrefix("/Pat1_2");
  producerHelper.SetAttribute("DataType", StringValue("2"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("5"));
  producerHelper.Install(producer5);

  ndnGlobalRoutingHelper.AddOrigins("/Pat1_2", producer6);
  producerHelper.SetPrefix("/Pat1_2");
  producerHelper.SetAttribute("DataType", StringValue("4"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("2"));
  producerHelper.Install(producer6);

  ndnGlobalRoutingHelper.AddOrigins("/Pat1_2", producer7);
  producerHelper.SetPrefix("/Pat1_2");
  producerHelper.SetAttribute("DataType", StringValue("2"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("4"));
  producerHelper.Install(producer7);

  ndnGlobalRoutingHelper.AddOrigins("/Pat1_2", producer8);
  producerHelper.SetPrefix("/Pat1_2");
  producerHelper.SetAttribute("DataType", StringValue("2"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("5"));
  producerHelper.Install(producer8);

  ndnGlobalRoutingHelper.AddOrigins("/Pat1_2", producer9);
  producerHelper.SetPrefix("/Pat1_2");
  producerHelper.SetAttribute("DataType", StringValue("4"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("3"));
  producerHelper.Install(producer9);

  ndnGlobalRoutingHelper.AddOrigins("/Pat3_4", producer10);
  producerHelper.SetPrefix("/Pat3_4");
  producerHelper.SetAttribute("DataType", StringValue("2"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("1"));
  producerHelper.Install(producer10);

  ndnGlobalRoutingHelper.AddOrigins("/Pat3_4", producer11);
  producerHelper.SetPrefix("/Pat3_4");
  producerHelper.SetAttribute("DataType", StringValue("2"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("3"));
  producerHelper.Install(producer11);

  ndnGlobalRoutingHelper.AddOrigins("/Pat3_4", producer12);
  producerHelper.SetPrefix("/Pat3_4");
  producerHelper.SetAttribute("DataType", StringValue("4"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("2"));
  producerHelper.Install(producer12);

  ndnGlobalRoutingHelper.AddOrigins("/Pat3_4", producer13);
  producerHelper.SetPrefix("/Pat3_4");
  producerHelper.SetAttribute("DataType", StringValue("2"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("1"));
  producerHelper.Install(producer13);

  ndnGlobalRoutingHelper.AddOrigins("/Pat3_4", producer14);
  producerHelper.SetPrefix("/Pat3_4");
  producerHelper.SetAttribute("DataType", StringValue("2"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("5"));
  producerHelper.Install(producer14);

  ndnGlobalRoutingHelper.AddOrigins("/Pat3_4", producer15);
  producerHelper.SetPrefix("/Pat3_4");
  producerHelper.SetAttribute("DataType", StringValue("4"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("2"));
  producerHelper.Install(producer15);

  ndnGlobalRoutingHelper.AddOrigins("/Pat3_4", producer16);
  producerHelper.SetPrefix("/Pat3_4");
  producerHelper.SetAttribute("DataType", StringValue("2"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("4"));
  producerHelper.Install(producer16);

  ndnGlobalRoutingHelper.AddOrigins("/Pat3_4", producer17);
  producerHelper.SetPrefix("/Pat3_4");
  producerHelper.SetAttribute("DataType", StringValue("2"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("5"));
  producerHelper.Install(producer17);

  ndnGlobalRoutingHelper.AddOrigins("/Pat3_4", producer18);
  producerHelper.SetPrefix("/Pat3_4");
  producerHelper.SetAttribute("DataType", StringValue("4"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("3"));
  producerHelper.Install(producer18);

  ndnGlobalRoutingHelper.AddOrigins("/Pat5_6", producer19);
  producerHelper.SetPrefix("/Pat5_6");
  producerHelper.SetAttribute("DataType", StringValue("4"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("3"));
  producerHelper.Install(producer19);

  ndnGlobalRoutingHelper.AddOrigins("/Pat5_6", producer20);
  producerHelper.SetPrefix("/Pat5_6");
  producerHelper.SetAttribute("DataType", StringValue("4"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("3"));
  producerHelper.Install(producer20);

  ndnGlobalRoutingHelper.AddOrigins("/Pat5_6", producer21);
  producerHelper.SetPrefix("/Pat5_6");
  producerHelper.SetAttribute("DataType", StringValue("4"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("3"));
  producerHelper.Install(producer21);

  ndnGlobalRoutingHelper.AddOrigins("/Pat5_6", producer22);
  producerHelper.SetPrefix("/Pat5_6");
  producerHelper.SetAttribute("DataType", StringValue("4"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("3"));
  producerHelper.Install(producer22);

  ndnGlobalRoutingHelper.AddOrigins("/Pat5_6", producer23);
  producerHelper.SetPrefix("/Pat5_6");
  producerHelper.SetAttribute("DataType", StringValue("4"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("3"));
  producerHelper.Install(producer23);

  ndnGlobalRoutingHelper.AddOrigins("/Pat5_6", producer24);
  producerHelper.SetPrefix("/Pat5_6");
  producerHelper.SetAttribute("DataType", StringValue("4"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("3"));
  producerHelper.Install(producer24);

  ndnGlobalRoutingHelper.AddOrigins("/Pat5_6", producer25);
  producerHelper.SetPrefix("/Pat5_6");
  producerHelper.SetAttribute("DataType", StringValue("4"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("3"));
  producerHelper.Install(producer25);

  ndnGlobalRoutingHelper.AddOrigins("/Pat5_6", producer26);
  producerHelper.SetPrefix("/Pat5_6");
  producerHelper.SetAttribute("DataType", StringValue("4"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("3"));
  producerHelper.Install(producer26);

  ndnGlobalRoutingHelper.AddOrigins("/Pat5_6", producer27);
  producerHelper.SetPrefix("/Pat5_6");
  producerHelper.SetAttribute("DataType", StringValue("4"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("3"));
  producerHelper.Install(producer27);

  ndnGlobalRoutingHelper.AddOrigins("/Pat5_6", producer28);
  producerHelper.SetPrefix("/Pat5_6");
  producerHelper.SetAttribute("DataType", StringValue("4"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("3"));
  producerHelper.Install(producer28);

  ndnGlobalRoutingHelper.AddOrigins("/Pat5_6", producer29);
  producerHelper.SetPrefix("/Pat5_6");
  producerHelper.SetAttribute("DataType", StringValue("4"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("3"));
  producerHelper.Install(producer29);

  ndnGlobalRoutingHelper.AddOrigins("/Pat5_6", producer30);
  producerHelper.SetPrefix("/Pat5_6");
  producerHelper.SetAttribute("DataType", StringValue("4"));
  producerHelper.SetAttribute("DiseaseRank", StringValue("3"));
  producerHelper.Install(producer30);

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
