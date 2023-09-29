#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "IDXShardPlugin.h"



void IDXShardPlugin::input(std::string file) {
 inputfile = file;
readParameterFile(file);
std::ifstream countfile(std::string(PluginManager::prefix())+"/"+myParameters["bowtie2_index"], std::ios::in);
}

void IDXShardPlugin::run() {}

void IDXShardPlugin::output(std::string file) {
  myCommand = "python plugins/IDXShard/runIDXShard.py ";
  myCommand += "--bowtie2_index "+std::string(PluginManager::prefix())+"/"+myParameters["bowtie2_index"];
  myCommand += " --shards "+myParameters["shards"];
  std::cout << myCommand << std::endl;
 system(myCommand.c_str());
}

PluginProxy<IDXShardPlugin> IDXShardPluginProxy = PluginProxy<IDXShardPlugin>("IDXShard", PluginManager::getInstance());
